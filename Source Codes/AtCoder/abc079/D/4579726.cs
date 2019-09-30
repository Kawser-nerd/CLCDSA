using System;
using System.Linq;

class Procon {
  public Procon () { }
  static void Main (string[] agrs) {
    new Procon ().Do ();
  }

  Scanner cin;

  public void Do () {
    cin = new Scanner ();
    int H = cin.nextInt ();
    int W = cin.nextInt ();
    int[, ] c = new int[10, 10];

    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        c[i, j] = cin.nextInt ();
      }
    }

    int[, ] A = new int[H, W];
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        A[i, j] = cin.nextInt ();
      }
    }

    int[] DP = new int[10];
    for (int i = 0; i < 10; i++) {
      DP[i] = c[i, 1];
    }

    for (int j = 0; j < 10; j++) {
      for (int i = 0; i < 10; i++) {
        for (int k = 0; k < 10; k++) {
          int tmp = c[i, k] + DP[k];
          if (tmp < DP[i]) {
            DP[i] = tmp;
          }
        }
      }
    }

    int ret = 0;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (A[i, j] == -1) {
          continue;
        }
        ret += DP[A[i, j]];
      }
    }
    Console.WriteLine (ret);
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