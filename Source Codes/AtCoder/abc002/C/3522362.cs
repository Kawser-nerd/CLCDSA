using System;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????1????
            string input = Console.ReadLine();

            // 3??????? p0(x0, y0), p1(x1, y1), p2(x2, y2)
            int x0 = int.Parse(input.Split(' ')[0]);
            int y0 = int.Parse(input.Split(' ')[1]);
            int x1 = int.Parse(input.Split(' ')[2]);
            int y1 = int.Parse(input.Split(' ')[3]);
            int x2 = int.Parse(input.Split(' ')[4]);
            int y2 = int.Parse(input.Split(' ')[5]);

            // p0?????????????
            x1 = x1 - x0;
            y1 = y1 - y0;
            x2 = x2 - x0;
            y2 = y2 - y0;

            // 3?(0, 0), (a, b), (c, d)???
            // S = |ad - bc| / 2
            double s = Math.Abs(x1 * y2 - y1 * x2) / 2.0;

            // ???????
            Console.WriteLine(s);
        }
    }
}