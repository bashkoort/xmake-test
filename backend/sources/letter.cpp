
#include"global.hpp"
#include"letter.hpp"


Letter::Letter(){};
Letter::Letter(int st_br, int end_br, int tm_pr, int start_time) {
    //letter_id = let_id;
    start_branch_id = st_br;
    end_branch_id = end_br;
    type = tm_pr;
    time_start_branch = start_time;
    return;
}
std::ostream& operator<<(std::ostream& str, const LetterView& v) {
    str << "Letter: " <<  "type: " << v.type << '\n' << "branch1: " << v.start_branch << " branch2: " << v.end_branch << '\n'
     << "start_time: " << v.start_time << " end_time: " << v.end_time << '\n';
     return str;
}
LetterView Letter::GetView() {
    return {type, start_branch_id, end_branch_id, time_start_branch, time_end_branch };
}
void Letter::SetEndtime(int time) {
    time_end_branch = time;
    return;
}
int Letter::GetStartTime() {
    return time_start_branch;
}
// int Letter::GetId() {
//     return letter_id;
// }
int Letter::GetEndBranch() {
    return end_branch_id;
}
int Letter::GetType() {
    return type;
}
int Letter::GetStartBranch() {
    return start_branch_id;
}
void Letter::SetExpectTime(int time) {
    time_expect = time;
    return;
}