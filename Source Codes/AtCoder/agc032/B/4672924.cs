using System;
using System.Collections.Generic;

public class Program {
  public static void Main(string[] args) {
    List<Pair> conns = new List<Pair>();
    
    int N = int.Parse(Console.ReadLine());
    int[] nodeSumMaxes = new int[N];
    nodeSumMaxes[1-1] = (N-1) * (2 + N) / 2; //2??N????
    for(int i = 1; i < N; ++i) {
      nodeSumMaxes[i] = nodeSumMaxes[i-1] - 1;
    }
    
    int S = nodeSumMaxes[N-1];
    if(N % 2 == 0) --S;
    
    for(int i = 0; i < N; ++i) {
      int diff = nodeSumMaxes[i] - S;
      for(int j = i; j < N; ++j) {
        if(j+1 != diff && i != j) {
          conns.Add(new Pair(i+1, j+1));
        }
      }
    }
    
    Console.WriteLine(conns.Count);
    foreach(var conn in conns) {
      Console.WriteLine(conn.a + " " + conn.b);
    }
  }
}

class Pair {
  public int a;
  public int b;
  
  public Pair(int a, int b) {
    this.a = a;
    this.b = b;
  }
}