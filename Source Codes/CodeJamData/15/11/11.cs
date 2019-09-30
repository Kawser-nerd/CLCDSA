using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace r1apa
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader("../../input.txt"))
            using (var outputStream = new StreamWriter("../../output.txt", false, Encoding.Default))
            {
                var caseCount = int.Parse(inputStream.ReadLine());

                for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
                {
                    inputStream.ReadLine();
                    var samples = inputStream.ReadLine().Split().Select(s => int.Parse(s)).ToArray();

                    var differences = new List<int>();
                    var current = samples[0];
                    for (var i = 1; i < samples.Length; i++)
                    {
                        var next = samples[i];
                        if (next < current)
                        {
                            differences.Add(current - next);
                        }
                        current = next;
                    }
                    var method1 = differences.Sum();

                    var method2 = 0;
                    var bestSpeed = differences.Count > 0 ? differences.Max() : 0;
                    current = samples[0];
                    for (var i = 1; i < samples.Length; i++)
                    {
                        if (current < bestSpeed)
                            method2 += current;
                        else
                            method2 += bestSpeed;
                        current = samples[i];
                    }

                    outputStream.WriteLine("Case #{0}: {1} {2}", caseNumber, method1, method2);
                }
            }
        }
    }
}
