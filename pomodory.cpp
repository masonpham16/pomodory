#include <iostream>
#include <chrono>   // For time functions
#include <thread>   // For sleep

using namespace std;
using namespace std::chrono;

// Function to display the timer
void startTimer(int minutes) {
    for (int i = minutes; i > 0; i--) {
        for (int j = 59; j >= 0; j--) {
            cout << "\rTime left: " << i - 1 << " minutes and " << j << " seconds." << flush;
            this_thread::sleep_for(seconds(1));  // Sleep for 1 second
        }
    }
    cout << "\nTime's up!\n";
}

int main() {
    int workDuration = 25;   // 25 minutes for work
    int breakDuration = 5;   // 5 minutes for break
    int numPomodoros = 4;    // Number of Pomodoros (optional, can be adjusted)

    cout << "Starting Pomodoro Timer\n";
    
    for (int i = 1; i <= numPomodoros; i++) {
        cout << "Pomodoro #" << i << " - Work for " << workDuration << " minutes.\n";
        startTimer(workDuration);

        if (i < numPomodoros) {
            cout << "Break for " << breakDuration << " minutes.\n";
            startTimer(breakDuration);
        } else {
            cout << "Pomodoro session completed!\n";
        }
    }

    return 0;
}
