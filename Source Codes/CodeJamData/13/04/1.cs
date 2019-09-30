using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Treasure
{
    class Program
    {
        private static string PathToTreasure = null;
        private static HashSet<string> PositionsSearched = new HashSet<string>();

        private static int MaxCount = 0;

        private static void Search(char[] chestsOpen, char[] keyTypesAvailable, int[] chests_keyTypeToOpen, List<int>[] chests_keysInside, int[] moves, int move)
        {
            if (PathToTreasure != null) return;   // stop search immediately

            if (move == moves.Length)
            {
                PathToTreasure = "";
                for (int i = 0; i < moves.Length; i++)
                {
                    if (PathToTreasure != "") PathToTreasure += " ";
                    PathToTreasure += moves[i] + 1; // 1-based
                }
                return;
            }


            bool prelimenarySearchImpossible = PrelimenarySearchImpossible(chestsOpen, keyTypesAvailable, chests_keyTypeToOpen, chests_keysInside);
            if (prelimenarySearchImpossible) return;

            // need to keep track of all possible states
            // state means chests open and key types available
            StringBuilder sb = new StringBuilder();
            sb.Append(chestsOpen);

//            for (int i = 0; i < chestsOpen.Length; i++)
//            {
//                if (chestsOpen[i])
//                {
//                    sb.Append(i);
//                }
//            }

            for (int i = 0; i < keyTypesAvailable.Length; i++)
            {
                if (keyTypesAvailable[i] != 0)
                {
                    sb.Append(Convert.ToChar(i)).Append(keyTypesAvailable[i]);
                }
            }

            string positionID = sb.ToString();
            if (PositionsSearched.Contains(positionID)) return;

            PositionsSearched.Add(positionID);

            if (PositionsSearched.Count > MaxCount)
            {
                MaxCount = PositionsSearched.Count;
            }


            for (int i = 0; i < chestsOpen.Length; i++)
            {
                if (chestsOpen[i] == 0)
                {
                    // try to open
                    int keyTypeToOpen = chests_keyTypeToOpen[i];

                    if (keyTypesAvailable[keyTypeToOpen] > 0)
                    {
                        // make move
                        moves[move] = i;
                        chestsOpen[i] = 'X';
                        keyTypesAvailable[keyTypeToOpen]--;

                        // read all bags - keys inside chest
                        foreach (int keyInside in chests_keysInside[i])
                        {
                            keyTypesAvailable[keyInside]++;
                        }


                        Search(chestsOpen, keyTypesAvailable, chests_keyTypeToOpen, chests_keysInside, moves, move + 1);


                        // undo move
                        foreach (int keyInside in chests_keysInside[i])
                        {
                            keyTypesAvailable[keyInside]--;
                        }
                        keyTypesAvailable[keyTypeToOpen]++;
                        chestsOpen[i] = Convert.ToChar(0);
                        moves[move] = 0;
                    }
                }
            }
        }

        private static void PrelimenarySearch(char[] chestsOpen, char[] keyTypesAvailable, int[] chests_keyTypeToOpen, List<int>[] chests_keysInside)
        {
            // Do initial DFS to eleminate dead sub-graphs
            for (int i = 0; i < chestsOpen.Length; i++)
            {
                if (chestsOpen[i] == 0)
                {
                    // try to open
                    int keyTypeToOpen = chests_keyTypeToOpen[i];

                    if (keyTypesAvailable[keyTypeToOpen] > 0)
                    {
                        // make move
                        chestsOpen[i] = 'X';

                        // read all bags - keys inside chest
                        foreach (int keyInside in chests_keysInside[i])
                        {
                            keyTypesAvailable[keyInside]++;
                        }


                        PrelimenarySearch(chestsOpen, keyTypesAvailable, chests_keyTypeToOpen, chests_keysInside);
                        // no "undo move"
                    }
                }
            }
        }

        private static bool PrelimenarySearchImpossible(char[] KTA, int[] chests_keyTypeToOpen, List<int>[] chests_keysInside)
        {
            char[] chestsOpen = new char[chests_keyTypeToOpen.Length];  // by default false - all closed
            char[] keyTypesAvailable = new char[KTA.Length];
            KTA.CopyTo(keyTypesAvailable, 0);

            PrelimenarySearch(chestsOpen, keyTypesAvailable, chests_keyTypeToOpen, chests_keysInside);

            for (int i = 0; i < chestsOpen.Length; i++)
            {
                if (chestsOpen[i] == 0) return true;    // impossible to find solution
            }

            return false;
        }

        private static bool PrelimenarySearchImpossible(char[] CO, char[] KTA, int[] chests_keyTypeToOpen, List<int>[] chests_keysInside)
        {
            char[] chestsOpen = new char[chests_keyTypeToOpen.Length];  // by default false - all closed
            CO.CopyTo(chestsOpen, 0);

            char[] keyTypesAvailable = new char[KTA.Length];
            KTA.CopyTo(keyTypesAvailable, 0);

            PrelimenarySearch(chestsOpen, keyTypesAvailable, chests_keyTypeToOpen, chests_keysInside);

            for (int i = 0; i < chestsOpen.Length; i++)
            {
                if (chestsOpen[i] == 0) return true;    // impossible to find solution
            }

            return false;
        }

        private static bool PreliminaryCountImpossible(char[] KTA, int[] chests_keyTypeToOpen, List<int>[] chests_keysInside)
        {
            // calculate totalKeys avaiable
            // calculate total type count requered by chests

            char[] keyTypesAvailable = new char[KTA.Length];
            KTA.CopyTo(keyTypesAvailable, 0);

            for (int i = 0; i < chests_keyTypeToOpen.Length; i++)
            {
                foreach (int keyInside in chests_keysInside[i])
                {
                    keyTypesAvailable[keyInside]++;
                }
            }

//            for (int i = 0; i < keyTypesAvailable.Length; i++)
//            {
//                if (keyTypesAvailable[i] != 0)
//                {
//                    Console.WriteLine(i + " - " + ((int) keyTypesAvailable[i]));
//                }
//            }

            int[] totalRequiredToOpen = new int[201];
            for (int i = 0; i < chests_keyTypeToOpen.Length; i++)
            {
                totalRequiredToOpen[chests_keyTypeToOpen[i]]++;
            }

//            Console.WriteLine();


            for (int i = 0; i < totalRequiredToOpen.Length; i++)
            {
//                if (totalRequiredToOpen[i] != 0)
//                {
//                    Console.WriteLine(i + " - " + totalRequiredToOpen[i] + " " + (totalRequiredToOpen[i] <= keyTypesAvailable[i]));
//                }

                if (totalRequiredToOpen[i] > keyTypesAvailable[i]) return true;
            }
            return false;
        }


        static void Main(string[] args)
        {
            try
            {
                int started = Environment.TickCount;
                string path = @"C:\Work\Trainings\Code Jam\2013 Qualification\D. Treasure\";
                string filenameIn = "D-large.in";    // 3916 ms, 4010 ms, 1328
                string filenameOut = "D-large.out";

                StreamReader sr = new StreamReader(path + filenameIn);
                StreamWriter sw = new StreamWriter(path + filenameOut);

                int testCount = Convert.ToInt32(sr.ReadLine());

                for (int t = 0; t < testCount; t++)
                {
                    int testStarted = Environment.TickCount;
                    string line = sr.ReadLine();
                    string[] splitted = line.Split(' ');

                    int keyCount = Convert.ToInt32(splitted[0]);
                    int chestCount = Convert.ToInt32(splitted[1]);   // chests

                    char[] keyTypesAvailable = new char[201]; //All chest types and key types will be integers between 1 and 200 inclusive. keys available to me

                    line = sr.ReadLine();
                    splitted = line.Split(' ');

                    if (splitted.Length != keyCount) throw new ApplicationException("Wrong");
                    for (int i = 0; i < keyCount; i++)
                    {
                        int keyType = Convert.ToInt32(splitted[i]);
                        keyTypesAvailable[keyType]++;
                    }

                    int[] chests_keyTypeToOpen = new int[chestCount];
                    List<int>[] chests_keysInside = new List<int>[chestCount];
                    for (int i = 0; i < chestCount; i++)
                    {
                        // read each chect info
                        line = sr.ReadLine();

                        splitted = line.Split(' ');
                        chests_keyTypeToOpen[i] = Convert.ToInt32(splitted[0]);

                        int keysInsideChest = Convert.ToInt32(splitted[1]);

                        if (keysInsideChest != splitted.Length - 2) throw new ApplicationException("Wrong");

                        chests_keysInside[i] = new List<int>();
                        for (int j = 0; j < keysInsideChest; j++)
                        {
                            int avaiableKey = Convert.ToInt32(splitted[j + 2]);
                            chests_keysInside[i].Add(avaiableKey);
                        }
                    }

                    // start full search
                    // make a node which describes a set (keys available, chests open / still closed)
                    // move means -> take a first closed chest, try to open -> transfer to a new state. keep transition info

                    PathToTreasure = null;
                    PositionsSearched.Clear();

                    string infoMsg = null;
                    bool impossible = PreliminaryCountImpossible(keyTypesAvailable, chests_keyTypeToOpen, chests_keysInside);

                    if (!impossible)
                    {
                        impossible = PrelimenarySearchImpossible(keyTypesAvailable, chests_keyTypeToOpen, chests_keysInside);

                        if (!impossible)
                        {
                            char[] chestsOpen = new char[chests_keyTypeToOpen.Length]; // by default false - all closed
                            int[] moves = new int[chests_keyTypeToOpen.Length];
                            Search(chestsOpen, keyTypesAvailable, chests_keyTypeToOpen, chests_keysInside, moves, 0);
                        }
                        else
                        {
                            infoMsg = "Reduced SearchImpossible";
                        }
                    }
                    else
                    {
                        infoMsg = "Reduced CountImpossible";
                    }

                    string message = PathToTreasure ?? "IMPOSSIBLE";
                    sw.WriteLine("Case #{0}: {1}", (t + 1), message);

                    int testElapsed = Environment.TickCount - testStarted;
                    Console.WriteLine("Case #{0} {1} ms {2} {3}", t.ToString().PadLeft(2), testElapsed.ToString().PadLeft(5), message, infoMsg);
                }


                Console.WriteLine("Dictionary count: " + MaxCount);

                sr.Close();
                sw.Close();

                int elapsed = Environment.TickCount - started;
                Console.WriteLine("Time elapsed: " + elapsed);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
        }
    }
}
