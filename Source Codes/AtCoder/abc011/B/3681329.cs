using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine();

            var head = s.Remove(1,s.Length - 1);
            var remain = s.Remove(0, 1);
            if (remain.Length != 0)
            {
                Console.WriteLine(head.ToUpper() + remain.ToLower());
            }
            else
            {
                Console.WriteLine(head.ToUpper());
            }
        }
    }
}