using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Math;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        uint[] a = Console.ReadLine().Split().Select(uint.Parse).OrderByDescending(x => x).ToArray();
        //2???-1????1...1 -2?1...0
        //????????????1?11?00?11????2?0
        //????????????
        //????????????????
        //???????????
        //valid(n,a) && valid(n,b)?a>b????b??????????????
        int res = 0;
        Dictionary<uint, Queue<int>> dict = a.Distinct().ToDictionary(x => x, _ => new Queue<int>());
        for (int i = 0; i < a.Length; i++)
        {
            dict[a[i]].Enqueue(i);
        }

        bool[] used = new bool[a.Length];
        for (int i = 0; i < a.Length; i++)
        {
            if (used[i]) continue;
            var item = a[i];
            uint j = 1u << Log2(item);

            if (dict.ContainsKey(j - item))
            {
                if (dict[j - item].Count == 0) continue;
                var value = dict[j - item].Dequeue();
                if (value == i)
                {
                    var temp = value;
                    if (dict[j - item].Count == 0)
                    {
                        dict[j - item].Enqueue(temp);
                        continue;
                    }
                    else
                    {
                        value = dict[j - item].Dequeue();
                        dict[j - item].Enqueue(temp);
                    }
                }
                if (used[value]) continue;
                used[i] = true;
                used[value] = true;
                res++;
            }
            
            end:;
        }
        Console.WriteLine(res);
    }

    public static readonly int[] MultiplyDeBruijnBitPosition = { 1, 10, 2, 11, 14, 22, 3, 30, 12, 15, 17, 19, 23, 26, 4, 31, 9, 13, 21, 29, 16, 18, 25, 8, 20, 28, 24, 7, 27, 6, 5, 32 };
    public static int Log2(uint n)
    {
        n |= (n >> 1);
        n |= (n >> 2);
        n |= (n >> 4);
        n |= (n >> 8);
        n |= (n >> 16);
        return MultiplyDeBruijnBitPosition[(n * 0x07c4acddu) >> 27];
    }
}

class State
{
    string seq;
    int[] remain;
    public State(string seq, int[] remain)
    {
        this.seq = seq;
        this.remain = remain.ToArray();
    }
}