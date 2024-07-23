#include "Simulation.h"


int main()
{
    double initVal = 100.0;
    double sigma = 0.2;
    double rf = 0.05;
    double div = 0.02;
    int timeSteps = 10;
    int simNum = 100;

    equitySimulation snp500(initVal, sigma, rf, div, timeSteps, simNum);
    vec2d simStocks = snp500.simulate();
    snp500.printSimulationResults();
}
