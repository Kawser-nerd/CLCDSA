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
                //.AsParallel().AsOrdered()
                .Select(SolveCase).ToList();
            foreach (var caseNumber in Enumerable.Range(1, caseCount))
            {
                Console.Write("Case #{0}: ", caseNumber);
                WriteSolution(solutions[caseNumber - 1]);
            }
        }

        static Case ReadCase()
        {
            var theCase = new Case();
            var numbers = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
            theCase.AsteroidCount = numbers[0];
            theCase.MaxSecondsWithoutJumping = numbers[1];
            theCase.Asteroids = new List<Asteroid>();
            for (var i = 0; i < theCase.AsteroidCount; i++)
            {
                numbers = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
                theCase.Asteroids.Add(new Asteroid
                {
                    StartPosition = new Vector3
                    {
                        X = numbers[0],
                        Y = numbers[1],
                        Z = numbers[2]
                    },
                    Velocity = new Vector3
                    {
                        X = numbers[3],
                        Y = numbers[4],
                        Z = numbers[5]
                    }
                });
            }
            return theCase;
        }

        static Solution SolveCase(Case theCase)
        {
            var maxJumpsByAsteroid = new Dictionary<int, double>
            {
                { 0, 0 }
            };

            var pending = new HashSet<int>();
            pending.Add(0);

            while (pending.Any())
            {
                var sourceIndex = pending.First();
                pending.Remove(sourceIndex);
                for (var destinationIndex = 0; destinationIndex < theCase.AsteroidCount; destinationIndex++)
                {
                    var distance = GetDistance(theCase, sourceIndex, destinationIndex);
                    var maxDistance = Math.Max(maxJumpsByAsteroid[sourceIndex], distance);
                    if (!maxJumpsByAsteroid.ContainsKey(destinationIndex) || 
                        (maxJumpsByAsteroid[destinationIndex] > maxDistance))
                    {
                        maxJumpsByAsteroid[destinationIndex] = maxDistance;
                        pending.Add(destinationIndex);
                    }
                }
            }

            var solution = new Solution
            {
                MaxJump = maxJumpsByAsteroid[1]
            };
            return solution;
        }

        static double GetDistance(Case theCase, int index1, int index2)
        {
            var asteroid1 = theCase.Asteroids[index1];
            var asteroid2 = theCase.Asteroids[index2];
            var dx = asteroid1.StartPosition.X - asteroid2.StartPosition.X;
            var dy = asteroid1.StartPosition.Y - asteroid2.StartPosition.Y;
            var dz = asteroid1.StartPosition.Z - asteroid2.StartPosition.Z;
            return Math.Sqrt(dx * dx + dy * dy + dz * dz);
        }

        static void WriteSolution(Solution solution)
        {
            Console.WriteLine(solution.MaxJump.ToString("0.0000000"));
        }

        class Case
        {
            public int AsteroidCount;
            public int MaxSecondsWithoutJumping;
            public IList<Asteroid> Asteroids;
        }

        class Solution
        {
            public double MaxJump;
        }

        class Asteroid
        {
            public Vector3 StartPosition;
            public Vector3 Velocity;
        }

        struct Vector3
        {
            public double X;
            public double Y;
            public double Z;
        }
    }
}
