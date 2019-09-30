using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;
using System.IO;

namespace BestR2
{
    public class A
    {
        public const string PATH_IN = @"C:\Users\sergey.shcheglov\Downloads\A-large (1).in";
        public const string PATH_OUT = @"D:\Dropbox\Competitions\GCJ16\R2\out.txt";

        static void Main(string[] args)
        {
            var s = new A();

            var lines = File.ReadAllLines(PATH_IN);

            var res = s.Solve(lines);

            File.WriteAllLines(PATH_OUT, res);
        }

        int GetInt(string s)
        {
            return int.Parse(s.Trim());
        }

        int[] GetIntArray(string s)
        {
            return s.Trim().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
        }

        public string[] Solve(string[] INPUT)
        {
            int cases = int.Parse(INPUT[0]);
            string[] res = new string[cases];

            int LINEIDX = 1;

            for (int test = 0; test < cases; test++)
            {
                int[] l = GetIntArray(INPUT[LINEIDX++]);
                int N = l[0], R = l[1], P = l[2], S = l[3];

                String a = "P", b = "R", c = "S";

                for (int i = 1; i <= N; i++)
                {
                    String a1 = a + b;
                    String b1 = a + c;
                    String c1 = b + c;
                    a = a1;
                    b = b1;
                    c = c1;
                }

                string ans = "IMPOSSIBLE";
                string[] all = new[] { a, b, c };
                for (int q = 0; q < 3; q++)
                {
                    int pp = 0, rr = 0, ss = 0;
                    a = all[q];
                    for (int i = 0; i < a.Length; i++)
                    {
                        if (a[i] == 'P')
                            pp++;
                        if (a[i] == 'R')
                            rr++;
                        if (a[i] == 'S')
                            ss++;
                    }

                    if (pp == P && rr == R && ss == S)
                    {
                        ans = all[q];
                        break;
                    }
                }

                Console.WriteLine("Case #{0}: {1}", (test + 1), ans);
                res[test] = string.Format("Case #{0}: {1}", (test + 1), ans);


            }
            return res;
        }
    }
}
