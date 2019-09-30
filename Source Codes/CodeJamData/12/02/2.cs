using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string filename = "B-large";
            //string filename = "B-small-attempt0";
            //string filename = "test";

            string[] inLine = File.ReadAllLines(filename + ".in");
            int T = Convert.ToInt32(inLine[0]);
            string[] outLine = new String[T];

            for (int t = 1; t <= T; t++)
            {
                int result = 0;
                string[] tmp = inLine[t].Split(' ');
                int N = Convert.ToInt32(tmp[0]);
                int S = Convert.ToInt32(tmp[1]);
                int p = Convert.ToInt32(tmp[2]);
                //int[] ti = new int[N];
                for (int n = 0; n < N; n++)
                {
                    //ti[n] = Convert.ToInt32(tmp[3 + n]);
                    int ti = Convert.ToInt32(tmp[3 + n]);
                    if( ti >= p+ 2* Math.Max(0,p-1)){
                        result++;
                    }else if( ti >= p+ 2*Math.Max(0,p-2)){
                        if (S > 0)
                        {
                            result++;
                            S--;
                        }
                    }


                }



                outLine[t - 1] = "Case #" + t.ToString() + ": " + result.ToString();
            }

            File.WriteAllLines(filename + ".out", outLine);
            
        }
    }
}
