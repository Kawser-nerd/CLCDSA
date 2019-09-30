using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;

    class Program
    {
        static void Main(string[] args)
        {
            var A = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
            Array.Sort(A);
            Console.WriteLine(A[0]*A[1]*(A[2]-A[2]/2)-(A[0] * A[1] * (A[2] / 2)));

        }
    }