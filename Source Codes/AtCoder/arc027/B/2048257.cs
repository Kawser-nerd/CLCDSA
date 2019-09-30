using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        Console.ReadLine();
        string s = Console.ReadLine();
        string t = Console.ReadLine();
        UnionFind uf = new UnionFind(10 + 26);
        bool[] isExist = new bool[10 + 26];
        for (int i = 0; i < s.Length; i++)
        {
            uf.Union(getIndex(s[i]), getIndex(t[i]));
            isExist[getIndex(s[i])] = true;
            isExist[getIndex(t[i])] = true;
        }
        bool[] parents = new bool[10 + 26];
        for (int i = 0; i < isExist.Length; i++)
        {
            if (isExist[i]) parents[uf.Parent(i)] = true;
        }
        for (int i = 0; i < 10; i++)
        {
            parents[uf.Parent(i)] = false;
        }
        int count = parents.Count(x => x);
        string res = "";
        if (count == 0)
        {
            res = "1";
        }
        else
        {
            if (parents[uf.Parent(getIndex(s[0]))] && parents[uf.Parent(getIndex(t[0]))])
            {
                res = "9";
            }
            else
            {
                res = "10";
            }
            res += string.Join("", Enumerable.Repeat('0', count - 1).ToArray());
        }
        Console.WriteLine(res);
    }
    static int getIndex(char i)
    {
        if (char.IsDigit(i)) return i - '0';
        else return i - 'A' + 10;
    }

}
 class UnionFind
{
    int[] data;
    public UnionFind(int count)
    {
        data = Enumerable.Range(0, count).ToArray();
    }
    public void Union(int x, int y)
    {
        int xp = Parent(x);
        int yp = Parent(y);
        if (xp != yp)
        {
            data[yp] = xp;
        }
    }
    public bool IsSameGroup(int x, int y) => Parent(x) == Parent(y);
    public int Parent(int x)
    {
        form(x);
        return data[x];
    }
    private void form(int x)
    {
        while (data[data[x]] != data[x])
        {
            data[x] = data[data[x]];
        }
    }
}