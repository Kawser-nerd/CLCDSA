using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp
{
    class Program
    {
        static List<string> perms = new List<string>();

        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());

            var dic = new Dictionary<string, int>();
            var w = Console.ReadLine();
            dic.Add(w, 0);
            bool shiritori = true;
            for (int i = 1; i < N; i++)
            {
                var prevW = w;
                w = Console.ReadLine();

                if (!shiritori) continue;

                if (dic.ContainsKey(w))
                {
                    shiritori = false;
                    continue;
                }

                if (prevW[prevW.Length - 1] != w[0])
                {
                    shiritori = false;
                    continue;
                }

                dic.Add(w, 0);
            }

            if (shiritori)
                Console.WriteLine("Yes");
            else
                Console.WriteLine("No");
        }
    }
}