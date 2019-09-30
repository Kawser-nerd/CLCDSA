using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace b
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
                string settingString = inputReader.ReadLine();
                int boostNumber = int.Parse(settingString.Trim().Split(' ')[0]);
                int buildTime = int.Parse(settingString.Trim().Split(' ')[1]);
                int starNumber = int.Parse(settingString.Trim().Split(' ')[2]);
                int distPeriod = int.Parse(settingString.Trim().Split(' ')[3]);

                int[] distanceData = new int[distPeriod];
                for (int i = 0; i < distPeriod; ++i)
                {
                    distanceData[i] = int.Parse(settingString.Trim().Split(' ')[4 + i]);
                }

                int currentTravelTime = 0;
                bool isBoostStarted = false;
                List<int> processedTravelTime = new List<int>();
                List<int> unprocessedTravelTime = new List<int>();
                for (int i = 0; i < starNumber; ++i)
                {
                    if (isBoostStarted)
                    {
                        unprocessedTravelTime.Add(distanceData[i % distPeriod] * 2);
                    }
                    else
                    {
                        if (buildTime <= currentTravelTime + distanceData[i % distPeriod] * 2)
                        {
                            isBoostStarted = true;
                            processedTravelTime.Add(buildTime - currentTravelTime);
                            unprocessedTravelTime.Add(currentTravelTime + distanceData[i % distPeriod] * 2 - buildTime);
                        }
                        else
                        {
                            currentTravelTime += distanceData[i % distPeriod] * 2;
                            processedTravelTime.Add(distanceData[i % distPeriod] * 2);
                        }
                    }
                }

                unprocessedTravelTime.Sort();
                unprocessedTravelTime.Reverse();

                for (int i = 0; i < boostNumber; ++i)
                {
                    if (i >= unprocessedTravelTime.Count)
                    {
                        break;
                    }
                    unprocessedTravelTime[i] = unprocessedTravelTime[i] / 2;
                }

                // Print Result
                outputWriter.WriteLine(string.Format("Case #{0}: {1}", caseIndex, processedTravelTime.Sum() + unprocessedTravelTime.Sum()));
            }


            outputWriter.Close();
            outputFileStream.Close();
            inputReader.Close();
            inputFileStream.Close();
        }
    }
}
