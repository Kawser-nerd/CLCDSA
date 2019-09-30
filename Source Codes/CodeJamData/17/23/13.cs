using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Threading;

using IharBury.Algorithms;

namespace ProblemC
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            var caseCount = int.Parse(Console.ReadLine());
            var cases = Enumerable.Range(1, caseCount).Select(_ => ReadCase()).ToList();
            var solutions = cases
                .AsParallel().AsOrdered()
                .Select(SolveCase).ToList();
            foreach (var caseNumber in Enumerable.Range(1, caseCount))
            {
                Console.Write("Case #{0}: ", caseNumber);
                WriteSolution(solutions[caseNumber - 1]);
            }
        }

        static Case ReadCase()
        {
            var values = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
            var cityCount = values[0];
            var deliveryCount = values[1];

            var cities = new List<(int MaxHorseDistance, int HorseSpeed)>(cityCount);
            for (var cityIndex = 0; cityIndex < cityCount; cityIndex++)
            {
                var horseValues = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
                cities.Add((horseValues[0], horseValues[1]));
            }

            var distances = new int?[cityCount, cityCount];
            for (var sourceCityIndex = 0; sourceCityIndex < cityCount; sourceCityIndex++)
            {
                var sourceCityDistances = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
                for (var destinationCityIndex = 0; destinationCityIndex < cityCount; destinationCityIndex++)
                    if (sourceCityDistances[destinationCityIndex] != -1)
                        distances[sourceCityIndex, destinationCityIndex] = sourceCityDistances[destinationCityIndex];
            }

            var deliveries = new List<(int SourceCityNumber, int DestinationCityNumber)>(deliveryCount);
            for (var deliveryIndex = 0; deliveryIndex < deliveryCount; deliveryIndex++)
            {
                var deliveryValues = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
                deliveries.Add((deliveryValues[0], deliveryValues[1]));
            }

            return new Case
            {
                Cities = cities,
                Distances = distances,
                Deliveries = deliveries
            };
        }

        static Solution SolveCase(Case theCase)
        {
            var deliveryTimes = new double?[theCase.Cities.Count, theCase.Cities.Count];
            for (var sourceCityIndex = 0; sourceCityIndex < theCase.Cities.Count; sourceCityIndex++)
            {
                var deliveryTimesFromSource = new double?[theCase.Cities.Count];
                var sourceCityHorseTasks = new Stack<(int cityIndex, double time, int distanceLeft)>();
                sourceCityHorseTasks.Push((sourceCityIndex, 0, theCase.Cities[sourceCityIndex].MaxHorseDistance));

                while (sourceCityHorseTasks.Count > 0)
                {
                    (var currentCityIndex, var currentTime, var currentDistanceLeft) = sourceCityHorseTasks.Pop();

                    for (var nextCityIndex = 0; nextCityIndex < theCase.Cities.Count; nextCityIndex++)
                    {
                        if ((nextCityIndex != sourceCityIndex) &&
                            (nextCityIndex != currentCityIndex) &&
                            (theCase.Distances[currentCityIndex, nextCityIndex] <= currentDistanceLeft))
                        {
                            var nextTime = currentTime +
                                theCase.Distances[currentCityIndex, nextCityIndex].Value /
                                    (double)theCase.Cities[sourceCityIndex].HorseSpeed;
                            var nextDistanceLeft = currentDistanceLeft - theCase.Distances[currentCityIndex, nextCityIndex].Value;
                            if ((deliveryTimesFromSource[nextCityIndex] == null) ||
                                (deliveryTimesFromSource[nextCityIndex] > nextTime))
                            {
                                deliveryTimesFromSource[nextCityIndex] = nextTime;
                                if (nextDistanceLeft > 0)
                                {
                                    sourceCityHorseTasks.Push((nextCityIndex, nextTime, nextDistanceLeft));
                                }
                            }
                        }
                    }
                }

                var betterRouteTasks = new Stack<(int sourceCityIndex, int destinationCityIndex)>();

                for (var destinationCityIndex = 0; destinationCityIndex < theCase.Cities.Count; destinationCityIndex++)
                {
                    if (deliveryTimesFromSource[destinationCityIndex] != null)
                    {
                        if ((deliveryTimes[sourceCityIndex, destinationCityIndex] == null) ||
                            (deliveryTimes[sourceCityIndex, destinationCityIndex] >
                                deliveryTimesFromSource[destinationCityIndex]))
                        {
                            deliveryTimes[sourceCityIndex, destinationCityIndex] = deliveryTimesFromSource[destinationCityIndex];
                            betterRouteTasks.Push((sourceCityIndex, destinationCityIndex));
                        }
                    }
                }

                while (betterRouteTasks.Count > 0)
                {
                    (var betterSourceCityIndex, var betterDestinationCityIndex) = betterRouteTasks.Pop();
                    
                    for (var grandSourceCityIndex = 0; grandSourceCityIndex < theCase.Cities.Count; grandSourceCityIndex++)
                    {
                        if ((grandSourceCityIndex != betterSourceCityIndex) &&
                            (grandSourceCityIndex != betterDestinationCityIndex) &&
                            (deliveryTimes[grandSourceCityIndex, betterSourceCityIndex] != null))
                        {
                            var betterTime = deliveryTimes[grandSourceCityIndex, betterSourceCityIndex] +
                                deliveryTimes[betterSourceCityIndex, betterDestinationCityIndex];
                            if ((deliveryTimes[grandSourceCityIndex, betterDestinationCityIndex] == null) ||
                                (deliveryTimes[grandSourceCityIndex, betterDestinationCityIndex] > betterTime))
                            {
                                deliveryTimes[grandSourceCityIndex, betterDestinationCityIndex] = betterTime;
                                betterRouteTasks.Push((grandSourceCityIndex, betterDestinationCityIndex));
                            }
                        }
                    }

                    for (var grandDestinationCityIndex = 0; grandDestinationCityIndex < theCase.Cities.Count; grandDestinationCityIndex++)
                    {
                        if ((grandDestinationCityIndex != betterSourceCityIndex) &&
                            (grandDestinationCityIndex != betterDestinationCityIndex) &&
                            (deliveryTimes[betterDestinationCityIndex, grandDestinationCityIndex] != null))
                        {
                            var betterTime = deliveryTimes[betterSourceCityIndex, betterDestinationCityIndex] +
                                deliveryTimes[betterDestinationCityIndex, grandDestinationCityIndex];
                            if ((deliveryTimes[betterSourceCityIndex, grandDestinationCityIndex] == null) ||
                                (deliveryTimes[betterSourceCityIndex, grandDestinationCityIndex] > betterTime))
                            {
                                deliveryTimes[betterSourceCityIndex, grandDestinationCityIndex] = betterTime;
                                betterRouteTasks.Push((betterSourceCityIndex, grandDestinationCityIndex));
                            }
                        }
                    }
                }
            }

            var solution = new Solution
            {
                MinDeliveryTimes = theCase.Deliveries
                    .Select(delivery => deliveryTimes[delivery.SourceCityNumber - 1, delivery.DestinationCityNumber - 1].Value)
                    .ToList()
            };
            return solution;
        }

        static void WriteSolution(Solution solution)
        {
            Console.WriteLine(string.Join(" ", solution.MinDeliveryTimes));
        }

        class Case
        {
            public IReadOnlyList<(int MaxHorseDistance, int HorseSpeed)> Cities;
            public int?[,] Distances;
            public IReadOnlyList<(int SourceCityNumber, int DestinationCityNumber)> Deliveries;
        }

        class Solution
        {
            public IReadOnlyList<double> MinDeliveryTimes;
        }
    }
}
