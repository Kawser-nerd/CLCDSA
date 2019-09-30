using System;

namespace atcoderB
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);

            int count = 0;
            for (int i = 0; i < n; i++)
            {
                int a = input[i];
                for (int j = a; j > 0; j--)
                {
                    if (a % 2 == 0 || a % 3 == 2)
                    {
                        count++;
                        a--;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            Console.WriteLine(count);
        }
    }
}