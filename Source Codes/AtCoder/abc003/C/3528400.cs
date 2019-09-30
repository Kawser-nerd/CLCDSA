using System;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????1????
            string input = Console.ReadLine();

            // ???N????????????K???
            int n = int.Parse(input.Split(' ')[0]);
            int k = int.Parse(input.Split(' ')[1]);

            // ??????1????
            input = Console.ReadLine();

            // ?????????????
            int[] movie = new int[n];

            // ???????
            for(int i = 0; i < n; i++)
            {
                movie[i] = int.Parse(input.Split(' ')[i]);
            }

            // ?????????
            Array.Sort(movie);

            // ????????
            double c = 0.0;

            // ???????????????????????????
            // ????????????????????
            for(int i = n - k; i < n; i++)
            {
                c = (c + movie[i]) / 2.0;
            }

            // ???????
            Console.WriteLine(c);
        }
    }
}