using System;
using System.Collections.Generic;
using System.Linq;

namespace Beginner008B
{
    class Program
    {
        static void Main(string[] args)
        {
            var votes = GetVotes(totalVotesCount: int.Parse(Console.ReadLine())).ToArray();

            var readerName = votes.Aggregate(new Dictionary<string, int>(), (accum, elem) =>
            {
                if (accum.ContainsKey(elem))
                {
                    accum[elem]++;
                }
                else
                {
                    accum.Add(elem, 1);
                }
                return accum;
            }).Aggregate((accum, elem) =>
            {
                if (accum.Value < elem.Value)
                {
                    accum = elem;
                }
                return accum;
            }).Key;

            Console.WriteLine(readerName);
        }

        private static IEnumerable<string> GetVotes(int totalVotesCount)
        {
            for (int i = 0; i < totalVotesCount; i++)
            {
                yield return Console.ReadLine();
            }
        }
    }
}