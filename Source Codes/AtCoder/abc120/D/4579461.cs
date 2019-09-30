using System;
using System.Collections.Generic;
using System.Linq;

class Tree {
  public Tree parent;
  public List<Tree> children;
  public string name;
  public long sum;
  public long height;
}
class Procon {
  public Procon () { }
  static void Main (string[] agrs) {
    new Procon ().Do ();
  }

  Scanner cin;

  public Tree GetParent (Tree t) {
    var tmp = t;
    while (true) {
      if (tmp.parent == null) {
        break;
      }
      tmp = tmp.parent;
    }
    return tmp;
  }

  public Tree GetChildOfHeight (Tree t, long height) {
    var tmp = t;
    while (true) {
      if (tmp.height == height + 1) {
        break;
      }
      tmp = tmp.children[0];
    }
    return tmp;
  }

  public void UpdateTree (Tree t, long sum) {
    var tmp = t;
    tmp.sum += sum;
    while (true) {
      if (tmp.parent == null) {
        break;
      }
      tmp = tmp.parent;
      tmp.sum += sum;
    }
  }

  public void Do () {
    cin = new Scanner ();
    long N = cin.nextLong ();
    long M = cin.nextLong ();

    long[, ] ab = new long[M, 2];
    for (long i = 0; i < M; i++) {
      ab[i, 0] = cin.nextInt () - 1;
      ab[i, 1] = cin.nextInt () - 1;
    }

    Tree[] shima = new Tree[N];
    for (long i = 0; i < N; i++) {
      shima[i] = new Tree ();
      shima[i].name = "shima" + i.ToString ();
      shima[i].sum = 1;
      shima[i].height = 1;
      shima[i].children = null;
    }

    long[] retarray = new long[M];
    Tree[] hashi = new Tree[M];
    long ret = N * (N - 1) / 2;
    for (long i = 0; i < M; i++) {
      retarray[M - i - 1] = ret;
      long a = ab[M - i - 1, 0];
      long b = ab[M - i - 1, 1];
      var roota = GetParent (shima[a]);
      var rootb = GetParent (shima[b]);
      if (roota.name == rootb.name) {
        continue;
      }
      ret -= roota.sum * rootb.sum;
      if (roota.height == rootb.height) {
        hashi[i] = new Tree ();
        hashi[i].name = "hasahi" + i.ToString ();
        hashi[i].sum = roota.sum + rootb.sum;
        hashi[i].height = roota.height + 1;
        hashi[i].children = new List<Tree> ();
        hashi[i].children.Add (roota);
        hashi[i].children.Add (rootb);
        roota.parent = hashi[i];
        rootb.parent = hashi[i];
      } else if (roota.height > rootb.height) {
        var tmp = GetChildOfHeight (roota, rootb.height);
        tmp.children.Add (rootb);
        rootb.parent = tmp;
        UpdateTree (tmp, rootb.sum);
      } else {
        var tmp = GetChildOfHeight (rootb, roota.height);
        tmp.children.Add (roota);
        roota.parent = tmp;
        UpdateTree (tmp, roota.sum);
      }
    }

    for (long i = 0; i < M; i++) {
      Console.WriteLine (retarray[i]);
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