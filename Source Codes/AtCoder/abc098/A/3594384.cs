using System;
using System.Linq;

namespace Atcoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //?????????
            string[] rawinput = Console.ReadLine().Split(' ');

            int A =int.Parse(rawinput[0]);int B = int.Parse(rawinput[1]);

            int add = A + B;int subtract = A - B;int maultiply= A * B;

            int[] input = {add,subtract,maultiply};
            Console.WriteLine(input.Max());

            

        }
    }
}