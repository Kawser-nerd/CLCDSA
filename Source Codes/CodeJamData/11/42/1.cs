using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace cs_console
{
    class G2_B
    {
        public static void Main(String[] args)
        {
            string input = @"../../B.in";
            string output = @"../../B.out";
            using (StreamWriter sw = new StreamWriter(output))
            {
                using (StreamReader sr = new StreamReader(input))
                {
                    long tn = long.Parse(sr.ReadLine());
                    for (long tc = 1; tc <= tn; tc++)
                    {
                        sw.WriteLine("Case #{0}: {1}", tc, ls(sr));
                    }
                }
            }
        }

        private static string ls(StreamReader sr)
        {
            checked
            {
                string[] ss = sr.ReadLine().Split(' ');
                string im = "IMPOSSIBLE";
                int r = int.Parse(ss[0]);
                int c = int.Parse(ss[1]);
                int d = int.Parse(ss[2]);
                int[,] a = new int[r, c];
                int[,] xa = new int[r, c];
                int[,] ya = new int[r, c];
                for (int i = 0; i < r; i++)
                {
                    string s = sr.ReadLine();
                    for (int j = 0; j < c; j++)
                    {
                        a[i, j] = (int)(s[j] - '0');
                        xa[i, j] = a[i, j] * i;
                        ya[i, j] = a[i, j] * j;
                    }
                }
                int[,] m = new int[r + 1, c + 1];
                int[,] xm = new int[r + 1, c + 1];
                int[,] ym = new int[r + 1, c + 1];
                for (int i = 1; i <= r; i++)
                {
                    for (int j = 1; j <= c; j++)
                    {
                        m[i, j] = m[i, j - 1] + m[i - 1, j] - m[i - 1, j - 1] + a[i - 1, j - 1];
                        xm[i, j] = xm[i, j - 1] + xm[i - 1, j] - xm[i - 1, j - 1] + xa[i - 1, j - 1];
                        ym[i, j] = ym[i, j - 1] + ym[i - 1, j] - ym[i - 1, j - 1] + ya[i - 1, j - 1];
                    }
                }
                for (int k = Math.Min(r, c); k >= 3; k--)
                {
                    for (int i = 0; i <= r - k; i++)
                    {
                        for (int j = 0; j <= c - k; j++)
                        {
                            /*int mt1 = 0;
                            int xt1 = 0;
                            int yt1 = 0;
                            for (int x = 0; x < k; x++)
                            {
                                for (int y = 0; y < k; y++)
                                {
                                    if ((x == 0 || x == k - 1) && (y == 0 || y == k - 1))
                                    {
                                    }
                                    else
                                    {
                                        mt1 += a[i + x, j + y];
                                        xt1 += xa[i + x, j + y];
                                        yt1 += ya[i + x, j + y];
                                    }
                                }
                            }*/

                            
                            int mt = m[i, j] + m[i + k, j + k] - m[i + k, j] - m[i, j + k];
                            int xt = xm[i, j] + xm[i + k, j + k] - xm[i + k, j] - xm[i, j + k];
                            int yt = ym[i, j] + ym[i + k, j + k] - ym[i + k, j] - ym[i, j + k];
                            mt -= a[i, j] + a[i, j + k - 1] + a[i + k - 1, j] + a[i + k - 1, j + k - 1];
                            xt -= xa[i, j] + xa[i, j + k - 1] + xa[i + k - 1, j] + xa[i + k - 1, j + k - 1];
                            yt -= ya[i, j] + ya[i, j + k - 1] + ya[i + k - 1, j] + ya[i + k - 1, j + k - 1];

                            //assert(mt == mt1);
                            //assert(xt == xt1);
                            //assert(yt == yt1);

                            if (mt * (i + i + k - 1) == xt * 2 && mt * (j + j + k - 1) == yt * 2)
                            {
                                Console.WriteLine(i + " " + j + " " + k);
                                return k + "";
                            }                            
                        }
                    }
                }
                return im;
            }
        }

        static void assert(bool v)
        {
            if (!v)
            {
                throw new Exception();
            }
        }
    }
}
