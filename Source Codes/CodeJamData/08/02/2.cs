using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace test.Google
{
    public class TrainTimetable
    {
        public static void Main(string[] arg)
        {
            try
            {
                using (StreamReader sr = new StreamReader(arg[0]))
                using (StreamWriter sw = new StreamWriter(arg[1]))
                {
                    int num = int.Parse(sr.ReadLine());
                    for (int i = 0; i < num; ++i)
                    {
                        int turn = int.Parse(sr.ReadLine());
                        string[] strs = sr.ReadLine().Split(' ');
                        int numA = int.Parse(strs[0]), numB = int.Parse(strs[1]);

                        int[][] timeA = new int[2][]{new int[numA], new int[numA]};
                        int[][] timeB = new int[2][]{new int[numB], new int[numB]};
                        for (int k = 0; k < numA; ++k)
                        {
                            string[] times = sr.ReadLine().Split(' ');
                            for (int j = 0; j < 2; ++j)
                            {
                                timeA[j][k] = 60 * int.Parse(times[j].Substring(0, 2)) + int.Parse(times[j].Substring(3));
                            }
                        }
                        for (int k = 0; k < numB; ++k)
                        {
                            string[] times = sr.ReadLine().Split(' ');
                            for (int j = 0; j < 2; ++j)
                            {
                                timeB[j][k] = 60 * int.Parse(times[j].Substring(0, 2)) + int.Parse(times[j].Substring(3));
                            }
                        }

                        //string input=sr.ReadLine();
                        //string output = Convert(input.Split(' '));
                        //Console.WriteLine(input + "=" + output);
                        int numa = Get(turn, timeA[0], timeB[1]);
                        int numb = Get(turn, timeB[0], timeA[1]);
                        sw.WriteLine("Case #" + (i + 1) + ": " + numa + " " + numb);
                    }
                }
            }
            catch (Exception e) { Console.WriteLine(e.Message + e.StackTrace); }
            Console.ReadKey();
        }


        public static int Get(int turn, int[] start, int[] arrive) 
        {
            for (int i = 0; i < arrive.Length; ++i) arrive[i] += turn;
            Array.Sort(start);
            Array.Sort(arrive);

            int res = start.Length;
            int pos = 0;
            for (int i = 0; i < arrive.Length && pos < start.Length; ++i)
            {
                while (pos<start.Length && start[pos] < arrive[i])pos++;

                if (pos < start.Length) { res--; pos++; }
            }

            return res;
        }
    }
}
