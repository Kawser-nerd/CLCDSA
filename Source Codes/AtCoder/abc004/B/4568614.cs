using System;

namespace atcoderB
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var data = new string[4, 4];

            for(int i = 0; i < 4; i++)
            {
                string[] input = Console.ReadLine().Split(' ');
                for(int j = 0; j < 4; j++)
                {
                    data[i, j] = input[j];
                }
            }

            for(int i = 3; i >= 0; i--)
            {
                string[] ans = new string[4];
                for(int j = 3; j >= 0; j--)
                {
                    ans[3 - j] = data[i, j];
                }
                Console.WriteLine(string.Join(" ", ans));
            }
        }
    }
}