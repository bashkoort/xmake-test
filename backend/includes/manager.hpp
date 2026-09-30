#pragma once

#include"generator.hpp"
#include"letter.hpp"
#include"branch.hpp"
#include"carrier.hpp"
#include<SFML/System/Clock.hpp>
#include<vector>
#include<map>
#include<set>

class Manager {
public:
    Manager(int branches_count, int carriers_count, std::vector<std::vector<int>> branch_g);
    void Update(int time);
    void GetLetter(TMP_Letter let);
    void Check();
    std::vector<BranchView> GetBranchesView();
    std::vector<CarrierView> GetCarrierView();
    // std::vector<


private:
    std::vector<Branch> branches;
    std::vector<Carrier> carriers;
    int global_current_time = 0;
    std::vector<std::vector<int>> branches_graph;
    std::set<int> available_carriers; // доступные курьеры без писем
    std::vector<std::map<int, Letter>> queue_letters;// start_time + letter id
   
};