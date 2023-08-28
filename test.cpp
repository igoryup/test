#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>

int main()
{
    std::priority_queue<int> pq;
    int num;
    std::string command;
    while (std::cin >> command)
    {
        if (command == "CLEAR")
        {
            while (!pq.empty())
            {
                pq.pop();
            }
        }
        else if (command == "ADD")
        {
            std::cin >> num;
            pq.push(num);
        }
        else if (command == "EXTRACT")
        {
            if (pq.empty())
            {
                std::cout << "CANNOT\n";
            }
            else
            {
                std::cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}
