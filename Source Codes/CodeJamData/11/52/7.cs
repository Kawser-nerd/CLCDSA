// twitter.com/P_E

using System;
using System.IO;
using System.Collections.Generic;

public class Solution
{
  StreamReader fin;
  StreamWriter fout;

  public void solve(int caseId)
  {
    int N = nextInt();

    if (N == 0)
    {
      fout.Write("Case #" + caseId + ": " + 0 + "\n");
      return;
    }

    int[] xs = new int[N];
    for (int i = 0; i < N; ++i)
      xs[i] = nextInt();
    Array.Sort(xs);

    SortedDictionary<int, int> lvs = new SortedDictionary<int, int>();
    SortedDictionary<int, int> nlvs;
    int ans = N + 1, cnt;
    for (int i = 0; i < N; i += cnt)
    {
      cnt = 1;
      while (i + cnt < N && xs[i + cnt - 1] == xs[i + cnt])
        ++cnt;

      if (i == 0 || xs[i] - xs[i - 1] > 1)
      {
        // test the shortest element
        foreach (int len in lvs.Keys)
        {
          if (len < ans) ans = len;
          break;
        }

        lvs = new SortedDictionary<int, int>();
      }

      /*
      foreach (int len in lvs.Keys)
        fout.Write(" " + len);
      fout.WriteLine();
      */

      int taken = 0;
      nlvs = new SortedDictionary<int, int>();
      foreach (int len in lvs.Keys)
      {
        if (taken >= cnt)
        {
          if (len < ans) ans = len;
          break;
        }

        int v;
        lvs.TryGetValue(len, out v);
        for (int j = 0; j < v; ++j)
        {
          if (taken >= cnt)
          {
            if (len < ans) ans = len;
            break;
          }

          // increment key at len + 1
          if (nlvs.ContainsKey(len + 1))
          {
            int t;
            nlvs.TryGetValue(len + 1, out t);
            nlvs.Remove(len + 1);
            nlvs.Add(len + 1, t + 1);
          }
          else
            nlvs.Add(len + 1, 1);

          ++taken;
        }
      }

      lvs = nlvs;
      if (cnt > taken)
        lvs.Add(1, cnt - taken);
    }

    // test shortest element
    foreach (int len in lvs.Keys)
    {
      if (len < ans) ans = len;
      break;
    }

    fout.Write("Case #" + caseId + ": " + ans + "\n");
  }

  public Solution()
  {
    try
    {
      fin = File.OpenText("bl.in");
      //fin = new StreamReader(Console.OpenStandardInput());
      fout = File.CreateText("bl.out");
      //fout = new StreamWriter(Console.OpenStandardOutput());

      int T = int.Parse(fin.ReadLine());
      for (int tc = 0; tc < T; ++tc)
        solve(tc + 1);

      fin.Close();
      fout.Close();
    }
    catch(Exception e)
    {
      Console.WriteLine(e);
    }
  }

  string[] st = new string[0];
  int p = 0;

  string next()
  {
    if (p >= st.Length)
    {
      st = fin.ReadLine().Split();
      p = 0;
    }
    return st[p++];
  }

  int nextInt()
  {
    return int.Parse(next());
  }

  long nextLong()
  {
    return long.Parse(next());
  }

  double nextDouble()
  {
    return double.Parse(next());
  }

  public static void Main()
  {
    new Solution();
  }
}
