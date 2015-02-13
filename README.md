3D-scanner

13 February 2015
-Done-

	GCode-like interpreter DONE for Arduino. The code AND the readme are in /scanner_bed
	Finalizing QT program config, as Arduino code is done.

-Working on now-

	Working with QT and OpenGL for 3d rendering of said pointcloud. OpenGL confuses me. More learning experience.
	Makefile still borked. 


==========
29 October 2014

-Done-
	
	Calibration is nearing completion!
	Camera calibration is now applied across all relevant screens.
	Ellipse detection has low error.
	More settings added appropriately to override my detected answers. We don't want the computer to be too smart...

-Working on now-
	
	Makefile is broken, badly. Was brought to my atention. Will collaborate to fix quick.
	Determining how to do accurate line detection. I have a few methods. 
	Thinking how to present scanner GUI for users.
	Re-writing Arduino to work better and more GCode-like. Will work with QT program to make ideal config.
	Simplyifying GUI so it works on little configuration, and catches errors. Easier for end-user, the better.




29 September 2014

QT program nearly functional for scanning!
What is done?

	GUI done.	
	Basic configuration.
	Camera lens calibration!
	
In the works (actively)?

	Laser line detection
	Ellipse detection (Yes, both of these will auto-calibrate the camera)
	Scanner.
	Algo's to increase accuracy and pointcloud generation.

Slightly future Goals?

	Implementation of PointCloud Library.
	Implement more than flat text file for data saving. Looking at .OBJ



Previously...

Cheap 3D scanner based on Arduino and Processing

I used the base project seen on http://www.instructables.com/id/Lets-cook-3D-scanner-based-on-Arduino-and-Proces/?&sort=ACTIVE&limit=40&offset=40#DISCUSS

If you want to use these programs, you will need the Arduino IDE (for compiling and uploading), and an Arduino Uno compatible devel board for the hardware.
For the Processing program, you will need the Arduino up and running to execute the 3d-scanner. I set up the line_processor as a stand-alone. Just dump the sample images with the program and run it in Processing. It doesnt display content, but it does generate line drawings for each image, and generates a pointcloud file that MeshLab can read.

Changes 4 August 2014:

	Scrapped Java for QT5, C++ and OpenCV.
	GUI mostly complete.
	Multiple video sources will not open concurrently, yet...
	Working on Calibration now.
	Alpha code for handling Android running IP Webcam

Changes 28 July 2014:

     Still learning Java - Now have GUI and basic webcam viewing set up.
     Looking at changing my Line and scanner sketch to display 3d point data instead. 


Changes 20 July 2014:

     Correct math for angled camera placement - Mostly correct
     Found better camera than my Sony PS2 Eyetoy. I was gifted a Logitech HD webcam!
     More sample data in /3D-scanner/sample_images/

Todo:

     Better project box enclosure
     Implementation of 2 line lasers I bought for $2.50 each on ebay
     Use Makerbot Digitizer technique of dual line lasers at x degrees from camera and -x degrees from camera and do a dual sweep.
     Make Processing programs Usable.
     Include circuit diagrams, per user's requests.
     Figure out technique to include color data with depth data
     Currently looking in Java for multiplatform and nice GUI options
     Implement a GCode-like system for the 3D scanner arduino hardware ~ looking at Fabscan arduino code..


______________________________________________________________________
Initial Changes:



Changes:

     Cleaned up variable names
     Configured my stepper.
     Set up a ping/pong system so the Processing program knows when a step increment is done. We do this for non-jerky pictures.
     Created a separate Processing program to handle image->pointcloud handling. This sped up dev time.
     Added a variable to account for vertical placement of camera. Original project assumes a 0 degree inclination respect to platter. Mine is at an angle.

Todo:

     Correct math for angled camera placement
     Better project box enclosure
     Implementation of 2 line lasers I bought for $2.50 each on ebay
     Find better camera than my Sony PS2 Eyetoy.
     Use Makerbot Digitizer technique of dual line lasers at x degrees from camera and -x degrees from camera and do a dual sweep.
     Make Processing programs Usable.

Pie in the sky Todo:

     Camera calibration code, including lens calibration
     Possibly implement 2 cameras, with one at 0deg and other at 45deg.
     Laser calibration code
     Table Calibration code
     Use PCL library to output pointcloud OR STL
