using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJamDinner
{
    class Program
    {
        public class GameObject
        {
            public int PeopleCount;
        }

        public class LogBla
        {
            public int x;
            public int y;
        }

        static void Main(string[] args)
        {
            List<GameObject> gameObjects = ReadData();

            StringBuilder strBuilder = new StringBuilder();

            for (int i = 0; i < gameObjects.Count(); i++)
            {
                GameObject gameObject = gameObjects[i];
                bool[] arr = new bool[gameObject.PeopleCount];

                List<int> primals = new List<int>();
                int j, k;
                for (j = 0; j < arr.Length; j++)
                {
                    arr[j] = true;
                }

                j = 2;

                while (j < arr.Length)
                {
                    if (!arr[j])
                    {
                        j++;
                        continue;
                    }

                    if (arr[j])
                    {
                        for (k = 2 * j; k < arr.Length; k += j)
                        {
                            arr[k] = false;
                        }

                        j++;
                    }
                }

                for (j = 2; j < arr.Length; j++)
                {
                    if (arr[j])
                    {
                        primals.Add(j);
                    }
                }

                List<LogBla> logBla = new List<LogBla>();

                foreach (int prim in primals)
                {
                    logBla.Add(new LogBla() { x = prim, y = (int)Math.Log(gameObject.PeopleCount, prim) });
                }

                int x = (logBla.Sum((a) => a.y) + 1) - logBla.Count();

                if (gameObject.PeopleCount == 1)
                {
                    x = 0;
                }

                strBuilder.AppendLine(string.Format("Case #{0}: {1}", i + 1, x));
            }

            File.WriteAllText(@"C:\temp\newtemp\outputFile2.txt", strBuilder.ToString());

        }

        static List<GameObject> ReadData()
        {
            List<GameObject> gameObjects = new List<GameObject>();

            string[] inputData = File.ReadAllLines(@"C:\temp\newtemp\inputFile2.txt");

            int caseNumber = Convert.ToInt32(inputData[0]);

            int currentLine = 1;

            for (int i = 1; i < caseNumber + 1; i++)
            {
                GameObject gameObject = new GameObject();

                ReadInternal(inputData, ref currentLine, gameObject);

                gameObjects.Add(gameObject);
            }

            return gameObjects;
        }

        private static void ReadInternal(string[] inputData, ref int currentLine, GameObject gameObject)
        {
            gameObject.PeopleCount = Convert.ToInt32(inputData[currentLine]);

            currentLine++;
        }
    }
}
