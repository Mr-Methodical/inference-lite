#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    const vector<pair<double, double>> data = {{1, 4}, {2, 6}, {3, 8}};
    double w = 0;
    double b = 0;
    const double learningRate = 0.05;
    for (int step = 0; step < 1000000; ++step) {
        double gradW = 0;
        double gradB = 0;

        for (auto [x, y] : data) {
            double prediction = w * x + b;
            double error = prediction - y;
            gradW += 2 * error * x;
            gradB += 2 * error;
        }
        gradW /= data.size();
        gradB /= data.size();

        w -= learningRate * gradW;
        b -= learningRate * gradB;
    }
    cout << "w = " << w << ", b = " << b << '\n';
}