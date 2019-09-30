using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cShaprTest
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine();

            var stack = new Stack<char>();
            int sum = 0;
            foreach(var c in s)
            {
                if (stack.Count == 0)
                {
                    stack.Push(c);
                    continue;
                }

                var value = stack.Peek();
                if (value == c)
                {
                    stack.Push(c);
                    continue;
                }

                stack.Pop();
                sum += 2;
            }
            Console.WriteLine(sum);
        }
    }
}