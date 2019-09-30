using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;
// http://www.themissingdocs.net/downloads/TMD.Algo.0.0.5.0.zip
using TMD.Algo.Algorithms;
using TMD.Algo.Collections;
using TMD.Algo.Collections.Generic;

namespace GCJ12R1AQ3
{
    class Q3
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(args[0]);
            List<string> output = new List<string>();
            int cases = int.Parse(lines[0]);
            int index = 1;
            for (int i = 0; i < cases; i++)
            {
                string[] bits = lines[index].Split(' ');
                int N = int.Parse(bits[0]);
                bool[] rightLane = new bool[N];
                int[] speed = new int[N];
                int[] start = new int[N];
                for (int j = 0; j < N; j++)
                {
                    index++;
                    string[] bits2 = lines[index].Split(' ');
                    if (bits2[0][0] == 'R')
                        rightLane[j] = true;
                    speed[j] = int.Parse(bits2[1]);
                    start[j] = int.Parse(bits2[2]);
                }
                output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(rightLane, speed, start)));
                index++;
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private class Car
        {
            public bool RightLane;
            public int Speed;
            public int Start;
        }

        private class CollisionPoint
        {
            public Car FastCar;
            public Car SlowCar;
            public Fraction Time;
        }

        private static string Solve(bool[] rightLane, int[] speed, int[] start)
        {
            Car[] cars = new Car[rightLane.Length];
            for (int i = 0; i < rightLane.Length; i++)
            {
                cars[i] = new Car() { RightLane = rightLane[i], Speed = speed[i], Start = start[i] };
            }

            // Sort by descending speed.
            Array.Sort(cars, (a, b) => b.Speed.CompareTo(a.Speed));
            List<CollisionPoint> potentialCollisions = new List<CollisionPoint>();
            for (int i = 0; i < cars.Length; i++)
            {
                for (int j = i + 1; j < cars.Length; j++)
                {
                    if (cars[i].Speed.Equals(cars[j].Speed))
                        continue;
                    int deltaSpeed = cars[i].Speed - cars[j].Speed;
                    int distToCollision = cars[j].Start - (cars[i].Start + 5);
                    if (distToCollision >= 0)
                    {
                        Fraction time = (Fraction)distToCollision / (Fraction)deltaSpeed;
                        potentialCollisions.Add(new CollisionPoint() { FastCar = cars[i], SlowCar = cars[j], Time = time });
                    }
                }
            }
            if (potentialCollisions.Count == 0)
                return "Possible";
            potentialCollisions.Sort((a, b) => a.Time.CompareTo(b.Time));
            Fraction cap = potentialCollisions[potentialCollisions.Count-1].Time + (Fraction)1;
            for (int i = 0; i < potentialCollisions.Count; i++)
            {
                for (int j = i + 1; j < potentialCollisions.Count; j++)
                {
                    if (potentialCollisions[i].Time != potentialCollisions[j].Time)
                        break;
                    if (potentialCollisions[i].SlowCar == potentialCollisions[j].SlowCar)
                        if (potentialCollisions[i].Time < cap)
                            cap = potentialCollisions[i].Time;
                    if (potentialCollisions[i].FastCar == potentialCollisions[j].FastCar)
                        if (potentialCollisions[i].Time < cap)
                            cap = potentialCollisions[i].Time;
                }
            }
            Fraction best = Best(potentialCollisions, cars, 0);
                if (best > cap)
                    best = cap;
            if (best > potentialCollisions[potentialCollisions.Count-1].Time)
                return "Possible";
            return best.ToDouble().ToString();
        }

        private static Fraction Best(List<CollisionPoint> potentials, Car[] cars, int considering)
        {
            if (considering >= potentials.Count)
                return potentials[potentials.Count-1].Time + (Fraction)1;
            CollisionPoint point = potentials[considering];
            if (point.FastCar.RightLane != point.SlowCar.RightLane)
            {
                Fraction first = Best(potentials, cars, considering + 1);
                if (CanSwap(cars, point.FastCar, point.Time) && CanSwap(cars, point.SlowCar, point.Time))
                {
                    point.FastCar.RightLane = !point.FastCar.RightLane;
                    point.SlowCar.RightLane = !point.SlowCar.RightLane;
                    Fraction second = Best(potentials, cars, considering + 1);
                    point.FastCar.RightLane = !point.FastCar.RightLane;
                    point.SlowCar.RightLane = !point.SlowCar.RightLane;
                    if (first < second)
                        return second;
                }
                return first;
            }
            else
            {
                Fraction best = point.Time;
                if (CanSwap(cars, point.FastCar, point.Time))
                {
                    point.FastCar.RightLane = !point.FastCar.RightLane;
                    Fraction second = Best(potentials, cars, considering + 1);
                    point.FastCar.RightLane = !point.FastCar.RightLane;
                    if (second > best)
                        best = second;
                }
                if (CanSwap(cars, point.SlowCar, point.Time))
                {
                    point.SlowCar.RightLane = !point.SlowCar.RightLane;
                    Fraction second = Best(potentials, cars, considering + 1);
                    point.SlowCar.RightLane = !point.SlowCar.RightLane;
                    if (second > best)
                        best = second;
                }
                return best;
            }
        }

        private static bool CanSwap(Car[] cars, Car car, Fraction when)
        {
            Fraction carPos = when*(Fraction)car.Speed+(Fraction)car.Start;
            // check if car is clear to change lanes at a specific time.
            for (int i = 0; i < cars.Length; i++)
            {
                if (cars[i].RightLane != car.RightLane)
                {
                    Fraction otherPos = when * (Fraction)cars[i].Speed + (Fraction)cars[i].Start;
                    if ((carPos - otherPos).Abs() < (Fraction)5)
                        return false;
                }
            }
            return true;
        }

    }
}
