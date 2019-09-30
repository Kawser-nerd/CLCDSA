using System;
using System.Collections.Generic;

class Procon
{
  public Procon() {}
  static void Main(string[] agrs)
  {
    new Procon().Do();
  }

  Scanner cin;

  public void Do()
  {
    cin = new Scanner();
    int N = cin.nextInt();
    List<int[]>[] node = new List<int[]>[N];
    for (int i=0; i<N; i++) {
      node[i] = new List<int[]>();
    }
    for (int i=0; i<N-1; i++) {
      int a = cin.nextInt()-1;
      int b = cin.nextInt()-1;
      int c = cin.nextInt();
      node[a].Add(new int[]{b, c});
      node[b].Add(new int[]{a, c});
    }

    int Q = cin.nextInt();
    int K = cin.nextInt() - 1;
    long[] d = new long[N];
    for (int i=0; i<N; i++) 
    {
      d[i] = -1;
    }
    d[K] = 0;

    recur(node, d, K);

    for (int i=0; i<Q; i++) 
    {
      int x = cin.nextInt() - 1;
      int y = cin.nextInt() - 1;
      Console.WriteLine((long)d[x] + (long)d[y]);
    }
  }
  
  public static void recur(List<int[]>[] node, long[] d, int n) 
  {
    for (int i=0; i < node[n].Count; i++) 
    {
      if (d[n] >= 0 && d[node[n][i][0]] < 0) 
      {
        d[node[n][i][0]] = d[n] + node[n][i][1];
        recur(node, d, node[n][i][0]);
      }
    }
  }
}


class Scanner
{
  string[] s;
  int i;
  int max_i;

  public Scanner()
  {
    s = new string[0];
    max_i = 0;
    i = 0;
  }

  public string nextString()
  {
    if (i >= s.Length) 
    {
      s = Console.ReadLine().Split(' ');
      max_i = s.Length;
      i = 0;
      if (max_i == 0) 
      {
        return "";
      }
      return s[i++];
    } else 
    {
      return s[i++];
    }
  }

  public int nextInt()
  {
    return int.Parse(nextString());
  }


  public long nextLong()
  {
    return long.Parse(nextString());
  }

  public double nextDouble()
  {
    return double.Parse(nextString());
  }

  public string[] arrayString()
  {
    return Console.ReadLine().Split(' ');
  }

  public int[] arrayInt()
  {
    string[] str = Console.ReadLine().Split(' ');
    int[] array = new int[str.Length];
    for (int i=0; i<str.Length; i++) 
    {
      array[i] = int.Parse(str[i]);
    }
    return array;
  }

  public long[] arrayLong()
  {
    string[] str = Console.ReadLine().Split(' ');
    long[] array = new long[str.Length];
    for (int i=0; i<str.Length; i++) 
    {
      array[i] = long.Parse(str[i]);
    }
    return array;
  }

  public double[] arrayDouble()
  {
    string[] str = Console.ReadLine().Split(' ');
    double[] array = new double[str.Length];
    for (int i=0; i<str.Length; i++) 
    {
      array[i] = double.Parse(str[i]);
    }
    return array;
  }
}