# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## PID Param Selcection
1. I chose a ramdom value which P I D equal [0.5,0.5,0.0005]
2. I achieved a twiddle in PID class and let it output the result and CTE(the detail in PID::twiddle() line 59)
3. I start run the car ,and before the car away from the road,I select the PID when the cte is best
4. I input the new pid param into the param, and repeat the 2 ,3 ,4 step until the car could always run in the road smoothly.
### for real 
 in my statuion:
+ I set P I D equal 0,0,0;
+ the first time I got PID is 0.11 0.11 0.0 and the best_err is 0.400429. 
+ and the system is failed so I set PID 0.11 0 0
+ I got PID is 0.231 0 0 
+ when the i is 0.11 the car run out of road so I set 0.231 0.0
+ I got PID is 0.3641 0.11 0 a but this time when the i is 0.11 the car run out agin so I set the Di to 0.01
+ I releaed the i is too big so I decreased the Di to 0.001 and all set to zero
+ this time I set PID is 0.231 0.00131 0

## chinese