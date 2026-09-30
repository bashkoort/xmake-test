#include"generator.hpp"

std::vector<TMP_Letter> Generator::generate_letters(int branch_size) {
    std::vector<TMP_Letter> gen_let;
    int start_time = 0;
    while(start_time < 8 * 60) {
        int get_time = start_time;
        if (start_time < 8 * 60) {
            get_time += get_random(30, 60 * 2);
        } else if (start_time < 12 * 60) {
            get_time += get_random(10, 60);
        } else if (start_time < 16 * 60) {
            get_time += get_random(1, 20);
        } else {
            get_time += get_random(10, 60);
        }
        int type;
        if (start_time < 12 * 60 || start_time >= 16 * 60) {
            int rand = get_random(0, 1000);
            if (rand < 200) {
                type = 1;
            } else if (type < 500) {
                type = 2;
            } else {
                type = 3;
            }
        } else {
            int rand = get_random(0, 1000);
            if (rand < 600) {
                type = 1;
            } else if (type < 800) {
                type = 2;
            } else {
                type = 3;
            }
        }
        int rand_br1 = get_random(0, 1000 * branch_size);
        
        int branch1 = generate_branch(branch_size);
        int branch2 = branch1;
        while(branch2 == branch1) branch2 = generate_branch(branch_size);
        TMP_Letter tmp = {branch1, branch2, type, get_time};
        gen_let.push_back(tmp);
        start_time = get_time;
    }
    return gen_let;
}

int Generator::get_random(int l, int r) {
    int rand_tmp = std::uniform_int_distribution<int>(l, r)(gen);
    return rand_tmp;
}

int Generator::generate_branch(int branch_size) {
    int rn = get_random(0, 100 * branch_size);
    for (int i = 0; i < branch_size; ++i) {
        if (rn < fib[i]) {
            return i;
        }
    }
    return 0;
    
}