#ifndef PID_H
#define PID_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

class PID {
public:

  /*
  * Initialization
  */
  bool not_initialised_ = true;
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;
  double dt;
  /*
  * Outputs
  */  
  double steerVal;
  /*
  * Useful
  */
  int numIter;
  double ctePrev;
  double cteTotErr;
  std::vector<double> cteVec;  
  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void ProcessManager(double cte);
  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd, double cte);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  void TotalError(double cte);

  //void PID::twiddle(double Kp, double Ki, double Kd);
};

#endif /* PID_H */
