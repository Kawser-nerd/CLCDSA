using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemB
{
    struct TimePosPair
    {
        public double Time;
        public double Pos;
    }
    class Program
    {
        static void Main(string[] args)
        {
            //var inputFilename = @"B-large.in";
            var inputFilename = @"B-small-attempt0.in";
            //var inputFilename = @".\TestInput.txt";
            var outputFilename = @".\TestOutput.txt";

            var inputLines = HelperFunctions.LoadLinesFromFile(inputFilename);
            var outputLines = ProcessProblem(inputLines);
            HelperFunctions.WriteLinesToFile(outputFilename, outputLines);
        }

        static List<string> ProcessProblem(List<string> inputLines)
        {
            List<string> output = new List<string>();

            int cases = int.Parse(inputLines[0]);
            //if (inputLines.Count != cases + 1)
            //    Debugger.Break(); // We have a parsing error!

            // Parse each test cases
            var testCase = 1;
            var N = 1;
            for (int i = 1; i < inputLines.Count; i += N + 2)
            {
                var items = inputLines[i].Split(' ');
                var distanceToHome = double.Parse(items[0]);
                N = int.Parse(items[1]);
                var A = int.Parse(items[2]);

                var timePosPairs = new List<TimePosPair>(N);

                for (int j = 1; j <= N; j++)
                {
                    var items2 = inputLines[i + j].Split(' ');
                    var time = double.Parse(items2[0]);
                    var position = double.Parse(items2[1]);

                    timePosPairs.Add(new TimePosPair() { Time = time, Pos = position });
                }

                var items3 = inputLines[i + N + 1].Split(' ');
                if (items3.Count() != A)
                    Debugger.Break(); // Wrong number of items?
                var accelerations = items3.Select(double.Parse);

                // Now process this test case
                var answers = ProcessTestCase(distanceToHome, timePosPairs, accelerations);

                // And store the output
                output.Add(string.Format("Case #{0}:", testCase));
                Debug.WriteLine(string.Format("Case #{0}:", testCase));
                foreach (var answer in answers)
                {
                    output.Add(answer);
                    Debug.WriteLine(answer);
                }

                testCase++;
            }

            return output;
        }

        static List<string> ProcessTestCase(double distanceToHome, List<TimePosPair> timePosPairs, IEnumerable<double> accelerations)
        {
            List<string> output = new List<string>();

            foreach (var acceleration in accelerations)
            {
                double earliestTimeHome = 0.0;
                double currentVelocity = 0.0;
                double currentPosition = 0.0;

                // Iterate through each time/pos pair of the other car
                for (int i = 0; i < timePosPairs.Count; i++)
                {
                    if (timePosPairs[i].Pos >= distanceToHome)
                    {
                        // if that car has passed our destination then figure out the remaining time needed to complete the journey taking into account our velocity at the end of the last step

                        // First work out how long it takes the other car to get to the destination as that is our min time
                        var timeForOtherCar = 0.0;
                        if (i != 0)
                        {
                            // First work out the proportion of the distance between the pairs needed
                            double distanceTraveled = timePosPairs[i].Pos - timePosPairs[i - 1].Pos;
                            double distanceNeeded = distanceToHome - timePosPairs[i - 1].Pos;
                            double proportion = distanceNeeded / distanceTraveled;

                            // then convert this to the proportion of time
                            double timeSpent = timePosPairs[i].Time - timePosPairs[i - 1].Time;
                            timeForOtherCar = timeSpent * proportion;
                        }

                        // Now calculate the amount of time it will take us to cover the required distance
                        var distance = (distanceToHome - currentPosition);
                        var timeTaken = CalculateTimeTaken(acceleration, currentVelocity, distance);

                        if (timeForOtherCar > timeTaken)
                        {
                            timeTaken = timeForOtherCar;
                        }

                        earliestTimeHome += timeTaken;
                        break;

                    }
                    else if (i > 0) // If i == 0 then this is the first entry for the other car so ignore it as it's just a starting position
                    {
                        // If that car is at a point before our destination then figure out how long it would take to keep up with it and the final velocity

                        // Time for the other car
                        var timeSpent = (timePosPairs[i].Time - timePosPairs[i - 1].Time);

                        var distance = (timePosPairs[i].Pos - currentPosition);
                        var calculatedTime = CalculateTimeTaken(acceleration, currentVelocity, distance);

                        // The resulting time will either be the time it takes for the other car if that is slower, or the calculated time
                        if (calculatedTime > timeSpent)
                        {
                            // shortest possible time
                            timeSpent = calculatedTime;
                        }

                        earliestTimeHome += timeSpent;
                        currentPosition = timePosPairs[i].Pos;
                        // V = v0 + 0.5*a*t
                        //currentVelocity = currentVelocity + (acceleration*timeSpent);
                        // V*V = u*u + 2*a*s
                        currentVelocity = Math.Sqrt((currentVelocity * currentVelocity) + (2 * acceleration * distance));
                    }
                }

                output.Add(earliestTimeHome.ToString("F7"));
            }

            return output;
        }

        static double CalculateTimeTaken(double acceleration, double currentVelocity, double distance)
        {
            // First put it into a quadratic equation
            // 0 = 0.5*a*t*t + v0*t - S
            // 0 = ax^2 + bx + c

            var a = 0.5 * acceleration;
            var b = currentVelocity;
            var c = -distance;

            // x = (-b [+|-] SQRT(b*b - 4ac)) / 2a
            var x1 = (-b + Math.Sqrt((b * b) - (4 * a * c))) / (2 * a);
            var x2 = (-b - Math.Sqrt((b * b) - (4 * a * c))) / (2 * a);

            if (x1 > 0.0)
            {
                return x1;
            }

            return x2;
        }

    }

    internal static class HelperFunctions
    {
        public static List<string> LoadLinesFromFile(string filepath)
        {
            List<string> result = new List<string>();
            using (var reader = new StreamReader(filepath))
            {
                while (!reader.EndOfStream)
                    result.Add(reader.ReadLine());
            }

            return result;
        }

        public static void WriteLinesToFile(string filepath, List<string> lines)
        {
            using (var writer = new StreamWriter(filepath))
            {
                foreach (var line in lines)
                {
                    writer.WriteLine(line);
                }
            }
        }
    }
}