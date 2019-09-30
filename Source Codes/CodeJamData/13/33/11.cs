using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
//using System.Math.*;

namespace google_code_jam
{
    class Program
    {
        static string ProblemA2(UInt64 A, UInt64[] b)
        {
            if (A == 1) return b.Length.ToString();
            Array.Sort(b);
            UInt64 n = 0;
            UInt64 m = 0;
            UInt64[] g = new UInt64[b.Length];
            while (true)
            {
                if (b[n] < A)
                {
                    A += b[n];
                    g[n] = m;
                    m = 0;
                    n++;
                    if (n == (UInt64)b.Length) break;
                }
                else
                {
                    A += A - 1;
                    m++;
                }
            }

            UInt64 r = 0;
            m = 0;
            n = 0;
            for (int i = b.Length - 1; i >= 0; i--)
            {
                n++;
                m += g[i];
                if (m > n)
                {
                    r += n;
                    n = 0;
                    m = 0;
                }
            }
            r += m;
            return r.ToString();
        }

        static void ProblemA()
        {
            StreamReader reader = new StreamReader(@"C:\tmp\A.in", Encoding.ASCII);
            StreamWriter writer = new StreamWriter(@"C:\tmp\outA.txt");
            string s = reader.ReadLine();

            int m = int.Parse(s);
            for (int i = 0; i < m; i++)
            {
                string[] c = reader.ReadLine().Split();
                UInt64 A = UInt64.Parse(c[0]);
                string[] t = reader.ReadLine().Split();
                UInt64[] b = new UInt64[t.Length];
                for (int j = 0; j < t.Length; j++)
                {
                    b[j] = UInt64.Parse(t[j]);
                }

                string x = ProblemA2(A, b);
                x = "Case #" + (i + 1).ToString() + ":" + " " + x;
                writer.WriteLine(x);
            }
            reader.Close();
            writer.Close();
        }



        static void ProblemC()
        {
            StreamReader reader = new StreamReader(@"C:\tmp\C.in", Encoding.ASCII);
            StreamWriter writer = new StreamWriter(@"C:\tmp\outC.txt");
            string s = reader.ReadLine();

            StreamReader reader2 = new StreamReader(@"C:\tmp\garbled_email_dictionary.txt", Encoding.ASCII);


            int m = int.Parse(s);
            for (int i = 0; i < m; i++)
            {
                string x = null;//ProblemC2(reader.ReadLine());
                x = "Case #" + (i + 1).ToString() + ":" + " " + x;
                writer.WriteLine(x);
            }
            reader.Close();
            writer.Close();
        }

        static int A2(string s, int n)
        {
            string t = "aeiou";
            int r = 0;
            for (int i = 0; i < s.Length; i++)
            {
                int c = 0;
                int max = 0;
                for (int j = i; j < s.Length; j++)
                {
                    string u = s.Substring(j, 1);
                    if (t.Contains(u))
                    {
                        c = 0;
                    }
                    else
                    {
                        c++;
                    }
                    if (c > max) max = c;
                    if (max >= n)
                    {
                        r++;
                    }
                }
            }
            return r;
        }


        static void A()
        {
            StreamReader reader = new StreamReader(@"C:\tmp\A.in", Encoding.ASCII);
            StreamWriter writer = new StreamWriter(@"C:\tmp\outA.txt");
            string s = reader.ReadLine();

            string r = "";
            int m = int.Parse(s);
            for (int i = 0; i < m; i++)
            {
                string[] c = reader.ReadLine().Split();
                int x = A2(c[0], int.Parse(c[1]));
                r = "Case #" + (i + 1).ToString() + ":" + " " + x.ToString();
                writer.WriteLine(r);
            }
            reader.Close();
            writer.Close();
        }

