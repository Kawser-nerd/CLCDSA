using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        public static void Main()
        {
            new Program().Solve();
        }

        void Solve()
        {
            var s = Console.ReadLine();
            var charArray = "ABCDEF".ToCharArray();
            var count = new int[charArray.Length];
            foreach (var c in s)
            {
                for (int i = 0; i < charArray.Length; i++)
                {
                    if (c == charArray[i])
                    {
                        count[i]++;
                    }
                }
            }
            Console.WriteLine(string.Join(" ", count));
        }
    }
}