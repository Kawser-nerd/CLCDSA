using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GCJ
{
    class PonyExpress
    {
        Horse[] horses;
        double[,] distances;
        Mail[] orders;

        public int CityCount => distances.GetLength(0);

        double[,] CalculateSingleHorseTravelTimes()
        {
            double[,] times = new double[this.CityCount, this.CityCount];
            for (int start = 0; start < CityCount; start++) {
                for (int end = 0; end < CityCount; end++)
                    times[start, end] = double.PositiveInfinity;
                times[start, start] = 0;
            }
            for (int start = 0; start < CityCount; start++) {
                var startingPoints = new Stack<Ride>();
                startingPoints.Push(new Ride {
                    Horse = horses[start],
                    Time = 0,
                    City = start,
                });
                while (startingPoints.Count > 0) {
                    var lastRide = startingPoints.Pop();
                    for (int end = 0; end < CityCount; end++) {
                        var newRide = lastRide;
                        if (lastRide.City == end)
                            continue;

                        double distance = distances[lastRide.City, end];
                        if (lastRide.Horse.Distance < distance)
                            continue;

                        newRide.Time += distance / lastRide.Horse.Speed;
                        if (newRide.Time > times[start, end])
                            continue;

                        times[start, end] = newRide.Time;
                        newRide.City = end;
                        newRide.Horse.Distance -= distance;
                        if (newRide.Horse.Distance > 0.5)
                            startingPoints.Push(newRide);
                    }
                }
            }
            return times;
        }

        public void WriteAnswer(TextWriter writer)
        {
            writer.WriteLine(string.Join(" ", this.Solve().Select(v => v.ToString())));
        }

        public double[] Solve()
        {
            double[,] oneHorseTime = CalculateSingleHorseTravelTimes();
            double[] results = new double[this.orders.Length];
            for(int i = 0; i < results.Length; i++) {
                var order = this.orders[i];
                var times = Enumerable.Repeat(double.PositiveInfinity, CityCount).ToArray();
                times[order.Source] = 0;
                var startingPoints = new Stack<Ride>();
                startingPoints.Push(new Ride { City = order.Source, Horse = this.horses[order.Source], Time = 0 });
                while(startingPoints.Count > 0) {
                    var lastRide = startingPoints.Pop();
                    for(int next = 0; next < CityCount; next++) {
                        if (next == lastRide.City)
                            continue;

                        var newRide = new Ride();
                        double time = oneHorseTime[lastRide.City, next];
                        if (double.IsPositiveInfinity(time))
                            continue;

                        newRide.Time = lastRide.Time + time;
                        if (newRide.Time > times[next])
                            continue;

                        times[next] = newRide.Time;
                        newRide.City = next;
                        startingPoints.Push(newRide);
                    }
                }
                results[i] = times[order.Dest];
            }
            return results;
        }

        public static PonyExpress Read(TextReader reader)
        {
            int[] nq = reader.ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
                .Select(int.Parse).ToArray();
            int cityCount = nq[0];
            int orderCount = nq[1];
            Horse[] horses = new Horse[cityCount];
            for (int i = 0; i < cityCount; i++) {
                horses[i] = Horse.Read(reader);
            }
            double[,] distances = new double[cityCount, cityCount];
            for (int from = 0; from < cityCount; from++) {
                int[] singleSourceDistances = reader.ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
                    .Select(int.Parse).ToArray();
                for (int to = 0; to < cityCount; to++)
                    distances[from, to] = singleSourceDistances[to] < 0 ? double.PositiveInfinity : singleSourceDistances[to];
            }
            Mail[] orders = new Mail[orderCount];
            for (int orderIndex = 0; orderIndex < orderCount; orderIndex++) {
                orders[orderIndex] = Mail.Read(reader);
            }
            return new PonyExpress {
                distances = distances,
                horses = horses,
                orders = orders,
            };
        }

        struct Mail
        {
            public int Source;
            public int Dest;

            internal static Mail Read(TextReader reader)
            {
                int[] startEnd = reader.ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
                    .Select(int.Parse).ToArray();
                return new Mail { Source = startEnd[0]-1, Dest = startEnd[1]-1 };
            }
        }

        struct Ride
        {
            public Horse Horse;
            public double Time;
            public int City;
        }

        struct Horse
        {
            public double Distance;
            public double Speed;

            internal static Horse Read(TextReader reader)
            {
                int[] distanceSpeed = reader.ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
                    .Select(int.Parse).ToArray();
                return new Horse { Distance = distanceSpeed[0], Speed = distanceSpeed[1] };
            }
        }
    }
}
