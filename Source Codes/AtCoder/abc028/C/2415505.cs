using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace VirtualAtCorder
{
    class Program
    {

        static List<int> Sum = new List<int>();

        static void Main(string[] args)
        {
            string[] inputs = Console.ReadLine().Split(' ');
            Calc(inputs, 0, 3);

            IEnumerable<int> result = Sum.Distinct();
            var dst = result.OrderBy(a => -a);

            Console.WriteLine(dst.ElementAt(2));

            Console.ReadKey();
        }

        static void Calc(string[] inputs, int sum, int level)
        {
            if(level == 0)
            {
                Sum.Add(sum);
                return;
            }
            foreach (var c in inputs)
            {
                List<string> _list = new List<string>(inputs);
                _list.Remove(c);
                inputs = _list.ToArray();

                Calc(inputs, sum + int.Parse(c), level - 1);
            }
        }
    }
}