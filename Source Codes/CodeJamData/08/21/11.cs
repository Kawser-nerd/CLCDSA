using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;


namespace Round1A
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream file = new FileStream("A-small-attempt0.in", FileMode.OpenOrCreate, FileAccess.Read);
            StreamReader sr = new StreamReader(file);

            FileStream file2 = new FileStream("out.txt", FileMode.Create, FileAccess.Write);
            StreamWriter sw = new StreamWriter(file2);

            String tempStr;
            Int32 numProb;

            tempStr = sr.ReadLine();
            numProb = Int32.Parse(tempStr);

            for (long i = 1; i <= numProb; i++)
            {
                long ans = FindAnswer(sr);
                sw.WriteLine("Case #" + i + ": " + ans);
            }

            sw.Close();
            sr.Close();
            file.Close();
            file2.Close();
        }

        static long FindAnswer(StreamReader sr)
        {
            char[] seps = { ' ' };
            String tempStr;
            tempStr = sr.ReadLine();

            String[] sArr = tempStr.Split(seps);
            long n,A,B,C,D,x,y,M;

            n = Int64.Parse(sArr[0]);
            A = Int64.Parse(sArr[1]);
            B = Int64.Parse(sArr[2]);
            C = Int64.Parse(sArr[3]);
            D = Int64.Parse(sArr[4]);
            x = Int64.Parse(sArr[5]);
            y = Int64.Parse(sArr[6]);
            M = Int64.Parse(sArr[7]);


            long[] xs = new long[n];
            long[] ys = new long[n];

            xs[0] = x%3;
            ys[0] = y%3;

            for (long i = 1; i < n; i++)
            {
                x = (A * x + B) % M;
                xs[i] = x;

                y = (C * y + D) % M;
                ys[i] = y;
            }

            long count=0;
            for (long i = 0; i < n; i++)
            {
                for (long j = 0; j < n; j++)
                {
                    for (long k = 0; k < n; k++)
                    {
                        if (i != j && i != k && j != k)
                        {
                            long xSum = xs[i] + xs[j] + xs[k];
                            long ySum = ys[i] + ys[j] + ys[k];

                            if (xSum % 3 == 0 && ySum % 3 == 0)
                                count++;
                        }
                    }
                }
            }

            return count/6;
        }

    }
}
