using System;
using System.Collections.Generic;

public class C
{
  public static void Main ()
  {
    int n = int.Parse (Console.ReadLine ());
    
    for (int i = 1; i <= n; ++i)
    {
      string[] val = Console.ReadLine ().Split (' ');
      Console.WriteLine ("Case #{0}: {1}", i, 1.0 - Solve (double.Parse (val[0]), double.Parse (val[1]), double.Parse (val[2]), double.Parse (val[3]), double.Parse (val[4])));
    }
  }
  
  
  static double Solve (double f, double R, double t, double r, double g)
  {
    t += f;
    r += f;
    g -= 2 * f;
    
    f = R - t;
    
    if (g <= 0 || f - r <= 0)
      return 0;
    
    R /= f;
    t /= f;
    r /= f;
    g /= f;
    
    double sz = 0;
    
    for (double h0 = r; h0 < 1; h0 += 2 * r + g)
      for (double v0 = r; h0 * h0 + v0 * v0 < 1; v0 += 2 * r + g)
        sz += GetSize (h0, v0, g);
    
    return sz / (Math.PI * R * R / 4.0);
  }
  
  
  static double GetSize (double h0, double v0, double g)
  {
    double h1 = h0 + g;
    double v1 = v0 + g;
    
    if (h1 * h1 + v1 * v1 < 1)
      return g * g;
    
    double res = 0;
    
    if (h0 * h0 + v1 * v1 < 1)
    {
      double hn = Math.Sqrt (1.0 - v1 * v1);
      res += (hn - h0) * (v1 - v0);
      h0 = hn;
    }
    
    if (h1 * h1 + v0 * v0 < 1)
    {
      double vn = Math.Sqrt (1.0 - h1 * h1);
      res += (vn - v0) * (h1 - h0);
      v0 = vn;
    }
    
    h1 = Math.Sqrt (1.0 - v0 * v0);
    v1 = Math.Sqrt (1.0 - h0 * h0);
    
    res += (Math.Asin (v1) - Math.Asin (v0)) / 2.0;
    res -= (h1 - h0) * v0 / 2.0;
    res -= (v1 - v0) * h0 / 2.0;
    
    return res;
  }
}
