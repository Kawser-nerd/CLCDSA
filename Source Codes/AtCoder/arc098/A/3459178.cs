using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]C - Attention

            //???????????
            Console.SetIn(new StreamReader(Console.OpenStandardInput(262144),
                                           Console.InputEncoding, false, 262144));

            int n = int.Parse(Console.ReadLine().TrimEnd());
            string line = Console.ReadLine().TrimEnd();

            int allEastern = CountEasternPeople(n, line);

            int min = CountMinimumTurnedPeople(n, line, allEastern);
            Console.WriteLine(min);
        }

        static int CountEasternPeople(int n, string line)
        {
            //[summary]????????????????
            var people = line.ToCharArray();
            return people.Count(c => c == 'E');
        }

        static int CountMinimumTurnedPeople(int n, string line, int allEastern)
        {
            int min = allEastern;
            int allWestern = 0;

            for (int i = 1; i < n; i++)
            {
                if (line[i - 1] == 'W')
                {
                    allWestern++;
                }
                else
                {
                    allEastern--;
                }

                int turnedPeople = allWestern + allEastern;

                if (line[i] == 'E')
                {
                    turnedPeople--;
                }

                if (turnedPeople == 0)
                {
                    return 0;
                }
                else if (turnedPeople < min)
                {
                    min = turnedPeople;
                }
            }

            return min;            
        }
    }
}