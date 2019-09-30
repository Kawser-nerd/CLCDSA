using System;
using System.Collections.Generic;
using System.Linq;

class Program {
  public Program () { }

  Scanner cin;

  int N;

  static void Main (string[] agrs) {
    new Program ().Do ();
  }

  public void Do () {
    cin = new Scanner ();
    N = cin.nextInt ();

    if (N == 3) {
      Console.WriteLine (2);
      Console.WriteLine ("{0} {1}", 1, 3);
      Console.WriteLine ("{0} {1}", 2, 3);
    } else if (N == 4) {
      Console.WriteLine (4);
      Console.WriteLine ("{0} {1}", 1, 2);
      Console.WriteLine ("{0} {1}", 1, 3);
      Console.WriteLine ("{0} {1}", 4, 2);
      Console.WriteLine ("{0} {1}", 4, 3);
    } else if (N % 2 == 0) {
      Console.WriteLine (2 * N);
      for (int i = 0; i < N / 2; i++) {
        if (i + 1 < N / 2) {
          Console.WriteLine ("{0} {1}", i + 1, i + 2);
          Console.WriteLine ("{0} {1}", i + 1, N - 1 - i);
          Console.WriteLine ("{0} {1}", N - i, i + 2);
          Console.WriteLine ("{0} {1}", N - i, N - 1 - i);
        }
      }
      Console.WriteLine ("{0} {1}", N / 2, 1);
      Console.WriteLine ("{0} {1}", N / 2, N);
      Console.WriteLine ("{0} {1}", N / 2 + 1, 1);
      Console.WriteLine ("{0} {1}", N / 2 + 1, N);
    } else {
      Console.WriteLine (2 * (N - 1));
      for (int i = 0; i < (N - 1) / 2; i++) {
        if (i + 1 < ((N - 1) / 2)) {
          Console.WriteLine ("{0} {1}", i + 1, i + 2);
          Console.WriteLine ("{0} {1}", i + 1, N - 2 - i);
          Console.WriteLine ("{0} {1}", N - 1 - i, i + 2);
          Console.WriteLine ("{0} {1}", N - 1 - i, N - 2 - i);
        }
      }

      Console.WriteLine ("{0} {1}", N, 1);
      Console.WriteLine ("{0} {1}", N, N - 1);
      Console.WriteLine ("{0} {1}", N, N / 2);
      Console.WriteLine ("{0} {1}", N, N / 2 + 1);
    }
  }
}

class Scanner {
  string[] s;
  int i;
  int max_i;

  public Scanner () {
    s = new string[0];
    max_i = 0;
    i = 0;
  }

  public string nextString () {
    if (i >= s.Length) {
      s = Console.ReadLine ().Split (' ');
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

  public int nextInt () {
    return int.Parse (nextString ());
  }

  public long nextLong () {
    return long.Parse (nextString ());
  }

  public double nextDouble () {
    return double.Parse (nextString ());
  }

  public string[] arrayString () {
    return Console.ReadLine ().Split (' ');
  }

  public int[] arrayInt () {
    string[] str = Console.ReadLine ().Split (' ');
    int[] array = new int[str.Length];
    for (int i = 0; i < str.Length; i++) {
      array[i] = int.Parse (str[i]);
    }
    return array;
  }

  public long[] arrayLong () {
    string[] str = Console.ReadLine ().Split (' ');
    long[] array = new long[str.Length];
    for (int i = 0; i < str.Length; i++) {
      array[i] = long.Parse (str[i]);
    }
    return array;
  }

  public double[] arrayDouble () {
    string[] str = Console.ReadLine ().Split (' ');
    double[] array = new double[str.Length];
    for (int i = 0; i < str.Length; i++) {
      array[i] = double.Parse (str[i]);
    }
    return array;
  }
}