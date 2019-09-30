using System;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????1???
            string input = Console.ReadLine();

            // l(??),s(??)???
            double s = double.Parse(input.Split(' ')[0]);
            double l = double.Parse(input.Split(' ')[1]);

            // ????12????0??????????
            double angleL = 360.0 * (l / 60.0);

            if (s >= 12)
            {
                s -= 12;
            }

            double angleS = 360.0 * (s / 12.0) + 30.0 * (l / 60.0);

            // ??????
            double output = Math.Abs(angleL - angleS);

            if(output > 180.0)
            {
                output = 360.0 - output;
            }

            // ???????
            Console.WriteLine(output);
        }
    }
}