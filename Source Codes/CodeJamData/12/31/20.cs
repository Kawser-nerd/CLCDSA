using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            using (TextReader input = new StreamReader("input.txt"))
            using (TextWriter output = new StreamWriter("output.txt"))
            //using (TextReader input = new StreamReader(Console.OpenStandardInput()))
            //using (TextWriter output = new StreamWriter(Console.OpenStandardOutput()))
            {
                Process(input, output);
            }
        }

        private static void Process(TextReader input, TextWriter output)
        {
            int numberOfCases = int.Parse(input.ReadLine());
            for (int currentCase = 0; currentCase < numberOfCases; currentCase++)
            {
                output.Write("Case #" + (currentCase + 1).ToString() + ": " );
                ProcessLine(input, output);
                output.WriteLine(string.Empty);
            }
        }

        private static string ProcessLine(TextReader input, TextWriter output)
        {
            int numberOfClasses = int.Parse(input.ReadLine());
            List<int>[] inheritList = new List<int>[numberOfClasses];
            List<int>[] inheritFromList = new List<int>[numberOfClasses];
            List<int>[] inheritToProcessList = new List<int>[numberOfClasses];
            bool[] isBase = new bool[numberOfClasses];
            for (int currentClass = 0; currentClass < numberOfClasses; currentClass++)
            {
                inheritList[currentClass] = new List<int>();
                inheritFromList[currentClass] = new List<int>();
                inheritToProcessList[currentClass] = new List<int>();
                isBase[currentClass] = true;
            }
            for (int currentClass = 0; currentClass < numberOfClasses; currentClass++)
            {
                string[] strings = input.ReadLine().Split(' ');
                int numberOfInherits = int.Parse(strings[0]);
                for (int index = 0; index < numberOfInherits; index++)
                {
                    int inherit = int.Parse(strings[index + 1]) - 1;
                    inheritList[inherit].Add(currentClass);
                    inheritFromList[currentClass].Add(inherit);
                    inheritToProcessList[currentClass].Add(inherit);
                }
            }
            bool moreWork = true;
            while (moreWork)
            {
                moreWork = false;
                for (int index = 0; index < numberOfClasses; index++)
                {
                    if (inheritToProcessList[index] != null && inheritToProcessList[index].Count == 0)
                    {
                        moreWork = true;
                        inheritToProcessList[index] = null;
                        foreach (int otherIndex in inheritList[index])
                        {
                            foreach (int insertValue in inheritFromList[index])
                            {
                                if (inheritFromList[otherIndex].Contains(insertValue))
                                {
                                    output.Write("Yes");
                                    return string.Empty;
                                }
                                else
                                {
                                    inheritFromList[otherIndex].Add(insertValue);
                                }
                            }
                            inheritToProcessList[otherIndex].Remove(index);
                        }
                    }
                }
            }
            output.Write("No");
            return string.Empty;
        }
    }
}
