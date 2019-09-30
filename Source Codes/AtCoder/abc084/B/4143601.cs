using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class Atcoderrrrrr
    {
        static void Main(string[] args)
        {
            int[] s = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int A = s[0];
            int B = s[1];
            string S = Console.ReadLine();
            if (S[A] == '-')
            {
                int cnt = 0;
                for (int i = 0; i < A+B+1; i++)
                {
                    if (S[i]=='-')
                    {
                        cnt++;
                    }
                }
                Console.WriteLine(cnt ==1? "Yes":"No");
            }
            else
            {
                Console.WriteLine("No");
            }

        }
    }
}