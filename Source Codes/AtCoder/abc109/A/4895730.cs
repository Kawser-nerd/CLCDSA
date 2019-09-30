using System;

namespace Wandbox
{
    class Program
    {
        static void Main(string[] args)
        {
            var imp = Console.ReadLine().Split(' ');
            int A = int.Parse(imp[0]);
            int B = int.Parse(imp[1]);
            if(A%2==0||B%2==0)
            {
            Console.Write("No");
            }
            else
            {
            Console.Write("Yes");
            }
        }
    }
}