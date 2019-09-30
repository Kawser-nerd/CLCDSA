using System;
namespace Practice0203
{
    class Program
    {
        static void Main(string[] args)
        {
            var km = double.Parse(Console.ReadLine()) / 1000;
            if (km < 0.1)
                Console.WriteLine("00");
            else if (0.1 <= km && km <= 5)
                Console.WriteLine("{0:00}", km * 10);
            else if (6 <= km && km <= 30)
                Console.WriteLine(km + 50);
            else if (35 <= km && km <= 70)
                Console.WriteLine((km - 30) / 5 + 80);
            else
                Console.WriteLine("89");
        }
    }
}