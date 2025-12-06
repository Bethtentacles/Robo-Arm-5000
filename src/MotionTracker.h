#ifndef MOTIONTRACKER_H
#define MOTIONTRACKER_H

#include <Arduino.h>

// Forward declarations
class Drive;
class Grabber;
class ElectroMagnet;


struct MovementStep {
  unsigned long time_stamp;      
  int joint_angles[4];         
  bool grabber_active;         
  bool magnet_active;          
};

class MotionTracker {
  private:
    static const int MAX_STEPS = 500;  
    MovementStep steps[MAX_STEPS];     
    int step_count;                    
    bool m_is_recording;                 
    unsigned long recording_start_time; 
    
    // Pointers to the robot components (set during begin())
    Drive* drives[4];                  
    Grabber* grabber;                  
    ElectroMagnet* magnet;             

  public:
    MotionTracker();
    
    // Initialize with pointers to robot components
    void begin(Drive* base, Drive* bottom, Drive* middle, Drive* top, 
               Grabber* grab, ElectroMagnet* mag);
    
    // Recording controls
    void start_recording();
    void stop_recording();
    void clear_recording();
    bool is_recording() const;
    
    // record current position
    void captureStep();
    
    // Playback controls
    void play_sequence(bool loop = false);
    void play_sequence_reverse();
    void return_to_origin();  

    // Utility
    int getStepCount() const;
    bool isFull() const;
    void printRecording() const; 
};

#endif