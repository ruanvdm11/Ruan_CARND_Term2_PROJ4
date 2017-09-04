#include "PID.h"
#include <random>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <math.h> 
#include <iostream>
#include <sstream>
#include <string>
#include <iterator>


using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::ProcessManager(double cte) {
	if(not_initialised_){
		Kp = 2.5;
		Kd = 11.0;
		Ki = 0.001;
		dt = 1.0;
		numIter = 0;
		
		Init(Kp, Kd, Ki, cte);
	} else{		
		TotalError(cte);
		double propPart = (Kp*cte);
		double difPart = (Kd*(cte-ctePrev));
		double intPart = (Ki*cteTotErr);
		double steerAngle = (propPart + difPart + intPart);
		UpdateError(cte);
		steerVal = (((25-steerAngle)/(50))*(2) - 1);
	}
}

void PID::Init(double Kp, double Ki, double Kd, double cte) {

	ctePrev = 0.0;
	TotalError(cte);
	double propPart = (Kp*cte);
	double difPart = (Kd*(cte-ctePrev)/dt);
	double intPart = (Ki*cteTotErr);
	double steerAngle = -(propPart + difPart + intPart);
	steerVal = (((25-steerAngle)/(50))*(2) - 1);
	not_initialised_ = false;	
}

void PID::UpdateError(double cte) {
	ctePrev = cte;
}

void PID::TotalError(double cte) {
	cteVec.push_back(cte*dt);
	cteTotErr = std::accumulate(cteVec.begin(), cteVec.end(), 0.0);
}