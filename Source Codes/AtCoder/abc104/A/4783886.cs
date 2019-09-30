using System;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            MainStream();
        }
        static void MainStream()
        {
            int r = int.Parse(Console.ReadLine());

            if(r<1200)
            {
                Console.WriteLine("ABC");
            }
            else if(r<2800)
            {
                Console.WriteLine("ARC");
            }else
            {
                Console.WriteLine("AGC");
            }
        }


    }
}