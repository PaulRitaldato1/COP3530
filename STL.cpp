#include <vector> //allows you to use vectors
#include <iostream> //allows basic io to stdout and stdin
#include <utility> //allows the use of pairs
#include <unordered_map> //allows the use of hashmaps 
#include <stack> //allows the use of stacks
#include <queue> //allows the use of queues
#include <list> //allows the use of (linked)lists
#include <string> //allows the use of strings

int main(){
    
    std::vector<int> vect;
    vect.push_back(1);

    std::pair<int, std::string> pair;
    pair.first = 1;
    pair.second = "Hello there";

    std::unordered_map<int, std::string> hashmap;
    hashmap.insert({1, "hello there"}); 

    std::stack<int> stack;
    stack.push(1);

    std::queue<int> queue;
    queue.push(1);

    std::list<int> list;
    list.emplace(0, 1);


}
