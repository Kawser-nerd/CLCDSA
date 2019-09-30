using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????1???
            string input = Console.ReadLine();

            // ??????
            int townNum = int.Parse(input);

            // ?????
            string[] townNames = new string[townNum];

            int[] population = new int[townNum];

            // ?????
            for(int i = 0; i < townNum; i++)
            {
                input = Console.ReadLine();
                townNames[i] = input.Split(' ')[0];
                population[i] = int.Parse(input.Split(' ')[1]);
            }

            // ????
            int sum = 0;

            // ???????
            for(int i = 0; i < townNum; i++)
            {
                sum += population[i];
            }

            // ???????
            string cityName = "atcoder";

            for(int i = 0; i < townNum; i++)
            {
                if(population[i] > sum / 2)
                {
                    cityName = townNames[i];
                }
            }

            // ???????
            Console.WriteLine(cityName);
        }
    }
}