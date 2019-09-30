using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace C
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader("small.in"))
            {
                using (StreamWriter sw = new StreamWriter("small.out"))
                {
                    int N = int.Parse(sr.ReadLine());
                    for (int i = 1; i <= N; i++)
                    {
                        string[] elem = sr.ReadLine().Split(' ');
                        long n = long.Parse(elem[0]);
                        long m = long.Parse(elem[1]);
                        long X = long.Parse(elem[2]);
                        long Y = long.Parse(elem[3]);
                        long Z = long.Parse(elem[4]);

                        long[] A = new long[m];
                        for (int j = 0; j < m; j++)
                            A[j] = long.Parse(sr.ReadLine());

                        long[] a = new long[n];
                        for (int j = 0; j < n; j++)
                        {
                            a[j] = A[j % m];
                            A[j % m] = (X * A[j % m] + Y * (j + 1)) % Z;
                        }

                        long[] res = new long[n];

                        res[0] = 1;

                        for (int j = 1; j < n; j++)
                        {
                            res[j] = 1;
                            for (int k = j - 1; k >= 0; k--)
                            {
                                if (a[j] > a[k])
                                {
                                    res[j] = ( res[j] + res[k] ) % 1000000007;
                                }
                            }
                        }

                        long total = 0;
                        for (int j = 0; j < n; j++) total = ( total + res[j] ) % 1000000007;

                        sw.WriteLine("Case #{0}: {1}", i, total);
                    }

                    sr.Close();
                    sw.Close();
                }
            }
        }
    }
}
