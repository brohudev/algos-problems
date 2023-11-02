#include <iostream>

class Solution {
public:
    int lastRemaining(int n) {
        return (n == 1) ? 1 : 2 * (n / 2 + 1 - lastRemaining(n / 2));
    }
};

int main() {
    Solution s;
    int n;
    std::cin >> n;
    std::cout << s.lastRemaining(n) << std::endl;
    return 0;
}
