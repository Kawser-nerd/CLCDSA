using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    class CruiseControl
    {
        public static double Solve(TextReader reader)
        {
            int[] targetHorseCount = PonyExpress.ReadIntArray(reader);
            int target = targetHorseCount[0];
            int horseCount = targetHorseCount[1];
            double worstTime = 0;
            for(int i = 0; i < horseCount; i++) {
                Horse horse = Horse.Read(reader);
                double time = (target - horse.Position) / horse.Speed;
                worstTime = Math.Max(worstTime, time);
            }
            return target / worstTime;
        }

        struct Horse
        {
            public double Speed;
            public double Position;

            internal static Horse Read(TextReader reader)
            {
                int[] positionSpeed = PonyExpress.ReadIntArray(reader);
                return new Horse {
                    Speed = positionSpeed[1],
                    Position = positionSpeed[0],
                };
            }
        }
    }
}
