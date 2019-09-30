using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GCJ
{
    public class NumberGame
    {
        public static void Main(string[] args)
        {
            var file = File.OpenText("C-small.in");
            var output = File.CreateText("C-small_out.txt");
            var t = int.Parse(file.ReadLine());
            for (int tc = 0; tc < t; tc++)
            {
                var temp = file.ReadLine().Split(new[] { " " }, StringSplitOptions.RemoveEmptyEntries).ToList().ConvertAll(x => int.Parse(x));
                var a1 = temp[0];
                var a2 = temp[1];
                var b1 = temp[2];
                var b2 = temp[3];
                long cnt = 0;
                for (int a = a1; a <= a2; a++)
                {
                    for (int b = b1; b <= b2; b++)
                    {
                        var mx = Math.Max(a, b);
                        var mn = Math.Min(a, b);
                        if (Win(mx, mn))
                        {
                            ++cnt;
                        }
                    }
                }
                output.WriteLine("Case #" + (tc + 1) + ": " + cnt);
            }
            output.Close();
        }

        private static bool Win(int a, int b)
        {
            if (a == b)
            {
                return false;
            }
            if (a % b == 0)
            {
                return true;
            }
            if (Win(b, a % b))
            {
                return a > 2 * b;
            }
            return true;
        }
    }
}
