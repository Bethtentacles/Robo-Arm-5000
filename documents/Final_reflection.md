This is a desktop robotic Arm project programmed in C++.\

The Kinematics, tool, and motion recording have all been implemented with verying degrees of functioning. Pre motion recording, both the Kinematics
and tool function well before motion recording was implemented but not currently. I haven't visited it in the passed week and update 3 was the last
major change to the arm.

I think the bones, are there. If i can refind it to work well I think i can make alot of use for it in driving other projects.

-------------------

Motion control with a joystick hasn't been impemented yet. It would be pretty involved to implement. I'd like to learn revers kinematics and
the vector math behind it but thats gonna have to wait for another time.

it currently doesnt work, I might of burnted out the I2C port on my teensy, but before that I wasn't able to get motion recording working. I
might be overwhelmed at the moment and taking a break to rethink my approach might be the healthiest action to take right now.

Getting motion recording to work would be a huge win. I can do alot of awesome costume and art projects using this firmware pretty much unmodified
if I can get that to work. Joystick support is less important, but with revers kinenatics working, I can also just treat it as a normal CNC machine
and send it g-code to move around. but finished wound be motion recording.

| Remaining Item    | Time Estimate |  Priority  |
|-------------------|---------------|------------|
| revers kinematics | 20-30 hours   |Nice-to-have|

------------------

I have no prior experiance in C++ and limited but functional knowledge of programming. essentially everything in the class was new to me. Encapsulation
is probably one of more critical things I've learned in this class along with class inheratence and constructors. This project really help me understand
pointers and is absolutely crucial for the project to function.

Troubleshooting was probably the hardest part. More on the tail end then in the beginning. Initially things went pretty smoothly, getting one motor to 
work just solely though analog pins and sending signals though digital pins then intergrating multible motors and moving to I2C was more challenging.
The entire motion recording portion has be fustrating at best, but if I got it working on a single motor, it won't be long till i get the rest working.
Hopefully.

Im pretty proud of the whole project. I don't think it's to complex  and abunch of people have made simular projects but things wen't much smoother then
I expected. I also like the over all look of the project, its alot less janky looking then most small desktop arms.

I hand no prior knowledge of data structures before this class. so the change is pretty dramatic. None to some is a infinite amount of improvement.
Understanding use cases for the different data structures, what to use when, is something I'm not 100% sure of but the class has giving me a strong
starting point in figuring that out. Over time things will probably get more apparent as I run in to those use cases.

Planning and design ~8 hours
Implementation ~20 hours
Testing and debugging ~60++ hours
Documentation ~4 hours
Total hours ~100 hours