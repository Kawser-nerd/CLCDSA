using System;

namespace ABC065A
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] bufs = Console.ReadLine().Split(' ');
            int X = Int32.Parse(bufs[0]);
            int A = Int32.Parse(bufs[1]);
            int B = Int32.Parse(bufs[2]);

            if (A >= B)
            {
                Console.WriteLine("delicious");
            }
            else if ((X + A) >= B)
            {
                Console.WriteLine("safe");
            }
            else
            {
                Console.WriteLine("dangerous");
            }

        }
    }
}