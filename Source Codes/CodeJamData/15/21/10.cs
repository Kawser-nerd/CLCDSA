using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2015_BA
{
  class Program
  {
    static int revInt(int p)
    {
      int r = 0;
      while (p > 0)
      {
        int d = p % 10;
        p /= 10;
        r *= 10;
        r += d;
      }
      return r;
    }
    static long revLong(long p)
    {
      long r = 0;
      while (p > 0)
      {
        long d = p % 10L;
        p /= 10L;
        r *= 10L;
        r += d;
      }
      return r;
    }


    static List<long> RevPoints(long n)
    {
      if ((n % 10L) == 0L) --n;
      var o = new List<long>();

      if (n < 20L) return o;
      if (n < 100L)
      {
        o.Add(10L + (n / 10L));
        return o;
      }
      o.Add(19);
      if (n <= 200L) return o;
      if (n < 1000L)
      {
        long r = revLong(n);
        o.Add(100L + (r % 100L));
        return o;
      }
      o.Add(199L);

      long a = 1000L;
      long b = 1100L;
      long c = 100L;
      bool cc = true;

      while (a > 0L)
      {
        if (n < b) return o;
        long a10 = a * 10L;
        if (n < a10)
        {
          long r = revLong(n);
          o.Add(a + r % c);
          return o;
        }
        o.Add(a + c - 1L);

        a *= 10L;
        if (cc) c *= 10L;
        cc = !cc;
        b = a + c;
      }
      throw new Exception("overflow!");
    }

    static long Solve(long n)
    {

      var rp = RevPoints(n);
      long a = 0;
      long c = 0;
      foreach(long r in rp)
      {
        c += (r - a) + 1;
        a = revLong(r);
      }
      c += (n - a);

      //Console.WriteLine("{0,8} {1,8} {2}", n, c, String.Join(", ", rp));

      return c;
    }

    static void Main(string[] args)
    {
            int tests = ReadInt();
            for (int test = 1; test <= tests; ++test)
            {
              long t = ReadLong();
              long result = Solve(t);
              Console.WriteLine("Case #{0}: {1}", test, result);
            }
/*
      var ii = new[] { 10000000,
          10000001,
          10000010,
          10000100,
          10001000,
          10010000,
          10100000,
          11000000,
          12000000,
          13000000,
          14000000,
          15000000,
          16000000,
          17000000,
          18000000,
          19000000,
          20000000,
         100000000 };

      foreach(var i in ii)
      {
        Solve((long)i);
      }*/
    }

    static void MainI(string[] args)
    {
      int N = 100000001;
      int[] c = new int[N];
      var rl = new int[N];
      c[1] = 1;
      rl[1] = 0;
      var q = new Queue<int>();
      q.Enqueue(1);
      while(q.Count > 0)
      {
        int j = q.Dequeue();
        int d = c[j] + 1;
        var jrl = rl[j];
        if (j + 1 < N)
        {
          if ((c[j+1] == 0) || c[j+1] > d)
          {
            c[j + 1] = d;
            rl[j + 1] = jrl;
            q.Enqueue(j + 1);
          }
        }
        int r = revInt(j);
        if ((r > 0) && (r < N))
        {
          if ((c[r] == 0) || (c[r] > d))
          {
            c[r] = d;
            rl[r] = j;
            q.Enqueue(r);
          }
        }
      }

      var ii = new[] { 10000000,
          10000001,
          10000010,
          10000100,
          10001000,
          10010000,
          10100000,
          11000000,
          12000000,
          13000000,
          14000000,
          15000000,
          16000000,
          17000000,
          18000000,
          19000000,
          20000000,
         100000000 };

      foreach(var i in ii)
      {
        Console.WriteLine("{0,8} {1,8} {2}", i, c[i], rl[i]);
      }

      /*
      int tests = ReadInt();
      for (int test = 1; test <= tests; ++test)
      {
        int t = ReadInt();
        int result = c[t];
        Console.WriteLine("Case #{0}: {1}", test, result);
      }
      */
    }

    static int ReadInt()
    {
      return Convert.ToInt32(Console.ReadLine());
    }

    static long ReadLong()
    {
      return Convert.ToInt64(Console.ReadLine());
    }

    static IEnumerable<String> ReadStrings()
    {
      string line = Console.ReadLine();
      return line.Split((char[])null, StringSplitOptions.RemoveEmptyEntries);
    }

    static IEnumerable<int> ReadInts()
    {
      return ReadStrings().Select(s => Convert.ToInt32(s));
    }

    static IEnumerable<long> ReadLongs()
    {
      return ReadStrings().Select(s => Convert.ToInt64(s));
    }

    static int[] ReadInts(int count)
    {
      return ReadInts().Take(count).ToArray();
    }

  }
}
