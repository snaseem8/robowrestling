# RoboWrestling - Georgia Tech

RoboWrestling is an autonomous robot competition organized by the RoboJackets, Georgia Tech's robotics team. The goal is to design and develop a robot capable of participating in sumo-style wrestling matches. Our robots autonomously detect and navigate their opponents, utilizing sensors and actuators to push them out of the ring while maintaining stability and following the rules of the competition.

## Project Overview

This repository contains the codebase for the RoboWrestling robot. The primary objective is to build an autonomous robot that can compete in sumo-style wrestling, where it must:
- Detect opponents using sensors (e.g., IR and line sensors).
- Navigate the competition ring.
- Execute strategies to push the opponent out of the ring.
- Ensure robust control and stability through various movement commands.

## Features

- **Robot Control:** Uses motor drivers to control the movement of the robot (forward, backward, turns).
- **Sensor Integration:** IR and line sensors are used for obstacle detection, tracking, and edge detection.
- **AI/Strategy:** Implements different strategies like `StayOn` to maintain positioning, and `Attack` for offensive maneuvers.
- **Simulation:** The robot's movement and behavior are designed with real-world application in mind, utilizing sensor data for decisions.

## Key Components

- **RobotAction:** Controls robot movement (e.g., forward, reverse, spin, turn).
- **WorldState:** Represents the robot's environment, including sensor data from line sensors and IR sensors.
- **RobotState:** Determines the robot's current state and interacts with the `StayOn` and `Attack` strategies to decide what action to take.
- **StayOn:** Strategy to ensure the robot stays within the ring and avoids getting pushed out.
- **Attack:** Strategy to push opponents out of the ring based on sensor input.

## Hardware

The robot relies on the following hardware components:

- **Motors & Motor Drivers:** Control movement in various directions (left/right, forward/backward).
- **IR Sensors:** Used for detecting edges and enemies.
- **Line Sensors:** Used for detecting the edges of the ring and helping the robot stay within bounds.
- **Chassis:** The robot's chassis is 3D printed, providing a lightweight yet sturdy structure that is customized for the components and sensors.
- **Custom PCB:** A custom-designed printed circuit board (PCB) integrates all the robot's electrical components, including motor drivers, sensors, and control systems, into a single compact solution.
- **Microcontroller:** The RoboWrestling robot uses an **Arduino-compatible microcontroller** to handle the robot's logic, sensor readings, and motor control. This platform is responsible for controlling the robot's behavior based on sensor input and executing the necessary actions according to the strategies defined in the code.
