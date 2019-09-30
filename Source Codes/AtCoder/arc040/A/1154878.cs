using System;

namespace arc040_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int red = 0;
            int brue = 0;
            for (int i = 0; i < n; i++)
            {
                string s = Console.ReadLine();
                for (int j = 0; j < n; j++)
                {
                    switch (s[j])
                    {
                        case ('R'):
                            {
                                red++;
                                break;
                            }
                        case ('B'):
                            {
                                brue++;
                                break;
                            }
                        default:
                            {
                                break;
                            }
                    }
                }
            }
            if (red > brue)
            {
                Console.WriteLine("TAKAHASHI");
            }
            else if (red < brue)
            {
                Console.WriteLine("AOKI");
            }
            else
            {
                Console.WriteLine("DRAW");
            }
        }
    }
}