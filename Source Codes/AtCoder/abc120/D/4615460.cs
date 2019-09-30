using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;

class _Class
{
  class UnionFind
  {
    public int Size(int i)
    {
      var last = Root(i);
      return _size[last];
    }

    public int Root(int newest)
    {
      var last = newest;
      for (; ;) 
      {
        if (_t[last] == last)
          break;

        last = _t[last];
      }

      _t[newest] = last ;

      return last;
    }

    public bool IsSame(int i1, int i2)
    {
      var ii1 = Root(i1);
      var ii2 = Root(i2);
      if(ii1==ii2)
        return true;
      return false;
    }

    public void Unite(int i1, int i2)
    {
      var ii1 = Root(i1);
      var ii2 = Root(i2);

      if (ii1 == ii2)
        return;

      if (ii1 > ii2)
      {
        var tmp = ii1;
        ii1 = ii2;
        ii2 = tmp;
      }
      //
      _t[ii2] = ii1;
      _size[ii1] += _size[ii2];
    }

    public UnionFind(int len)
    {
      _size = new int[len];

      _t = new int[len];

      for (int i = 0; i < len; i++)
      {
        _size[i] = 1;
        _t[i] = i;
      }
    }
    int[] _size;
    int[] _t;
  }


  class Int2
  {
    public int i1;
    public int i2;
    public Int2(int i1,int i2)
    {
      this.i1 = i1;
      this.i2 = i2;
    }
  }

  void _Do()
  {    
    //
    var ints = Split.ints();
    var N = ints[0];
    var M_edge = ints[1];
    //
    var ab = new List<Int2>();
    for (int i = 0; i < M_edge; i++)
    {
      ints = Split.ints();
      ab.Add(new Int2(ints[0],ints[1]));
    }

    var MAX = 1L*N * (N - 1) / 2;


    var ss = new List<string>();
    var sum = 0L;

    // ??N
    var uf = new UnionFind(N+1);
    var cc = new long[N+1];

    // 1..M
    for (int i=M_edge;i>=1 ;i-- )
    {
      if(i == M_edge)
      {
        sum += 0; 
      }else
      {
        if (!uf.IsSame(ab[i].i1, ab[i].i2))
        {
          var r1 = uf.Root(ab[i].i1);
          var r2 = uf.Root(ab[i].i2);

          sum += (uf.Size(r1) * uf.Size(r2));


          uf.Unite(ab[i].i1, ab[i].i2);




        }
        else
          sum += 0;
      }

      //
      ss.Add($"{MAX - sum}");
    }

    // ?
    ss.Reverse();
    for(int i=0;i< ss.Count;i++)
      Console.WriteLine(ss[i]);
  }


  static void Main(string[] args)
  {
    new _Class()._Do();
  }
}

static class Split
{ 

  // 1
  public static string[] strings()
  {
    return Console.ReadLine().Split();
  }


  // [2.1] -2,147,483,648 ~ +2,147,483,647
  public static int[] ints()
  {
    var _s = Console.ReadLine().Split();

    var x = new int[_s.Length];
    for (var i = 0; i < _s.Length; i++)
      x[i] = int.Parse(_s[i]);

    return x;
  }

  // [2.2] 
  // -9,223,372,036,854,775,808 ~ 
  // +9,223,372,036,854,775,807
  public static long[] longs()
  {
    var _s = Console.ReadLine().Split();

    var x = new long[_s.Length];
    for (var i = 0; i < _s.Length; i++)
      x[i] = long.Parse(_s[i]);

    return x;
  }

  public static double[] doubles()
  {
    var _s = Console.ReadLine().Split();

    var x = new double[_s.Length];
    for (var i = 0; i < _s.Length; i++)
      x[i] = double.Parse(_s[i]);

    return x;
  }

  public static BigInteger[] bigs()
  {
    var _s = Console.ReadLine().Split();

    var x = new BigInteger[_s.Length];
    for (var i = 0; i < _s.Length; i++)
      x[i] = BigInteger.Parse(_s[i]);

    return x;
  }
}