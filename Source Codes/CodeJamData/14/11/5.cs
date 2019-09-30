using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace ChargingChaos
{
    class Program
    {
        static List<int> ConvertNumToVector(long num, int base_)
        {
            List<int> l = new List<int>();
            while (num > 0)
            {
                l.Insert(0, (int)(num % base_));
                num /= base_;
            }

            return l;
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

        static int CountNumOnes(long N)
        {
            List<int> l = ConvertNumToVector(N, 2);

            int countOnes = 0;
            foreach (int ln in l)
            {
                if (ln == 1) countOnes++;
            }

            return countOnes;
        }

        static int SolveBruteForce(int N, int L, long[] outlets, long[] devices)
        {
            int max = 1 << L;

            List<long> s = new List<long>(devices);
            s.Sort();

            int minOnes = 1000;

            for (int i = 0; i < max; i++)
            {
                List<long> temp = new List<long>();

                for (int j = 0; j < outlets.Length; j++)
                {
                    temp.Add(outlets[j] ^ i);
                }

                temp.Sort();
                bool possible = true;
                for (int j = 0; j < N; j++)
                {
                    if (temp[j] != s[j])
                    {
                        possible = false;
                        break;
                    }
                }

                if (possible)
                {
                    int numOnes = CountNumOnes(i);
                    if (numOnes < minOnes)
                    {
                        minOnes = numOnes;
                    }
                }
            }

            if (minOnes == 1000)
                return -1;
            else
                return minOnes;
        }

        static void Main(string[] args)
        {

            //StreamReader sr = new StreamReader("D:\\a.txt");
            //StreamWriter sw = new StreamWriter("D:\\b.txt");

            //StreamReader sr = new StreamReader("D:\\A-small-attempt2.in");
            //StreamWriter sw = new StreamWriter("D:\\A-small-attempt2.out");

            StreamReader sr = new StreamReader("D:\\A-large.in");
            StreamWriter sw = new StreamWriter("D:\\A-large.out");


            int numTestCases = Convert.ToInt32(sr.ReadLine());


            for (int i = 0; i < numTestCases; i++)
            {

                Console.WriteLine(i);

                string[] str = sr.ReadLine().Split(' ');

                int N = Convert.ToInt32(str[0]);
                int L = Convert.ToInt32(str[1]);

                long[] outlets = new long[N];
                long[] devices = new long[N];

                str = sr.ReadLine().Split(' ');

                for (int j = 0; j < N; j++)
                {
                    int[] vec = new int[L];
                    for (int k = 0; k < str[j].Length; k++)
                    {
                        vec[k] = Convert.ToInt32(str[j][k].ToString());
                    }
                    outlets[j] = ConvertVectorToNum(new List<int>( vec), 2);
                }

                str = sr.ReadLine().Split(' ');

                for (int j = 0; j < N; j++)
                {
                    int[] vec = new int[L];
                    for (int k = 0; k < str[j].Length; k++)
                    {
                        vec[k] = Convert.ToInt32(str[j][k].ToString());
                    }
                    devices[j] = ConvertVectorToNum(new List<int>(vec), 2);
                }

                
                long[,] switching = new long[N, N];

                for (int j = 0; j < N; j++)
                {
                    for (int k = 0; k < N; k++)
                    {
                        switching[j, k] = outlets[j] ^ devices[k];
                    }
                }

                List<long> currentList = new List<long>();
                for (int k = 0; k < N; k++)
                {
                    currentList.Add(switching[0, k]);
                }

                currentList.Sort();

                for (int j = 1; j < N; j++)
                {
                    List<long> newList = new List<long>();
                
                    for (int k = 0; k < N; k++)
                    {
                        if(currentList.Contains( switching[j, k]))
                        {
                            newList.Add(switching[j, k]);
                        }
                    }

                    currentList = newList;
                    currentList.Sort();
                }


                int minOnes = 1000;
                bool possible = false;

                for (int j = 0; j < currentList.Count; j++)
                {
                    possible = true;
                    List<int> l = ConvertNumToVector(currentList[j], 2);

                    int countOnes = 0;
                    foreach (int ln in l)
                    {
                        if (ln == 1) countOnes++;
                    }

                    if (countOnes < minOnes)
                    {
                        minOnes = countOnes;
                    }
                }
                

                //int minOnes = SolveBruteForce(N, L, outlets, devices);

                sw.Write("Case #{0}: ", i + 1);
                if (possible) sw.Write(minOnes);
                else sw.Write("NOT POSSIBLE");
                //if (minOnes>=0) sw.Write(minOnes);
                //else sw.Write("NOT POSSIBLE");
                sw.WriteLine();

            }
            sr.Close();
            sw.Close();
        }

    }
}
