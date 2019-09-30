using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace ProperShuffle
{
    class Result
    {
        public int index;
        public double centreOfMass;
        public bool isGood;
    }

    class Program
    {
        static void Swap<T>(ref T t1, ref T t2)
        {
            T temp = t1;
            t1 = t2;
            t2 = temp;
        }

        static long ConvertVectorToNum(List<int> l, int base_)
        {
            long num = 0;
            foreach (int d in l)
            {
                num *= base_;
                num += d;
            }

            return num;
        }

        static int[] GoodPerm(int N, Random r)
        {
            int[] l = new int[N];
            for (int i = 0; i < N; i++)
            {
                l[i] = i;
            }

            for (int i = 0; i < N; i++)
            {
                int p = r.Next(i, N);
                Swap(ref l[i], ref l[p]);
            }

            return l;
        }

        static int[] BadPerm(int N,Random r)
        {
            int[] l = new int[N];
            for (int i = 0; i < N; i++)
            {
                l[i] = i;
            }

            for (int i = 0; i < N; i++)
            {
                int p = r.Next(0, N);
                Swap(ref l[i], ref l[p]);
            }

            return l;
        }

        static void ShuffleTest()
        {
            Random r = new Random();
            int N = 10;
            Dictionary<long, long> freq = new Dictionary<long,long>();
            int numTests = 100000;

            double[] position = new double[N];
            double centreOfMass = 0;

            for (int it = 0; it < numTests; it++)
            {
                int[] l = new int[N];
                for (int i = 0; i < N; i++)
                {
                    l[i] = i;
                }

                for (int i = 0; i < N; i++)
                {
                    int p = r.Next(0, N);
                    Swap(ref l[i], ref l[p]);
                }

                for (int i = 0; i < N; i++)
                {
                    position[l[i]] += i;
                    centreOfMass += (double)(l[i] * i);
                }

                long output = ConvertVectorToNum(new List<int>(l), 10);

                if (freq.ContainsKey(output) == false)
                {
                    freq[output] = 0;
                }
                freq[output]++;
            }

            for (int i = 0; i < N; i++)
            {
                position[i] /= (double)numTests;
            }
            centreOfMass /= (double)numTests;
        }

        static double CentreOfMass(int[] l)
        {
            double centreOfMass = 0.0;

            for (int i = 0; i < l.Length; i++)
            {
                centreOfMass += (double)((long)l[i] * (long)l[i] * (long)i);
            }

            return centreOfMass;
        }
        /*
         * The bad scheme seems to be such that the larger numbers tend to be at a higher location. Therefore we will just 
         * calculate the average position of the numbers (i.e. centre of mass)
         */ 
        static void Main(string[] args)
        {
            
            Random r = new Random();
            
            
            /*
            List<double> good = new List<double>();
            double total = 0.0;
            for (int i = 0; i < 10000; i++)
            {
                int[] l = BadPerm(1000,r);
                good.Add(CentreOfMass(l));
                total +=good[i];
            }
            total /= 10000;
            */
            //StreamReader sr = new StreamReader("D:\\a.txt");
            //StreamWriter sw = new StreamWriter("D:\\b.txt");

            StreamReader sr = new StreamReader("D:\\C-small-attempt13.in");
            StreamWriter sw = new StreamWriter("D:\\C-small-attempt13.out");

            //StreamReader sr = new StreamReader("D:\\A-large.in");
            //StreamWriter sw = new StreamWriter("D:\\A-large.out");


            int numTestCases = Convert.ToInt32(sr.ReadLine());

            List<Result> results = new List<Result>();

            bool[] actual = new bool[numTestCases];

            for (int i = 0; i < numTestCases; i++)
            {

                Console.WriteLine(i);

                string[] str = sr.ReadLine().Split(' ');

                int N = Convert.ToInt32(str[0]);

                str = sr.ReadLine().Split(' ');

                int[] perm = new int[N];
                for (int j = 0; j < N; j++)
                {
                    perm[j] = Convert.ToInt32(str[j]);
                }

                /*
                actual[i] = r.Next(0, 2) == 0;
                if (actual[i])
                {
                    perm = GoodPerm(1000, r);
                }
                else
                {
                    perm = BadPerm(1000, r);
                }
                */

                Result temp=new Result();
                temp.index = i;
                temp.centreOfMass = CentreOfMass(perm);
                temp.isGood = false;

                results.Add(temp);
            }

            results.Sort((a, b) => a.centreOfMass.CompareTo(b.centreOfMass));

            for (int i = 0; i < numTestCases; i++)
            {
                if (i < numTestCases / 2)
                {
                    results[i].isGood = true;
                }
                else
                {
                    results[i].isGood = false;
                }

                //results[i].isGood = results[i].centreOfMass < 251800000;
            }

            results.Sort((a, b) => a.index.CompareTo(b.index));

            for (int i = 0; i < numTestCases; i++)
            {
                sw.Write("Case #{0}: ", i + 1);
                sw.Write(results[i].isGood ? "GOOD" : "BAD");
                sw.WriteLine();
            }

            
            /*
            int nc = 0;
            for (int i = 0; i < 120; i++)
            {
                if (results[i].isGood == actual[i])
                {
                    nc++;
                }
            }
           */

            sr.Close();
            sw.Close();
        }

    }
}
