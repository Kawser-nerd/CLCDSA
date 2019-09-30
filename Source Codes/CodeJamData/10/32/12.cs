using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ10_R1C_02_01
{
    class Program
    {
        static void Main(string[] args)
        {
            string dir = @"C:\Projects\GCJ10\R1C\02\";

            using(StreamReader sr = new StreamReader(dir + "input.in"))
            {
                string readstr;
                readstr = sr.ReadLine();

                int TestCases = int.Parse(readstr);

                using (StreamWriter sw = new StreamWriter(dir + "output.out"))
                {
                    for (int testCnt = 0; testCnt < TestCases; testCnt++)
                    {
                        int L, P, C;
                        string[] nums;
                        readstr = sr.ReadLine();
                        nums = readstr.Split(' ');

                        L = int.Parse(nums[0]);
                        P = int.Parse(nums[1]);
                        C = int.Parse(nums[2]);

                        double step1 = Math.Ceiling(Math.Log( ((double)P)/L, C));
                        double step2 = Math.Ceiling(Math.Log(step1, 2));

                        sw.WriteLine("Case #{0}: {1}", testCnt + 1, step2);
                    }
                }
            }
        }
    }
}
