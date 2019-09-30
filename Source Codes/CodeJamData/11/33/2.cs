using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace c_small
{
    class Program
    {
        static void Main(string[] args)
        {
            Stream inputFileStream = new FileStream("input.txt", FileMode.Open, FileAccess.Read);
            TextReader inputReader = new StreamReader(inputFileStream);

            Stream outputFileStream = new FileStream("output.txt", FileMode.Create, FileAccess.Write);
            TextWriter outputWriter = new StreamWriter(outputFileStream);


            string caseNumberString = inputReader.ReadLine();
            int caseNumber = int.Parse(caseNumberString.Trim());
            for (int caseIndex = 1; caseIndex <= caseNumber; ++caseIndex)
            {
                string pointString = inputReader.ReadLine();
                int harmonyNumber = int.Parse(pointString.Trim().Split(' ')[0]);
                int minFreq = int.Parse(pointString.Trim().Split(' ')[1]);
                int maxFreq = int.Parse(pointString.Trim().Split(' ')[2]);

                int[] frequencyList = new int[harmonyNumber];
                string harmonyString = inputReader.ReadLine();
                string[] frequencyToken = harmonyString.Trim().Split(' ');
                for (int i = 0; i < harmonyNumber; ++i)
                {
                    frequencyList[i] = int.Parse(frequencyToken[i]);
                }

                bool isAnswerFound = false;
                for (int i = minFreq; i <= maxFreq; ++i)
                {
                    bool isNoAnswer = false;
                    foreach (int currentHarmony in frequencyList)
                    {
                        if (currentHarmony % i != 0 && i % currentHarmony != 0)
                        {
                            isNoAnswer = true;
                            break;
                        }
                    }

                    if (!isNoAnswer)
                    {
                        isAnswerFound = true;
                        outputWriter.WriteLine(string.Format("Case #{0}: {1}", caseIndex, i));
                        break;
                    }
                }

                // Print Result
                if (!isAnswerFound)
                    outputWriter.WriteLine(string.Format("Case #{0}: NO", caseIndex));
            }


            outputWriter.Close();
            outputFileStream.Close();
            inputReader.Close();
            inputFileStream.Close();
        }
    }
}
