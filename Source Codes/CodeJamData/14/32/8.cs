using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Numerics;
using System.Text.RegularExpressions;
using JamHelpers;

namespace R1C_B
{
    class Program : ProgramBase
    {
        static void Main()
        {
            new Program().Run();
        }

        private const int Modulus = 1000000007;

        private BigInteger Factorial(int n)
        {
            return Product(Enumerable.Range(1, n).Select(i => (BigInteger)i));
        }

        private BigInteger Product(IEnumerable<BigInteger> sequence)
        {
            return sequence.Aggregate<BigInteger, BigInteger>(1, (current, i) => (current * i) % Modulus);
        }

        public string SimplyCar(string car)
        {
            return Regex.Replace(car, @"(.)\1+", @"$1");
        }

        public override void RunCase()
        {
            var count = ReadLine().ToInt();
            var cars = ReadLine().Split();
            Debug.Assert(count == cars.Length);
            var mixedCars = cars.Where(car => car.Distinct().Count() > 1).ToList();
            var uniformCars = cars.Where(car => !mixedCars.Contains(car)).ToList();
            var firstLetters = mixedCars.Select(car => car.First()).ToList();
            var lastLetters = mixedCars.Select(car => car.Last()).ToList();
            var joinedLetters = firstLetters.Intersect(lastLetters).ToList();
            var freeUniformCars = uniformCars.Where(car => !firstLetters.Contains(car.First()) && !lastLetters.Contains(car.First()));

            foreach (var letter in joinedLetters)
            {
                var firstCar = mixedCars.First(car => car.First() == letter);
                var lastCar = mixedCars.First(car => car.Last() == letter);
                if (firstCar == lastCar)
                {
                    WriteAnswer(0);
                    return;
                }
                var newCar = SimplyCar(lastCar + firstCar);
                mixedCars.Remove(firstCar);
                mixedCars.Remove(lastCar);
                mixedCars.Add(newCar);
            }

            var freeCars = mixedCars.Concat(freeUniformCars).ToList();
            var train = string.Join("", freeCars.OrderBy(car => car));
            train = SimplyCar(train);
            if (train.Length != train.Distinct().Count())
            {
                WriteAnswer(0);
                return;
            }

            BigInteger withinLetter = Product(uniformCars.Select(car => car.First()).GroupBy(c => c).Select(g => Factorial(g.Count())));
            BigInteger letterKinds = Factorial(freeCars.Select(SimplyCar).Distinct().Count());
            BigInteger result = Product(new[] { withinLetter, letterKinds });
            WriteAnswer(result);
        }
    }
}
