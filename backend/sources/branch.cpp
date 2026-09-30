#include"branch.hpp"
#include "letter.hpp"
#include <vector>


Branch::Branch(){};
Branch::Branch(int sz) {
    start_letters.resize(sz);
}
void Branch::ReceiveLetter(std::vector<Letter> let) {
    for (auto& x : let) {
        end_letters.push_back(x);
    }
    return;
}

BranchView Branch::GetView() {
    std::vector<LetterView> start_let;
    for (auto& x : start_letters) {
        for (auto& z : x) {
            start_let.push_back(z.GetView());
        }
    }
    std::vector<LetterView> end_let;
    for (auto& x : end_letters) {
        end_let.push_back(x.GetView());
    }
    return {start_let, end_let, branch_id};
}

std::ostream& operator<<(std::ostream& str, const BranchView& v) {
    str << "Branch ID: " << v.branch_id << '\n'
    << "Current branch's start_letters\n";
    for (auto& x : v.start_letters) str << x;
    str << '\n';
    str << "Current branch's end_letters\n";
    for (auto& x : v.end_letters) str << x;
    str << '\n';
    return str;
}

void Branch::ReceivePushLetter(Letter let) {
    start_letters[let.GetEndBranch()].push_back(let);
}
void Branch::SetId(int id) {
    branch_id = id;
}

std::vector<Letter> Branch::GetLettersToCarrier(int b_id) {
    std::vector<Letter> tmp = start_letters[b_id];
    start_letters[b_id].clear();
    return tmp;
}
