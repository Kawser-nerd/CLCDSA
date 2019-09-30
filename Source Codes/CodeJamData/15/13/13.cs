using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace R1_C
{
    class Program
    {
        public struct Point
        {
            public Int64 x;
            public Int64 y;
        };

        static void Main(string[] args)
        {
            string fin = "C-small-attempt2.in";
            //"input.txt";
            string fout = "C.out";
            StreamReader sr = new StreamReader(fin);
            StreamWriter sw = new StreamWriter(fout);
            int T = Int32.Parse(sr.ReadLine());
            Point[] p = new Point[3000];
            int[] ans = new int[3000];
            for (int i = 1; i <= T; i++)
            {
                int N = Int32.Parse(sr.ReadLine());
                for (int j = 0; j < N; j++)
                {
                    string txt = sr.ReadLine();
                    p[j].x = Int64.Parse(txt.Split(' ')[0]);
                    p[j].y = Int64.Parse(txt.Split(' ')[1]);
                }

                for (int j = 0; j < N; j++)
                {
                    ans[j] = N;
                    if (N <= 2) { ans[j] = 0; continue; }
                    for (int k = 0; k < N; k++)
                    {
                        if (j == k) continue;
                        // get line
                        Int64 a = p[j].y - p[k].y;
                        Int64 b = p[k].x - p[j].x;
                        Int64 c = p[j].x * p[k].y - p[j].y * p[k].x;
                        int cnt1 = 0;
                        int cnt2 = 0;
                        for (int m = 0; m < N; m++)
                            if (a * p[m].x + b * p[m].y + c < 0) cnt1++;
                            else if (a * p[m].x + b * p[m].y + c > 0) cnt2++;
                        if (cnt1 < ans[j]) ans[j] = cnt1;
                        else if (cnt2 < ans[j]) ans[j] = cnt2;
                    }
                    if (ans[j] == 0) continue;
                }
                sw.WriteLine(string.Format("Case #{0}:", i));
                for (int j = 0; j < N; j++)
                    sw.WriteLine(ans[j]);
            }
            sr.Close();
            sw.Close();
        }
    }
}
