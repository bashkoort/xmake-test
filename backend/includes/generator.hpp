#pragma once
#include<vector>
#include <random>

struct TMP_Letter {
    int start_branch_id = -1;
    int end_branch_id = -1;
    int type = 0;
    int time_start_branch = 0;
};

class Generator {
public:
    Generator() {
        gen.seed(5252);
        fib.resize(20);
        fib[0] = 1;
        fib[1] = 2;
        for (int i = 2; i < fib.size(); ++i) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
    }
    std::vector<TMP_Letter> generate_letters(int branch_size);
    int get_random(int l, int r);
    int generate_branch(int branch_size);

private:
    std::vector<int> fib;
    std::mt19937 gen;
};