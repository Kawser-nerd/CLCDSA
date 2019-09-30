using System;
using System.Collections.Generic;
using System.Linq;

namespace Beginner008B
{
    class Program
    {
        static void Main(string[] args)
        {
            var votes = new List<string>();

            for (int i = int.Parse(Console.ReadLine()); i != 0; i--)
            {
                votes.Add(Console.ReadLine());
            }

            var uniqueNames = votes.Distinct();
            var nameAndVotesList = uniqueNames.Select(name => new KeyValuePair<string, int>(name, votes.Count(vote => vote == name)));
            int maximumVotes = nameAndVotesList.Max(nameAndVotes => nameAndVotes.Value);
            var readerName = nameAndVotesList.First(nameAndVotes => nameAndVotes.Value == maximumVotes).Key;

            Console.WriteLine(readerName);
        }
    }
}