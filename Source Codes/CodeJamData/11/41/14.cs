using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJamAirway
{
    class Program
    {
        public class WalkWay
        {
            public double Length;
            public double Speed;
        }

       public class GameObject
        {
            public double CorridorLength;
            public double WalkingSpeed;
            public double RunningSpeed;
            public double MaxRunTime;
            public List<WalkWay> WalkWays = new List<WalkWay>();
        }

        public class WalkwayComparer : Comparer<WalkWay>
        {
            public override int Compare(WalkWay x, WalkWay y)
            {
                if (x.Speed > y.Speed)
                {
                    return 1;
                }
                if (x.Speed < y.Speed)
                {
                    return -1;
                }

                return 0;
            }
        }


        static void Main(string[] args)
        {
            List<GameObject> gameObjects = ReadData();

            StringBuilder strBuilder = new StringBuilder();

            for (int i = 0; i < gameObjects.Count(); i++)
            {
                GameObject gameObject = gameObjects[i];

                gameObject.WalkWays.Sort(new WalkwayComparer());

                double walkWayLength = gameObject.WalkWays.Sum((walk) => (walk.Length));
                double normalWalkWay = gameObject.CorridorLength - walkWayLength;

                gameObject.WalkWays.Insert(0, new WalkWay() { Speed = 0, Length = normalWalkWay });

                double runTimeLeft = gameObject.MaxRunTime;

                double totalTime = 0;

                foreach (WalkWay walkway in gameObject.WalkWays)
                {
                    if (runTimeLeft == 0)
                    {
                        totalTime += (walkway.Length / (walkway.Speed + gameObject.WalkingSpeed));
                        continue;
                    }

                    double time = (walkway.Length / (walkway.Speed + gameObject.RunningSpeed));

                    if (time <= runTimeLeft)
                    {
                        totalTime += time;
                        runTimeLeft -= time;
                        continue;
                    }


                    double lengthLeft = walkway.Length - (runTimeLeft * (walkway.Speed + gameObject.RunningSpeed));
                    totalTime += runTimeLeft;
                    totalTime += (lengthLeft / (walkway.Speed + gameObject.WalkingSpeed));
                    runTimeLeft = 0;
                }

                strBuilder.AppendLine(string.Format("Case #{0}: {1}", i + 1, totalTime));
            }

            File.WriteAllText(@"C:\temp\newtemp\outputFile1.txt", strBuilder.ToString());
        }

        static List<GameObject> ReadData()
        {
            List<GameObject> gameObjects = new List<GameObject>();

            string[] inputData = File.ReadAllLines(@"C:\temp\newtemp\inputFile1.txt");

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
            string[] data = inputData[currentLine].Split(' ');

            gameObject.CorridorLength = Convert.ToInt32(data[0]);
            gameObject.WalkingSpeed = Convert.ToInt32(data[1]);
            gameObject.RunningSpeed = Convert.ToInt32(data[2]);
            gameObject.MaxRunTime = Convert.ToInt32(data[3]);

            int walkWays = Convert.ToInt32(data[4]);

            currentLine++;

            for (int i = 0; i < walkWays; i++)
            {
                WalkWay walkWay = new WalkWay();

                string[] newData = inputData[currentLine].Split(' ');

                walkWay.Length = Convert.ToInt32(newData[1]) - Convert.ToInt32(newData[0]);
                walkWay.Speed = Convert.ToInt32(newData[2]);

                gameObject.WalkWays.Add(walkWay);

                currentLine++;
            }

        }
    }
}
