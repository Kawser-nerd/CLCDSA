using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp
{
    class Program
    {
        static int ans = 0;

        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var str = Console.ReadLine();
            var strs = str.Split(' ');

            var hs = new List<int>();
            foreach (var item in strs)
            {
                hs.Add(int.Parse(item));
            }

            Watering(hs);

            Console.WriteLine(ans);
        }

        static void Watering(List<int> hs)
        {

            for (int i = 0; i < hs.Count; i++)
            {
                if (hs[i] != 0)
                {
                    break;
                }

                if (i == hs.Count - 1)
                {
                    return;
                }
            }

            if (hs.Count == 1)
            {
                ans += hs[0];
                return;
            }

            while (!hs.Contains(0))
            {
                for (int i = 0; i < hs.Count; i++)
                {
                    hs[i]--;
                }
                ans++;
            }

            var borderIndex = hs.IndexOf(0);

            if (borderIndex != 0)
            {
                Watering(hs.Take(borderIndex).ToList());
            }

            if (borderIndex != hs.Count - 1)
            {
                Watering(hs.Skip(borderIndex + 1).Take(hs.Count - borderIndex).ToList());
            }
        }
    }
}