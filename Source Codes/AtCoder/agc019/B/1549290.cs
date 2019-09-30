using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace AtCoder.AGC019
{
    class ReverseAndCompare
    {
        public static void Main()
        {
            var chars = "abcdefghijklmnopqrstuvwxyz";
            var str = ReadLine().Trim();
            WriteLine((long)str.Length * (str.Length + 1) / 2 - chars.Select(_ => str.Where(c => c == _).Count()).Select(_ => (long)_ * (_ + 1) / 2).Sum() + 1);
        }
    }
}