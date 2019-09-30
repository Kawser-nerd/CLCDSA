using System;
using System.Linq;
 
class P{
  static void Main(){
    
    int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int W = n[0];
    int H = n[1];
    int N = n[2];
    int[] x = new int[N];
    int[] y = new int[N];
    int[] a = new int[N];
    for(int i = 0; i < N; i++){
      int[] m = Console.ReadLine().Split().Select(int.Parse).ToArray();
      x[i] = m[0];
      y[i] = m[1];
      a[i] = m[2];
    }
    
    int minX = 0, maxX = W, minY = 0, maxY = H;
    for(int i = 0; i < N; i++){
      if(a[i] == 1) minX = Math.Max(minX, x[i]);
      else if(a[i] == 2) maxX = Math.Min(maxX, x[i]);
      else if(a[i] == 3) minY = Math.Max(minY, y[i]);
      else maxY = Math.Min(maxY, y[i]);
    }
    
    int ans = maxX >= minX&&maxY >= minY ? (maxX - minX) * (maxY -minY) : 0;
    Console.WriteLine(ans);
    
  }
}