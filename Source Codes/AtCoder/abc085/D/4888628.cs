using System;
using System.Collections.Generic;
using System.Linq;
    class Program
    {
        static void Main(string[] args)
        {
            var NH = Console.ReadLine().Split(' ').Select(s=>int.Parse(s)).ToList();
            var N = NH[0];
            var H = NH[1];
            var bList = new List<int>();
            var aMax = 0;
            for (var i = 0; i < N; i++)
            {
                var ab = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToList();
                if(aMax<ab[0])aMax=ab[0];
                bList.Add(ab[1]);
            }
            bList = bList
                .Where(b=>aMax<b)
                .OrderByDescending(i => i).ToList();
            var count = 0;
            foreach (var b in bList)
            {
                H -= b;
                count++;
                if (H <= 0)
                {
                    Console.WriteLine(count);
                    return;
                }
            }
            if (H % aMax != 0)
            {
                count++;
            }
            count += H / aMax;
            Console.WriteLine(count);
        }
    }