using System;
using System.Linq;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var alist = Console.ReadLine().Split(' ').Select(int.Parse).OrderBy(x=>x);
            var good = 0;
            var now = 0;
            var nowcount = 0;
            foreach(var a in alist)
            {
                if (a != now)
                {
                    now = a;
                    nowcount = 0;
                }
                nowcount += 1;
                if(nowcount == a)
                {
                    good += a;
                }
            }
            Console.WriteLine(N - good);
        }
    }
}