using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Program
    {
        private StreamReader inputStream = new StreamReader("in.txt");
        private StreamWriter outputStream = new StreamWriter("out.txt");

        static void Main(string[] args)
        {
            var program = new Program();
            program.RunAllTestCases();
            program.outputStream.Flush();
            program.outputStream.Close();
        }

        public void RunAllTestCases()
        {
            int testCasesCount = this.ReadInteger();
            foreach (var testCaseIndex in Enumerable.Range(1, testCasesCount))
            {
                string testCaseResult = this.RunTestCase();
                outputStream.WriteLine($"Case #{testCaseIndex}: {testCaseResult}");
            }
        }

        private string RunTestCase()
        {
            var components = this.ReadIntegers();
            var trainLength = components[0];
            var customersCount = components[1];
            var ticketsCount = components[2];
            var customers = new Dictionary<int, List<int>>();
            // trainLength = Math.Min(trainLength, customers);
            foreach (var c in Enumerable.Range(0, customersCount))
            {
                customers[c] = new List<int>();
            }

            int longestCustomer = 0;

            var seats = new int[trainLength];
            for (int i = 0; i < ticketsCount; ++i)
            {
                components = this.ReadIntegers();
                var seatIndex = components[0] - 1;
                var customerIndex = components[1] - 1;
                customers[customerIndex].Add(seatIndex);
                seats[seatIndex]++;
                longestCustomer = Math.Max(longestCustomer, customers[customerIndex].Count());
            }

            int promotionsCount, minRides;
            minRides = longestCustomer;
            GenerateRides(longestCustomer, seats, ref minRides, out promotionsCount);
            GenerateRides(longestCustomer, seats, ref minRides, out promotionsCount);

            string result = $"{minRides} {promotionsCount}";
            return result;
        }

        private static void GenerateRides(int longestCustomer, int[] seats, ref int minRides, out int promotionsCount)
        {
            int freeSeatsPreviousRows = 0;
            promotionsCount = 0;
            for (int seatIndex = 0; seatIndex < seats.Length; ++seatIndex)
            {
                int placesRequired = seats[seatIndex];
                if (placesRequired > minRides)
                {
                    placesRequired -= minRides;
                    int take = Math.Min(freeSeatsPreviousRows, placesRequired);
                    freeSeatsPreviousRows -= take;
                    promotionsCount += take;
                    placesRequired -= take;

                    if (placesRequired > 0) {
                        var newRides = (placesRequired + seatIndex) / (seatIndex + 1);
                        minRides += newRides;
                        freeSeatsPreviousRows += newRides * (seatIndex + 1);
                        take = Math.Min(freeSeatsPreviousRows, placesRequired);
                        freeSeatsPreviousRows -= take;
                        placesRequired -= take;
                        promotionsCount += take;
                        Debug.Assert(placesRequired == 0);
                    }
                }
                else if (placesRequired < minRides)
                {
                    freeSeatsPreviousRows += minRides - placesRequired;
                }
            }
        }

        private string ReadString()
        {
            return this.inputStream.ReadLine();
        }

        private string[] ReadStrings(string separator)
        {
            return this.inputStream.ReadLine().Split(new [] { separator }, StringSplitOptions.None);
        }

        private T[] ReadComponents<T>(string separator, Func<string, T> parseComponent)
        {
            return this.ReadStrings(separator).Select(element => parseComponent(element)).ToArray();
        }

        private int ReadInteger()
        {
            return int.Parse(this.ReadString());
        }

        private double ReadDouble()
        {
            return double.Parse(this.ReadString());
        }

        private int[] ReadIntegers()
        {
            return this.ReadComponents(" ", int.Parse);
        }

        private double[] ReadDoubles()
        {
            return this.ReadComponents(" ", double.Parse);
        }
    }
}
