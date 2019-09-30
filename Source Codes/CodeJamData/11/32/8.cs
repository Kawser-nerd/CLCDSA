using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ
{
    public class SpaceEmergency
    {
        public void Solve()
        {
            //var inputStream = new StreamReader(@"C:\Users\asaraswat\Downloads\B.in");
            //var outputStream = new StreamWriter(@"D:\Projects\GCJ\GCJ\B.out");

            //var inputStream = new StreamReader(@"C:\Users\asaraswat\Downloads\B-small-attempt0.in");
            //var outputStream = new StreamWriter(@"D:\Projects\GCJ\GCJ\B-small-attempt0.out");

            //var inputStream = new StreamReader(@"C:\Users\asaraswat\Downloads\A-small-attempt1.in");
            //var outputStream = new StreamWriter(@"D:\Projects\GCJ\GCJ\A-small-attempt1.out");

            //var inputStream = new StreamReader(@"C:\Users\asaraswat\Downloads\A-small-attempt1.in");
            //var outputStream = new StreamWriter(@"D:\Projects\GCJ\GCJ\A-small-attempt1.out");

            var inputStream = new StreamReader(@"C:\Users\asaraswat\Downloads\B-large.in");
            var outputStream = new StreamWriter(@"D:\Projects\GCJ\GCJ\B-large.out");

            Console.SetIn(inputStream);
            Console.SetOut(outputStream);

            int totalCases = int.Parse(Console.ReadLine());
            for (int cs = 1; cs <= totalCases; ++cs)
            {

                var ltnc = Console.ReadLine().Split(' ');

                long l = long.Parse(ltnc[0]);
                long t = long.Parse(ltnc[1]);
                long n = long.Parse(ltnc[2]);
                long c = long.Parse(ltnc[3]);

                List<long> intervals = new List<long>();

                for (int i = 0; i < c; ++i)
                    intervals.Add(long.Parse(ltnc[i + 4]));

                List<long> stars = new List<long>();
                stars.Add(0);
                int intervalIndex = 0;
                long lastStarPos = 0;
                while (stars.Count <= n)
                {
                    long newStarPos = lastStarPos + intervals[intervalIndex];
                    stars.Add(newStarPos);
                    lastStarPos = newStarPos;
                    intervalIndex = (intervalIndex + 1) % intervals.Count;
                }

                long longestDistance = intervals.Max();

                long totalTime = lastStarPos * 2;

                long boosterPos = t / 2;
                List<long> distances = new List<long>();

                int j = 0;
                while (j < stars.Count && stars[j] < boosterPos)
                    j++;

                while (j < stars.Count)
                {
                    distances.Add(stars[j] - boosterPos);
                    boosterPos = stars[j];
                    j++;
                }

                distances.Sort();
                distances.Reverse();

                for (int index = 0; index < l; ++index)
                    totalTime -= distances[index];

                Console.WriteLine("Case #{0}: {1}", cs, totalTime);
            }

            inputStream.Close();
            outputStream.Close();
        }
    }
}
