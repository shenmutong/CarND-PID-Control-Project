#include "PID.h"

using namespace std;
#include <iostream>

/*
* TODO: Complete the PID class.
*/

PID::PID() { }

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    K_array[0] = &this->Kp;
    K_array[1] = &this->Ki;
    K_array[2] = &this->Kd;
    
 
 // double Dd;
    p_error = 0;
    i_error = 0;
    d_error = 0;   

    //Dp =0.1;
    //Di = 0.0001;
    //Dd  = 1;
    Dp =1;
    Di = 1;
    Dd  = 1;
    /* this->Dp = Kp;
    this->Di = Ki;
    this->Dd = Kd; */
    D_array[0] = &this->Dp;
    D_array[1] = &this->Di;
    D_array[2] = &this->Dd;
    err =0;
    best_err = 100;
    is_twiddle_plus = false;    
}

void PID::UpdateError(double cte) {        
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
    //err = err * update_count;
    //update_count++;
    err = pow(cte ,2);   
    //err /= update_count; 
    //err = p_error;
    std::cout << "P:" << Kp   << "  I:" << Ki << "  D:"<<Kd << std::endl;
    
  //  std::cout <<"err is " << err << std::endl;   
    

}

double PID::TotalError() {
   
    return -Kp * p_error 
          - Ki * i_error 
          - Kd * d_error;
}

bool is_first_in_twiddle = true;
void PID::twiddle(double tol) {
    double d_sum = *D_array[0] + *D_array[1] + *D_array[2];
   /*  if(update_count % twiddle_count != 0){
        std::cout <<"best_err is " << best_err << std::endl;
        return;
    } */
    if(is_first_in_twiddle){
        best_err = err;
        is_first_in_twiddle = false;
        return;
    }
    if(d_sum > tol){
        std::cout << "err is "<< err << "best_err is " << best_err << std::endl;
        if(!is_twiddle_plus){           
            if(err < best_err){ 
                best_err = err;
                *D_array[K_index%3] *= 1.1;
                *K_array[K_index%3] += *D_array[K_index%3];
                //K_index++;
            }else{
                * K_array[K_index%3] -= 2 * (*D_array[K_index%3]);        
                std::cout << "else widdle plus" << std::endl;
                is_twiddle_plus = true;
                return;
                //return;
            }            
        }
        else{
            if(err < best_err){
                best_err = err;
                *D_array[K_index%3] *= 1.05;
                is_twiddle_plus = false;
                *K_array[K_index%3] += *D_array[K_index%3];

                //K_index++;
                //return;
            }
            else{
                std::cout << "else widdle" << std::endl;
                *K_array[K_index%3] += *D_array[K_index%3];               
              
                //* K_array[K_index%3] += *D_array[K_index%3];      
                *D_array[K_index%3] *= 0.95;          
                //K_index++;
                is_twiddle_plus = false;
                *K_array[K_index%3] += *D_array[K_index%3];
                //K_index++;

            }
        }                 

        K_index++;              
           
    }
    
    std::cout << "array is "<< K_index %3 << "value is " << *K_array[K_index%3] << std::endl;
  //std::cout << "CTE: " << *D_array[K_index%3]   << " Steering Value: " << K_index << std::endl;

}


