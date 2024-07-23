#pragma once
#include <vector>
#include <iostream>
#include <random>
#include <iomanip>

typedef std::vector<std::vector<double>> vec2d;
typedef std::vector<double> vec1d;


class equitySimulation
{
public:
	equitySimulation(const double& initVal, const double& sigma, const double& rf, 
					 const double& div, const int& timeSteps, const int& simNum) :
					 initVal_(initVal), sigma_(sigma), rf_(rf), div_(div), timeSteps_(timeSteps), 
					 simNum_(simNum), simulatedPaths_(simNum, vec1d(timeSteps+1)) {}

	vec2d simulate();
	void printSimulationResults() const;

private:
	const double initVal_, sigma_, rf_, div_;
	const int timeSteps_, simNum_;
	vec2d simulatedPaths_;
	double getRandomNormal() const;
};

