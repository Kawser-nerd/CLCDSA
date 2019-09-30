using System;

class main{
  public static int Main(){
      string[] a = Console.ReadLine().Split(' ');
      string[] s = Console.ReadLine().Split(' ');
      int n = int.Parse(s[0]) * int.Parse(a[0]);
      int m = int.Parse(s[1]) * int.Parse(a[1]);
      int o = int.Parse(s[0]) + int.Parse(s[1]);
      if( int.Parse(a[3]) <= o){
        Console.WriteLine(n + m - (o * int.Parse(a[2])));
      }else{
        Console.WriteLine(n + m);
      }
      return 0;
  }
}