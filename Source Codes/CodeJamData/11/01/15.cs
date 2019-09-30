using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;


namespace GCJ11QRQ1
{
    class Q1
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
                int count = int.Parse(bits[0]);
                bool[] turns = new bool[count];
                int[] position = new int[count];
                for (int j = 0; j < count; j++)
                {
                    turns[j] = bits[j * 2 + 1] == "O";
                    position[j] = int.Parse(bits[j * 2 + 2]);
                }
                output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(turns, position)));
                index++;
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static string Solve(bool[] turns, int[] positions)
        {
            int curPosA = 1;
            int curPosB = 1;
            int curTarget = 0;
            int curATarget = DetermineTarget(true, turns, positions, curTarget);
            int curBTarget = DetermineTarget(false, turns, positions, curTarget); ;
            int turn = 0;
            while (true)
            {
                if (turns[curTarget])
                {
                    if (curATarget == curPosA)
                    {
                        curTarget++;
                        curATarget = DetermineTarget(true, turns, positions, curTarget);
                        curBTarget = DetermineTarget(false, turns, positions, curTarget);
                    }
                    else
                    {
                        Move(ref curPosA, curATarget);
                    }
                    Move(ref curPosB, curBTarget);
                }
                else
                {
                    if (curBTarget == curPosB)
                    {
                        curTarget++;
                        curATarget = DetermineTarget(true, turns, positions, curTarget);
                        curBTarget = DetermineTarget(false, turns, positions, curTarget);
                    }
                    else
                    {
                        Move(ref curPosB, curBTarget);
                    }
                    Move(ref curPosA, curATarget);
                }
                turn++;
                if (curTarget >= turns.Length)
                    return turn.ToString();
            }
        }

        private static void Move(ref int curPosA, int curATarget)
        {
            if (curPosA < curATarget)
                curPosA = curPosA + 1;
            else if (curPosA > curATarget)
                curPosA = curPosA - 1;
        }

        private static int DetermineTarget(bool who, bool[] turns, int[] positions, int curTarget)
        {
            for (int i = curTarget; i < turns.Length; i++)
            {
                if (turns[i] == who)
                    return positions[i];
            }
            return 1;
        }
    }
}
