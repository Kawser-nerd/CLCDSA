using System;
using System.Collections.Generic;

class B
{
  static int[] dx = { -1, 1, 0, 0 };
  static int[] dy = { 0, 0, -1, 1 };
  
  class Pt
  {
    public int x, y, ax, ay, bx, by;
    
    public Pt (int y, int x, int ay, int ax, int by, int bx)
    {
      this.x = x;
      this.y = y;
      this.ax = ax;
      this.ay = ay;
      this.bx = bx;
      this.by = by;
    }
  }
  
  public static void Main ()
  {
    int N = int.Parse (Console.ReadLine ());
    
    for (int I = 1; I <= N; ++I)
    {
      string[] ss = Console.ReadLine ().Split (' ');
      
      int y = int.Parse (ss[0]);
      int x = int.Parse (ss[1]);
      
      bool[,] map = new bool[y + 2, x + 2];
      
      int ax = 0, ay = 0, bx = 0, by = 0;
      
      for (int i = 0; i < y; ++i)
      {
        string s = Console.ReadLine ();
        for (int j = 0; j < x; ++j)
        {
          map[i + 1, j + 1] = s[j] != '#';
          
          if (s[j] == 'O')
          {
            ay = i + 1;
            ax = j + 1;
          }
          if (s[j] == 'X')
          {
            by = i + 1;
            bx = j + 1;
          }
        }
      }
      
      x += 2;
      y += 2;
      
      int[,,] wx = new int[y, x, 4];
      int[,,] wy = new int[y, x, 4];
      
      for (int i = 0; i < y; ++i)
        for (int j = 0; j < x; ++j)
          if (map[i, j])
      {
        for (int k = 0; k < 4; ++k)
        {
          int wwy = i;
          int wwx = j;
          
          while (map[wwy + dy[k], wwx + dx[k]])
          {
            wwy += dy[k];
            wwx += dx[k];
          }
          
          wy[i, j, k] = wwy;
          wx[i, j, k] = wwx;
        }
      }
      
      bool[,,,,,] qq = new bool[y, x, y, x, y, x];
      Queue<Pt> q = new Queue<Pt> ();
      q.Enqueue (new Pt (ay, ax, 0, 0, 0, 0));
      
      bool ok = false;
      
      for (int moves = 0; q.Count > 0 && !ok; ++moves)
      {
        Queue<Pt> nq = new Queue<Pt> ();
        
        while (q.Count > 0)
        {
          Pt p = q.Dequeue ();
          
//          Console.WriteLine ("deq {0} {1} {2} {3} {4} {5}", p.y, p.x, p.ay, p.ax, p.by, p.bx);
          
          if (qq[p.y, p.x, p.ay, p.ax, p.by, p.bx])
            continue;
          
          qq[p.y, p.x, p.ay, p.ax, p.by, p.bx] = true;
          
          if (p.y == by && p.x == bx)
          {
            Console.WriteLine ("Case {0}: {1}", I, moves);
            ok = true;
            break;
          }
          
          for (int k = 0; k < 4; ++k)
          {
            int ny = p.y + dy[k];
            int nx = p.x + dx[k];
            
            if (map[ny, nx] && !qq[ny, nx, p.ay, p.ax, p.by, p.bx])
              enq (nq, ny, nx, p.ay, p.ax, p.by, p.bx);
          }
          
          for (int k = 0; k < 4; ++k)
          {
//            Console.WriteLine ("hu {0} {1} {2} {3} {4} {5}", p.y, p.x, wy[p.y, p.x, k], wx[p.y, p.x, k], p.by, p.bx);
            
            if (!qq[p.y, p.x, wy[p.y, p.x, k], wx[p.y, p.x, k], p.by, p.bx])
              enq (q, p.y, p.x, wy[p.y, p.x, k], wx[p.y, p.x, k], p.by, p.bx);
            if (!qq[p.y, p.x, p.ay, p.ax, wy[p.y, p.x, k], wx[p.y, p.x, k]])
              enq (q, p.y, p.x, p.ay, p.ax, wy[p.y, p.x, k], wx[p.y, p.x, k]);
          }
          
          if (p.ay != 0 && p.by != 0 && p.y == p.ay && p.x == p.ax)
            enq2 (nq, p.by, p.bx, p.ay, p.ax, p.by, p.bx);
        }
        
        q = nq;
      }
      
      if (!ok)
        Console.WriteLine ("Case {0}: THE CAKE IS A LIE", I);
    }
  }
  
  static void enq (Queue<Pt> q, int y, int x, int ay, int ax, int by, int bx)
  {
//    Console.WriteLine ("enqueueing {0} {1} {2} {3} {4} {5}", y, x, ay, ax, by, bx);
    q.Enqueue (new Pt (y, x, ay, ax, by, bx));
  }
  static void enq2 (Queue<Pt> q, int y, int x, int ay, int ax, int by, int bx)
  {
//    Console.WriteLine ("enqueueing2 {0} {1} {2} {3} {4} {5}", y, x, ay, ax, by, bx);
    q.Enqueue (new Pt (y, x, ay, ax, by, bx));
  }
}
