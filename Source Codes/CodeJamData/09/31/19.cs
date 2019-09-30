using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam2009
{
    public class Problem1CA
    {
        public Problem1CA(String inputFile, String outputFile)
        {
            StreamReader sr = new StreamReader(inputFile);
            StreamWriter sw = new StreamWriter(outputFile);

            int totalCases = int.Parse(sr.ReadLine());
            for (int i = 0; i < totalCases; i++)
            {
                string number = sr.ReadLine();

                SortedList<char, Int64> CharMap = new SortedList<char, Int64>();
                CharMap[number[0]] = 1;
                int min = 0;
                for (int j = 1; j < number.Length; j++)
                {
                    if (!CharMap.ContainsKey(number[j]))
                    {
                        CharMap[number[j]] = min;
                        if (min == 0)
                            min = 2;
                        else
                            min++;
                    }
                }

                //Now convert the number to seconds...
                Int64 total = 0;
                for (int j = 0; j < number.Length; j++)
                {
                    total += this.pow(Math.Max((Int64)CharMap.Count(), 2), j) * CharMap[number[number.Length - 1 - j]];
                }

                sw.WriteLine("Case #" + (i+1).ToString() + ": " + total.ToString());
            }
            sr.Close();
            sw.Flush();
            sw.Close();
        }

        private Int64 pow(Int64 baseVal, Int64 powerVal)
        {
            if (powerVal == 0)
                return 1;
            else if (powerVal == 1)
                return baseVal;
            else if (powerVal % 2 == 0)
                return this.pow(baseVal * baseVal, powerVal / 2);
            else
                return this.pow(baseVal, powerVal - 1) * baseVal;
        }
    }
}
