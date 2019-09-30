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

        static void RankAndFile(int N)
        {
            // read input from console
            int[] nums = new int[2501];
            for (int i = 0; i < 2501; ++i)
            {
                nums[i] = 0;
            }
            
            for (int i = 0; i < 2*N-1; ++i)
            {
                var line = Console.ReadLine().Split(' ');
                foreach (String num in line)
                {
                    nums[int.Parse(num)]++;
                }
            }

            // print out the odd ones
            for (int i = 0; i < 2501; ++i)
            {
                if (nums[i]%2==1)
                {
                    Console.Write(" {0}", i);
                }
            }
            Console.WriteLine();
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 1; i <= T; ++i)
            {
                Console.Write("Case #{0}:", i);
                RankAndFile(int.Parse(Console.ReadLine()));
            }
        }
    }
}
