using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJamFreecell
{
    class Program
    {
        public class GameObject
        {
            public UInt64 MaxGames;
            public UInt64 StatisticsToday;
            public UInt64 StatisticsAllTimes;
        }

        static void Main(string[] args)
        {
            List<GameObject> gameObjects = ReadData();
            StringBuilder strBuilder = new StringBuilder();

            for (int i = 0; i < gameObjects.Count(); i++)
            {
                GameObject gameObject = gameObjects[i];
                bool failure = false;

                bool found = false;
                if (gameObject.MaxGames >= 100)
                {
                    found = true;
                }
                else
                {
                    for (UInt64 j = 1; j < gameObject.MaxGames + 1; j++)
                    {
                        if ((j * gameObject.StatisticsToday) % 100 == 0)
                        {
                            found = true;
                        }
                    }
                }

                if ((!found) && (gameObject.MaxGames != 0))
                {
                    failure = true;
                }

                if ((gameObject.StatisticsToday != 0) && (gameObject.StatisticsAllTimes == 0))
                {
                    failure = true;
                }

                if (((gameObject.StatisticsToday != 100) && (gameObject.MaxGames != 0)) && (gameObject.StatisticsAllTimes == 100))
                {
                    failure = true;
                }

                strBuilder.AppendLine(string.Format("Case #{0}: {1}", i + 1, failure ? "Broken" : "Possible")); 
            }

            File.WriteAllText(@"C:\temp\outputFile1.txt", strBuilder.ToString());
        }

        static List<GameObject> ReadData()
        {
            List<GameObject> gameObjects = new List<GameObject>();

            string[] inputData = File.ReadAllLines(@"C:\temp\inputFile1.txt");

            int caseNumber = Convert.ToInt32(inputData[0]);

            int currentLine = 1;

            for (int i = 1; i < caseNumber + 1; i++)
            {
                GameObject gameObject = new GameObject();

                ReadInternal(inputData, currentLine, gameObject);

                currentLine += 1;

                gameObjects.Add(gameObject);
            }

            return gameObjects;
        }

        private static void ReadInternal(string[] inputData, int currentLine, GameObject gameObject)
        {
            string[] data = inputData[currentLine].Split(' ');

            gameObject.MaxGames = Convert.ToUInt64(data[0]);
            gameObject.StatisticsToday = Convert.ToUInt64(data[1]);
            gameObject.StatisticsAllTimes = Convert.ToUInt64(data[2]);
        }
    }
}
