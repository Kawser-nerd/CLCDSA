using System;
using System.IO;
using System.Linq;

namespace CompetitiveProgramming
{

  class Solve
  {
 
    private void main()
    {
      int N = int.Parse(Console.ReadLine());
      ulong[] a = new ulong[N];
      ulong[] b = new ulong[N];
      int[] idx = new int[N];

      for (int i = 0; i < N; i++)
      {
        a[i] = ulong.Parse(Console.ReadLine());
        b[i] = a[i];
        idx[i] = i;
      }

      Array.Sort(a, idx);

      int ans = 0;
     
      for (int i= 0; i < N; i++)
      {
        if (i % 2 == 1 && idx[i] % 2 == 0)
        {
          ans++;
        }
      }

      Console.WriteLine(ans);
    
    }


    public Solve()
    {
      Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
      main();
      Console.Out.Flush();
    }
  }

  class Program
  {
    static void Main(string[] args)
    {
      new Solve();
    }
  }

}