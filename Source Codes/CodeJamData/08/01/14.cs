using System;
using System.Collections.Generic;

public class A
{
  public static void Main ()
  {
    int n = int.Parse (Console.ReadLine ());
    
    for (int i = 1; i <= n; ++i)
    {
      int s = int.Parse (Console.ReadLine ());
      string[] ss = new string[s];
      
      for (int j = 0; j < s; ++j)
        ss[j] = Console.ReadLine ();
      
      int q = int.Parse (Console.ReadLine ());
      int[] qq = new int[q];
      
      for (int j = 0; j < q; ++j)
        qq[j] = ((IList<string>) ss).IndexOf (Console.ReadLine ());
      
      Console.WriteLine ("Case #{0}: {1}", i, Solve (s, qq));
    }
  }
  
  
  static int Solve (int s, int[] q)
  {
    int qn = q.Length;
    int[,] cnt = new int[qn + 1, s];
    
    if (qn == 0)
      return 0;
    
    for (int i = 0; i < s; ++i)
      cnt[qn, i] = 0;
    
    while (--qn >= 0)
    { 
      int val = q[qn];
      cnt[qn, val] = int.MaxValue;
      
      for (int i = 0; i < s; ++i)
        if (val != i)
      {
        cnt[qn, i] = cnt[qn + 1, i];
        cnt[qn, val] = Math.Min (cnt[qn, val], cnt[qn, i] + 1);
      }
    }
    
    return cnt[0, q[0]] - 1;
  }
}
