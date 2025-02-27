#include <iostream>
#include <cstdlib>
#include <ctime>

double get_random_threshold() {
    return (double)rand() / RAND_MAX * 1000;
}

double cover_paradox_simulation(int trials = 100000) {
    int success = 0;
    for (int i = 0; i < trials; i++) {
        int x = rand() % 1001;
        int y = rand() % 1001;
        if (x > y) std::swap(x, y);

        int revealed = (rand() % 2) ? x : y;
        double T = get_random_threshold();

        bool guess_higher = revealed < T;
        bool correct = (guess_higher == (revealed == x));

        if (correct) success++;
    }
    return (double)success / trials * 100.0;
}

int main() {
    srand(time(0));
    std::cout << "Success Rate: " << cover_paradox_simulation() << "%\n";
    return 0;
}