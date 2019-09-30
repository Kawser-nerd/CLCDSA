using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            var S = Console.ReadLine();
            var counter = new int[26];

            foreach (var s in S)
            {
                counter[(int)s - (int)'a']++;
            }
            var oddcounter = 0;
            for (var i = 0; i < 26; i++)
            {
                if (counter[i] % 2 == 1)
                {
                    oddcounter++;
                }
            }

            if (oddcounter <= 1)
            {
                Console.WriteLine(S.Length);
            }
            else
            {
                var rest = (S.Length - oddcounter) / 2;
                var ans = (rest - rest % oddcounter) / oddcounter * 2 + 1;
                Console.WriteLine(ans);
            }
        }
    }
}