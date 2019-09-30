using System;
using System.Collections.Generic;

class Procon
{
  public Procon() {}
  static void Main(string[] args)
  {
    new Procon().Do();
  }

  Scanner cin;

  public void Do()
  {
    cin = new Scanner();
    int N = cin.nextInt();
    int M = cin.nextInt();
    int R = cin.nextInt();

    int[] r = cin.arrayInt();

    int[,] x = new int[N, N];
    int MAX = int.MaxValue / 2 - 1;
    for (int i=0; i<N; i++) 
    {
      for (int j=0; j<N; j++) 
      {
        if (i==j) 
        {
          x[i,j] = 0;
        } else 
        {
          x[i,j] = MAX;
        }
      }
    }

    for (int i=0; i<M; i++) 
    {
      int a = cin.nextInt();
      int b = cin.nextInt();
      int c = cin.nextInt();
      x[a-1, b-1] = c;
      x[b-1, a-1] = c;
    }

    for (int k=0; k<N; k++) 
    {
      for (int i=0; i<N; i++) 
      {
        for (int j=0; j<N; j++)
        {
          x[i, j] = Math.Min(x[i,j], x[i, k] + x[k, j]);
        }
      }
    }

    int[] cr = new int[R];
    for (int i=0; i<R; i++) 
    {
      cr[i] = i;
    }

    long min = long.MaxValue / 2 - 1;;
    do 
    {
      int tmp = 0;
      for (int j=1; j<R; j++) 
      {
        tmp += x[r[cr[j-1]]-1, r[cr[j]]-1];
      }
      min = Math.Min(min, tmp);
    } while(next_permutation(cr));

    Console.WriteLine(min);
  }

  public static bool next_permutation<T>(T[] array) where T : IComparable<T> 
  {
    int end = array.Length - 1;
    int last = end;
    while (true)
    {
      int pos = last - 1;
      if (array[pos].CompareTo(array[last]) < 0)
      {
        int i;
        for (i=end;; i--) {
          if (array[pos].CompareTo(array[i])<0) {
            break;
          }
        }
        T tmp = array[pos];
        array[pos] = array[i];
        array[i] = tmp;
        Array.Reverse(array, last, end - last + 1);
        return true;
      }
      last --;
      if (last == 0 )
      {
        return false;
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
    if (i >= s.Length) {
      s = Console.ReadLine().Split(' ');
      max_i = s.Length;
      i = 0;
      if (max_i == 0) {
        return "";
      }
      return s[i++];
    } else {
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
    for (int i=0; i<str.Length; i++) {
      array[i] = int.Parse(str[i]);
    }
    return array;
  }

  public long[] arrayLong()
  {
    string[] str = Console.ReadLine().Split(' ');
    long[] array = new long[str.Length];
    for (int i=0; i<str.Length; i++) {
      array[i] = long.Parse(str[i]);
    }
    return array;
  }

  public double[] arrayDouble()
  {
    string[] str = Console.ReadLine().Split(' ');
    double[] array = new double[str.Length];
    for (int i=0; i<str.Length; i++) {
      array[i] = double.Parse(str[i]);
    }
    return array;
  }
}