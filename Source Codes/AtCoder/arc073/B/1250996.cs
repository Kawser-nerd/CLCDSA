using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

class Program
{
    public void Proc()
    {
        Reader.IsDebug = false;
        long[] inpt = Reader.ReadLine().Split(' ').Select(a => long.Parse(a)).ToArray();
        this.ItemCount = (int)inpt[0];
        this.MaxWeight = inpt[1];
        for (int i = 0; i < ItemCount; i++)
        {
            this.Items.Add(new Item(Reader.ReadLine()));
        }
        this.Items = this.Items.OrderBy(a => a.Weight).ToList();
        long ans = GetAns(0, 0);
        Console.WriteLine(ans);
    }

    private Dictionary<int, Dictionary<long, long>> dic = new Dictionary<int, Dictionary<long, long>>();
    private long GetAns(int idx, long subTotalWeight)
    {
        if (!dic.ContainsKey(idx))
        {
            dic.Add(idx, new Dictionary<long, long>());
        }
        if (dic[idx].ContainsKey(subTotalWeight))
        {
            return dic[idx][subTotalWeight];
        }
        if (idx >= this.ItemCount)
        {
            return 0;
        }
        if (this.Items[idx].Weight > MaxWeight - subTotalWeight)
        {
            return 0;
        }
        long ans = GetAns(idx + 1, subTotalWeight + this.Items[idx].Weight) + this.Items[idx].Value;
        ans = Math.Max(ans, GetAns(idx + 1, subTotalWeight));
        dic[idx][subTotalWeight] = ans;
        return ans;
    }

    long MaxWeight;
    int ItemCount;


    private List<Item> Items = new List<Item>();
    class Item
    {
        public long Value;
        public long Weight;

        public Item(string init)
        {
            long[] tmp = init.Split(' ').Select(a => long.Parse(a)).ToArray();
            this.Weight = tmp[0];
            this.Value = tmp[1];
        }
    }

    public class Reader
    {
        public static bool IsDebug = true;
        private static String PlainInput = @"



4 6
2 1
3 4
4 10
3 4

";
        private static System.IO.StringReader Sr = null;
        public static string ReadLine()
        {
            if (IsDebug)
            {
                if (Sr == null)
                {
                    Sr = new System.IO.StringReader(PlainInput.Trim());
                }
                return Sr.ReadLine();
            }
            else
            {
                return Console.ReadLine();
            }
        }
    }
    static void Main()
    {
        Program prg = new Program();
        prg.Proc();
    }
}