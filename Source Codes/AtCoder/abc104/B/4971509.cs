using System;
using System.Linq;

namespace ABC
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            ABC104_B();
        }


        static void ABC104_B()
        {
            var S = Console.ReadLine();

            var cCount = 0;
            var cIndex = 0;
            for (var i = 2; i < S.Length-1; i++)
            {
                if (S[i] == 'C')
                {
                    cCount++;
                    cIndex = i;
                }
            }

            var komoji = true;
            for (var i = 1; i < S.Length; i++)
            {
                if (cIndex == i)
                    continue;

                if (char.IsUpper(S[i]))
                {
                    komoji = false;
                    break;
                }
            }

            if (cCount != 1 || S[0] != 'A' || !komoji)
            {
                Console.WriteLine("WA");
                return;
            }

            Console.WriteLine("AC");
        }
    }
}