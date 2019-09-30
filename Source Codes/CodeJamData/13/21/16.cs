using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Problem_A
{
    class Program
    {
        static void Main(string[] args)
        {
            var pathIn = @"D:\Projects\Google CodeJam 2013\Round 1B\A-large.in";
            var pathOut = Path.ChangeExtension(pathIn, @"out");
            using (var input = new StreamReader(pathIn))
            {
                using (var output = new StreamWriter(pathOut, false) { AutoFlush = true })
                {
                    Solve(input, output);
                }
            }
        }

        private static void Solve(StreamReader input, StreamWriter output)
        {
            var T = Int32.Parse(input.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string aa = input.ReadLine();
                var arr = aa.Split(' ');
                var armin = int.Parse(arr[0]);
                //var N = int.Parse(arr[1]);
                var arr1 = input.ReadLine().Split(' ').Select(i => int.Parse(i)).OrderBy(i => i).ToArray();
                int result = int.MaxValue;
                if (armin < 2)
                {
                    result = arr1.Length;
                }
                else
                    for (int k = 0; k <= arr1.Length; k++)
                    {
                        int currRes = arr1.Length - k;
                        int w = armin;
                        for (var i = 0; i < k; i++)
                        {
                            while (w <= arr1[i])
                            {
                                w += w - 1;
                                currRes++;
                            }
                            w += arr1[i];
                        }
                        result = Math.Min(result, currRes);
                    }
                output.WriteLine("Case #{0}: {1}", t, result);
            }
        }
    }
}
