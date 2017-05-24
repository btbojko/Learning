#include <iostream>
#include <vector>
#include <utility>
#include <map>

typedef std::vector<int> vec_i;
typedef std::vector<double> vec_d;

std::map<int, double> pair_to_map(std::pair<vec_i, vec_d> my_pair)
{
    std::map<int, double> my_map;
    for (unsigned i = 0; i < my_pair.first.size(); ++i)
    {
        my_map[my_pair.first[i]] = my_pair.second[i];
    }
    return my_map;
}

int main()
{

    std::pair<vec_i, vec_d> temp = {{2, 3, 4}, {4.3, 5.1, 6.4}};

    std::map<int, double> new_map = pair_to_map(temp);

    for (auto it = new_map.begin(); it != new_map.end(); ++it)
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }
    return 0;
}
