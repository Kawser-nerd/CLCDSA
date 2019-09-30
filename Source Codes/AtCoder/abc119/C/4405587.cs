using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ABC119C_2
{
    class Program
    {
        List<int> bamboos = new List<int>();
        List<int> targets = new List<int>();

        static void Main(string[] args)
        {
            if (args.Length > 0)
            {
                Console.SetIn(new StreamReader(args[0]));
            }

            new Program().Solve();
        }

        void Solve()
        {
            var temp = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var numBamboos = temp[0];
            targets.Add(temp[1]);
            targets.Add(temp[2]);
            targets.Add(temp[3]);

            for (int i = 0; i < numBamboos; i++)
            {
                bamboos.Add(int.Parse(Console.ReadLine()));
            }

            Console.WriteLine(Calculate(0, new List<int> { 0, 0, 0 }, 0));
        }

        // index: ????????????
        // sizes: ?????????
        // consumed: ?????????MP
        int Calculate(int index, List<int> sizes, int consumed)
        {
            if (index == bamboos.Count)
            {
                // ???????
                if (sizes.Min() == 0)
                {
                    // ????????????????
                    return int.MaxValue;
                }

                // ????????????????????
                for (int i = 0; i < sizes.Count; i++)
                {
                    consumed += Math.Abs(targets[i] - sizes[i]);
                }

                return consumed;
            }

            var bamboo = bamboos[index];
            var min = int.MaxValue;

            for (int i = 0; i < sizes.Count; i++)
            {
                // ??????????????????
                var synthesized = sizes[i] == 0 ? 0 : 10; // ???1???????2?????MP?10????
                var nextSizes = new List<int>(sizes);
                nextSizes[i] += bamboo;
                min = Math.Min(min, Calculate(index + 1, nextSizes, consumed + synthesized));
            }

            // ????????
            min = Math.Min(min, Calculate(index + 1, sizes, consumed));
            return min;
        }
    }
}