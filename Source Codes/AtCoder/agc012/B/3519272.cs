using System;
using System.Linq;//??????
using System.Collections.Generic;
using System.Text;//????????????
class Solve
{
  List<int>[] G;
  int[] color;
  int[] us;//??????
  StringBuilder sb;//??
  
  public static void Main()
  {
    new Solve().Run();
  }
  
  void Run()
  {
    sb = new StringBuilder();
    Calc();
    Console.Write(sb.ToString());
  }
  
  void Calc()
  {
    string[] str = Console.ReadLine().Split(' ');
    int N = int.Parse(str[0]);
    int M = int.Parse(str[1]);
    G = new List<int>[N];//?????
    for(int i = 0; i < N; i++) G[i] = new List<int>();
    for(int i = 0; i < M; i++)//????????
    {
      str = Console.ReadLine().Split(' ');
      int a = int.Parse(str[0]) - 1;//?????1????????
      int b = int.Parse(str[1]) - 1;
      G[a].Add(b);
      G[b].Add(a);
    }
      
    int Q = int.Parse(Console.ReadLine());
    int[] V = new int[Q];//?????????
    int[] D = new int[Q];
    int[] C = new int[Q];
    for(int i = 0; i < Q; i++)
    {
      str = Console.ReadLine().Split(' ');
      V[i] = int.Parse(str[0])-1;
      D[i] = int.Parse(str[1]);
      C[i] = int.Parse(str[2]);
    }
      
    color = new int[N];
    us = new int[N];
    for(int i = 0; i < N; i++) us[i] = -1;//???
    
    for(int i = Q-1; i >= 0; i--)//?????????
    {
      if(us[V[i]] < D[i])//??????????????
      {
        dfs(V[i],D[i],C[i]);//???????????
      }
    }
    
    for(int i = 0; i < N; i++) sb.Append(color[i]+"\n");//????
  }
    
  void dfs(int v,int d,int c)//??????
  {
    us[v] = d;//??????
    if(color[v] == 0) color[v] = c;//????????????
    if(d != 0)//?????????????
    {
      for(int i = 0; i < G[v].Count; i++)//???????
      {
        int t = G[v][i];
        if(us[t] < d-1) dfs(t,d-1,c);
      }
    }
  }
}