using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

using System.Numerics;

namespace ExampleApp
{
    class Program
    {
        class Task
        {
            public int Number;

            public class Chest
            {
                public int type;
                public int[] keys;
                public HashSet<int> keyTypesInside;
                public int index;

                public Chest()
                {
                    keys = Enumerable.Repeat(0, 200).ToArray();
                }
            }

            public class State
            {
                public int[] keys;
                public Chest[] chests;

                public State OpenChest(int a)
                {
                    Chest picked = chests[a];
                    State r = new State();
                    r.keys = Enumerable.Range(0, 200).Select(i => keys[i] + picked.keys[i] - (i == picked.type ? 1 : 0)).ToArray();
                    r.chests = chests.Where((ch, j) => j != a).ToArray();
                    return r;
                }

                public bool AllChestsOpenable()
                {
                    HashSet<int> typesToOpen = new HashSet<int>(chests.Select(ch => ch.type));
                    HashSet<int> keysAvailable = new HashSet<int>(Enumerable.Range(0, 200).Where(i => keys[i] != 0));
                    HashSet<int> keysConsidered = new HashSet<int>();

                    while (keysAvailable.Count != 0)
                    {
                        HashSet<int> keysDiscovered = new HashSet<int>();
                        foreach (int keyAvailable in keysAvailable)
                        {
                            foreach (HashSet<int> inThat in chests.Where(ch => ch.type == keyAvailable).Select(ch => ch.keyTypesInside))
                            {
                                keysDiscovered.UnionWith(inThat);
                            }
                        }
                        keysConsidered.UnionWith(keysAvailable);
                        foreach (int keyConsidered in keysConsidered)
                            keysDiscovered.Remove(keyConsidered);
                        keysAvailable = keysDiscovered;
                    }

                    return typesToOpen.IsSubsetOf(keysConsidered);
                }

                public List<int> FindNextToOpen()
                {
                    if (chests.Length == 0)
                        return new List<int>();

                    for (int a = 0; a < chests.Length; a++)
                    {
                        if (keys[chests[a].type] == 0)
                            continue;
                        int aIndex = chests[a].index;
                        State aOpened = OpenChest(a);
                        if (aOpened.AllChestsOpenable())
                        {
                            List<int> r = aOpened.FindNextToOpen();
                            r.Add(aIndex);
                            return r;
                        }
                    }
                    throw new Exception("Something is really wrong");
                }

                public List<int> Solve()
                {
                    bool sanity = Enumerable.Range(0, 200).All(i => keys[i] + chests.Select(ch => ch.keys[i] - (ch.type == i ? 1 : 0)).Sum() >= 0);
                    if (!sanity)
                        return null;
                    if (!AllChestsOpenable())
                        return null;
                    List<int> r = FindNextToOpen();
                    r.Reverse();
                    return r;
                }

                public State()
                {
                    keys = Enumerable.Repeat(0, 200).ToArray();
                }
            }

            public State TaskState;

            public static int[] ReadInts(string s)
            {
                string[] splitted = s.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int num = splitted.Length;
                int[] r = new int[num];
                for (int i = 0; i < num; i++)
                    r[i] = int.Parse(splitted[i]);
                return r;
            }

            public static Task ReadMe(int num, StreamReader sr)
            {
                Task t = new Task() { Number = num };

                int[] kn = ReadInts(sr.ReadLine());

                t.TaskState = new State();
                foreach (int key in ReadInts(sr.ReadLine()))
                    t.TaskState.keys[key - 1]++;

                t.TaskState.chests = new Chest[kn[1]];
                for (int i = 0; i < kn[1]; i++)
                {
                    int[] chest = ReadInts(sr.ReadLine());
                    t.TaskState.chests[i] = new Chest();
                    t.TaskState.chests[i].type = chest[0] - 1;
                    t.TaskState.chests[i].index = i + 1;
                    for (int j = 2; j < chest.Length; j++)
                        t.TaskState.chests[i].keys[chest[j]-1]++;
                    t.TaskState.chests[i].keyTypesInside = new HashSet<int>(Enumerable.Range(0, 200).Where(j => t.TaskState.chests[i].keys[j] != 0));
                }
                return t;
            }

            private string SolveInner()
            {
                List<int> r = TaskState.Solve();
                if (r == null)
                    return "IMPOSSIBLE";
                return string.Join(" ", r.Select(i => i.ToString()));
            }

            public string[] Solve()
            {
                return new string[] { String.Format("Case #{0}: {1}", Number, SolveInner()) };
            }
        }

        static void Main(string[] args)
        {
            using (StreamWriter sw = new StreamWriter(new FileStream(args[1], FileMode.Create)))
            {
                int tasksCount;

                List<Task> tasks = new List<Task>();
                using (StreamReader sr = new StreamReader(new FileStream(args[0], FileMode.Open)))
                {
                    tasksCount = int.Parse(sr.ReadLine());
                    for (int i = 0; i < tasksCount; i++)
                        tasks.Add(Task.ReadMe(i + 1, sr));
                }

                foreach (Task t in tasks)
                {
                    string[] solution = t.Solve();
                    WriteLinesToOutput(sw, solution);
                }
            }
        }

        private static void WriteLinesToOutput(StreamWriter sw, params string[] lines)
        {
            foreach (string line in lines)
                sw.WriteLine(line);
        }
    }
}
