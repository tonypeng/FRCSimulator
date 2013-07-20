FRC-Simulator
=============

FRC Robot Simulator is a Windows application that simulates your robot code and displays it as an XNA game!

The code uses the Win32 API, .NET ,and XNA technology, and uses a Win32 (Windows) port of WPILib for the code dependencies. You shouldn't have to change any code (if you do, just slap on a simple #define SIMULATION); just build a Win32 DLL with your existing robot code, then hook it up to the main simulator!

The Windows port of WPILib doesn't have to be used with this simulator, use it with any program! The functions should be the exact same as the actual WPILib.
Although targeted for FRC simulation, it may be able to be used for any WPILib projects.
