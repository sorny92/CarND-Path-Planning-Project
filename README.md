# CarND-Path-Planning-Project
Self-Driving Car Engineer Nanodegree Program
   
### Simulator.
You can download the Term3 Simulator which contains the Path Planning Project from the [releases tab (https://github.com/udacity/self-driving-car-sim/releases).

### Goals
In this project your goal is to safely navigate around a virtual highway with other traffic that is driving +-10 MPH of the 50 MPH speed limit. You will be provided the car's localization and sensor fusion data, there is also a sparse map list of waypoints around the highway. The car should try to go as close as possible to the 50 MPH speed limit, which means passing slower traffic when possible, note that other cars will try to change lanes too. The car should avoid hitting other cars at all cost as well as driving inside of the marked road lanes at all times, unless going from one lane to another. The car should be able to make one complete loop around the 6946m highway. Since the car is trying to go 50 MPH, it should take a little over 5 minutes to complete 1 loop. Also the car should not experience total acceleration over 10 m/s^2 and jerk that is greater than 10 m/s^3.

### Project rubric
1. **The code compiles correctly.**  
Doing cd to build folder and executing make once you have all the dependiencies solved will compile the program.
2. **The car is able to drive at least 4.32 miles without incident.**  
The car is able to drive at least 4.32 miles in the circuit. In one of the test it was able to get around 80 miles without accidents.  
One of the things I observed it is that other cars change lines randomly so there wasn't an easy way to avoid accidents without assuming a big acceleration.
3. **The car drives according to the speed limit.**  
It's maximum speed is attached to 49.5mph so it never reaches a higher speed.
4. **Max Acceleration and Jerk are not Exceeded.**

5. **Car does not have collisions.**  
As I mention in the point 2, the car is able to drive safetely but the problem comes with the random behaviour of the other cars that decide to change lane even when you are in the side of that car then creating an accident. Although this happens every several hours.
6. **The car stays in its lane, except for the time between changing lanes.**  
The car, to attach to european laws, try to stay in the lane in the right always that it doesn't have to pass a car. This point goes a bit against the rubic point but it does make sense for European laws.
7. **The car is able to change lanes.**  
When it detects a car less than 30 meters ahead and it has enough space in the left lane it pass the car it has in front of it. Then to come back to the lane in the right as long there is enough distance with the car behind.

#### Model documentation  
The algorith that generate paths is quite straight forward, mainly based on the Q&A walkthrough.  
First of all the algorithm try to stay always that is possible in the right lane of the road. This is due because in spanish road you should go in the right lane always that is possible so you don't block cars tha goes faster than you.  

When there is a car less than 30 meters ahead it will try to pass it. To do so, it will check the left lane is available to pass. The conditions to state the lane is available is that there is no car in the left lane 30 meter ahead or 20 meters behind. If this condition is not satisfied, the car will slowdown based on the distance to the car ahead and the difference of speed, then set to the same speed as the car ahead.
Once the lane is available it will pass the car.  
Always there is no car in the right lane and it's not the right lane, it will try to change lane to that one so it complies with the first working condition.


## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./path_planning`.



## Dependencies

* cmake >= 3.5
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `install-mac.sh` or `install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!


## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).

