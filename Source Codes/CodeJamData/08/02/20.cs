using System;

public class universe
{
    public static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());

        for (int cs = 1; cs <= N; cs++)
        {
            int T = int.Parse(Console.ReadLine());
            string[] ps = Console.ReadLine().Split();
            int NA = int.Parse(ps[0]);
            int NB = int.Parse(ps[1]);

            Trip[] trips = new Trip[NA + NB];
            for (int i = 0; i < NA; i++)
            {
                string[] parts = Console.ReadLine().Split();
                trips[i] = new Trip(parts[0], parts[1], true);
            }
            for (int i = 0; i < NB; i++)
            {
                string[] parts = Console.ReadLine().Split();
                trips[i + NA] = new Trip(parts[0], parts[1], false);
            }

            Array.Sort<Trip>(trips);
            int A = 0;
            int B = 0;
            for (int i = 0; i < trips.Length; i++)
            {
                if (trips[i].TripDone) continue;

                if (trips[i].FromA)
                    A++;
                else
                    B++;

                bool AtA = trips[i].FromA;
                int ActTime = trips[i].StartTime;
                while (true)
                {
                    int nextj = -1;
                    for (int j = 0; j < trips.Length; j++)
                    {
                        if (!trips[j].TripDone && trips[j].FromA == AtA && trips[j].StartTime >= ActTime)
                        {
                            nextj = j;
                            break;
                        }
                    }
                    if (nextj == -1) break;
                    trips[nextj].TripDone = true;
                    ActTime = trips[nextj].EndTime + T;
                    AtA ^= true;
                }
            }

            Console.WriteLine("Case #" + cs + ": " + A + " " + B);
        }
    }

    public class Trip : IComparable<Trip>
    {
        public int StartTime, EndTime;
        public bool FromA, TripDone = false;

        public Trip(string Start, string End, bool FromA)
        {
            this.FromA = FromA;
            StartTime = ParseTime(Start);
            EndTime = ParseTime(End);
        }

        public int CompareTo(Trip t2)
        {
            return StartTime - t2.StartTime;
        }

        public int ParseTime(string time)
        {
            string[] parts = time.Split(':');
            return int.Parse(parts[0]) * 60 + int.Parse(parts[1]);
        }
    }
}