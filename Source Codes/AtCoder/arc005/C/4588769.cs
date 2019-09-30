using System;
using System.Collections.Generic;
using System.Linq;

class Procon {
  public Procon () { }
  static void Main (string[] agrs) {
    new Procon ().Do ();
  }

  public bool CheckBorder (int i, int j, int H, int W) {
    if (i < 0 || H <= i) {
      return false;
    }
    if (j < 0 || W <= j) {
      return false;
    }
    return true;
  }

  Scanner cin;

  public void Do () {
    cin = new Scanner ();
    int H = cin.nextInt ();
    int W = cin.nextInt ();
    int[, ] c = new int[H, W];
    int[] s = new int[2];
    int[] g = new int[2];

    for (int i = 0; i < H; i++) {
      var tmp = cin.nextString ();
      for (int j = 0; j < W; j++) {
        if (tmp[j] == 's') {
          s[0] = i;
          s[1] = j;
          c[i, j] = 0;
        } else if (tmp[j] == 'g') {
          g[0] = i;
          g[1] = j;
          c[i, j] = 0;
        } else if (tmp[j] == '.') {
          c[i, j] = 0;
        } else if (tmp[j] == '#') {
          c[i, j] = 1;
        }
      }
    }

    int[, ] cost = new int[H, W];
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        cost[i, j] = -1;
      }
    }

    Queue<int[]> queue = new Queue<int[]> ();

    cost[s[0], s[1]] = 0;
    queue.Enqueue (s);
    while (queue.Count () > 0) {
      var tmp = queue.Dequeue ();
      int i = tmp[0];
      int j = tmp[1];
      if (CheckBorder (i, j - 1, H, W)) {
        var nc = cost[i, j] + c[i, j - 1];
        if (cost[i, j - 1] < 0 || nc < cost[i, j - 1]) {
          cost[i, j - 1] = nc;
          queue.Enqueue (new int[2] { i, j - 1 });
        }
      }
      if (CheckBorder (i, j + 1, H, W)) {
        var nc = cost[i, j] + c[i, j + 1];
        if (cost[i, j + 1] < 0 || nc < cost[i, j + 1]) {
          cost[i, j + 1] = nc;
          queue.Enqueue (new int[2] { i, j + 1 });
        }
      }
      if (CheckBorder (i - 1, j, H, W)) {
        var nc = cost[i, j] + c[i - 1, j];
        if (cost[i - 1, j] < 0 || nc < cost[i - 1, j]) {
          cost[i - 1, j] = nc;
          queue.Enqueue (new int[2] { i - 1, j });
        }
      }
      if (CheckBorder (i + 1, j, H, W)) {
        var nc = cost[i, j] + c[i + 1, j];
        if (cost[i + 1, j] < 0 || nc < cost[i + 1, j]) {
          cost[i + 1, j] = nc;
          queue.Enqueue (new int[2] { i + 1, j });
        }
      }
    }
    if (cost[g[0], g[1]] <= 2) {
      Console.WriteLine ("YES");
    } else {
      Console.WriteLine ("NO");
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