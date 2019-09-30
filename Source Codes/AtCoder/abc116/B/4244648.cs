using System;
using System.Linq;
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
    int s = cin.nextInt();
    
    int n = s;
    List<int> prevn = new List<int>();
    for (int i=1; ;i++) {
      prevn.Add(n);
      n = fn(n);
      for (int j=0; j<i; j++) {
        if (prevn[j] == n) {
          Console.WriteLine(i+1);
          return;
        }
      }
    }
  }

  public static int fn(int n) {
    if (n%2 == 0) {
      return n/2;
    } else {
      return 3 * n+1;
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