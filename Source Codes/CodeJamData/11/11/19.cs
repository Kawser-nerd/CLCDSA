using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class Program
    {
        static string _folderPath = Directory.GetCurrentDirectory() + @"/../../DataFiles/";

        static void Main(string[] args)
        {
            string question = "FreeCell";
            string inputFile = "L";  // "T", "S", "L"
            bool outputToFile = true;
            Action<IList<string>, TextWriter> solve = FreeCell.Run;

            var data = OpenDataFile(question + "_" + inputFile + ".txt");

            if (outputToFile)
            {
                using (StreamWriter writer = new StreamWriter(_folderPath + @"out.txt"))
                {
                    solve(data, writer);
                }
            }
            else
            {
                solve(data, null);
            }

            Console.WriteLine("Done!");

            Console.Read();
        }

        static IList<string> OpenDataFile(string filename)
        {
            var lines = new List<string>();

            using (StreamReader reader = new StreamReader(_folderPath + filename))
            {
                while (!reader.EndOfStream)
                {
                    lines.Add(reader.ReadLine());
                }
            }

            return lines;
        }

        static void Dif(string file1, string file2)
        {
            using (StreamReader reader1 = new StreamReader(_folderPath + file1))
            {
                using (StreamReader reader2 = new StreamReader(_folderPath + file2))
                {
                    int line = 1;
                    while (!reader1.EndOfStream && !reader2.EndOfStream)
                    {
                        string line1 = reader1.ReadLine();
                        string line2 = reader2.ReadLine();

                        if (line1 != line2)
                        {
                            Console.WriteLine("Line{0}\r\n{1}\r\n{2}", line, line1, line2);
                            return;
                        }

                        line++;
                    }

                    if (reader1.EndOfStream || reader2.EndOfStream)
                    {
                        Console.WriteLine("Extra lines: {0}", line);
                    }
                }
            }
        }

    }
}
