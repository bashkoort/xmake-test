#pragma once

#include<deque>
#include <ostream>
#include"letter.hpp"
#include"vector"

struct CarrierView {
    int carrier_id, current_branch, next_branch, start_time, end_time;
    std::vector<LetterView> current_letters;
};

std::ostream& operator<<(std::ostream& str, const CarrierView& v);

class Carrier {
public:
    void ReceiveLetters(std::vector<Letter> letters);
    CarrierView GetView();
    void SetId(int id);
    int GetCurBranchId();
    int GetNextBranchId();
    bool Update(int time);
    void SetStartTime(int time);
    void SetNextBranch(int branch_id, int next_time);
    void SetTimeToBranch(int time);
    void AddMovement(int b1, int b2);
    void SetCurrentBranch(int branch_id);
    std::vector<Letter> PushLetterToBranch(int branch_id);
private:
    int carrier_id = 0;
    std::deque<Letter> current_letters;
    int current_branch_id = 0;
    int time_start_branch = 0;
    int next_branch_id = -1;
    std::vector<std::pair<int, int>> movements;
    int time_to_next_branch = 0;
    int time_end_branch = 0;
};
