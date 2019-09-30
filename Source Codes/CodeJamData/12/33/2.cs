using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam2012
{
    public class C1BC
    {
        private string mInputFile = @"E:\work\codejam2012\data\1C\C-large.in";

        static void Main(string[] args)
        {
            var p = new C1BC();
            p.Run();
            Console.WriteLine("Done");
            Console.ReadLine();
        }

        public void Run()
        {
            Console.WriteLine(mInputFile);
            Console.WriteLine(mInputFile + ".out");
            using (StreamWriter sw = new StreamWriter(mInputFile + ".out"))
            using (StreamReader sr = new StreamReader(mInputFile))
            {
                int testNum = int.Parse(sr.ReadLine());
                for (int i = 0; i < testNum; i++)
                {
                    RunTest(i + 1, sr, sw);
                }
            }
        }

        private int[] ReadIntsFromLine(StreamReader sr)
        {
            string[] splits = sr.ReadLine().Split();
            return splits.Select(x => int.Parse(x)).ToArray();
        }

        private decimal[] ReadDecsFromLine(StreamReader sr)
        {
            string[] splits = sr.ReadLine().Split();
            return splits.Select(x => decimal.Parse(x)).ToArray();
        }

        private IEnumerator<string> ReadStrings(StreamReader sr)
        {
            string line = null;
            while ((line = sr.ReadLine()) != null)
            {
                foreach (string split in line.Split())
                    yield return split;
            }
        }

        private void RunTest(int testNum, StreamReader sr, StreamWriter sw)
        {
            int[] ints = ReadIntsFromLine(sr);
            int N = ints[0];
            int M = ints[1];
            int[] A = new int[N];
            decimal[] a = new decimal[N];
            int[] B = new int[M];
            decimal[] b = new decimal[M];

            var decs = ReadDecsFromLine(sr);
            for (int i = 0; i < N; i++)
            {
                a[i] = decs[2 * i];
                A[i] = (int)decs[2 * i + 1];
            }

            decs = ReadDecsFromLine(sr);
            for (int i = 0; i < M; i++)
            {
                b[i] = decs[2 * i];
                B[i] = (int)decs[2 * i + 1];
            }

            //
            decimal[][] points = new decimal[N][];
            for (int i = 0; i < N; i++)
                points[i] = new decimal[M];

            if (A[0] == B[0])
                points[0][0] = Math.Min(a[0], b[0]);
            else
                points[0][0] = 0;

            for (int i = 0; i < N; i++ )
                for (int j = 0; j < M; j++)
                {
                    if (i == 0 && j == 0) continue;
                    //if (i == 0)
                    //{
                    //    if (A[i] == B[j])
                    //    {
                    //        points[i][j] = Math.Max(points[i][j], Math.Min(a[i], b[j]));
                    //    }
                    //}
                    //else if (j == 0)
                    //{
                    //    if (A[i] == B[j])
                    //    {
                    //        points[i][j] = Math.Max(points[i-1][j], Math.Min(a[i], b[j]));
                    //    }
                    //}
                    //else
                    {
                        //var pre1 = (i == 0 || j == 0) ? 0m : points[i - 1][i - 1];
                        //points[i][j] = ((A[i] == B[j]) ? Math.Min(a[i], b[j]) : 0m) +  pre1;
                        if (A[i] == B[j])
                        {
                            decimal sumA = 0;
                            for (int k = i; k >= 0; k--)
                            {
                                if (A[k] == A[i])
                                {
                                    sumA += a[k];
                                    decimal sumB = 0;
                                    for (int l = j; l >= 0; l--)
                                    {
                                        if (B[l] == B[j])
                                        {
                                            sumB += b[l];
                                        }
                                        decimal pre = (k == 0 || l == 0) ? 0m : points[k - 1][l - 1];
                                        decimal newVal = Math.Min(sumA, sumB) + pre;
                                        points[i][j] = Math.Max(points[i][j], newVal);
                                    }
                                }
                            }
                        }
                        if (i > 0)
                            points[i][j] = Math.Max(points[i][j], points[i - 1][j]);
                        if ( j > 0)
                            points[i][j] = Math.Max(points[i][j], points[i][j-1]);
                    }
                }

            sw.WriteLine("Case #{0}: {1}", testNum, points[N-1][M-1]);
        }
    }

}

