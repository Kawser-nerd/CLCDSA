using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Console.SetIn(new System.IO.StreamReader("in.txt"));
            Console.SetOut(new System.IO.StreamWriter("out.txt") { AutoFlush = true });

            int t = int.Parse(Console.ReadLine());

            for (int i = 0; i < t; i++)
            {
                var ss = Console.ReadLine().Split();
                int n = int.Parse(ss[0]);
                int k = int.Parse(ss[1]);


                var rr = new double[n];
                var hh = new double[n];
                for (int j=0;j< n; j++)
                {
                    ss = Console.ReadLine().Split();
                    rr[j] = double.Parse(ss[0]);
                    hh[j] = double.Parse(ss[1]);
                }

                double result = 0;
                Array.Sort(rr, hh);
                for(int z = k-1;z < n; z++)
                {
                    double bb = rr[z];
                    double now = Math.PI * bb * bb + hh[z] * 2 * Math.PI * bb;
                    var arr = new double[z];

                    for (int y = 0; y < z; y++)
                        arr[y] = hh[y] * rr[y];
                    Array.Sort(arr);

                    for (int y = 0; y < k - 1; y++)
                        now += 2 * Math.PI * arr[z - y - 1];
                    result = Math.Max(result, now);
                }

                Console.WriteLine($"Case #{i+1}: {result.ToString("#.##########").Replace(',', '.')}");
            }
        }
    }
}