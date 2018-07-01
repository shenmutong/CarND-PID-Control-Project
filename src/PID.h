#ifndef PID_H
#define PID_H
#include <math.h>
class PID {
public:
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

  /*
  * Coefficients
  */ 
  double Dp;
  double Di;
  double Dd;

  double err; 
  double best_err;
  bool is_twiddle_plus;
  
  double* K_array[3];
  int K_index =0;
  double* D_array[3];
  int update_count =0;
  int twiddle_count = 300;
  
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
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  /*
  * Twiddle for calculate best P I D params.
  */
  void twiddle(double tol);
};

#endif /* PID_H */
