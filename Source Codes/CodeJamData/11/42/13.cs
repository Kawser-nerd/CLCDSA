using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJamSpinningBlade
{
    class Program
    {
        public class GameObject
        {
            public int[,] Grid;
        }


        static void Main(string[] args)
        {
            List<GameObject> gameObjects = ReadData();

            StringBuilder strBuilder = new StringBuilder();

            for (int i = 0; i < gameObjects.Count(); i++)
            {
                GameObject gameObject = gameObjects[i];

                int final = 0;
                int minNum = Math.Min(gameObject.Grid.GetLength(0), gameObject.Grid.GetLength(1));


                try
                {
                    for (int k = minNum; k >= 3; k--)
                    {
                        for (int a = 0; a <= gameObject.Grid.GetLength(0) - k; a++)
                        {
                            for (int b = 0; b <= gameObject.Grid.GetLength(1) - k; b++)
                            {
                                if (IsGoolBlade(k, a, b, gameObject.Grid))
                                {
                                    final = k;
                                    throw new Exception();
                                }
                            }
                        }
                    }
                }
                catch (Exception)
                {
                }

                if (final == 0)
                {
                    strBuilder.AppendLine(string.Format("Case #{0}: {1}", i + 1, "IMPOSSIBLE"));
                }
                else
                {
                    strBuilder.AppendLine(string.Format("Case #{0}: {1}", i + 1, final));
                }
            }

            File.WriteAllText(@"C:\temp\newtemp\outputFile3.txt", strBuilder.ToString());

        }

        static bool IsGoolBlade(int size, int x, int y, int[,] arr)
        {
            double wx = 0;
            double wy = 0;

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if ((i == 0) && (j == 0))
                    {
                        continue;
                    }
                    if ((i == 0) && (j == size - 1))
                    {
                        continue;
                    }
                    if ((i == size - 1) && (j == 0))
                    {
                        continue;
                    }
                    if ((i == size - 1) && (j == size - 1))
                    {
                        continue;
                    }

                    wx += arr[i + x, j + y] * ((double)i + 0.5 - ((double)size / 2));
                    wy += arr[i + x, j + y] * ((double)j + 0.5 - ((double)size / 2));
                }
            }

            if ((wx == 0) && (wy == 0))
            {
                return true;
            }

            return false;
        }

        static List<GameObject> ReadData()
        {
            List<GameObject> gameObjects = new List<GameObject>();

            string[] inputData = File.ReadAllLines(@"C:\temp\newtemp\inputFile3.txt");

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
            string[] dataLine =  inputData[currentLine].Split(' ');

            int lines = Convert.ToInt32(dataLine[0]);
            int rows = Convert.ToInt32(dataLine[1]);

            currentLine++;

            gameObject.Grid = new int[lines,rows];

            for (int i = 0; i < lines; i++)
            {
                for (int j = 0; j < rows; j++)
                {
                    gameObject.Grid[i, j] = Convert.ToInt32(inputData[currentLine][j].ToString());
                }

                currentLine++;
            }
        }
    }
}
