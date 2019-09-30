using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ProblemC
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            var caseCount = int.Parse(Console.ReadLine());
            for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
            {
                var kidCount = int.Parse(Console.ReadLine());
                var bestFriendsByKid = Console
                    .ReadLine()
                    .Split(' ')
                    .Select((lineItem, itemIndex) => Tuple.Create(itemIndex + 1, int.Parse(lineItem)))
                    .ToDictionary(x => x.Item1, x => x.Item2);
                var mutualFriends = FindMutualFriends(bestFriendsByKid, kidCount);
                var maxCycleSize = RemoveCycles(bestFriendsByKid, kidCount);
                var vectorSizesEndingWithKids = GetVectorSizesEndingWithKids(bestFriendsByKid, kidCount);
                var maxWithMutualFriends = mutualFriends
                    .Select(m => (int?)(
                        (vectorSizesEndingWithKids.ContainsKey(m.Item1) ? vectorSizesEndingWithKids[m.Item1] : 0) +
                        (vectorSizesEndingWithKids.ContainsKey(m.Item2) ? vectorSizesEndingWithKids[m.Item2] : 0) + 2))
                    .Sum() ?? 0;
                var result = Math.Max(maxCycleSize, maxWithMutualFriends);

                Console.WriteLine("Case #{0}: {1}", caseNumber, result);
            }
        }

        private static Dictionary<int, int> GetVectorSizesEndingWithKids(Dictionary<int, int> bestFriendsByKid, int kidCount)
        {
            var vectorEndsByKid = new Dictionary<int, int>();
            var vectorSizesByKid = new Dictionary<int, int>();
            while (bestFriendsByKid.Any())
            {
                foreach (var bestFriendByKid in bestFriendsByKid.ToList())
                {
                    var bestFriend = bestFriendByKid.Value;
                    if (!bestFriendsByKid.ContainsKey(bestFriend))
                    {
                        var kid = bestFriendByKid.Key;
                        int vectorEnd;
                        int vectorSize;
                        if (vectorEndsByKid.ContainsKey(bestFriend))
                        {
                            vectorEnd = vectorEndsByKid[bestFriend];
                            vectorSize = vectorSizesByKid[bestFriend] + 1;
                        }
                        else
                        {
                            vectorEnd = bestFriend;
                            vectorSize = 1;
                        }
                        vectorEndsByKid.Add(kid, vectorEnd);
                        vectorSizesByKid.Add(kid, vectorSize);
                        bestFriendsByKid.Remove(kid);
                    }
                }
            }

            return vectorSizesByKid
                .Select(vectorSizeByKid => new
                {
                    Size = vectorSizeByKid.Value,
                    End = vectorEndsByKid[vectorSizeByKid.Key]
                })
                .GroupBy(x => x.End)
                .ToDictionary(g => g.Key, g => g.Max(x => x.Size));
        }

        private static int RemoveCycles(Dictionary<int, int> bestFriendsByKid, int kidCount)
        {
            var maxCycleSize = 0;
            for (var kid = 1; kid <= kidCount; kid++)
            {
                var removedCycleSize = TryRemoveCycle(bestFriendsByKid, kid);
                if (removedCycleSize > maxCycleSize)
                    maxCycleSize = removedCycleSize;
            }
            return maxCycleSize;
        }

        private static int TryRemoveCycle(Dictionary<int, int> bestFriendsByKid, int kidInCycle)
        {
            if (bestFriendsByKid.ContainsKey(kidInCycle))
            {
                var visitedKids = new HashSet<int>();
                var currentBestFriend = bestFriendsByKid[kidInCycle];
                while (true)
                {
                    if (currentBestFriend == kidInCycle)
                    {
                        bestFriendsByKid.Remove(kidInCycle);
                        foreach (var visitedKid in visitedKids)
                            bestFriendsByKid.Remove(visitedKid);
                        return visitedKids.Count + 1;
                    }

                    if (visitedKids.Contains(currentBestFriend))
                        return 0;

                    if (!bestFriendsByKid.ContainsKey(currentBestFriend))
                        return 0;

                    visitedKids.Add(currentBestFriend);
                    currentBestFriend = bestFriendsByKid[currentBestFriend];
                }
            }
            return 0;
        }

        private static List<Tuple<int, int>> FindMutualFriends(Dictionary<int, int> bestFriendsByKid, int kidCount)
        {
            var result = new List<Tuple<int, int>>();
            for (var kid = 1; kid < kidCount; kid++)
            {
                var mutualFriendCandidate = bestFriendsByKid[kid];
                if ((mutualFriendCandidate > kid) && (bestFriendsByKid[mutualFriendCandidate] == kid))
                    result.Add(Tuple.Create(kid, mutualFriendCandidate));
            }
            return result;
        }
    }
}
