#include"manager.hpp"
#include "branch.hpp"
#include "carrier.hpp"
#include "generator.hpp"
#include "letter.hpp"
#include <random>
#include <vector>


std::mt19937 rnd(525252);

Manager::Manager(int branches_count, int carriers_count, std::vector<std::vector<int>> branch_g) {
    branches.resize(branches_count, Branch(branches_count));
    carriers.resize(carriers_count);
    queue_letters.resize(4);
    for (int i = 0; i < branches_count; ++i) {
        branches[i].SetId(i);
    }
    branches_graph = branch_g;
    for (int i = 0; i < carriers_count; ++i) {
        available_carriers.insert(i);
    }
    for (int i = 0; i < carriers_count; ++i) {
        carriers[i].SetId(i);
        carriers[i].SetCurrentBranch(std::uniform_int_distribution<int>(0LL, branches_count - 1LL)(rnd));
    }
}

void Manager::Update(int time) {
    global_current_time += time;
    for (auto& x : carriers) {
        if (x.GetNextBranchId() != -1) {
            if (x.Update(time)) {
                std::vector<Letter> push = x.PushLetterToBranch(x.GetNextBranchId());
                branches[x.GetNextBranchId()].ReceiveLetter(push);
                x.SetCurrentBranch(x.GetNextBranchId());
                x.SetNextBranch(-1, 0);
            }
        }
    }
    return;
}
void Manager::GetLetter(TMP_Letter let) {
    Letter nw(let.start_branch_id, let.end_branch_id, let.type, let.time_start_branch);
    branches[let.start_branch_id].ReceivePushLetter(nw);
    queue_letters[nw.GetType()][nw.GetStartTime()] = nw;
    return;
}
void Manager::Check() {
    if (available_carriers.empty()) return;
    Letter let;
    bool flag = false;
    for (auto& x : queue_letters) {
        if (x.empty()) continue;
        let = x.begin()->second;
        flag = true;
        break;
    }
    if (flag == false) return;
    int start_branch = let.GetStartBranch();
    int best_id = *available_carriers.begin();
    int end_branch = let.GetEndBranch();
    int best_time = 1e8;
    for (auto& car_id : available_carriers) {
        int tmp_time = branches_graph[start_branch][carriers[car_id].GetCurBranchId()];
        if (best_time > tmp_time) {
            best_time = tmp_time;
            best_id = car_id;
        }
    }
    std::vector<Letter> push_let = branches[start_branch].GetLettersToCarrier(end_branch);
    int time_to_end = branches_graph[start_branch][end_branch] + std::uniform_int_distribution<int>(0, 15)(rnd);
    for (auto& x : push_let) queue_letters[x.GetType()].erase(x.GetStartTime());
    for (auto& x : push_let) x.SetEndtime(global_current_time + time_to_end);
    carriers[best_id].ReceiveLetters(push_let);
    carriers[best_id].SetTimeToBranch(time_to_end);
    carriers[best_id].SetNextBranch(end_branch, global_current_time + time_to_end);
    carriers[best_id].SetStartTime(global_current_time);
    carriers[best_id].AddMovement(start_branch, end_branch);
    available_carriers.erase(best_id);

    return;
}

std::vector<BranchView> Manager::GetBranchesView() {
    std::vector<BranchView> tmp;
    for (int i = 0; i < branches.size(); ++i) {
        tmp.push_back(branches[i].GetView()); 
    }
    return tmp;
}

std::vector<CarrierView> Manager::GetCarrierView() {
    std::vector<CarrierView> tmp;
    for (int i = 0; i < carriers.size(); ++i) {
        CarrierView z = carriers[i].GetView();
        tmp.push_back(z);
    }
    return tmp;
}
