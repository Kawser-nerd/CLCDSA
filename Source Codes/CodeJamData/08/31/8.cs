using System;
using System.Collections;
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
                var arr = sr.ReadLine().Split(' ');
                var P = long.Parse(arr[0]);
                var K = long.Parse(arr[1]);
                arr = sr.ReadLine().Split(' ');

                List<long> li = new List<long>();
                for (int j = 0; j < arr.Length; j++)
                    li.Add(long.Parse(arr[j]));
                li.Sort();
                li.Reverse();

                long result = 0;
                for (int j = 0; j < arr.Length; j++)
                {
                    long temp = j / K + 1;
                    result += li[j] * temp;
                }
                sw.WriteLine("Case #" + (i + 1) + ": " + result);
            }
            sw.Close();
        }
    }
}
