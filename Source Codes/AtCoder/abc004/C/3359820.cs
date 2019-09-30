using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());

            //???????
            var firstletter = ((N / 5) % 6) + 1;
            var array = Enumerable.Range(0, 6).Select(x => (x + firstletter - 1) % 6 + 1).ToArray();

            //????????????
            foreach(var i in Enumerable.Range(0, N % 5))
            {
                var tmp = array[i+1];
                array[i + 1] = array[i];
                array[i] = tmp;
            }

            Console.WriteLine(string.Join("", array));
        }
    }
}