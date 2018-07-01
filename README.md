# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---
## PID Control 
In this project,PID is focus on reduce CTE which is cross-track error.The main control output is the steering angle.In the following discussion, mainly for the bicycle model, the output is considered to be the steering angle.
### P-Proportional

Represents the reverse steering angle, which is used to bring the system closer to expectations, ie to reduce cte. The output is p * cte . But just using the p parameter results in the model continuing to oscillate in the x-axis. The p control considers the current error.
p代表反向的转向角度，用来使系统接近预期，即减少cte。输出结果为 p * cte 。但是只是用p参数的结果是模型将会持续在x轴震荡。p控制考虑当前误差。
### I- Intergral
Consider the error in the past, add the error of a certain period of time to the system in a certain proportion. But when there are too many i parameters, there will be overshoot.

考虑过去误差，将一段时间的误差以一定比例加入到系统中。但是当i参数过多时，会出现过冲的现象。
### D-derivative
The difference between this cte and the last cte is added to the system through a certain percentage. Consider future errors. The larger the value, the faster the system will reflect on the output. It can improve the setting time and system stability.
将本次cte和上次cte的差值通过一定比例加入系统。考虑将来的误差。该值越大，系统对输出结果反映越迅速。可以提升整定时间和系统稳定性。

## PID Hyperparameter Selcection
### twiddle
my first ideas is blow(in pid.cpp line 69 - 126):
1. I chose a ramdom value which P I D equal [0.5,0.5,0.0005]
2. I achieved a twiddle in PID class and let it output the result and CTE(the detail in PID::twiddle() line 59)
3. I start run the car ,and before the car away from the road,I select the PID when the cte is best
4. I input the new pid param into the param, and repeat the 2 ,3 ,4 step until the car could always run in the road smoothly.
but in the real implementation,I found that, when I use the twiddle ,the car is easily out of the road. so I changed the idea,and manually tuning the hyperparameters.
### manual tuning
1.我首先调节P 参数 设置 i和d参数为0.
2. 增加d参数 到震荡消退。
3. 观察车驶出道路的原因，如果是因为反应过慢 增加kp 和kd ki 如果是因为震荡(过冲) 减少 kp 和 ki 

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

