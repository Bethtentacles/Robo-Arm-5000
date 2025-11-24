#ifndef MOTIONTRACKER_H
#define MOTIONTRACKER_H

#include <Arduino.h>

// Forward declaration to avoid circular dependency
class Drive;
class Grabber;
class ElectroMagnet;

// Structure to hold a single movement snapshot
struct MovementStep {
  unsigned long timestamp;      // Time since recording started (ms)
  int joint_angles[4];         // Angles for base, bottom, middle, top
  bool grabber_active;         // Grabber state
  bool magnet_active;          // Magnet state
};

class MotionTracker {
  private:
    static const int MAX_STEPS = 500;  // Maximum recording capacity
    MovementStep steps[MAX_STEPS];     // Array to store recorded steps
    int step_count;                    // Number of recorded steps
    bool is_recording;                 // Recording state flag
    unsigned long recording_start_time; // When recording started
    
    // Pointers to the robot components (set during begin())
    Drive* drives[4];                  // Pointers to 4 Drive instances
    Grabber* grabber;                  // Pointer to Grabber
    ElectroMagnet* magnet;             // Pointer to ElectroMagnet

  public:
    MotionTracker();
    
    // Initialize with pointers to robot components
    void begin(Drive* base, Drive* bottom, Drive* middle, Drive* top, 
               Grabber* grab, ElectroMagnet* mag);
    
    // Recording controls
    void startRecording();
    void stopRecording();
    void clearRecording();
    bool isRecording() const;
    
    // Capture current state (call this repeatedly during recording)
    void captureStep();
    
    // Playback controls
    void playSequence(bool loop = false);
    void playSequenceReverse();
    void returnToOrigin();  // Return to first recorded position
    
    // Utility
    int getStepCount() const;
    bool isFull() const;
    void printRecording() const;  // Debug output to Serial
};

#endif