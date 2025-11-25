// #include "MotionTracker.h"
// #include "Drive.h"
// #include "Grabber.h"
// #include "ElectroMagnet.h"

// MotionTracker::MotionTracker() {
//   step_count = 0;
//   m_is_recording = false;
//   recording_start_time = 0;
//   for(int i = 0; i < 4; i++) {
//     drives[i] = nullptr;
//   }
//   grabber = nullptr;
//   magnet = nullptr;
// }

// void MotionTracker::begin(Drive* base, Drive* bottom, Drive* middle, Drive* top, 
//                           Grabber* grab, ElectroMagnet* mag) {
//   drives[0] = base;
//   drives[1] = bottom;
//   drives[2] = middle;
//   drives[3] = top;
//   grabber = grab;
//   magnet = mag;
// }

// void MotionTracker::start_recording() {
//   clear_recording();
//   m_is_recording = true;
//   recording_start_time = millis();
// }

// void MotionTracker::stop_recording() {
//   m_is_recording = false;
// }

// void MotionTracker::clear_recording() {
//   step_count = 0;
//   recording_start_time = 0;
// }

// bool MotionTracker::is_recording() const {
//   return m_is_recording;
// }

// void MotionTracker::captureStep() {
//   if (!m_is_recording || step_count >= MAX_STEPS) {
//     return;
//   }
  
//   MovementStep& step = steps[step_count];
//   step.time_stamp = millis() - recording_start_time;
  
//   for(int i = 0; i < 4; i++) {
//     if(drives[i] != nullptr) {
//       step.joint_angles[i] = drives[i]->servo.getAngle();
//     }
//   }
  
//   if(grabber != nullptr) {
//     step.grabber_active = grabber->is_engaged();
//   }
  
//   if(magnet != nullptr) {
//     step.magnet_active = false;  // ElectroMagnet doesn't track state, assume off
//   }
  
//   step_count++;
// }

// void MotionTracker::play_sequence(bool loop) {
//   do {
//     for(int i = 0; i < step_count; i++) {
//       MovementStep& step = steps[i];
      
//       for(int j = 0; j < 4; j++) {
//         if(drives[j] != nullptr) {
//           drives[j]->servo.write(step.joint_angles[j]);
//         }
//       }
      
//       if(grabber != nullptr) {
//         if(step.grabber_active) {
//           grabber->engage();
//         } else {
//           grabber->disengage();
//         }
//       }
      
//       if(magnet != nullptr) {
//         if(step.magnet_active) {
//           magnet->engage();
//         } else {
//           magnet->disengage();
//         }
//       }
      
//       if(i < step_count - 1) {
//         unsigned long delay_time = steps[i + 1].time_stamp - step.time_stamp;
//         delay(delay_time);
//       }
//     }
//   } while(loop);
// }

// void MotionTracker::play_sequence_reverse() {
//   for(int i = step_count - 1; i >= 0; i--) {
//     MovementStep& step = steps[i];
    
//     for(int j = 0; j < 4; j++) {
//       if(drives[j] != nullptr) {
//         drives[j]->servo.write(step.joint_angles[j]);
//       }
//     }
    
//     if(grabber != nullptr) {
//       if(step.grabber_active) {
//         grabber->engage();
//       } else {
//         grabber->disengage();
//       }
//     }
    
//     if(magnet != nullptr) {
//       if(step.magnet_active) {
//         magnet->engage();
//       } else {
//         magnet->disengage();
//       }
//     }
    
//     if(i > 0) {
//       unsigned long delay_time = step.time_stamp - steps[i - 1].time_stamp;
//       delay(delay_time);
//     }
//   }
// }

// void MotionTracker::return_to_origin() {
//   if(step_count > 0) {
//     MovementStep& step = steps[0];
    
//     for(int j = 0; j < 4; j++) {
//       if(drives[j] != nullptr) {
//         drives[j]->servo.write(step.joint_angles[j]);
//       }
//     }
    
//     if(grabber != nullptr) {
//       if(step.grabber_active) {
//         grabber->engage();
//       } else {
//         grabber->disengage();
//       }
//     }
    
//     if(magnet != nullptr) {
//       if(step.magnet_active) {
//         magnet->engage();
//       } else {
//         magnet->disengage();
//       }
//     }
//   }
// }

// int MotionTracker::getStepCount() const {
//   return step_count;
// }

// bool MotionTracker::isFull() const {
//   return step_count >= MAX_STEPS;
// }

// void MotionTracker::printRecording() const {
//   Serial.print("Recording: ");
//   Serial.print(step_count);
//   Serial.println(" steps");
  
//   for(int i = 0; i < step_count; i++) {
//     Serial.print("Step ");
//     Serial.print(i);
//     Serial.print(" @ ");
//     Serial.print(steps[i].time_stamp);
//     Serial.print("ms: [");
//     for(int j = 0; j < 4; j++) {
//       Serial.print(steps[i].joint_angles[j]);
//       if(j < 3) Serial.print(", ");
//     }
//     Serial.print("] G:");
//     Serial.print(steps[i].grabber_active);
//     Serial.print(" M:");
//     Serial.println(steps[i].magnet_active);
//   }
// }
