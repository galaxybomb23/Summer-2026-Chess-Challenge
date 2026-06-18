# Devlog #1
The goal for this devlog it to get the inital enviroment setup. I am doing this on a flight to japan, so no internet );
## CMake
I have decided to use CMake as my build system for this project. I have some experience with CMake and think it will be a good fit for this project. I have set up a basic CMakeLists.txt file 

I use a .dependencies folder to keep deps local since i am doing this on a flight and don't have internet. 

I spent a lot of time trying to get CMake to find the dependencies I need. as well as setting up header includes and source files. I also had to figure out how to link the dependencies correctly.

# Setup

I had a lot of issues with circular declared and forgot how to handle includes in C++. 

The current setup is as follows:
- include/ - header files
- src/ - source files
- tests/ - test files

# development
i made a basic Null piece that is used for rendering the background of the board, i then copied this and updated names and added TODOs for the other pieces.
