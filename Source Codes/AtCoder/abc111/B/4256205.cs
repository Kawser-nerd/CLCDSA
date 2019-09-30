using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B.AtCoder_Beginner_Contest_111
{
    class Program
    {
        static void Main(string[] args)
        {
            var num = Console.ReadLine().ToCharArray();
            var str = string.Empty;

            if (int.Parse(new string(num)) > int.Parse(string.Concat(Enumerable.Repeat(int.Parse(num[0].ToString()), num.Length))))
                str = string.Concat(Enumerable.Repeat(int.Parse(num[0].ToString()) + 1, num.Length));
            else
                str = string.Concat(Enumerable.Repeat(int.Parse(num[0].ToString()), num.Length));

            Console.WriteLine(str);
        }
    }
}