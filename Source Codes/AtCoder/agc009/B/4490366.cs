using System;
using System.Linq;
using System.Collections.Generic;
using static System.Math;
using MethodImplAttribute = System.Runtime.CompilerServices.MethodImplAttribute;
using MethodImplOptions = System.Runtime.CompilerServices.MethodImplOptions;
using LayoutKind = System.Runtime.InteropServices.LayoutKind;
using StructLayoutAttribute = System.Runtime.InteropServices.StructLayoutAttribute;
using FieldOffsetAttribute = System.Runtime.InteropServices.FieldOffsetAttribute;

class P
{
    static int[] Parents;
    static List<int>[] Childs;
    static bool[] IsEmpty;
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        Parents = Enumerable.Repeat(-1, 1).Concat(Enumerable.Repeat(0, n - 1).Select(_ => int.Parse(Console.ReadLine()) - 1)).ToArray();
        Childs = Enumerable.Repeat(0, n).Select(_ => new List<int>()).ToArray();
        for (int i = 1; i < Parents.Length; i++) Childs[Parents[i]].Add(i);
        IsEmpty = Childs.Select(x => x.Count == 0).ToArray();
        memo = Enumerable.Repeat(-1, n).ToArray();
        Console.WriteLine(DFS(0));
    }

    static int[] memo;
    //????????????
    static int DFS(int n)
    {
        if (IsEmpty[n]) return 0;
        if (memo[n] != -1) return memo[n];
        int[] a = new int[Childs[n].Count];
        for (int i = 0; i < Childs[n].Count; i++) a[i] = DFS(Childs[n][i]);
        Array.Sort(a);
        int res = 0;
        for (int i = 0; i < a.Length; i++) res = Max(res, a[i] + a.Length - i);
        return memo[n] = res;
    }
}