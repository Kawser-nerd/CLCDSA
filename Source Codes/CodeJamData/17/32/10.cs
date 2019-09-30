using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    using TwoTuple = Tuple<int, int>;

    class Program
    {
        private StreamReader inputStream = new StreamReader("in.txt");
        private StreamWriter outputStream = new StreamWriter("out.txt");
        private double PI = Math.PI;
        private int minPerDay = 2 * 720;
        private int halfDay = 720;

        static void Main(string[] args)
        {
            new Program().Run();
        }

        public double AreaCircle(int radius)
        {
            return PI * radius * radius;
        }

        public double AreaBorder(int radius, int height) {
            return 2 * PI * radius * height;
        }

        public enum Who {
            Cameron,
            Jaimie
        }

        public class Activity {
            public Who Who;
            public int Start;
            public int End;
        }

        public class Comparer : IComparer<Activity>
        {
            public int Compare(Activity x, Activity y)
            {
                return x.Start.CompareTo(y.Start);
            }
        }

        public void OptimizeSame() {
        }
        public void Run()
        {
            string line = ReadString();
            int testCasesCount = int.Parse(line);
            for (int testCaseIndex = 1; testCaseIndex < testCasesCount + 1; ++testCaseIndex)
            {
                var activitiesCameron = new List<Activity>();
                var activitiesJaimie = new List<Activity>();
                var components = this.ReadIntegers();
                var camC = components[0];
                var jamC = components[1];
                int totalMinsCam = 0;
                int totalMinsJam = 0;
                for (int i = 0; i < camC; ++i)
                {
                    var newComponents = this.ReadIntegers();
                    var start = newComponents[0];
                    var end = newComponents[1];
                    activitiesCameron.Add(new Activity() { Who = Who.Cameron, Start = start, End = end });
                    totalMinsCam += end - start;
                }
                for (int i = 0; i < jamC; ++i)
                {
                    var newComponents = this.ReadIntegers();
                    var start = newComponents[0];
                    var end = newComponents[1];
                    activitiesJaimie.Add(new Activity() { Who = Who.Jaimie, Start = start, End = end });
                    totalMinsJam += end - start;
                }

                activitiesCameron.Sort(new Comparer());
                activitiesJaimie.Sort(new Comparer());
                var actitiviesBoth = activitiesCameron.Union(activitiesJaimie).ToList();
                actitiviesBoth.Sort(new Comparer());
                actitiviesBoth.Insert(0, new Activity() { Who = actitiviesBoth.Last().Who, Start = actitiviesBoth.Last().Start - minPerDay, End = actitiviesBoth.Last().End - minPerDay });
                List<int> activitiesBetweenCam = new List<int>();
                List<int> activitiesBetweenJaimie = new List<int>();
                List<int> activitiesBetweenCamToJaimie = new List<int>();
                List<int> activitiesBetweenJaimieToCam = new List<int>();

                int currentChanges = 0;
                for (int i = 0; i + 1 < actitiviesBoth.Count(); ++i) {
                    var current = actitiviesBoth[i].Who;
                    var next = actitiviesBoth[i + 1].Who;
                    var amountOfTime = actitiviesBoth[i + 1].Start - actitiviesBoth[i].End;
                    if (amountOfTime == 0) {
                        if (current != next) {
                            ++currentChanges;
                        }
                        continue;
                    }
                    if (current == Who.Jaimie)
                    {
                        if (next == Who.Jaimie)
                        {
                            activitiesBetweenJaimie.Add(amountOfTime);
                        }
                        else
                        {
                            ++currentChanges;
                            activitiesBetweenJaimieToCam.Add(amountOfTime);
                        }
                    }
                    else {
                        if (next == Who.Jaimie)
                        {
                            ++currentChanges;
                            activitiesBetweenCamToJaimie.Add(amountOfTime);
                        }
                        else
                        {
                            activitiesBetweenCam.Add(amountOfTime);
                        }
                    }
                }

                int freeTime = activitiesBetweenJaimieToCam.Sum() + activitiesBetweenCamToJaimie.Sum();

                activitiesBetweenJaimie.Sort();
                activitiesBetweenJaimie.Reverse();
                activitiesBetweenCam.Sort();
                activitiesBetweenCam.Reverse();

                if (totalMinsCam + activitiesBetweenCam.Sum() + freeTime < halfDay)
                {
                    int nextIndex = 0;
                    while (totalMinsCam + activitiesBetweenCam.Sum() + freeTime < halfDay)
                    {
                        totalMinsCam += activitiesBetweenJaimie[nextIndex++];
                        currentChanges += 2;
                    }
                }
                else if (totalMinsJam + activitiesBetweenJaimie.Sum() + freeTime < halfDay) {
                    int nextIndex = 0;
                    while (totalMinsJam + activitiesBetweenJaimie.Sum() + freeTime < halfDay)
                    {
                        totalMinsJam += activitiesBetweenCam[nextIndex++];
                        currentChanges += 2;
                    }
                }

                outputStream.WriteLine($"Case #{testCaseIndex}: {currentChanges}");
            }
            outputStream.Flush();
            outputStream.Close();
        }

        private string ReadString()
        {
            return this.inputStream.ReadLine();
        }

        private int[] ReadIntegers()
        {
            string line = this.ReadString();
            var components = line.Split(' ').Select(txt => int.Parse(txt)).ToArray();
            return components;
        }

        private double[] ReadDoubles()
        {
            string line = this.ReadString();
            var components = line.Split(' ').Select(txt => double.Parse(txt)).ToArray();
            return components;
        }
    }
}
