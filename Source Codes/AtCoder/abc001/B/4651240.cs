using System;

namespace BeginnerContest_001_B
{
    class Program
    {
        static int CalculateVV(double dist)
        {
            int vv = -1;

            if (dist < 0.1) vv = 0;
            else if (0.1 <= dist && dist <= 5) vv = int.Parse(Convert.ToString(dist *= 10));
            else if (6 <= dist && dist <= 30) vv = int.Parse(Convert.ToString(dist + 50));
            else if (35 <= dist && dist <= 70) vv = int.Parse(Convert.ToString( ((dist - 30) / 5) + 80));
            else vv = 89;
            return vv;
        }

        static void Main(string[] args)
        {
            double km = double.Parse(Console.ReadLine()) / 1000;
            Console.WriteLine("{0:D2}", CalculateVV(km));
        }
    }
}