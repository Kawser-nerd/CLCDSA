using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace GCJR1B
{
    class P1
    {
        static void Main(string[] args)
        {
            using (var reader = new StreamReader(File.OpenRead(args[0])))
            {
                using (var writer = new StreamWriter(File.Open(args[1], FileMode.Create)))
                {
                }
            }
        }
    }

    class P2
    {
        static void Main(string[] args)
        {
            using (var reader = new StreamReader(File.OpenRead(args[0])))
            {
                using (var writer = new StreamWriter(File.Open(args[1], FileMode.Create)))
                {
                    int numCases = int.Parse(reader.ReadLine());

                    for (int i = 1; i <= numCases; i++)
                    {
                        writer.WriteLine("Case #{0}: {1}", i, Next(reader.ReadLine()));
                    }
                }
            }
        }

        static string Next(string n)
        {
            var input = ("0" + n).ToCharArray().Reverse().ToArray();

            for (int i = 0; i < input.Length; i++)
            {
                if (input[i] > input[i + 1])
                {
                    var c = input[i + 1];
                    input[i + 1] = input[i];
                    input[i] = c;

                    char min = input.Take(i + 2).Where(x => x > input[i]).Min();

                    for (int j = 0; j <= i; j++)
                    {
                        if (input[j] == min)
                        {
                            input[j] = input[i + 1];
                            input[i + 1] = min;
                            break;
                        }
                    }

                    var sorted = input.Take(i + 1).OrderByDescending(x => x).ToArray();

                    for (int j = 0; j <= i; j++)
                        input[j] = sorted[j];

                    var output = new string(input.Reverse().ToArray());

                    return output[0] == '0' ? output.Substring(1) : output;
                }
            }

            throw new ApplicationException("should've never been reached");
        }
    }

    class P3
    {
        static void Main(string[] args)
        {
            using (var reader = new StreamReader(File.OpenRead(args[0])))
            {
                using (var writer = new StreamWriter(File.Open(args[1], FileMode.Create)))
                {
                }
            }
        }
    }
}
