using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;



namespace CodeJam
{
    class Problem2
    {
        private const string INPUT_FILE = "A-small-attempt0.in";
        private const string OUTPUT_FILE = "A-small-attempt0.out";


        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines(INPUT_FILE);
            var output = new List<string>();
            int caseCounter = 0;
            for (int i = 1; i < input.Length; i++)
            {
                output.Add("Case #" + ++caseCounter + ": " + Execute(input[i]));
                Console.WriteLine(caseCounter);
            }
            File.WriteAllLines(OUTPUT_FILE, output);
        }

        private static string Execute(string p)
        {
            long startRadius = Convert.ToInt64(p.Split()[0]);
            long totalPaint = Convert.ToInt64(p.Split()[1]);
            
            double paintUsed = 0;
            long blackRings = 0;

            long positionOfWhiteCircle = startRadius;

            while (true)
            {
                double areaOfSingleBlackLine = (Math.Pow(positionOfWhiteCircle + 1, 2) - Math.Pow(positionOfWhiteCircle, 2));
                //long areaOfSingleBlackLine = positionOfWhiteCircle * 4 - 1;
                paintUsed += areaOfSingleBlackLine;
                if (paintUsed <= totalPaint)
                {
                    blackRings++;
                    positionOfWhiteCircle += 2;
                }
                else
                {
                    break;
                }
            }

            return blackRings.ToString();
        }
    }
}
