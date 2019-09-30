using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_009
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] km = ReadInts();
            long[] array=ReadLongs();
            long[] cArray = ReadLongs();
            int k = km[0];
            int m = km[1];
            if (m <= k)
            {
                Console.WriteLine(array[m - 1]);
                return;
            }
            m -= k;

            long[,] aMatrix=new long[k, 1];
            long[,] cMatrix = new long[k, k];
            for(int i = 0; i < k; i++)
            {
                aMatrix[i, 0] = array[k-1-i];
                for(int j = 0; j < k; j++)
                {
                    if (i == 0)
                    {
                        cMatrix[i, j] = cArray[j];
                    }
                    else
                    {
                        cMatrix[i, j] = i == j + 1 ? long.MaxValue : 0;
                    }
                    //Console.Write(cMatrix[i, j] + " ");
                }
                //Console.WriteLine();
            }

            var matList = new List<long[,]>();
            matList.Add(cMatrix);
            long mm = m;
            long[,] tarMat = mm % 2 == 1 ? cMatrix : null;
            mm /= 2;
            while (mm > 0)
            {
                long[,] mat = matList[matList.Count - 1];

                matList.Add(MultiMat(mat, mat));
                if (mm % 2 == 1)
                {
                    if (tarMat == null)
                    {
                        tarMat = matList[matList.Count - 1];
                    }
                    else
                    {
                        tarMat = MultiMat(matList[matList.Count - 1], tarMat);
                    }
                }
                mm /= 2;
            }

            long[,] resMat = MultiMat(tarMat, aMatrix);
            Console.WriteLine(resMat[0, 0]);
        }

        static long[,] MultiMat(long[,] left,long[,] right)
        {
            int h = left.GetLength(0);
            int w = right.GetLength(1);
            int c = left.GetLength(1);
            if (c != right.GetLength(0)) return null;

            long[,] mat = new long[h, w];

            for (int i = 0; i < h; i++)
            {
                for (int ii = 0; ii < w; ii++)
                {
                    long val = left[i, 0] & right[0, ii];
                    for (int iii = 1; iii < c; iii++)
                    {
                        val ^= left[i, iii] & right[iii, ii];
                    }
                    mat[i, ii] = val;
                    //Console.Write(mat[i, ii]+" ");
                }
                //Console.WriteLine();
            }
            return mat;
        }

        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}