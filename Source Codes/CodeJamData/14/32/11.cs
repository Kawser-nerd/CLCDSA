using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var sr = new StreamReader("input.txt"))
            using (var sw = new StreamWriter("output.txt") { AutoFlush = true })
            {
                Func<long[]> readIntArrLine = () => sr.ReadLine().Split(' ').Select(long.Parse).ToArray();

                var testCaseCount = readIntArrLine()[0];
                for (int iCase = 1; iCase <= testCaseCount; iCase++)
                {
                    var stringCount = (int)readIntArrLine()[0];
                    var strs = sr.ReadLine().Split(' ');

                    var okCount = 0;

                    var maxProb = 1;
                    for (int i = 1; i <= stringCount; i++)
                        maxProb *= i;

                    for (int i = 0; i < maxProb; i++)
                    {
                        var strsCopy = strs.ToList();

                        var strToCheck = "";
                        var iCopy = i;
                        for (int j = stringCount; j >= 1; j--)
                        {
                            var val = iCopy % j;
                            iCopy /= j;

                            strToCheck += strsCopy[val];
                            strsCopy.RemoveAt(val);
                        }

                        var lastChar = '.';
                        var okIndices = new bool[26];

                        var ok = true;
                        foreach (var c in strToCheck)
                        {
                            if (c != lastChar)
                            {
                                if (okIndices[c - 'a'])
                                {
                                    ok = false;
                                    break;
                                }

                                lastChar = c;
                                okIndices[c - 'a'] = true;
                            }
                        }

                        if (ok)
                            okCount++;
                    }

                    var resLine = String.Format(CultureInfo.InvariantCulture, "Case #{0}: {1}", iCase, okCount);
                    sw.WriteLine(resLine);
                    Console.WriteLine(resLine);
                }
            }
        }
    }
}
