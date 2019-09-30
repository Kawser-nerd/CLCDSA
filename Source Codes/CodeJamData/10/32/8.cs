using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;


namespace tests
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputFile = args[0];
            var outputFile = args[1];

            using (var inputStream = new StreamReader(inputFile))
            using (var outputStream = new StreamWriter(outputFile, false))
            {
                var cases = int.Parse(inputStream.ReadLine());

                for (var caseNo = 1; caseNo <= cases; caseNo++)
                {
                    var inputData = inputStream.ReadLine().Split().Select(s => int.Parse(s)).ToArray();

                    var l = new BigInteger(inputData[0]);
                    var p = new BigInteger(inputData[1]);
                    var c = new BigInteger(inputData[2]);

                    var testCount = 0;
                    var currentTest = l * c;
                    while (currentTest < p)
                    {
                        testCount++;
                        currentTest *= c;
                    }

                    var minimum = 0;
                    while (testCount > 0)
                    {
                        minimum++;
                        testCount = testCount / 2;
                    }

                    outputStream.WriteLine("Case #{0}: {1}", caseNo, minimum);
                }
            }
        }
    }
}
