using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Treasure
{
    class Program
    {
        static int[] Parse(String[] nums)
        {
            int[] ret = new int[nums.Length];
            for (int i = 0; i < nums.Length; ++i)
            {
                ret[i] = int.Parse(nums[i]);
            }
            return ret;
        }

        struct Chest
        {
            public bool fOpened;
            public List<int> keys;
            public int key;
        }

        static bool Solve(ref Chest[] chests, ref int[] keys, ref List<int> answer, ref SortedSet<UInt32> cachedFailues, UInt32 currentState)
        {
            if (answer.Count == chests.Length) return true;
            if (cachedFailues.Contains(currentState)) return false;
            for (int i = 0; i < chests.Length; ++i)
            {
                if (!chests[i].fOpened && keys[chests[i].key] > 0)
                {
                    // open this chest, recurse in, close this chest if we didn't find the answer
                    answer.Add(i);
                    chests[i].fOpened = true;
                    keys[chests[i].key]--;
                    for (int j = 0; j < chests[i].keys.Count; ++j)
                    {
                        keys[chests[i].keys[j]]++;
                    }
                    currentState |= (2u << i);
                    if (!Solve(ref chests, ref keys, ref answer, ref cachedFailues, currentState))
                    {
                        cachedFailues.Add(currentState);
                        currentState ^= (2u << i);
                        answer.RemoveAt(answer.Count - 1);
                        chests[i].fOpened = false;
                        for (int j = 0; j < chests[i].keys.Count; ++j)
                        {
                            keys[chests[i].keys[j]]--;
                        }
                        keys[chests[i].key]++;
                    }
                    else
                    {
                        return true;
                    }                    
                }
            }
            return false;
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                String[] nums = Console.ReadLine().Split(' ');
                int K = int.Parse(nums[0]);
                int N = int.Parse(nums[1]);
                int[] keysInit = Parse(Console.ReadLine().Split(' '));
                Chest[] chests = new Chest[N];
                for (int j = 0; j < N; ++j)
                {
                    int[] temp = Parse(Console.ReadLine().Split(' '));
                    chests[j].key = temp[0];
                    chests[j].keys = new List<int>(temp.Skip(2));
                    chests[j].fOpened = false;
                }
                
                // now try to solve the problem
                List<int> keys = new List<int>(keysInit);
                int[] keysBucket = new int[500];
                for (int j = 0; j < 500; ++j)
                {
                    keysBucket[j] = 0;
                }
                foreach (int key in keys)
                {
                    keysBucket[key]++;
                }
                List<int> answer = new List<int>();
                //List<UInt32> cacheFailures = new List<UInt32>();
                SortedSet<UInt32> cacheFailures = new SortedSet<uint>();
                if (Solve(ref chests, ref keysBucket, ref answer, ref cacheFailures, 0))
                {
                    Console.Write("Case #{0}: ", 1 + i);
                    foreach (int n in answer)
                    {
                        Console.Write("{0} ", 1+n);
                    }
                    Console.WriteLine();
                }
                else
                {
                    Console.WriteLine("Case #{0}: IMPOSSIBLE", 1 + i);
                }
            }
        }
    }
}
