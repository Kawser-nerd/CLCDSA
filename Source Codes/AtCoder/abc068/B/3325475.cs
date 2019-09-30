using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC068B_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = int.Parse(Console.ReadLine());
            var result = 0;
            var maxCount = 0;
            if(n == 1) { Console.WriteLine("1");return; }
            for (var i = 2; i <= n; i += 2)
            {
                var count = 0;
                var x = i;
                while (x % 2 == 0)
                {
                    x = x / 2;
                    count++;
                }
                if (maxCount < count)
                {
                    maxCount = count;
                    result = i;

                }
            }
            
            Console.WriteLine(result);
        }
    }
}