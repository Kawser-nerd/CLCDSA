using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using static System.Console;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(ReadLine());
            Item[] items = new Item[N];
            for (int i = 0; i < N; i++)
            {
                float[] ar = ReadLine().Split(' ').Select(_ => float.Parse(_)).ToArray();
                items[i] = new Item()
                {
                    Max = ar[0],
                    Min=    ar[1]
                };
            }
            int cnt1 = items.Count(_ => _.Max >= 35);
            int cnt2 = items.Count(_ => _.Max >= 30 && _.Max < 35);
            int cnt3 = items.Count(_ => _.Max >= 25 && _.Max < 30);
            int cnt4 = items.Count(_ => _.Min >= 25);
            int cnt5 = items.Count(_ => _.Min < 0 && _.Max >= 0);
            int cnt6 = items.Count(_ => _.Max < 0);
            WriteLine($"{cnt1} {cnt2} {cnt3} {cnt4} {cnt5} {cnt6}");
            ReadLine();
        }
    }
    class Item
    {
        public float Max { get; set; }
        public float Min { get; set; }
    }
}