using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        
        static long A;
        static long B;
        static long K;
        static long L;

        static void Main(string[] args)
        {

            //Console.SetIn(new StreamReader("input.txt"));

            long[] inputs = Array.ConvertAll(Console.ReadLine().Split(' '), new Converter<string, long>(s => long.Parse(s)));

            A = inputs[0];
            B = inputs[1];
            K = inputs[2];
            L = inputs[3];

            long answer = (K / L) * B + Math.Min(B, (K % L) * A);


            Console.WriteLine(answer);

        }
        
    }
}