using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Threading.Tasks;

namespace _2016RoundTwoB
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
                        int columnRowWidth = int.Parse(inputFileReader.ReadLine());
                        bool[] isMissing = new bool[2501];

                        for (int index2 = 0; index2 < columnRowWidth * 2 - 1; ++index2)
                        {
                            string[] input = inputFileReader.ReadLine().Split(' ');
                            foreach (string number in input)
                            {
                                int numberParsed = int.Parse(number);
                                isMissing[numberParsed] = !isMissing[numberParsed];
                            }
                        }

                        List<int> isMissingList = new List<int>();
                        for (int index2 = 1; index2 < isMissing.Length; ++index2)
                        {
                            if (isMissing[index2])
                            {
                                isMissingList.Add(index2);
                            }
                        }
                        isMissingList.Sort();

                        outFileWriter.Write("Case #" + (index + 1) + ":");

                        foreach (int number in isMissingList)
                        {
                            outFileWriter.Write(" " + number);
                        }

                        outFileWriter.WriteLine();
                    }
                }
            }
        }
    }
}
