using System;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            float m = float.Parse(Console.ReadLine());
            int vv = 0;
            if (m >= 100 && m <= 5000)
            {
                vv = (int)((m / 1000) * 10);
            }
            else if (m >= 6000 && m <= 30000)
            {
                vv = (int)((m / 1000) + 50);
            }
            else if (m >= 35000 && m <= 70000)
            {
                vv = (int)((((m / 1000) - 30) / 5) + 80);
            }
            else if (m > 70000)
            {
                vv = 89;
            }
            Console.WriteLine(vv.ToString("D2"));
        }
    }
}