using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] NM = Console.ReadLine().Split().Select(int.Parse).ToArray();
        Tree tree = new Tree(NM[0]);
        for (int i = 0; i < NM[1]; i++)
        {
            int[] LRD = Console.ReadLine().Split().Select(int.Parse).ToArray();
            if(!tree.Union(LRD[0] - 1, LRD[1] - 1, LRD[2]))
            {
                Console.WriteLine("No");
                return;
            }
        }
        Console.WriteLine("Yes");
    }
}

public class Tree
{
    //??????????(?????????????????)
    TreeD[] data;
    public Tree(int count)
    {
        data = Enumerable.Range(0, count).Select(x => new TreeD(x, 0)).ToArray();
    }
    public bool Union(int x, int y, int Diff)
    {
        int xparent = Parent(x);
        int yparent = Parent(y);
        int xvalue = Value(x);
        int yvalue = Value(y);
        if (xparent != yparent)
        {
            data[yparent].Parent = xparent;
            data[yparent].Value = Diff + (xvalue - yvalue);
        }
        else
        {
            if (yvalue - xvalue != Diff) return false;
        }
        return true;
    }
    public int Parent(int x)
    {
        form(x);
        return data[x].Parent;
    }
    public int Value(int x)
    {
        form(x);
        return data[x].Value;
    }
    //???????????
    private void form(int x)
    {
        while (data[data[x].Parent].Parent != data[x].Parent)
        {
            //??Add????????????
            data[x].Value += data[data[x].Parent].Value;
            data[x].Parent = data[data[x].Parent].Parent;
        }
    }
}
class TreeD
{
    public int Parent;
    public int Value;
    public TreeD(int p, int a)
    {
        Parent = p;
        Value = a;
    }
}