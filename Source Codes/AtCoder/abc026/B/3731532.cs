using System;

namespace CircleN
{
    class Program
    {
        public static string Solve()
        {
            int row = int.Parse(Console.ReadLine());

            int radius = 0;
            int[] unko = new int[row];

            for (int i = 0; i < row; i++)
            {
                unko[i] = int.Parse(Console.ReadLine());
            }
            Array.Sort(unko);
            Array.Reverse(unko);

            for (int i = 0; i < row; i++)
            {

                if (i % 2 == 0)
                {
                    radius += (int)Math.Pow(unko[i], 2);
                }
                else if (i % 2 == 1)
                {
                    radius -= (int)Math.Pow(unko[i], 2);
                }
            }
            double area = radius * Math.PI;

            return area.ToString();
        }

        static void Main(string[] args)
        {
            Console.WriteLine(Solve());
        }
    }
}