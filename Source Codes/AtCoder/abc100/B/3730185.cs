using System;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            // ?????
            String a = Console.ReadLine();

            // ?????????????
            int D = int.Parse(a.Split(' ')[0]);
            int Tani = (int)(Math.Pow(100, D));
            int N = int.Parse(a.Split(' ')[1]);

            // 100????Skip??
            N += N / 100;

            int result = Tani * N;

            //??
            Console.WriteLine(result);
        }
    }
}