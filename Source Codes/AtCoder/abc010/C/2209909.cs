using System;
using System.Linq;

class Program
{
  static void Main()
  {
    string[ ] input = Console.ReadLine().Split(' ');
    int tXa = int.Parse(input[0]);
    int tYa = int.Parse(input[1]);
    int tXb = int.Parse(input[2]);
    int tYb = int.Parse(input[3]);
    int T = int.Parse(input[4]);
    int V = int.Parse(input[5]);
    int n  = int.Parse(Console.ReadLine());
    int[ ] x = new int[n];
    int[ ] y = new int[n];
    for(int i = 0; i < n; i++)
    {
      string[ ] place = Console.ReadLine().Split(' ');
      x[i] = int.Parse(place[0]);
      y[i] = int.Parse(place[1]);
    }
    double[ ] dis = new double[n];
    double[ ] d1 = new double[n];
    double[ ] d2 = new double[n];
    double[ ] D1 = new double[n];
    double[ ] D2 = new double[n];
    for(int j = 0; j < n; j++)
    {
      D1[j] = Math.Pow(tXa - x[j], 2) + Math.Pow(tYa - y[j], 2);
      D2[j] = Math.Pow(tXb - x[j], 2) + Math.Pow(tYb - y[j], 2);
      d1[j] = Math.Sqrt(D1[j]);
      d2[j] = Math.Sqrt(D2[j]);
      dis[j] = d1[j] + d2[j];
    }
    double D = dis.Min();
    if(T * V >= D)
    {
      Console.WriteLine("YES");
    }
    else
    {
      Console.WriteLine("NO");
    }
  }
}