#include <iostream>

using namespace std;

int main() {
    int n;
    std::cin >> n;
    int r[n];

    for(int i = 0; i < n; i++) {
        std::cin >> r[i];
    }
    int diffMax = -999999999;
    int min = r[0];
    int tmp = 0;
    for(int i = 1; i <= n-1; i++) {
        if(diffMax < r[i] - min) diffMax = r[i] - min;
        if(r[i] < min) min = r[i];
    }
    std::cout << diffMax << endl;
}