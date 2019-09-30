using System;

namespace AtCoder_20190218
{
    class Program
    {
        static void Main(string[] args)
        {
            string str_500 = Console.ReadLine();
            string str_100 = Console.ReadLine();
            string str_50 = Console.ReadLine();
            string str_total = Console.ReadLine();


            int Yen500 = int.Parse(str_500);
            int Yen100 = int.Parse(str_100);
            int Yen50 = int.Parse(str_50);
            int total = int.Parse(str_total);

            int count = 0;
            for (int a = 0; a <= Yen500; a++)
            {
                for (int b = 0; b <= Yen100; b++)
                {
                    for (int c = 0; c <= Yen50; c++)
                    {
                        if((a*500+b*100+c*50)==total)
                        {
                            count++;
                        }
                    }
                }
            }
                        Console.WriteLine(count);
        }
    }
}