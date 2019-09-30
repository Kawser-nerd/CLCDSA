using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Threading.Tasks;

namespace _2016RoundOneA
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader inputFileReader = new StreamReader(args[0]))
            {
                using (StreamWriter outFileWriter = new StreamWriter("output.txt"))
                {
                    int count = int.Parse(inputFileReader.ReadLine());
                    for (int index = 0; index < count; ++index)
                    {
                        string input = inputFileReader.ReadLine();
                        string output = "";

                        foreach (char letter in input)
                        {
                            if (output == "")
                            {
                                output = letter.ToString();
                            }
                            else
                            {
                                int comparisonResult = output.Substring(0, 1).CompareTo(letter.ToString());
                                if (comparisonResult == 0 || comparisonResult < 0)
                                {
                                    output = letter + output;
                                }
                                else
                                {
                                    output = output + letter;
                                }
                            }
                        }

                        outFileWriter.WriteLine("Case #" + (index + 1) + ": " + output);
                    }
                }
            }
        }
    }
}
