# Arduino Bluetooth Car Project

This README provides an overview of the Arduino Bluetooth Car project, which involves building a remote-controlled car using an Arduino board and a Bluetooth module. The car can be controlled through a mobile app or device connected via Bluetooth, allowing it to move in different directions, play melodies, and even avoid obstacles using an ultrasonic sensor.


## Project Overview

The Arduino Bluetooth Car project is a fun and educational project that combines various hardware components to create a remote-controlled car. The key features of this project include:

- **Bluetooth Control**: The car can be controlled remotely using a Bluetooth-enabled device such as a smartphone or tablet. Different commands are sent via Bluetooth to control the car's movement.

- **Ultrasonic Sensor**: An ultrasonic sensor is used to detect obstacles in front of the car. When an obstacle is detected, the car performs an avoidance maneuver to navigate around it.

- **Buzzer and Melodies**: The car is equipped with a buzzer that can play melodies. It includes a Super Mario theme melody and an alarm melody.

- **Servo Motor**: A servo motor is used to control the orientation of a sensor, which can be adjusted to different angles (0, 90, or 180 degrees).
  
![Schematichs](https://github.com/UngureanuEduard/Bluetooth-Car-Arduino/assets/130817880/62444d74-2720-462d-900f-46f21d85dce4)

## Components Used

The following components are used in this project:

- Arduino board (e.g., Arduino Uno)
- Bluetooth module
- Ultrasonic sensor (HC-SR04)
- Servo motor
- Motor driver module
- Buzzer
- DC motors (for the car's wheels)
- Chassis, wheels, and other mechanical components

## Code Overview

The code for this project is written in Arduino's C/C++-based programming language. Here's a brief overview of the code's main components:

- **Melodies**: The code defines two melodies, one for the Super Mario theme and another for an alarm melody. These melodies are played using the buzzer.

- **Bluetooth Communication**: The project uses Bluetooth communication to receive commands from a connected device. Commands are sent as single characters (e.g., 'F' for forward, 'B' for backward) and control the car's movement and other functions.

- **Ultrasonic Sensor**: The ultrasonic sensor is used to measure the distance to objects in front of the car. When an obstacle is detected, the car performs an obstacle avoidance routine.

- **Servo Motor Control**: The code controls the servo motor to adjust the orientation of a sensor. This can be used for scanning the environment or changing the direction of the ultrasonic sensor.

- **Motor Control Functions**: Various functions (e.g., `inainte`, `stanga`, `dreapta`) are defined to control the car's movement, such as moving forward, backward, left, or right.

- **Main Loop**: The `loop` function continuously reads commands from the Bluetooth module and executes corresponding actions based on the received commands.

## Setup and Usage

To set up and use this Arduino Bluetooth Car project, follow these general steps:

1. Assemble the physical components of the car, including the Arduino board, motors, chassis, wheels, Bluetooth module, ultrasonic sensor, servo motor, and buzzer.

2. Upload the provided Arduino code to your Arduino board using the Arduino IDE.

3. Pair your Bluetooth-enabled device (e.g., smartphone) with the Bluetooth module on the car.

4. Use a Bluetooth app or program to send commands to the car (e.g., 'F' to move forward, 'B' to move backward).

5. Experiment with different commands, melodies, and obstacle avoidance to control and enjoy your Arduino Bluetooth Car.

Please note that the specific connections and pin assignments may vary depending on the components and hardware you are using. Be sure to double-check and adjust the code and connections as needed for your setup.
