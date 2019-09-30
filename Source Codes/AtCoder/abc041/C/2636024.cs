using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.ReadLine();
            var i = 1;
            Console.ReadLine()
                .Split(' ')
                .Select(x => new KeyValuePair<int,long>(i++,long.Parse(x)))
                .OrderByDescending(x => x.Value)
                .ToList()
                .ForEach(x => Console.WriteLine(x.Key));
        }
    }
}