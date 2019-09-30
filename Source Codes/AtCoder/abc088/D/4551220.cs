using System;
using System.Linq;

class Procon
{
  public Procon() {}
  static void Main(string[] agrs)
  {
    new Procon().Do();
  }

  Scanner cin;

  public bool Check(bool[,] b, int[,] dp, int H, int W, int i, int j) {
    if (i < 0 || H <= i) {
      return false;
    } 
    if (j < 0 || W <= j) {
      return false;
    } 
    if (dp[i,j] < 0) {
      return false;
    }
    if (b[i,j] == true) {
      return false;
    }

    return true;
  }

  public void Do()
  {
    cin = new Scanner();

    int H = cin.nextInt();
    int W = cin.nextInt();

    bool[,] b = new bool[H,W];
    int cnt = 0;

    for (int i=0; i<H; i++) {
      string tmp = cin.nextString();
      for (int j=0; j<W; j++) {
        if (tmp[j] == '.') {
          b[i,j] = false;
        } else {
          b[i,j] = true;
          cnt ++;
        }
      }
    }

    int[,] dp = new int[H,W];
    for (int i=0; i<H; i++) {
      for (int j=0; j<W; j++) {
        dp[i,j] = -1;
      }
    }
    dp[0,0] = 1;

    for (int k=0; k<H*W; k++) {
      for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
          if (b[i, j]) {
            continue;
          }
          if (Check(b, dp, H, W, i, j-1)) {
            int tmp = dp[i, j-1] + 1; 
            if (tmp < dp[i, j] || dp[i, j] == -1) {
              dp[i, j] = tmp;
            }
          }
          if (Check(b, dp, H, W, i, j+1)) {
            int tmp = dp[i, j+1] + 1; 
            if (tmp < dp[i, j] || dp[i, j] == -1) {
              dp[i, j] = tmp;
            }
          }
          if (Check(b, dp, H, W, i-1, j)) {
            int tmp = dp[i-1, j] + 1; 
            if (tmp < dp[i, j] || dp[i,j] == -1) {
              dp[i, j] = tmp;
            }
          }
          if (Check(b, dp, H, W, i+1, j)) {
            int tmp = dp[i+1, j] + 1; 
            if (tmp < dp[i, j] || dp[i, j] == -1) {
              dp[i, j] = tmp;
            }
          }
        }
      }
    }

    if  (dp[H-1, W-1] < 0) {
      Console.WriteLine(-1);
      return;
    }
    Console.WriteLine(H*W-dp[H-1,W-1]-cnt);
  }
}


class Scanner
{
  string[] s;
  int i;
  int max_i;

  public Scanner()
  {
    s = new string[0];
    max_i = 0;
    i = 0;
  }

  public string nextString()
  {
    if (i >= s.Length) 
    {
      s = Console.ReadLine().Split(' ');
      max_i = s.Length;
      i = 0;
      if (max_i == 0) 
      {
        return "";
      }
      return s[i++];
    } else 
    {
      return s[i++];
    }
  }

  public int nextInt()
  {
    return int.Parse(nextString());
  }


  public long nextLong()
  {
    return long.Parse(nextString());
  }

  public double nextDouble()
  {
    return double.Parse(nextString());
  }

  public string[] arrayString()
  {
    return Console.ReadLine().Split(' ');
  }

  public int[] arrayInt()
  {
    string[] str = Console.ReadLine().Split(' ');
    int[] array = new int[str.Length];
    for (int i=0; i<str.Length; i++) 
    {
      array[i] = int.Parse(str[i]);
    }
    return array;
  }

  public long[] arrayLong()
  {
    string[] str = Console.ReadLine().Split(' ');
    long[] array = new long[str.Length];
    for (int i=0; i<str.Length; i++) 
    {
      array[i] = long.Parse(str[i]);
    }
    return array;
  }

  public double[] arrayDouble()
  {
    string[] str = Console.ReadLine().Split(' ');
    double[] array = new double[str.Length];
    for (int i=0; i<str.Length; i++) 
    {
      array[i] = double.Parse(str[i]);
    }
    return array;
  }
}