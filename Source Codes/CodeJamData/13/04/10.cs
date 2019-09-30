using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{

    // After that, there will be N lines, each representing a single chest.
    // Each line will begin with integers Ti and Ki, indicating the key type
    // needed to open the chest and the number of keys inside the chest.
    // These two integers will be followed by Ki more integers,
    // indicating the types of the keys contained within the chest.
    public class Chest
    {
        /// <summary>
        /// Gets or sets the type of the key.
        /// </summary>
        /// <value>
        /// The type of the key.
        /// </value>
        public int Type { get; set; }

        /// <summary>
        /// 
        /// </summary>
        public List<int> Keys { get; set; }

        /// <summary>
        /// Gets or sets a value indicating whether this <see cref="Chest"/> is opened.
        /// </summary>
        /// <value>
        ///   <c>true</c> if opened; otherwise, <c>false</c>.
        /// </value>
        public bool Opened { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="Chest"/> class.
        /// </summary>
        public Chest()
        {
            Keys = new List<int>();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"D-small-practice.in");
            int cases = Int32.Parse(lines[0]);

            for (int c = 0, c1 = 1; c1 <= cases; c1++)
            {
                // K and N, representing the number of keys you start with and the number of chests you need to open.
                c += 1;
                var str = lines[c].Split(new char[] {' '});
                int K = int.Parse(str[0]), N = int.Parse(str[1]);
                // This is followed by a line containing K integers, representing the types of the keys that you start with.

                int[] keys = new int[100];
                int[] allKeys = new int[100];
                int[] allChests = new int[100];

                c += 1;
                var keysStr = lines[c].Split(new char[] {' '});

                for (int i = 0; i < keysStr.Length; i++)
                {
                    keys[Int32.Parse(keysStr[i])] += 1;
                    allKeys[Int32.Parse(keysStr[i])] += 1;
                }

                var chests = new List<Chest>();

                for (int i = 0; i < N; i++)
                {
                    c += 1;
                    var chestStr = lines[c].Split(new char[] { ' ' });

                    var chest = new Chest() { Type = Int32.Parse(chestStr[0])};

                    for (int j = 2; j < chestStr.Length; j++)
                    {
                        chest.Keys.Add(Int32.Parse(chestStr[j]));
                        allKeys[Int32.Parse(chestStr[j])] += 1;
                    }

                    chests.Add(chest);
                }

                // Check if solution exists
                for (int i = 0; i < chests.Count; i++)
                {
                    allChests[chests[i].Type] += 1;
                }

                bool solutionExist = true;

                for (int i = 0; i < 100; i++)
                {
                    int diff = allKeys[i] - allChests[i];

                    if (diff < 0)
                    {
                        solutionExist = false;
                        break;
                    }
                }

                if (!solutionExist)
                {
                    Console.WriteLine("Case #{0}: {1}", c1, "IMPOSSIBLE");
                    continue;
                }

                //1 4 start keys number, start chests number
                //1 start keys
                //1 0       // chest 1
                //1 2 1 3   // chest 2
                //2 0       // chest 3
                //3 1 2     // chest 4

                //3 3
                //1 1 1
                //1 0   // chest 1
                //1 0   // chest 2
                //1 0   // chest 3

                //1 1
                //2
                //1 1 1

                // a. Select chest with min number you can open
                // b. Open chest
                // c. Decrease by used key, add keys found in chest

                // if all chests are opened exit
                // if you can't open any chest but there are chests left:
                // back one step, open next chest
                var answer = new List<int>();
                var d = new Dictionary<string, string>();

                if (Calculate(keys, chests, answer, 0, d))
                {
                    string result = "";

                    for (int j = 0; j < answer.Count; j++)
                    {
                        result += answer[j].ToString() + " ";
                    }

                    result = result.Trim();

                    Console.WriteLine("Case #{0}: {1}", c1, result);
                }
                else
                {
                    Console.WriteLine("Case #{0}: {1}", c1, "IMPOSSIBLE");
                }
            }

            Console.ReadLine();
        }

        static bool Calculate(int[] keys, List<Chest> chests, List<int> order, int opened, Dictionary<string, string> d)
        {
            //bool allOpened = true;

            //for (int i = 0; i < chests.Count; i++)
            //{
            //    if (!chests[i].Opened)
            //    {
            //        allOpened = false;
            //        break;
            //    }
            //}

            //if (allOpened)
            //{
            //    return true;
            //}

            string str = "";
            // var o2 = new List<int>(order);
            var o2 = new List<int>();

            for (int j = 0; j < chests.Count; j++)
            {
                if (!chests[j].Opened)
                {
                    o2.Add(j + 1);
                }
            }

            o2.Sort();

            for (int j = 0; j < o2.Count; j++)
            {
                str += o2[j].ToString() + " ";
            }

            str = str.Trim();

            if (d.ContainsKey(str))
            {
                return false;
            }

            for (int i = 0; i < chests.Count; i++)
            {
                if (!chests[i].Opened && keys[chests[i].Type] > 0)
                {
                    opened += 1;

                    // Opened all chests !!!

                    keys[chests[i].Type] -= 1;
                    chests[i].Opened = true;

                    order.Add(i + 1);

                    if (opened == chests.Count)
                    {
                        return true;
                    }

                    for (int j = 0; j < chests[i].Keys.Count; j++)
                    {
                        keys[chests[i].Keys[j]] += 1;
                    }

                    // Count number of keys
                    int keysSum = keys.Sum();
                    bool solutionExist = true;

                    bool result = false;

                    //int[] allKeys = keys.ToList().ToArray();
                    //int[] allChests = new int[100];

                    //// Check if solution exists
                    //for (int j = 0; j < chests.Count; j++)
                    //{
                    //    if (!chests[j].Opened)
                    //    {
                    //        allChests[chests[j].Type] += 1;
                    //        for (int j0 = 0; j0 < chests[j].Keys.Count; j0++) allKeys[chests[j].Keys[j0]] += 1;
                    //    }
                    //}

                    //for (int j = 0; j < 100; j++)
                    //{
                    //    int diff = allKeys[j] - allChests[j];

                    //    if (diff < 0)
                    //    {
                    //        solutionExist = false;
                    //        break;
                    //    }
                    //}

                    if (keysSum != 0 && solutionExist)
                    {
                        var chestsNew = new List<Chest>();
                        for (int j = 0; j < chests.Count; j++)
                        {
                            chestsNew.Add(new Chest() { Keys = new List<int>(chests[j].Keys), Opened = chests[j].Opened, Type = chests[j].Type });
                        }

                        result = Calculate(new List<int>(keys).ToArray(), chestsNew, order, opened, d);
                    }

                    if (result)
                    {
                        return result;
                    }

                    if (!result)
                    {
                        opened -= 1;
                        keys[chests[i].Type] += 1;
                        chests[i].Opened = false;

                        order.RemoveAt(order.Count - 1);

                        for (int j = 0; j < chests[i].Keys.Count; j++)
                        {
                            keys[chests[i].Keys[j]] -= 1;
                        }
                    }
                }
            }

            // Check that decision leads to answer
            d.Add(str, "");
            return false;
        }
    }
}