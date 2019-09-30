using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace second
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader(@"..\..\input.txt"))
            using (var outputStream = new StreamWriter(@"..\..\output.txt"))
            {
                var caseCount = int.Parse(inputStream.ReadLine());
                for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
                {
                    inputStream.ReadLine();

                    var cars = inputStream.ReadLine().Split().ToList();

                    var shortCars = new List<string>();
                    var startingAndEndingLetters = new HashSet<char>();
                    foreach (var car in cars)
                    {
                        var firstLetter = car[0];
                        var lastLetter = car[car.Length - 1];
                        shortCars.Add(string.Concat(firstLetter, lastLetter));
                        startingAndEndingLetters.Add(firstLetter);
                        startingAndEndingLetters.Add(lastLetter);
                    }

                    var middleLetters = new HashSet<char>();
                    var valid = true;
                    foreach (var car in cars)
                    {
                        var firstLetter = car[0];
                        var lastLetter = car[car.Length - 1];

                        var i = 0;
                        while (i < car.Length && car[i] == firstLetter)
                            i++;
                        var j = car.Length - 1;
                        while (j >= 0 && car[j] == lastLetter)
                            j--;

                        var previous = firstLetter;
                        for (var k = i; k <= j; k++)
                        {
                            var current = car[k];
                            if (previous != current && middleLetters.Contains(current))
                                valid = false;
                            if (startingAndEndingLetters.Contains(current))
                                valid = false;
                            middleLetters.Add(current);
                            previous = current;
                        }

                        if (firstLetter == lastLetter && i < j)
                            valid = false;

                        if (!valid)
                            break;
                    }

                    if (!valid)
                    {
                        outputStream.WriteLine("Case #{0}: 0", caseNumber);
                    }
                    else
                    {
                        var subTrains = new List<string>();

                        while (shortCars.Count > 0)
                        {
                            var startingWagon = shortCars[0];
                            shortCars.RemoveAt(0);

                            var subTrain = startingWagon;

                            var nextLetter = startingWagon[1];
                            while (true)
                            {
                                var cloneWagons = shortCars.Where(s => s[0] == nextLetter && s[1] == nextLetter).ToList();
                                subTrain += string.Join("", cloneWagons);
                                shortCars = shortCars.Where(s => s[0] != nextLetter || s[1] != nextLetter).ToList();
                                var nextWagons = shortCars.Where(s => s[0] == nextLetter).ToList();
                                shortCars = shortCars.Where(s => s[0] != nextLetter).ToList();
                                if (nextWagons.Count > 1)
                                {
                                    valid = false;
                                    break;
                                }
                                else if (nextWagons.Count == 1)
                                {
                                    subTrain += nextWagons[0];
                                    nextLetter = nextWagons[0][1];
                                }
                                else
                                {
                                    break;
                                }
                            }

                            if (!valid)
                                break;

                            var previousLetter = startingWagon[0];
                            while (true)
                            {
                                var cloneWagons = shortCars.Where(s => s[0] == previousLetter && s[1] == previousLetter).ToList();
                                subTrain = string.Join("", cloneWagons) + subTrain;
                                shortCars = shortCars.Where(s => s[0] != previousLetter || s[1] != previousLetter).ToList();
                                var previousWagons = shortCars.Where(s => s[1] == previousLetter).ToList();
                                shortCars = shortCars.Where(s => s[1] != previousLetter).ToList();
                                if (previousWagons.Count > 1)
                                {
                                    valid = false;
                                    break;
                                }
                                else if (previousWagons.Count == 1)
                                {
                                    subTrain = previousWagons[0] + subTrain;
                                    previousLetter = previousWagons[0][0];
                                }
                                else
                                {
                                    break;
                                }
                            }

                            if (!valid)
                                break;

                            subTrains.Add(subTrain);
                        }

                        var seen = new HashSet<char>();
                        BigInteger combinations = new BigInteger(1);
                        foreach (var subTrain in subTrains)
                        {
                            if (!valid)
                                break;

                            char? previous = null;
                            foreach (var current in subTrain)
                            {
                                if (seen.Contains(current) && (!previous.HasValue || previous.HasValue && current != previous.Value))
                                {
                                    valid = false;
                                    break;
                                }
                                seen.Add(current);
                                previous = current;
                            }

                            var streak = 0;
                            previous = null;
                            for (var i = 0; i < subTrain.Length / 2; i++)
                            {
                                if (subTrain[i * 2] != subTrain[i * 2 + 1])
                                {
                                    combinations *= Factorial(streak);
                                    streak = 0;
                                    previous = null;
                                } 
                                else 
                                {
                                    if (!previous.HasValue || previous.HasValue && previous.Value != subTrain[i * 2])
                                    {
                                        combinations *= Factorial(streak);
                                        streak = 1;
                                        previous = subTrain[i * 2];
                                    }
                                    else
                                    {
                                        streak++;
                                    }
                                }
                            }
                            combinations *= Factorial(streak);
                        }

                        combinations *= Factorial(subTrains.Count);

                        if (!valid)
                            combinations = new BigInteger(0);

                        var result = combinations % 1000000007;

                        outputStream.WriteLine("Case #{0}: {1}", caseNumber, result);
                    }
                }
            }
        }

        static BigInteger Factorial(int n)
        {
            BigInteger result = new BigInteger(1);
            for (var i = 1; i <= n; i++)
            {
                result *= i;
            }
            return result;
        }
    }
}
