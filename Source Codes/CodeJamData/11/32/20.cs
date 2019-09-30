using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{

    class Program
    {
        class Star : IComparable<Star>
        {
            public long index;
            public long savedTime;
            public Star(long i, long t) { index = i; savedTime = t; }

            #region IComparable<Star> Members

            public int CompareTo(Star other)
            {
                return -savedTime.CompareTo(other.savedTime);
            }

            #endregion
        }

        static void Main(string[] args)
        {

            FileStream output = new FileStream("output.txt", FileMode.Create, FileAccess.Write);
            StreamWriter sw = new StreamWriter(output);

            FileStream input = new FileStream("input.txt", FileMode.Open, FileAccess.Read);
            StreamReader sr = new StreamReader(input);


            int nTestCases = int.Parse(sr.ReadLine());

            for (int t = 1; t <= nTestCases; t++)
            {

                string line = sr.ReadLine();

                string[] splitted = line.Split();
                long L = long.Parse(splitted[0]);
                long T = long.Parse(splitted[1]);
                long N = long.Parse(splitted[2]);
                long C = long.Parse(splitted[3]);
                long[] a = new long[C];
                
                for (int i = 0; i < C; i++)
                {
                    a[i] = int.Parse(splitted[4 + i]);
                }

                long accTime = 0;
                long[] starsTimes = new long[N];
                Star[] sortedStars = new Star[N];
                for (int i = 0; i < N; i++)
                {
                    long starDist = a[i % a.Length];
                    long starTime = starDist * 2;
                    starsTimes[i] = starTime;
                    
                    if (accTime > T)
                    {
                        sortedStars[i] = new Star(i, starDist);
                    }
                    else if(accTime + starTime > T)
                    {
                        long diffTime = accTime + starTime - T;
                        long savedTime = starTime - ((starDist * 2 - diffTime) + diffTime / 2);
                        sortedStars[i] = new Star(i, savedTime);
                    }
                    else
                    {
                        sortedStars[i] = new Star(i, 0);
                    }
                    accTime += starTime;
                }
                Array.Sort(sortedStars);
                Dictionary<long, long> savedTimes = new Dictionary<long, long>();
                for (int i = 0; i < L; i++)
                {
                    savedTimes.Add(sortedStars[i].index, sortedStars[i].savedTime);
                }

                long ret = 0;
                for (int i = 0; i < N; i++)
                {
                    ret += starsTimes[i];
                    if (savedTimes.ContainsKey(i)) ret -= savedTimes[i];
                }



                sw.WriteLine("Case #" + t.ToString() + ": " + ret);
                sw.Flush();
            }



        }
    }
}
