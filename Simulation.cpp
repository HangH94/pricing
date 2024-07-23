#include "Simulation.h"

double equitySimulation::getRandomNormal() const {
    static thread_local std::random_device rd;
    static thread_local std::mt19937 gen(rd());
    static thread_local std::normal_distribution<> d(0, 1);
    return d(gen);
}

vec2d equitySimulation::simulate()
{
    for (int i = 0; i < simNum_; ++i) {
        simulatedPaths_[i][0] = initVal_;
        for (int t = 1; t < timeSteps_; ++t) {
            double dt = 1.0 / timeSteps_;
            double dW = getRandomNormal() * sqrt(dt);
            int nowTime = t - 1;
            simulatedPaths_[i][t] = simulatedPaths_[i][nowTime] * exp((rf_ - div_ - 0.5 * sigma_ * sigma_) * dt + sigma_ * dW);
        }
    }

    return simulatedPaths_;
}

void equitySimulation::printSimulationResults() const {

    std::cout << std::fixed << std::setprecision(2);

    // Print each simulation path
    for (int i = 0; i < simNum_; ++i) {
        for (int t = 0; t < timeSteps_; ++t) {
            std::cout << std::setw(10) << simulatedPaths_[i][t];
        }
        std::cout << std::endl;
    }
    
}
