using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamBotTrust
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine();
            int testCount = int.Parse(s);
            for (int i = 0; i < testCount; i++)
            {
                var elements = Console.ReadLine().Split();
                int seqLength = int.Parse(elements[0]);
                int[] currentButton = { 1, 1 };
                int[] freeMoves = { 0, 0 };
                int time = 0;
                for (int step = 0; step < seqLength; step++)
                {
                    int worker = elements[step * 2 + 1] == "B" ? 0 : 1;
                    int targetButton = int.Parse(elements[step * 2 + 2]);
                    int stepTime = Math.Abs(currentButton[worker] - targetButton) - freeMoves[worker];
                    if (stepTime < 0)
                        stepTime = 0;
                    stepTime++;
                    currentButton[worker] = targetButton;
                    freeMoves[worker] = 0;
                    freeMoves[1 - worker] += stepTime;
                    time += stepTime;
                }
                Console.WriteLine("Case #{0}: {1}", i + 1, time);
            }
        }
    }
}
