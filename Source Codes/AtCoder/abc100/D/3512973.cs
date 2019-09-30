using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_100
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nm = ReadInts();
            var paramArray = new long[nm[0]][];
            for (int i = 0; i < nm[0]; i++)
            {
                long[] input = ReadLongs();
                paramArray[i] = new long[4];
                paramArray[i][0] = input[0];
                paramArray[i][1] = input[1];
                paramArray[i][2] = input[2];
            }

            long result = long.MinValue;
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    bool plus = ((i >> j) & 1) == 1;
                    for (int k = 0; k < nm[0]; k++)
                    {
                        if (j == 0) paramArray[k][3] = 0;
                        if (plus)
                        {
                            paramArray[k][3] += paramArray[k][j];
                        }
                        else
                        {
                            paramArray[k][3] -= paramArray[k][j];
                        }
                    }
                }
                //Array.Sort(paramArray, (a, b) => (int)(b[3] - a[3]));
                paramArray = paramArray.OrderBy(a => -a[3]).ToArray();
                var tempResults = new long[4];
                for (int mm = 0; mm < nm[1]; mm++)
                {
                    tempResults[0] += paramArray[mm][0];
                    tempResults[1] += paramArray[mm][1];
                    tempResults[2] += paramArray[mm][2];
                    /*Console.WriteLine(
                        paramArray[mm][0] + " "
                        + paramArray[mm][1] + " "
                        + paramArray[mm][2] + " "
                        + paramArray[mm][3]);*/
                }
                tempResults[3] = Math.Abs(tempResults[0])
                    + Math.Abs(tempResults[1])
                    + Math.Abs(tempResults[2]);
                result = Math.Max(result, tempResults[3]);
            }

            Console.WriteLine(result);
        }

        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }

    struct Value
    {
        public long x;
        public long y;
        public long z;
        public long sum;

        public Value(long x,long y,long z,long sum)
        {
            this.x = x;
            this.y = y;
            this.z = z;
            this.sum = sum;
        }
    }
}