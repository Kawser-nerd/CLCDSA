using System;
using System.Collections.Generic;
using System.Linq;
//using System.Numerics;
class Item
{
    public int A {get; set;}
    public int B {get; set;}
    public int Cost {get; set;}
    public Item(string[] args)
    {
        A = int.Parse(args[0]);
        B = int.Parse(args[1]);
        Cost = int.Parse(args[2]);
    }
    public Item(int a, int b, int c)
    {
        A = a;
        B = b;
        Cost = c;
    }
    public static Item operator+(Item item1, Item item2)
    {
        return new Item(item1.A + item2.A, item1.B + item2.B, item1.Cost + item2.Cost);
    }
}
class Program
{     
    static int MinCost(int index, Item[] items, Item item, ref int min, int ma, int mb)
    {
        if(item.Cost >= min)
            return int.MaxValue;
        if(items.Length == index)
        {
            if(item.A > 0 && item.A * mb == item.B * ma)
            {
                min = Math.Min(min, item.Cost);
                return item.Cost;
            }
            else
            {
                return int.MaxValue;
            }
        }
        return Math.Min(
            MinCost(index + 1, items, item, ref min, ma, mb),
            MinCost(index + 1, items, item + items[index], ref min, ma, mb)
        );
    }
    public void Slove()
    {
        var inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);
        int ma = int.Parse(inputs[1]);
        int mb = int.Parse(inputs[2]);
        var items = Enumerable.Range(0, n)
            .Select(x => Console.ReadLine().Split())
            .Select(x => new Item(x))
            .ToArray();
        int min = int.MaxValue;
        MinCost(0, items, new Item(0, 0, 0), ref min, ma, mb);
        if(min == int.MaxValue)
            min = -1;
        System.Console.WriteLine(min);
    }
    
    static void Main(string[] args)
    {
        new Program().Slove();
    }
}