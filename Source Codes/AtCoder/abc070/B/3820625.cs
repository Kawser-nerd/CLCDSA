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

  public void Do()
  {
    cin = new Scanner();
    int a = cin.nextInt();
    int b = cin.nextInt();
    int c = cin.nextInt();
    int d = cin.nextInt();

    int max = Math.Min(b, d);
    int min = Math.Max(a, c);

    if (max-min > 0) {
      Console.WriteLine(max-min);
    } else {
      Console.WriteLine(0);
    }
    return;
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