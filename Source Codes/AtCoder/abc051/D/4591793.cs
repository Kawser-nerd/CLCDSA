using System;
using System.Collections.Generic;
using System.Linq;

class Node {
  public List<Edge> edges;
  public int cost;
}

class Edge {
  public Node node1;
  public Node node2;
  public int cost;
}

class Procon {
  public Procon () { }
  static void Main (string[] agrs) {
    new Procon ().Do ();
  }

  Scanner cin;

  public int calc (Node[] n, Edge[] e, Node start, Node end) {
    for (int i = 0; i < n.Count (); i++) {
      n[i].cost = 0;
    }

    Queue<Node> que = new Queue<Node> ();
    que.Enqueue (start);

    while (que.Count () > 0) {
      var node = que.Dequeue ();
      for (int i = 0; i < node.edges.Count (); i++) {
        var edge = node.edges[i];
        var cost = node.cost + edge.cost;
        if (edge.node1 == node) {
          if (edge.node2.cost == 0 || cost < edge.node2.cost) {
            edge.node2.cost = cost;
            que.Enqueue (edge.node2);
          }
        } else if (edge.node2 == node) {
          if (edge.node1.cost == 0 || cost < edge.node1.cost) {
            edge.node1.cost = cost;
            que.Enqueue (edge.node1);
          }
        }
      }
    }

    return end.cost;
  }
  public void Do () {
    cin = new Scanner ();

    var N = cin.nextInt ();
    var M = cin.nextInt ();

    Node[] nodes = new Node[N];
    for (int i = 0; i < N; i++) {
      nodes[i] = new Node ();
      nodes[i].edges = new List<Edge> ();
    }

    Edge[] edges = new Edge[M];
    for (int i = 0; i < M; i++) {
      edges[i] = new Edge ();
      edges[i].node1 = nodes[cin.nextInt () - 1];
      edges[i].node2 = nodes[cin.nextInt () - 1];
      edges[i].cost = cin.nextInt ();

      edges[i].node1.edges.Add (edges[i]);
      edges[i].node2.edges.Add (edges[i]);
    }

    int ret = 0;
    for (int i = 0; i < M; i++) {
      var cost = calc (nodes, edges, edges[i].node1, edges[i].node2);
      if (cost < edges[i].cost) {
        ret++;
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