using System;
using System.Linq;

namespace B___Theater
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var Ln = Enumerable.Range(1, N).Select(x => Console.ReadLine()).ToArray();
            var cnt = 0;

            foreach (var l in Ln)
                cnt += int.Parse(l.Split()[1]) - int.Parse(l.Split()[0]) + 1;

            Console.WriteLine(cnt);
        }
    }
}