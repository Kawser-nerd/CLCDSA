using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class Program
    {
        const double EPS = 1e-9;

        static void Main(string[] args)
        {
            int total = int.Parse(Console.ReadLine());
            int[] ans = {
                            1,      // 0
                            5,      // 1
                            27,     // 2
                            143,    // 3
                            751,    // 4
                            935,    // 5
                            607,    // 6
                            903,    // 7
                            991,    // 8
                            335,    // 9
                            47,     // 10
                            943,    // 11
                            471,    // 12
                            055,    // 13
                            447,    // 14
                            463,    // 15
                            991,    // 16
                            95,     // 17
                            607,    // 18
                            263,    // 19
                            151,    // 20
                            855,    // 21
                            527,    // 22
                            743,    // 23
                            351,    // 24
                            135,    // 25
                            407,    // 26
                            903,    // 27
                            791,    // 28
                            135,    // 29
                            647,    // 30
                        };
            for (int casen = 1; casen <= total; casen++)
            {
                int n = int.Parse(Console.ReadLine());
                Console.WriteLine("Case #{0}: {1:D3}", casen, ans[n]);
            }
        }

        static string[] Split(string str, char ch)
        {
            string[] buf = str.Split(ch);
            List<string> list = new List<string>();
            foreach (string s in buf)
                if (!string.IsNullOrEmpty(s)) list.Add(s);
            return list.ToArray();
        }
    }
}
