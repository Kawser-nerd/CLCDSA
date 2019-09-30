using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder1
{
    class Program
    {
        static void Main()
        {
            var S = ReadLine();
            var K = long.Parse(ReadLine());

            for (int i = 0; i < S.Length; i++)
            {
                if (S[i] != '1')
                {
                    WriteLine(K >= i + 1 ? S[i] : '1');
                    return;
                }
            }
            WriteLine('1');
        }
    }
}