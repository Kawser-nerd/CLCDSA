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
            string N = Console.ReadLine();

            int n = 0;
            for(int i = 0; i < N.Length; i++)
            {
                n += int.Parse(N[i].ToString());
            }
            Console.WriteLine(
                int.Parse(N) % n == 0 ? "Yes":"No"
                );
        }
    }
}