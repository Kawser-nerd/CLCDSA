using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Round1C
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader input = File.OpenText(args[0]))
            {
                using (StreamWriter output = File.CreateText(args[1]))
                {
                    int testCaseCount = int.Parse(input.ReadLine());
                    for (int testCaseNum = 1; testCaseNum <= testCaseCount; testCaseNum++)
                    {
                        SpaceEmergency spaceEmergency = new SpaceEmergency(input);
                        output.WriteLine("Case #{0}: {1}", testCaseNum, spaceEmergency.Run());
                    }
                }
            }
        }
    }
}
