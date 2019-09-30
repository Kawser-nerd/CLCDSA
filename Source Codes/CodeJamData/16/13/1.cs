using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication7
{
    class Program
    {
        //static String TheLastWord(String S)
        //{
        //    char max = S.Max();
        //    int maxIndex = S.LastIndexOf(max);

        //    String ret = "" + max;
        //    if (maxIndex > 0)
        //    {
        //        ret = ret + TheLastWord(S.Substring(0, maxIndex));
        //    }
        //    if (maxIndex + 1 < S.Length)
        //    {
        //        ret = ret + S.Substring(maxIndex + 1, S.Length - (maxIndex + 1)); // have to be in order
        //    }
        //    return ret;
        //}

        //static void Main(string[] args)
        //{
        //    int T = int.Parse(Console.ReadLine());
        //    for (int i = 1; i <= T; ++i)
        //    {
        //        Console.WriteLine("Case #{0}: {1}", i, TheLastWord(Console.ReadLine()));
        //    }
        //}

        //static void RankAndFile(int N)
        //{
        //    // read input from console
        //    int[] nums = new int[2501];
        //    for (int i = 0; i < 2501; ++i)
        //    {
        //        nums[i] = 0;
        //    }

        //    for (int i = 0; i < 2*N-1; ++i)
        //    {
        //        var line = Console.ReadLine().Split(' ');
        //        foreach (String num in line)
        //        {
        //            nums[int.Parse(num)]++;
        //        }
        //    }

        //    // print out the odd ones
        //    for (int i = 0; i < 2501; ++i)
        //    {
        //        if (nums[i]%2==1)
        //        {
        //            Console.Write(" {0}", i);
        //        }
        //    }
        //    Console.WriteLine();
        //}

        //static void Main(string[] args)
        //{
        //    int T = int.Parse(Console.ReadLine());
        //    for (int i = 1; i <= T; ++i)
        //    {
        //        Console.Write("Case #{0}:", i);
        //        RankAndFile(int.Parse(Console.ReadLine()));
        //    }
        //}

        static int MaxCycleLength(List<int> bffs, int start)
        {
            int index = start;
            for (int i = 0; i < bffs.Count; ++i)
            {
                index = bffs[index];
                if (index == start)
                {
                    // we are a cycle
                    return i+1;
                }
                else if (index == bffs[bffs[index]])
                {
                    // we are a chain
                    return 2;
                }
            }
            return 0;
        }

        static int ChainTerminal(List<int> bffs, int start)
        {
            int index = start;
            for (int i = 0; i < bffs.Count; ++i)
            {
                index = bffs[index];
                if (index == bffs[bffs[index]])
                {
                    return bffs[index];
                }
            }
            return -1;
        }

        static int ChainLength(List<int> bffs, int start)
        {
            int index = start;
            for (int i = 0; i < bffs.Count; ++i)
            {
                if (index == bffs[bffs[index]])
                {
                    return i + 2;
                }
                index = bffs[index];
            }
            return -1;
        }

        static int BFF(List<int> bffs)
        {
            List<int> chains = new List<int>();

            int max = 0;

            // for each kid, are we a chain or cycle?
            for (int i = 0; i < bffs.Count; ++i)
            {
                int length = MaxCycleLength(bffs, i);
                if (length == 2)
                {
                    // we have a chain...
                    chains.Add(i);
                }
                else if (length > max)
                {
                    max = length;
                }
            }

            // now we are either max cycle, or sum of chains
            Dictionary<int, int> maxChains = new Dictionary<int, int>();
            foreach (int chain in chains)
            {
                int terminal = ChainTerminal(bffs, chain);
                int length = ChainLength(bffs, chain);
                if (maxChains.ContainsKey(terminal))
                {
                    maxChains[terminal] = Math.Max(maxChains[terminal], length);
                }
                else
                {
                    maxChains.Add(terminal, length);
                }
            }

            // for each terminal, we can have longest chain that ends at that terminal
            int sumChains = 0;
            foreach (var kv in maxChains)
            {
                sumChains += kv.Value - 1; // -1 because we don't count terminal node
            }

            return Math.Max(sumChains, max);
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 1; i <= T; ++i)
            {
                List<int> list = new List<int>();
                int N = int.Parse(Console.ReadLine());
                var line = Console.ReadLine().Split(' ');
                foreach (var s in line)
                {
                    list.Add(int.Parse(s)-1);
                }

                Console.WriteLine("Case #{0}: {1}", i, BFF(list));
            }
        }

    }
}
