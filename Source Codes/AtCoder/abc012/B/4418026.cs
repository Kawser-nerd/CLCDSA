using System;

namespace ABC012B
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            int hh = N / 3600;
            int mm = (N - 3600 * hh) / 60;
            int ss = (N - 3600 * hh - 60 * mm);
            if(hh < 10)
            {
                Console.Write($"0{hh}:");
            }
            else
            {
                Console.Write($"{hh}:");
            }
            if(mm < 10)
            {
                Console.Write($"0{mm}:");
            }
            else
            {
                Console.Write($"{mm}:");
            }
            if(ss < 10)
            {
                Console.Write($"0{ss}");
            }
            else
            {
                Console.Write($"{ss}");
            }
            Console.WriteLine();
        }
    }
}