using System;
using System.Linq;


namespace Acs
{
    class Program
    {
        static void Main(string[] args)
        {
            /*
            var ss = Console.ReadLine().Split(' ');
            var a = int.Parse(ss[0]);
            var b = int.Parse(ss[1]);
            Console.WriteLine(a<=b ?a:a-1);
            */

            var int_ = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            Console.WriteLine(int_[0] <= int_[1] ? int_[0] : int_[0] - 1);
        }
    }
}