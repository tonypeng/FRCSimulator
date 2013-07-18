using System;

namespace FRCSimulator
{
#if WINDOWS || XBOX
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        static void Main(string[] args)
        {
            new FakeDriverstation().Show();

            RobotLib.Interop.InteropTest();

            Console.WriteLine();

            RobotLib.Interop.RobotMain();

            using (Simulator game = new Simulator())
            {
                game.Run();
            }
        }
    }
#endif
}

