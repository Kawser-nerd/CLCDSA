using System;

class Program
{
  static void Main()
  {
    int N = int.Parse(Console.ReadLine());
    int[] NG = new int[3];
    for(int i = 0; i < 3; i++)
    {
      NG[i] = int.Parse(Console.ReadLine());
    }
    Array.Sort(NG);
    if(NG[0] + 1 == NG[1] && NG[1] + 1 == NG[2] && N > NG[2])
    {
      Console.WriteLine("NO");
    }
    else if(N == NG[0] || N == NG[1] || N == NG[2])
    {
      Console.WriteLine("NO");
    }
    else{
      int i = 1;
      int count = 0;
      while(true){
      for(i = i; N - 3 > 0 && N - 3 != NG[0] && N - 3 != NG[1] && N - 3 != NG[2]; i++)
      {
        N = N - 3;
        count++;
      }
      if(N - 3 <= 0)
      {
        count++;
        break;
      }
      else{
        if(N - 2 == NG[0] || N - 2 == NG[1] || N - 2 == NG[2])
        {
          N = N - 1;
          count++;
        }
        else
        {
          N = N - 2;
          count++;
        }
      }
      }
      if(count <= 100)
      {
        Console.WriteLine("YES");
      }
      else
      {
        Console.WriteLine("NO");
      }
    }
  }
}