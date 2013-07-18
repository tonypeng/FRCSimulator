using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace RobotLib
{
	public class Interop
	{
        [DllImport("TestRobot.dll", EntryPoint="InteropTest")]
        public static extern void InteropTest();

        [DllImport("TestRobot.dll", EntryPoint = "FRC_UserProgram_StartupLibraryInit")]
        public static extern void RobotMain();
	}
}
