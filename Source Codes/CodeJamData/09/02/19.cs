using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Diagnostics;
using System.IO;

namespace GCJ
{
    class P3
    {
        /*
         * Built using Microsoft Visual Studio 2008
         * 
         * args [0]: input file name
         * args [1]: output file name
         * 
         * use 0 args for interactive mode, used for debugging + performance measure
         */
        static void Main(string[] args)
        {
            if (args.Length == 0)
            {
                string input;

                while ((input = Console.In.ReadLine()) != string.Empty)
                {
                    var sw = new Stopwatch();

                    sw.Start();

                    Console.Out.WriteLine("{0:0000}", Match(input));

                    sw.Stop();

                    Console.Out.WriteLine("Finished in {0} ms", sw.ElapsedMilliseconds);
                }
            }
            else if (args.Length == 2)
            {
                using (var reader = new StreamReader(new FileStream(args[0], FileMode.Open)))
                {
                    using (var writer = new StreamWriter(new FileStream(args[1], FileMode.Create)))
                    {
                        int inputSize = int.Parse(reader.ReadLine());

                        for (int i = 0; i < inputSize; i++)
                            writer.WriteLine("Case #{0}: {1:0000}", i + 1, Match(reader.ReadLine()));
                    }
                }
            }
        }

        static int Match(string input)
        {
            const string pattern = "welcome to code jam";

            var patternLength = pattern.Length;
            var match = new int[patternLength + 1];

            for (int i = 0; i < patternLength + 1; i++)
                match[i] = 0;

            match[0] = 1;

            foreach (var c in input)
            {
                for (int i = 0; i < patternLength; i++)
                {
                    if (c == pattern[i])
                    {
                        match[i + 1] += match[i];
                        match[i + 1] %= 10000;
                    }
                }
            }

            return match[patternLength];
        }
    }
}
