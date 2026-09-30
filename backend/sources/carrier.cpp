#include"carrier.hpp"
#include "letter.hpp"
#include <vector>

void Carrier::ReceiveLetters(std::vector<Letter> letters) {
    next_branch_id = letters[0].GetEndBranch();
    for (auto& x : letters) {
        current_letters.push_back(x);
    }
}
void Carrier::SetId(int id) {
    carrier_id = id;
}
CarrierView Carrier::GetView() {
    std::vector<LetterView> let;
    for (auto& x : current_letters) let.push_back(x.GetView());
    return {carrier_id, current_branch_id, next_branch_id, time_start_branch, time_end_branch, let};
}
bool Carrier::Update(int time) {
    if (next_branch_id == -1) return 0;
    time_to_next_branch -= time;
    return time_to_next_branch == 0;

}
std::ostream& operator<<(std::ostream& str, const CarrierView& v) {
    str << "Carrier ID: " << v.carrier_id << '\n'
    << "Current_branch: " << v.current_branch << ' ' << "Next_Branch: " << v.next_branch << '\n'
    << "Start_time: " << v.start_time << ' ' << "End_time: " << v.end_time << '\n';
    str << "Current carriers' letters\n";
    for (auto& x : v.current_letters) {
        str << x;
    }
    str << '\n';
    return str;
}
void Carrier::AddMovement(int b1, int b2) {
    movements.push_back({b1, b2});
}
void Carrier::SetStartTime(int time) {
    time_start_branch = time;
}
int Carrier::GetNextBranchId() {
    return next_branch_id;
}
int Carrier::GetCurBranchId() {
    return current_branch_id;
}
std::vector<Letter> Carrier::PushLetterToBranch(int branch_id) {
    std::vector<Letter> tmp;
    if (current_letters.empty()) return tmp;
    while (!current_letters.empty() && current_letters.front().GetEndBranch() == branch_id) {
        Letter let = current_letters.front();
        current_letters.pop_front();
        tmp.push_back(let);
    }
    return tmp;
}
void Carrier::SetNextBranch(int branch_id, int next_time) {
    time_end_branch = next_time;
    next_branch_id = branch_id;
    return;
}

void Carrier::SetCurrentBranch(int branch_id) {
    current_branch_id = branch_id;
    return;
}
void Carrier::SetTimeToBranch(int time) {
    time_to_next_branch = time;
    return;
}

