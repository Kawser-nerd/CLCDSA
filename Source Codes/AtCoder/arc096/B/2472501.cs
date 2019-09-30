using System;
using System.Collections.Generic;

namespace AtCoder.ARC096
{
    public struct Sushi
    {
        public long Distance { get; set; }
        public long CounterclockwiseDistance { get; set; }
        public int Calorie { get; set; }
    }

    public struct EfficientCandidate
    {
        public int Index { get; set; }
        public long CalorieSum { get; set; }
    }

    public class ARC096D
    {
        private int SushiNum { get; set; }

        private long LengthOfCounter { get; set; }

        private Sushi[] Sushis { get; set; }

        public static void Main(string[] args)
        {
            string[] lineArgs = Console.ReadLine().Split(' ');
            int sushiNum = int.Parse(lineArgs[0]);
            long lengthOfCounter = long.Parse(lineArgs[1]);
            Sushi[] sushis = new Sushi[sushiNum];
            for (int index = 0; index < sushiNum; index++)
            {
                lineArgs = Console.ReadLine().Split(' ');
                sushis[index] = new Sushi()
                {
                    Distance = long.Parse(lineArgs[0]),
                    Calorie = int.Parse(lineArgs[1]),
                };
                sushis[index].CounterclockwiseDistance = lengthOfCounter - sushis[index].Distance;
            }
            Array.Sort(sushis, (Sushi x, Sushi y) => x.Distance.CompareTo(y.Distance));
            Console.WriteLine(new ARC096D(sushiNum, lengthOfCounter, sushis).GetMaxCal());
        }

        public ARC096D(int sushiNum, long lengthOfCounter, Sushi[] sushis)
        {
            this.SushiNum = sushiNum;
            this.LengthOfCounter = lengthOfCounter;
            this.Sushis = sushis;
        }

        public long GetMaxCal()
        {
            // ??????????????????????????????????????????
            // ?????????????????????????
            Dictionary<int, EfficientCandidate> leftEfficient = new Dictionary<int, EfficientCandidate>();
            long calorieSum = 0;
            long caloriePrediction = 0;
            EfficientCandidate mostEfficient = new EfficientCandidate() { Index = -1, CalorieSum = 0 };
            for (int index = 0; index < this.SushiNum; index++)
            {
                caloriePrediction = calorieSum + this.Sushis[index].Calorie - this.Sushis[index].Distance;
                calorieSum += this.Sushis[index].Calorie;
                if (mostEfficient.CalorieSum - (mostEfficient.Index == -1 ? 0 : this.Sushis[mostEfficient.Index].Distance) < caloriePrediction)
                {
                    mostEfficient.Index = index;
                    mostEfficient.CalorieSum = calorieSum;
                }
                leftEfficient[index] = new EfficientCandidate(){ Index = mostEfficient.Index, CalorieSum = mostEfficient.CalorieSum };
            }

            // ???????????????????????????????????
            // ??????????????????
            calorieSum = 0;
            caloriePrediction = 0;
            mostEfficient = new EfficientCandidate() { Index = -1, CalorieSum = 0 };
            long maxCalorie = 0;
            long calorie = 0;
            long cost = 0;
            int leftIndex = 0;
            for (int index = this.SushiNum; 0 <= index; index --)
            {
                if (index < this.SushiNum)
                {
                    caloriePrediction = calorieSum + this.Sushis[index].Calorie - this.Sushis[index].CounterclockwiseDistance;
                    calorieSum += this.Sushis[index].Calorie;
                    if (mostEfficient.CalorieSum - (mostEfficient.Index == -1 ? 0 : this.Sushis[mostEfficient.Index].CounterclockwiseDistance) < caloriePrediction)
                    {
                        mostEfficient.Index = index;
                        mostEfficient.CalorieSum = calorieSum;
                    }
                }
                leftIndex = index - 1;
                calorie = 0;
                if (0 <= leftIndex && 0 <= leftEfficient[leftIndex].Index) calorie += leftEfficient[leftIndex].CalorieSum;
                if (0 <= mostEfficient.Index) calorie += mostEfficient.CalorieSum;
                cost = 0;
                if (0 <= leftIndex && 0 <= leftEfficient[leftIndex].Index) cost += this.Sushis[leftEfficient[leftIndex].Index].Distance * 2;
                if (0 <= mostEfficient.Index) cost += this.Sushis[mostEfficient.Index].CounterclockwiseDistance;
                maxCalorie = Math.Max(maxCalorie, calorie - cost);
                cost = 0;
                if (0 <= leftIndex && 0 <= leftEfficient[leftIndex].Index) cost += this.Sushis[leftEfficient[leftIndex].Index].Distance;
                if (0 <= mostEfficient.Index) cost += this.Sushis[mostEfficient.Index].CounterclockwiseDistance * 2;
                maxCalorie = Math.Max(maxCalorie, calorie - cost);
            }

            return maxCalorie;
        }

        private void DebugLog(string format, params object[] objects)
        {
#if DEBUG
            Console.Error.WriteLine(string.Format(format, objects));
#endif
        }
    }
}