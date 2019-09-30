using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

class Item
{
    public int Value { get; set;}
    public int Weight { get; set;}
    public Item(int value, int weight)
    {
        Value = value;
        Weight = weight;
    }
}

class Program
{
    static long GetMaxVulue(Item[] items, int limit)
    {
        if(items.Length < 31)
        {
            long[] cSumWeight = new long[items.Length + 1];
            long[] cSumValue = new long[items.Length + 1];
            Item[] sortedItems = items.OrderByDescending(x => x.Weight).ToArray();
            foreach(int i in sortedItems.Select((x, i) => i).Reverse())
            {
                cSumValue[i] = cSumValue[i + 1] + sortedItems[i].Value; 
                cSumWeight[i] = cSumWeight[i + 1] + sortedItems[i].Weight; 
            }
            return GetMaxVulue(0, 0, 0, sortedItems, limit, cSumValue, cSumWeight);
        }
        int maxValue = items.Max(x => x.Value);
        int maxWeight = items.Max(x => x.Weight);
        if(maxValue > maxWeight)
            return GetMaxValue(items, limit, maxWeight);
        return
            GetMaxValueByValue(items, limit, maxValue);
    }
    static long GetMaxValue(Item[] items, int limit, int max)
    {
        long[] dp = new long[limit + 1];
        foreach(var item in items)
        {
            foreach(int i in Enumerable.Range(0, dp.Length).Reverse())
            {
                int index = i - item.Weight;
                if(index < 0)
                    break;
                dp[i] = Math.Max(dp[i], dp[index] + item.Value);
            }
        }
        return dp.Max();
    }
    static long GetMaxValueByValue(Item[] items, int limit, int max)
    {
        long[] dp = new long[max * items.Length + 1]
            .Select(x => (long)limit + 1)
            .ToArray();
        dp[0] = 0;
        foreach(var item in items)
        {
            foreach(int i in Enumerable.Range(0, dp.Length).Reverse())
            {
                int index = i - item.Value;
                if(index < 0)
                    break;
                dp[i] = Math.Min(dp[i], dp[index] + item.Weight);
            }
        }
        return dp
            .Select((Value, Index) => new {Value, Index })
            .Last(x => x.Value <= limit).Index;
    }
    static long GetMaxVulue(long weight, long value, int index, Item[] items, int limit
        , long[] cSumValue, long[] cSumWeight)
    {
        if(index == items.Length)
            return value;
        if(weight + cSumWeight[index] <= limit)
            return value + cSumValue[index];
        if(weight + items[index].Weight > limit)
            return GetMaxVulue(weight, value, index + 1, items, limit, cSumValue, cSumWeight);
        else
            return Math.Max(
                GetMaxVulue(weight, value, index + 1, items, limit, cSumValue, cSumWeight),
                GetMaxVulue(
                    weight + items[index].Weight, 
                    value + items[index].Value, index + 1, items, limit, cSumValue, cSumWeight)
                );
    }

    public void Slove()
    {    
        string[] inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);
        int limitWight = int.Parse(inputs[1]);
        var items =
            Enumerable.Range(0, n)
            .Select(x => Console.ReadLine().Split())
            .Select(x => new Item(int.Parse(x[0]), int.Parse(x[1])))
            .ToArray();
        //Random rnd = new Random();
        //limitWight = int.MaxValue;
        //items =
        //    Enumerable.Range(0, 30)
        //    .Select(x => new Item(rnd.Next(1000), rnd.Next(10000000)))
        //    .ToArray();
        Console.WriteLine(GetMaxVulue(items, limitWight));
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}