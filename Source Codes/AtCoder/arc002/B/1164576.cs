using System;

namespace arc002_2
{
    class Program
    {
        static void Main(string[] args)
        {
            DateTime date = DateTime.Parse(Console.ReadLine());
            for (; date.Year % (date.Month * date.Day) != 0;)
            {
                date = date.AddDays(1);
            }
            Console.WriteLine(date.ToString("yyyy/MM/dd"));
        }
    }
}