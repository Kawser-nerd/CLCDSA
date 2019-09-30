using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace codejam_2011_round2
{
    public class Planet
    {
        public int Number { get; set; }
        public List<Planet> ConnectedPlanents = new List<Planet>();
    }

    public class Path
    {
        public Planet CurrentPlanet;
        public List<Planet> FollowedPath = new List<Planet>();
        public List<Planet> ThreatenList = new List<Planet>();
    }

    class Program
    {
        static void Main(string[] args)
        {
            // Checks
            if (args.Length != 1)
            {
                Console.WriteLine("Specify input file");
                Console.ReadLine();
                return;
            }

            StreamReader reader = new StreamReader(args[0]);
            int T = int.Parse(reader.ReadLine());
            for (int current = 1; current <= T; ++current)
            {
                int[] values = reader.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                int P = values[0];
                int W = values[1];

                Dictionary<int, Planet> planetRoster = Enumerable.Range(0, P).Select(x => new Planet() { Number = x }).ToDictionary(x => x.Number);
                foreach (string connectionString in reader.ReadLine().Split(' '))
                {
                    int[] connection = connectionString.Split(',').Select(x => int.Parse(x)).ToArray();
                    Planet planetA = planetRoster[connection[0]];
                    Planet planetB = planetRoster[connection[1]];
                    if (!planetA.ConnectedPlanents.Contains(planetB))
                    {
                        planetA.ConnectedPlanents.Add(planetB);
                    }
                    if (!planetB.ConnectedPlanents.Contains(planetA))
                    {
                        planetB.ConnectedPlanents.Add(planetA);
                    }
                }
                Path path = new Path() { CurrentPlanet = planetRoster[0], FollowedPath = new List<Planet>() { planetRoster[0] }, ThreatenList = planetRoster[0].ConnectedPlanents.ToList() };
                List<Path> pathsList = new List<Path>() { path };
                while (!pathsList.SelectMany(x => x.CurrentPlanet.ConnectedPlanents).Any(x => x.Number == 1))
                {
                    List<Path> newPaths = new List<Path>();
                    foreach (Path currentPath in pathsList)
                    {
                        newPaths.AddRange(ExpandLevel(currentPath));
                    }
                    pathsList = newPaths;
                }

                path = pathsList.Where(x => x.CurrentPlanet.ConnectedPlanents.Any(y => y.Number == 1)).OrderBy(x => x.FollowedPath.Count).ThenByDescending(x => x.ThreatenList.Count).First();

                int c = path.FollowedPath.Count - 1;
                int t = path.ThreatenList.Count;

                Console.WriteLine("Case #{0}: {1} {2}", current, c, t);
            }
        }

        private static IEnumerable<Path> ExpandLevel(Path path)
        {
            foreach (Planet child in path.CurrentPlanet.ConnectedPlanents.Where(x => !path.FollowedPath.Contains(x)))
            {
                List<Planet> followedPath = path.FollowedPath.ToList();
                followedPath.Add(child);
                List<Planet> threatenedList = path.ThreatenList.Union(child.ConnectedPlanents).Where(x => !followedPath.Contains(x)).ToList();
                yield return new Path() { CurrentPlanet = child, FollowedPath = followedPath, ThreatenList = threatenedList };
            }
        }
    }
}
