using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Treasure
{
    public class Chest
    {
        public Chest()
        {
            m_chestNumber = 0;
            m_keysToOpen = 0;
            m_keysInside = new Dictionary<int, int>();
        }

        private int m_chestNumber;

        public int ChestNumber
        {
            get { return m_chestNumber; }
            set { m_chestNumber = value; }
        }

        private int m_keysToOpen;

        public int KeysToOpen
        {
            get { return m_keysToOpen; }
            set { m_keysToOpen = value; }
        }

        private Dictionary<int, int> m_keysInside;

        public Dictionary<int, int> KeysInside
        {
            get { return m_keysInside; }
            set { m_keysInside = value; }
        }
    }

    internal class Program
    {
        public static bool OpenChest(SortedDictionary<int, Chest> chests,
            SortedDictionary<int, Chest> closedChests,
            Dictionary<int, int> availableKeys,
            List<int> openSequence)
        {
            if (closedChests.Count == 0)
                return true;

            if (availableKeys.Count == 0)
                return false;

            foreach (var chest in closedChests.Values)
            {
                bool canOpen = availableKeys.ContainsKey(chest.KeysToOpen);

                if (canOpen)
                {
                    //open chest
                    openSequence.Add(chest.ChestNumber);
                    Dictionary<int, int> retrievedKey = chest.KeysInside;
                    foreach (var item in retrievedKey)
                    {
                        if (availableKeys.ContainsKey(item.Key))
                        {
                            availableKeys[item.Key] += item.Value;
                        }
                        else
                        {
                            availableKeys[item.Key] = item.Value;
                        }
                    }

                    //remove used key
                    if (--availableKeys[chest.KeysToOpen] == 0)
                        availableKeys.Remove(chest.KeysToOpen);

                    //remove closed chest
                    SortedDictionary<int, Chest> newClosedChests = new SortedDictionary<int, Chest>(closedChests);
                    newClosedChests.Remove(chest.ChestNumber);

                    //all closed chests must have possible keys in other chests
                    bool shouldContinueOpen = true;
                    foreach (Chest closedChest in newClosedChests.Values)
                    {
                        int keyToOpen = closedChest.KeysToOpen;
                        if (availableKeys.ContainsKey(keyToOpen))
                            continue;

                        bool foundPossibleKey = false;
                        foreach (Chest otherCloseChest in newClosedChests.Values)
                        {
                            if (closedChest != otherCloseChest && otherCloseChest.KeysToOpen != keyToOpen
                                && otherCloseChest.KeysInside.ContainsKey(keyToOpen))
                            {
                                foundPossibleKey = true;
                                break;
                            }
                        }

                        if (!foundPossibleKey)
                        {
                            shouldContinueOpen = false;
                            break;
                        }
                    }

                    if (shouldContinueOpen && OpenChest(chests, newClosedChests, availableKeys, openSequence))
                    {
                        return true;
                    }

                    //revert
                    Revert(availableKeys, openSequence, chest, retrievedKey);
                }
            }

            return false;
        }

        private static void Revert(Dictionary<int, int> availableKeys, List<int> openSequence, Chest chest, Dictionary<int, int> retrievedKey)
        {
            openSequence.RemoveAt(openSequence.Count - 1);
            if (availableKeys.ContainsKey(chest.KeysToOpen))
                ++availableKeys[chest.KeysToOpen];
            else
                availableKeys[chest.KeysToOpen] = 1;

            foreach (var item in retrievedKey)
            {
                availableKeys[item.Key] -= item.Value;
                if (availableKeys[item.Key] == 0)
                    availableKeys.Remove(item.Key);
            }
        }

        public class Problem
        {
            public Problem()
            {
                m_chests = new SortedDictionary<int, Chest>();
                m_keyStart = new Dictionary<int, int>();
            }

            private SortedDictionary<int, Chest> m_chests;

            public SortedDictionary<int, Chest> Chests
            {
                get { return m_chests; }
                set { m_chests = value; }
            }

            private Dictionary<int, int> m_keyStart;

            public Dictionary<int, int> KeyStart
            {
                get { return m_keyStart; }
                set { m_keyStart = value; }
            }
        }

        public enum PARSE_STATE { P_BEGIN, P_READ_START, P_READ_CHEST };

        public static List<Problem> ParseInput(string[] lines)
        {
            int caseCount = 0;

            List<Problem> problems = new List<Problem>();
            Problem problem = new Problem();
            PARSE_STATE state = PARSE_STATE.P_BEGIN;
            int startKeyCount = 0;
            int chestCount = 0;
            int chestNumber = 1;
            for (int index = 0; index < lines.Length; index++)
            {
                string line = lines[index];

                if (index == 0)
                {
                    if (!Int32.TryParse(line, out caseCount))
                    {
                        Console.WriteLine("Invalid line {0}:{1}", index, line);
                        break;
                    }
                }
                else if (state == PARSE_STATE.P_BEGIN)
                {
                    string[] items = line.Split(' ');
                    startKeyCount = int.Parse(items[0]);
                    chestCount = int.Parse(items[1]);
                    state = PARSE_STATE.P_READ_START;
                }
                else if (state == PARSE_STATE.P_READ_START)
                {
                    string[] items = line.Split(' ');
                    foreach (var item in items)
                    {
                        int key = int.Parse(item);
                        if (problem.KeyStart.ContainsKey(key))
                        {
                            ++problem.KeyStart[key];
                        }
                        else
                        {
                            problem.KeyStart[key] = 1;
                        }
                    }
                    state = PARSE_STATE.P_READ_CHEST;
                }
                else if (state == PARSE_STATE.P_READ_CHEST)
                {
                    Chest chest = new Chest();
                    chest.ChestNumber = chestNumber;
                    ++chestNumber;
                    string[] items = line.Split(' ');
                    for (int i = 0; i < items.Length; i++)
                    {
                        int key = int.Parse(items[i]);

                        if (i == 0)
                            chest.KeysToOpen = key;
                        else if (i > 1)
                        {
                            if (chest.KeysInside.ContainsKey(key))
                            {
                                ++chest.KeysInside[key];
                            }
                            else
                            {
                                chest.KeysInside[key] = 1;
                            }
                        }
                    }

                    problem.Chests.Add(chest.ChestNumber, chest);

                    if (problem.Chests.Count == chestCount)
                    {
                        problems.Add(problem);
                        problem = new Problem();
                        state = PARSE_STATE.P_BEGIN;
                        startKeyCount = 0;
                        chestCount = 0;
                        chestNumber = 1;
                    }
                }
            }

            if (problems.Count != caseCount)
            {
                Console.WriteLine("Invalid case count");
            }

            return problems;
        }

        private static void Main(string[] args)
        {
            string[] rawInput = System.IO.File.ReadAllLines(args[0]);
            List<Problem> problems = ParseInput(rawInput);

            for (int caseIndex = 0; caseIndex < problems.Count; caseIndex++)
            {
                Problem problem = problems[caseIndex];
                List<int> openSequence = new List<int>();
                SortedDictionary<int, Chest> closedChests = new SortedDictionary<int, Chest>(problem.Chests);

                //check not enough key
                SortedDictionary<int, int> supply = new SortedDictionary<int, int>();
                foreach (var item in problem.Chests.Values)
                {
                    foreach (var key in item.KeysInside)
                    {
                        if (supply.ContainsKey(key.Key))
                            supply[key.Key] += key.Value;
                        else
                            supply[key.Key] = key.Value;
                    }
                }

                foreach (var key in problem.KeyStart)
                {
                    if (supply.ContainsKey(key.Key))
                        supply[key.Key] += key.Value;
                    else
                        supply[key.Key] = key.Value;
                }

                bool hasEnough = true;
                foreach (var item in problem.Chests.Values)
                {
                    if (supply.ContainsKey(item.KeysToOpen))
                    {
                        if (--supply[item.KeysToOpen] < 0)
                            hasEnough = false;
                    }
                    else
                    {
                        hasEnough = false;
                    }

                    if (!hasEnough)
                    {
                        break;
                    }
                }

                if (hasEnough)
                {
                    if (OpenChest(problem.Chests, closedChests, problem.KeyStart, openSequence))
                    {
                        Console.Write("Case #{0}:", caseIndex + 1);
                        foreach (var item in openSequence)
                        {
                            Console.Write(" {0}", item);
                        }
                        Console.WriteLine();
                    }
                    else
                    {
                        Console.WriteLine("Case #{0}: IMPOSSIBLE", caseIndex + 1);
                    }
                }
                else
                {
                    Console.WriteLine("Case #{0}: IMPOSSIBLE", caseIndex + 1);
                }
            }
        }
    }
}