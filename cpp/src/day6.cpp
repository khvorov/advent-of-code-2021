#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

int main()
{
    std::vector<int> fishes;

    std::string data;
    std::getline(std::cin, data);

    std::stringstream ss(data);

    for (int i; ss >> i;) {
        fishes.push_back(i);

        if (ss.peek() == ',') {
            ss.ignore();
        }
    }

    for (int d = 0; d < 80; ++d) {
        int newborn = 0;

#if 0
        for (auto f : fishes) {
            std::cout << f << ' ';
        }
        std::cout << '\n';
#endif

        for (auto& f : fishes) {
            if (f == 0) {
                f = 6;
                ++newborn;
            } else {
                --f;
            }
        }

        for (int i = 0; i < newborn; ++i) {
            fishes.push_back(8);
        }
    }

    std::cout << fishes.size() << '\n';

    return 0;
}
