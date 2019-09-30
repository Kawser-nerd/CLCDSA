using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using static System.Console;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            Dictionary<char, int> rule = new Dictionary<char, int>();
            int index = 0;
            foreach (var _ in ReadLine().Split(' '))
                rule.Add(_[0], index++);

            int N = int.Parse(ReadLine());
            string[] nums = new string[N];
            for (int i = 0; i < N; i++)
            {
                nums[i] = ReadLine();
            }
            var query = nums.
                // ???????????
                GroupBy(_ => _.Length).
                // ?????????
                OrderBy(__ => __.Key);

            foreach (var group in query)
            {
                var list = group.ToList();
                list.Sort((a, b) =>
                {
                    for (int i = 0; i < a.Length; i++)
                    {
                        int idxA = rule[a[i]];
                        int idxB = rule[b[i]];
                        if (idxA < idxB) return -1;
                        if (idxA > idxB) return 1;
                    }
                    return 0;
                });
                foreach (var vals in list)
                    WriteLine(vals);
            }
            ReadLine();
        }
    }
}