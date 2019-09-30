using System;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ????????
            string input = Console.ReadLine();

            // ????????
            int startTemp = int.Parse(input.Split(' ')[0]);

            // ??????????
            int goalTemp = int.Parse(input.Split(' ')[1]);

            // ????
            int count = 0;

            // ?????????????
            int diff = (int)Math.Abs(goalTemp - startTemp);

            // ????? diff / 10 + (diff % 10)????????
            if (diff % 10 == 0)
            {
                count = diff / 10;
            }
            else if (diff % 10 == 1 || diff % 10 == 5)
            {
                count = diff / 10 + 1;
            }
            else if (diff % 10 == 2 || diff % 10 == 4 || diff % 10 == 6 || diff % 10 == 9)
            {
                count = diff / 10 + 2;
            }
            else
            {
                count = diff / 10 + 3;
            }

            // ???????
            Console.WriteLine(count);
        }
    }
}