using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Round1BProblemC
{
    public class TestCase
    {
        public class City
        {
            public int HorseDistance;
            public int HorseSpeed;
            public int[] Distances;
        }

        public class Route
        {
            public int StartCity;
            public int EndCity;
        }

        public City[] Cities;
        public Route[] Routes;
    }

    class Program
    {
        static void Main(string[] args)
        {
            var testName = args[0];

            using (var reader = new StreamReader($"{testName}.in"))
            using (var writer = new StreamWriter($"{testName}.out"))
            {
                var count = int.Parse(reader.ReadLine());
                for (var caseId = 1; caseId <= count; caseId++)
                {
                    var line = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
                    int cityCount = line[0];
                    int routeCount = line[1];

                    var cities = new TestCase.City[cityCount];
                    for (var i = 0; i < cityCount; i++)
                    {
                        line = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
                        cities[i] = new TestCase.City();
                        cities[i].HorseDistance = line[0];
                        cities[i].HorseSpeed = line[1];
                    }

                    for (var i = 0; i < cityCount; i++)
                    {
                        line = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
                        cities[i].Distances = line;
                    }

                    var routes = new TestCase.Route[routeCount];
                    for (var i = 0; i < routeCount; i++)
                    {
                        line = reader.ReadLine().Split(' ').Select(int.Parse).Select(n => n - 1).ToArray();
                        routes[i] = new TestCase.Route { StartCity = line[0], EndCity = line[1] };
                    }

                    var testCase = new TestCase { Cities = cities, Routes = routes };
                    var distance = FindSmallestDistance(testCase);

                    writer.WriteLine("Case #{0}: {1}", caseId, string.Join(" ", distance));
                    writer.Flush();
                }
            }
        }

        struct PotentialRoute
        {
            public int DistanceToRide;
            public double RemainingTime;
        }

        class PotentialRoutes
        {
            public List<PotentialRoute> Routes = new List<PotentialRoute>();

            public bool Updated;

            public bool Add(int distance, double remainingTime)
            {
                if (distance > 1000000000)
                {
                    return false;
                }

                foreach (var route in this.Routes)
                {
                    if (route.DistanceToRide <= distance && route.RemainingTime <= remainingTime)
                    {
                        return false;
                    }
                }

                this.Updated = true;
                this.Routes.RemoveAll(route => route.DistanceToRide >= distance && route.RemainingTime >= remainingTime);
                this.Routes.Add(new PotentialRoute { DistanceToRide = distance, RemainingTime = remainingTime });

                return true;
            }
        }

        private static double[] FindSmallestDistance(TestCase testCase)
        {
            return testCase.Routes.Select(r => Solve(testCase.Cities, r.StartCity, r.EndCity)).ToArray();
        }

        private static double Solve(TestCase.City[] cities, int startCity, int endCity)
        {
            var routes = Enumerable.Range(0, cities.Length).Select(i => new PotentialRoutes()).ToArray();

            routes[endCity].Add(0, 0);

            bool anyChanged = true;
            while (anyChanged)
            {
                anyChanged = false;
                for (var destIndex = 0; destIndex < cities.Length; destIndex++)
                {
                    if (routes[destIndex].Updated)
                    {
                        routes[destIndex].Updated = false;

                        for (var sourceIndex = 0; sourceIndex < cities.Length; sourceIndex++)
                        {
                            var sourceCity = cities[sourceIndex];

                            var distance = sourceCity.Distances[destIndex];
                            if (distance != -1)
                            {
                                foreach (var potentialRoute in routes[destIndex].Routes)
                                {
                                    // take our horse
                                    var routeDistance = potentialRoute.DistanceToRide + distance;
                                    if (routeDistance <= sourceCity.HorseDistance)
                                    {
                                        var time = (double)routeDistance / (double)sourceCity.HorseSpeed;
                                        anyChanged |= routes[sourceIndex].Add(0, potentialRoute.RemainingTime + time);
                                    }

                                    // keep current horse
                                    var totalDistance = distance + potentialRoute.DistanceToRide;
                                    anyChanged |= routes[sourceIndex].Add(totalDistance, potentialRoute.RemainingTime);
                                }
                            }
                        }
                    }
                }
            }

            return routes[startCity].Routes.Single(r => r.DistanceToRide == 0).RemainingTime;
        }
    }
}
