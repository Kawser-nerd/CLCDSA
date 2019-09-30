using System.Collections.Generic;
using System.Linq;
using System;

public class Hello
{
    public static void Main()
    {
        var a = Console.ReadLine().Trim();
        var st = new Stack<int>();
        for (int i = 0; i < a.Length; i++)
            if (st.Count() == 0) st.Push(a[i] == 'S' ? 0 : 1);
            else
            {
                if (a[i] == 'S') st.Push(0);
                else if (a[i] == 'T' && st.Peek() == 1) st.Push(1);
                else st.Pop();
            }
        Console.WriteLine(st.Count());
    }
}