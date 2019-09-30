using System;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??N?????????
            Console.ReadLine();

            // ?????
            int divisionCnt = 0;

            // ?????????????
            string secondLine = Console.ReadLine();
            foreach (var a in secondLine.Split(' '))
            {
                for (int tar = int.Parse(a); tar % 2 == 0; tar /= 2)
                {
                    divisionCnt++;
                }
            }

            //??
            Console.WriteLine(divisionCnt);
        }
    }
}