using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace AirportWalkways
{
    class Program
    {
        static void Main(string[] args)
        {
            var inFile = String.Empty;
            var outFile = String.Empty;

            for (var i = 0; i < args.Length; i++)
            {
                switch (args[i])
                {
                    case "-i":
                        inFile = args[++i];
                        break;
                    case "-o":
                        outFile = args[++i];
                        break;
                }
            }

            if (!String.IsNullOrEmpty(inFile) && !String.IsNullOrEmpty(outFile))
            {
                using (var reader = new StreamReader(inFile))
                using (var writer = new StreamWriter(outFile))
                {
                    var p = new Program();
                    p.Run(reader, writer);
                }
            }
        }

        private void Run(TextReader reader, TextWriter writer)
        {
            var stopwatch = System.Diagnostics.Stopwatch.StartNew();

            var caseCount = int.Parse(reader.ReadLine());
            for (var i = 1; i <= caseCount; i++)
            {
                var answer = RunCase(reader);
                writer.WriteLine("Case #{0}: {1}", i, answer);
            }

            stopwatch.Stop();
            Console.WriteLine("{0:#,###}ms", stopwatch.ElapsedMilliseconds);
        }

        private double RunCase(TextReader reader)
        {
            var values = reader.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();

            var totalLength = values[0];
            var walkSpeed = values[1];
            var runSpeed = values[2];
            var runTime = (double)values[3];
            var walkwayCount = values[4];

            var remainLength = totalLength;
            List<Section> sections = new List<Section>();
            for (var i = 0; i < walkwayCount; i++)
            {
                values = reader.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                var length = values[1] - values[0];
                sections.Add(new Section(length, values[2] + walkSpeed));
                remainLength -= length;
            }
            if (remainLength > 0)
                sections.Add(new Section(remainLength, walkSpeed));

            var totalTime = 0d;
            double addedSpeed = runSpeed - walkSpeed;
            sections = sections.OrderBy(s => s.Speed).ToList();

            foreach (var s in sections)
            {
                if (runTime > 0d)
                {
                    var time = s.Length / (s.Speed + addedSpeed);
                    if (time > runTime)
                    {
                        var runLength = runTime * (s.Speed + addedSpeed);
                        totalTime += runTime;
                        runTime = 0;

                        totalTime += (s.Length - runLength) / s.Speed;
                    }
                    else
                    {
                        runTime -= time;
                        totalTime += time;
                    }
                }
                else
                {
                    totalTime += s.Length / s.Speed;
                }
            }

            return totalTime;
        }

        struct Section
        {
            public double Length;
            public double Speed;

            public Section(int length, int speed)
            {
                this.Length = length;
                this.Speed = speed;
            }
        }
    }
}