        static string B2(int X, int Y)
        {
            string r = "";
            string x = "W";
            if (X < 0)
            {
                x = "E";
                X = -X;
            }
            for (int i = 0; i < 2 * X; i++)
            {
                r = r + x;
                if (x == "E")
                {
                    x = "W";
                }
                else
                {
                    x = "E";
                }
            }

            string y = "S";
            if (Y < 0)
            {
                y = "N";
                Y = -Y;
            }
            for (int i = 0; i < 2 * Y; i++)
            {
                r = r + y;
                if (y == "N")
                {
                    y = "S";
                }
                else
                {
                    y = "N";
                }
            }

            return r;
        }


        static void B()
        {
            StreamReader reader = new StreamReader(@"C:\tmp\B.in", Encoding.ASCII);
            StreamWriter writer = new StreamWriter(@"C:\tmp\outB.txt");
            string s = reader.ReadLine();

            string r = "";
            int m = int.Parse(s);
            for (int i = 0; i < m; i++)
            {
                string[] c = reader.ReadLine().Split();
                string x = B2(int.Parse(c[0]), int.Parse(c[1]));
                r = "Case #" + (i + 1).ToString() + ":" + " " + x;
                writer.WriteLine(r);
            }
            reader.Close();
            writer.Close();
        }

        static int C2(int[] d, int[] n, int[] w, int[] e, int[] s, int[] delta_d, int[] delta_p, int[] delta_s)
        {
            int N = d.Length;
            int[] g = new int[d.Length];


            var wall = new int[10000];
            var wall2 = new int[wall.Length];

            int c = 5000;

            int day = 0;
            int m = 0;
            int r = 0;
            while (true)
            {
                bool f = false;
                for (int i = 0; i < d.Length; i++)
                {
                    if (d[i] == day)
                    {
                        bool b = false;
                        for (int j = w[i]; j < e[i]; j++)
                        {
                            if (s[i] > wall[j + c])
                            {
                                b = true;
                                f = true;
                                wall2[j + c] = Math.Max(wall2[j + c], s[i]);
                            }
                        }
                        if (b)
                        {
                            r++;
                        }
                        d[i] += delta_d[i];
                        w[i] += delta_p[i];
                        e[i] += delta_p[i];
                        s[i] += delta_s[i];
                        n[i]--;
                        if (n[i] == 0)
                        {
                            d[i] = -1;
                            m++;
                        }
                    }
                }

                if (m == N) break;
                day++;
                if (!f) continue;
                for (int i = 0; i < wall.Length; i++)
                {
                    wall[i] = wall2[i];
                }
            }
            return r;
        }

        static void C()
        {
            StreamReader reader = new StreamReader(@"C:\tmp\C.in", Encoding.ASCII);
            StreamWriter writer = new StreamWriter(@"C:\tmp\outC.txt");
            string s = reader.ReadLine();

            string r = "";
            int m = int.Parse(s);
            for (int i = 0; i < m; i++)
            {
                int N = int.Parse(reader.ReadLine());
                var di = new int[N];
                var ni = new int[N];
                var wi = new int[N];
                var ei = new int[N];
                var si = new int[N];
                var delta_di = new int[N];
                var delta_pi = new int[N];
                var delta_si = new int[N];
                for (int j = 0; j < N; j++)
                {
                    string[] c = reader.ReadLine().Split();
                    di[j] = int.Parse(c[0]);
                    ni[j] = int.Parse(c[1]);
                    wi[j] = int.Parse(c[2]);
                    ei[j] = int.Parse(c[3]);
                    si[j] = int.Parse(c[4]);
                    delta_di[j] = int.Parse(c[5]);
                    delta_pi[j] = int.Parse(c[6]);
                    delta_si[j] = int.Parse(c[7]);
                }
                int x = C2(di, ni, wi, ei, si, delta_di, delta_pi, delta_si);
                r = "Case #" + (i + 1).ToString() + ":" + " " + x;
                writer.WriteLine(r);
            }
            reader.Close();
            writer.Close();
        }


        static void Main(string[] args)
        {
            // ProblemA();
            //  ProblemB();
            //ProblemC();
            //A();
            //B();
            C();
        }
    }
}
