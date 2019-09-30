using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            double m = double.Parse(Console.ReadLine());
            m /= 1000;

            if (m < 0.1)
            {
                Console.WriteLine("00");
            }
            else if (m >= 0.1 && m <= 5)
            {
                if (m < 1)
                {
                    double v = m * 10;
                    string v2 = v.ToString();
                    Console.WriteLine("0" + v2);
                }
                else
                {
                    Console.WriteLine(m * 10);
                }
            }
            else if (m >= 6 && m <= 30)
            {
                Console.WriteLine(m + 50);
            }
            else if (m >= 35 && m <= 70)
            {
                Console.WriteLine((m - 30) / 5 + 80);
            }
            else
            {
                Console.WriteLine(89);
            }
        }
    }
}