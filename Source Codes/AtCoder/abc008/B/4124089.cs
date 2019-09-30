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

            var uniqueNames = votes.Distinct();
            var nameAndVotesList = uniqueNames.Select(name => new KeyValuePair<string, int>(name, votes.Count(vote => vote == name)));
            int maximumVotes = nameAndVotesList.Max(nameAndVotes => nameAndVotes.Value);
            var readerName = nameAndVotesList.First(nameAndVotes => nameAndVotes.Value == maximumVotes).Key;

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