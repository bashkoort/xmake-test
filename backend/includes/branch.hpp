#pragma once

#include<vector>
#include"letter.hpp"

struct BranchView {
    std::vector<LetterView> start_letters;
    std::vector<LetterView> end_letters;
    int branch_id;
};

std::ostream& operator<<(std::ostream& str, const BranchView& v);

class Branch {
public:
    Branch();
    Branch(int cnt_size);
    std::vector<Letter> GetLettersToCarrier(int branch_id);
    BranchView GetView();
    void SetId(int id);
    void ReceivePushLetter(Letter let);
    void ReceiveLetter(std::vector<Letter> let);

 
private:
    int branch_id = -1;
    std::vector<std::vector<Letter>> start_letters;  //для каждого филиала отдельно массив писем которые нужно отвезти в этот филиал
    std::vector<Letter> end_letters;
    //std::vector<int> all_lettes;
};
