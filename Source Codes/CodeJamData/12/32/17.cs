using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace downhill
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader("..\\..\\input.txt"))
            using (var outputStream = new StreamWriter("..\\..\\output.txt.", false))
            {
                var totalCases = int.Parse(inputStream.ReadLine());

                for (var currentCase = 1; currentCase <= totalCases; currentCase++)
                {
                    var parameters = inputStream.ReadLine().Split();
                    var distanceToHome = decimal.Parse(parameters[0]);
                    var n = int.Parse(parameters[1]);
                    var positions = new decimal[n];
                    var times = new decimal[n];
                    for (var i = 0; i < n; i++)
                    {
                        var td = inputStream.ReadLine().Split().Select(s => decimal.Parse(s)).ToArray();
                        times[i] = td[0];
                        positions[i] = td[1];
                    }
                    var accelerations = inputStream.ReadLine().Split().Select(s => decimal.Parse(s)).ToArray();
                    outputStream.WriteLine("Case #{0}:", currentCase);

                    while (positions.Length >= 2 && positions[positions.Length-2] >= distanceToHome)
                    {
                        positions = positions.Take(positions.Length - 1).ToArray();
                        times = times.Take(times.Length - 1).ToArray();
                    }

                    if (positions[positions.Length - 1] > distanceToHome)
                    {
                        if (positions.Length > 1)
                        {
                            var ratio = (distanceToHome - positions[positions.Length - 2]) / (positions[positions.Length - 1] - positions[positions.Length - 2]);
                            var newTime = (times[times.Length - 1] - times[times.Length - 2]) * ratio + times[times.Length - 2];
                            positions[positions.Length - 1] = distanceToHome;
                            times[times.Length - 1] = newTime;
                        }
                        else
                        {
                            positions[0] = distanceToHome;
                            times[0] = 0;
                        }
                    }

                    foreach (var acceleration in accelerations)
                    {
                        var result = Simulate(acceleration, times, positions);
                        outputStream.WriteLine("{0:0.0000000}", result);
                    }
                }
            }
        }

        static decimal Simulate(decimal acceleration, decimal[] times, decimal[] positions)
        {
            var pointCount = times.Length;
            var myPosition = 0M;
            var mySpeed = 0M;
            var previousTime = 0M;
            for (var i = 1; i < pointCount; i++)
            {
                var timeElapsed = times[i] - previousTime;
                var howFarIHaveDriven = mySpeed * timeElapsed + 0.5M * acceleration * timeElapsed * timeElapsed;
                var myNewPosition = myPosition + howFarIHaveDriven;
                if (myNewPosition > positions[i])
                {
                    myPosition = positions[i];
                    mySpeed = (positions[i] - positions[i - 1]) / (times[i] - times[i - 1]);
                    previousTime = times[i];
                }
            }
            if (myPosition < positions[pointCount - 1])
            {
                var toGo = positions[pointCount - 1] - myPosition;
                var a = 0.5M * acceleration;
                var b = mySpeed;
                var c = -toGo;
                var timeNeeded = (-b + (decimal)Math.Sqrt((double)(b * b - 4.0M * a * c))) / (2.0M * a);
                return previousTime + timeNeeded;
            }
            else
            {
                return times[pointCount - 1];
            }
        }
    }
}
