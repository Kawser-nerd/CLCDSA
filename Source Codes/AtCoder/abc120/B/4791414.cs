using System;
using System.Linq;
using System.Collections;

class Problem
{
    static void Main()
    {
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        ArrayList al = new ArrayList();
        for(int i=1; i<=Math.Min(a[0],a[1]); i++)
        {
            if(a[0]%i==0 && a[1] % i == 0)
            {
                al.Add(i);
            }
        }
        Console.WriteLine(al[al.Count-a[2]]);
    }
}