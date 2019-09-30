using System;
using System.Collections.Generic;
using System.IO;
using System.Globalization;
using System.Threading;

namespace B
{
    class Program
    {
        static string iFile = "B-small.in";
        static string oFile = "B-small.out";
        //static string iFile = "B-large.in";
        //static string oFile = "B-large.out";

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("");

            FileInfo input = new FileInfo(iFile);
            TextReader inputStream = input.OpenText();

            FileInfo output = new FileInfo(oFile);
            TextWriter outputStream = output.CreateText();

            int testCase = Convert.ToInt32(inputStream.ReadLine());

            for (int i = 1; i <= testCase; i++)
            {
                TestCase(i, inputStream, outputStream);
            }

            outputStream.Close();
            inputStream.Close();
        }

        static void TestCase(int testCase, TextReader inputStream, TextWriter outputStream)
        {
            string[] tmp = inputStream.ReadLine().Split(' ');

            int H = Convert.ToInt32(tmp[0]);
            int N = Convert.ToInt32(tmp[1]);
            int M = Convert.ToInt32(tmp[2]);

            int[,] ceilings = new int[N, M];

            for (int i = 0; i < N; i++)
            {
                tmp = inputStream.ReadLine().Split(' ');

                for (int j = 0; j < M; j++)
                {
                    ceilings[i, j] = Convert.ToInt32(tmp[j]);
                }
            }

            int[,] floors = new int[N, M];

            for (int i = 0; i < N; i++)
            {
                tmp = inputStream.ReadLine().Split(' ');

                for (int j = 0; j < M; j++)
                {
                    floors[i, j] = Convert.ToInt32(tmp[j]);
                }
            }

            double[,] times = new double[N, M];

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    times[i, j] = -1;
                }
            }

            State initial = new State() { X = 0, Y = 0, Water = H, Time = 0 };
            times[0, 0] = 0;
            Queue<State> q = new Queue<State>();

            q.Enqueue(initial);

            while (q.Count > 0)
            {
                State state = q.Dequeue();

                if (state.X < M - 1)
                {
                    if (ceilings[state.Y, state.X] - floors[state.Y, state.X + 1] >= 50
                        && ceilings[state.Y, state.X + 1] - floors[state.Y, state.X] >= 50
                        && ceilings[state.Y, state.X + 1] - floors[state.Y, state.X + 1] >= 50)
                    {
                        int water = state.Water;
                        double time = state.Time;

                        int x = ceilings[state.Y, state.X + 1] - 50;

                        if (water > x)
                        {
                            time = time + 0.1 * (water - x);
                            water = x;
                        }

                        if (time > 0)
                        {
                            if (water - floors[state.Y, state.X] >= 20)
                            {
                                water -= 10;
                                time += 1;
                            }
                            else
                            {
                                water = Math.Max(0, water - 100);
                                time += 10;
                            }
                        }

                        if (times[state.Y, state.X + 1] == -1 || time < times[state.Y, state.X + 1])
                        {
                            times[state.Y, state.X + 1] = time;
                            State newState = new State() { X = state.X + 1, Y = state.Y, Water = water, Time = time };

                            q.Enqueue(newState);
                        }
                    }
                }

                if (state.X > 0)
                {
                    if (ceilings[state.Y, state.X] - floors[state.Y, state.X - 1] >= 50
                        && ceilings[state.Y, state.X - 1] - floors[state.Y, state.X] >= 50
                        && ceilings[state.Y, state.X - 1] - floors[state.Y, state.X - 1] >= 50)
                    {
                        int water = state.Water;
                        double time = state.Time;

                        int x = ceilings[state.Y, state.X - 1] - 50;

                        if (water > x)
                        {
                            time = time + 0.1 * (water - x);
                            water = x;
                        }

                        if (time > 0)
                        {
                            if (water - floors[state.Y, state.X] >= 20)
                            {
                                water -= 10;
                                time += 1;
                            }
                            else
                            {
                                water = Math.Max(0, water - 100);
                                time += 10;
                            }
                        }

                        if (times[state.Y, state.X - 1] == -1 || time < times[state.Y, state.X - 1])
                        {
                            times[state.Y, state.X - 1] = time;
                            State newState = new State() { X = state.X - 1, Y = state.Y, Water = water, Time = time };

                            q.Enqueue(newState);
                        }
                    }
                }

                if (state.Y < N - 1)
                {
                    if (ceilings[state.Y, state.X] - floors[state.Y + 1, state.X] >= 50
                        && ceilings[state.Y + 1, state.X] - floors[state.Y, state.X] >= 50
                        && ceilings[state.Y + 1, state.X] - floors[state.Y + 1, state.X] >= 50)
                    {
                        int water = state.Water;
                        double time = state.Time;

                        int x = ceilings[state.Y + 1, state.X] - 50;

                        if (water > x)
                        {
                            time = time + 0.1 * (water - x);
                            water = x;
                        }

                        if (time > 0)
                        {
                            if (water - floors[state.Y, state.X] >= 20)
                            {
                                water -= 10;
                                time += 1;
                            }
                            else
                            {
                                water = Math.Max(0, water - 100);
                                time += 10;
                            }
                        }

                        if (times[state.Y + 1, state.X] == -1 || time < times[state.Y + 1, state.X])
                        {
                            times[state.Y + 1, state.X] = time;
                            State newState = new State() { X = state.X, Y = state.Y + 1, Water = water, Time = time };

                            q.Enqueue(newState);
                        }
                    }
                }

                if (state.Y > 0)
                {
                    if (ceilings[state.Y, state.X] - floors[state.Y - 1, state.X] >= 50
                        && ceilings[state.Y - 1, state.X] - floors[state.Y, state.X] >= 50
                        && ceilings[state.Y - 1, state.X] - floors[state.Y - 1, state.X] >= 50)
                    {
                        int water = state.Water;
                        double time = state.Time;

                        int x = ceilings[state.Y - 1, state.X] - 50;

                        if (water > x)
                        {
                            time = time + 0.1 * (water - x);
                            water = x;
                        }

                        if (time > 0)
                        {
                            if (water - floors[state.Y, state.X] >= 20)
                            {
                                water -= 10;
                                time += 1;
                            }
                            else
                            {
                                water = Math.Max(0, water - 100);
                                time += 10;
                            }
                        }

                        if (times[state.Y - 1, state.X] == -1 || time < times[state.Y - 1, state.X])
                        {
                            times[state.Y - 1, state.X] = time;
                            State newState = new State() { X = state.X, Y = state.Y - 1, Water = water, Time = time };

                            q.Enqueue(newState);
                        }
                    }
                }
            }

            outputStream.WriteLine("Case #{0}: {1:0.0000000}", testCase, times[N - 1, M - 1]);
        }

        public class State
        {
            public int X { get; set; }
            public int Y { get; set; }
            public int Water { get; set; }
            public double Time { get; set; }
        }
    }
}
