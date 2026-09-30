#pragma once
#include<ostream>

struct LetterView {
    int type, start_branch, end_branch, start_time, end_time;
};

std::ostream& operator<<(std::ostream& str, const LetterView& v);

class Letter {
public:
    Letter();
    Letter(int st_br, int end_br, int tm_pr, int start_time);
    void SetExpectTime(int time);
    LetterView GetView();
    void SetEndtime(int time);
    int GetId();
    int GetStartTime();
    int GetEndBranch();
    int GetType();
    int GetStartBranch();

private:
    //int letter_id = 0;
    int start_branch_id = -1;
    int end_branch_id = -1;
    int type = 0;
    int time_start_branch = 0;
    int time_end_branch = 0;
    int time_expect = 0;
};
