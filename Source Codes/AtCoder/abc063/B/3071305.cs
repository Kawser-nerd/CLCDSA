using System;

namespace Bmondai
{
    class Program
    {
        public static void ABC063()
        {
            var S = Console.ReadLine();
            var f = true;
            foreach (var s1 in S)
            {
                var count = 0;
                foreach (var s2 in S)
                {
                    if (s1 == s2)
                        count++;
                }
                if (count > 1)
                {
                    f = false;
                    break;
                }
            }

            if (f)
                Console.WriteLine("yes");
            else
                Console.WriteLine("no");
        }

        static void Main(string[] args)
        {
            ABC063();
        }
    }
}