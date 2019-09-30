using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;


namespace ropes
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
                    var lineCount = int.Parse(inputStream.ReadLine());

                    var ropes = new Rope[lineCount];
                    for (var i = 0; i < lineCount; i++)
                    {
                        var points = inputStream.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
                        ropes[i] = new Rope() { Start = points[0], End = points[1] };
                    }

                    ropes = ropes.OrderBy(r => r.Start).ToArray();

                    var result = 0;
                    for (var i = 0; i < ropes.Length; i++)
                        for (var j = i + 1; j < ropes.Length; j++)
                            if (ropes[i].End > ropes[j].End)
                                result++;

                    outputStream.WriteLine("Case #{0}: {1}", caseNo, result);
                }
            }
        }

        public class Rope
        {
            public int Start;
            public int End;
        }
    }
}
