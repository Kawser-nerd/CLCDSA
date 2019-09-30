using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CookieClicker
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
                    var inputValues = inputStream.ReadLine().Split().Select(s => double.Parse(s)).ToArray();
                    var R = 2.0d;
                    var C = inputValues[0];
                    var F = inputValues[1];
                    var X = inputValues[2];

                    var factor = X / C;

                    var previousSum = 0d;
                    var result = X / R;
                    var iteration = 0;
                    while (true)
                    {
                        previousSum += C / (R + iteration * F);
                        iteration++;
                        var newResult = X / (R + iteration * F) + previousSum;
                        if (newResult >= result)
                            break;
                        result = newResult;
                    }


                    outputStream.WriteLine("Case #{0}: {1:0.0000000}", caseNumber, result);
                }
            }
        }
    }
}
