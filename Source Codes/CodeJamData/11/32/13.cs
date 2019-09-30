using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemA
{
    public class IndexAndDistance
    {
        public IndexAndDistance(long index, double distance)
        {
            Index = index;
            Distance = distance;
        }

        public long Index
        {
            get;
            set;
        }
        public double Distance
        {
            get;
            set;
        }

        public static bool operator <(IndexAndDistance c1, IndexAndDistance c2)
        {
            return c1.Distance < c2.Distance;
        }
        public static bool operator >(IndexAndDistance c1, IndexAndDistance c2)
        {
            return c1.Distance > c2.Distance;
        }
        public static bool operator ==(IndexAndDistance c1, IndexAndDistance c2)
        {
            return c1.Distance == c2.Distance;
        }
        public static bool operator !=(IndexAndDistance c1, IndexAndDistance c2)
        {
            return c1.Distance != c2.Distance;
        }
        public override bool Equals(object obj)
        {
            IndexAndDistance objAsSomething = obj as IndexAndDistance;

            if (objAsSomething == null)
                return false;

            return this.Distance.Equals(objAsSomething.Distance);
        }
    }
    
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader(@"D:\temp\CodeJam\ProblemA\Inputs\B-large.in"))
            {
                using (StreamWriter writer = new StreamWriter(@"D:\Temp\CodeJam\ProblemA\Outputs\B-large.out"))
                {
                    long inputCount = Convert.ToInt64(reader.ReadLine());

                    for (long i = 0; i < inputCount; i++)
                    {
                        string[] longegersStrings = reader.ReadLine().Split(' ');

                        long L = Convert.ToInt64(longegersStrings[0]);
                        long t = Convert.ToInt64(longegersStrings[1]);
                        long N = Convert.ToInt64(longegersStrings[2]);
                        long C = Convert.ToInt64(longegersStrings[3]);
                        
                        long[] repeatedDistances = new long[C];
                        for (long j = 0; j < C; j++)
                        {
                            repeatedDistances[j] = Convert.ToInt64(longegersStrings[4 + j]);
                        }

                        long[] distances = new long[N];
                        for (long j = 0; j < N; j++)
                        {
                            distances[j] = repeatedDistances[j % C];
                        }

                        double distanceAfterBoostersAreBuilt = 0.5 * t;

                        double distanceLeftToReachNextStar = 0;
                        long nextStarIndex = -1;
                        long sum = 0;
                        for (long star = 0; star < distances.Length; star++)
                        {
                            sum += distances[star];

                            if (sum > distanceAfterBoostersAreBuilt)
                            {
                                nextStarIndex = star;
                                distanceLeftToReachNextStar = sum - distanceAfterBoostersAreBuilt;
                                break;
                            }
                        }

                        //we finish traveling before the boosters are even built!
                        //Then boosters have no effect!
                        if (nextStarIndex == -1)
                        {
                            long sumOfAllDistances = 0;
                            for (long j = 0; j < distances.Length; j++)
                            {
                                sumOfAllDistances += distances[j];
                            }

                            long sillyResult = sumOfAllDistances * 2;

                            writer.WriteLine("Case #" + (i + 1).ToString() + ": " + sillyResult.ToString());
                            continue;
                        }

                        List<IndexAndDistance> distancesToBoost = new List<IndexAndDistance>();
                        distancesToBoost.Add(new IndexAndDistance(nextStarIndex, distanceLeftToReachNextStar));
                        for (long j = nextStarIndex + 1; j < N; j++)
                        {
                            distancesToBoost.Add(new IndexAndDistance(j, distances[j]));
                        }

                        //Take top L
                        var distancesByDistance = from distanceToBoost in distancesToBoost 
                                                       orderby distanceToBoost.Distance descending
                                                      select distanceToBoost;

                        List<IndexAndDistance> boostedOnes = new List<IndexAndDistance>();
                        List<IndexAndDistance> notBoostedOnes = new List<IndexAndDistance>();

                        long counter = 0;
                        foreach (IndexAndDistance iAndD in distancesByDistance)
                        {
                            if (counter < L)
                            {
                                boostedOnes.Add(iAndD);
                            }
                            else
                            {
                                notBoostedOnes.Add(iAndD);
                            }

                            counter++;
                        }

                        for (long j = 0; j < nextStarIndex; j++)
                        {
                            notBoostedOnes.Add(new IndexAndDistance(j, distances[j]));
                        }
                        notBoostedOnes.Add(new IndexAndDistance(nextStarIndex, distances[nextStarIndex] - distanceLeftToReachNextStar));

                        double totalTime = 0;
                        foreach (IndexAndDistance boosted in boostedOnes)
                        {
                            totalTime += boosted.Distance;
                        }
                        foreach (IndexAndDistance notBoosted in notBoostedOnes)
                        {
                            totalTime += (notBoosted.Distance * 2);
                        }


                        writer.WriteLine("Case #" + (i + 1).ToString() + ": " + ((long) totalTime).ToString());
                    }
                }
            }
        }
    }
}
