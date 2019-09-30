using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

//Trochę siłowo, Andrzeju, ale liczę na to że się uda
//w końcu to 2.000.000 * 6 * 6 operacji, pikuś

namespace recycled
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
                    var input = inputStream.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
                    var lowerLimit = input[0];
                    var upperLimit = input[1];

                    var numberOfDigits = 0;
                    var divisor = 1;
                    var temp = lowerLimit;
                    while (temp > 0)
                    {
                        numberOfDigits++;
                        temp = temp / 10;
                        divisor *= 10;
                    }
                    divisor /= 10;
                    long pairCount = 0;

                    for (var i = lowerLimit; i <= upperLimit; i++)
                    {
                        var current = i;
                        var found = new List<int>();
                        for (var j = 0; j < numberOfDigits - 1; j++)
                        {
                            var topDigit = current / divisor;
                            current = (current - (topDigit * divisor)) * 10 + topDigit;

                            if (current > i && current <= upperLimit && !found.Contains(current))
                                pairCount++;

                            found.Add(current);
                        }
                    }

                    outputStream.WriteLine("Case #{0}: {1}", currentCase, pairCount);
                }
            }
        }
    }
}
