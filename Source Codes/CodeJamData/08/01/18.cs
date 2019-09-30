using System;
using System.Collections.Generic;
using System.IO;

namespace GoogleCodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            var sr = new StreamReader("input.txt");
            var sw = new StreamWriter("output.txt");
            var N = int.Parse(sr.ReadLine());

            for (int i = 0; i < N; i++)
            {
                var S = int.Parse(sr.ReadLine());
                var ls1 = new List<string>();
                for(var j = 0; j < S; j++)
                    ls1.Add(sr.ReadLine());

                var Q = int.Parse(sr.ReadLine());
                var ls2 = new List<int>();
                for (var j = 0; j < Q; j++)
                    ls2.Add(ls1.IndexOf(sr.ReadLine()));

                var arr = new int[Q + 1,S];
                for (var j = 0; j < Q; j++)
                {
                    arr[j, ls2[j]] = 1000000;
                    var mn = 1000000;
                    for (var q = 0; q < S; q++)
                        if (q != ls2[j])
                        {
                            arr[j + 1, q] = arr[j, q];
                            mn = Math.Min(arr[j, q], mn);
                        }
                    arr[j + 1, ls2[j]] = mn + 1;
                }

                if (Q == 0)
                {
                    sw.WriteLine("Case #" + (i + 1) + ": " + 0);
                }
                else
                {
                    var result = 1000000;
                    for (var j = 0; j < S; j++)
                        result = Math.Min(result, arr[Q, j]);

                    sw.WriteLine("Case #" + (i + 1) + ": " + result);
                }
            }

            sw.Close();
        }
    }
}
