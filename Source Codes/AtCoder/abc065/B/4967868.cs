using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B___Trained
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var ai = Enumerable.Range(1, N).Select(_ => int.Parse(Console.ReadLine())).ToArray();
            int index = 1, count = 0;

            while (true)
            {
                index = ai[index - 1];
                count++;
                if (count == N) break;
                if (index == 2) break;
            }

            Console.WriteLine(count == N ? -1 : count);
        }
    }
}