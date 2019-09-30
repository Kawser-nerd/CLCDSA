using System;

class main{
  public static int Main(){
      int s = 0;
      string a = Console.ReadLine();
      string b = Console.ReadLine();
      int p = (int.Parse(b) - 1) / 5;
      int q = int.Parse(b) % 5;
      if( q == 0){
        s = 4;
      }else{
        s = q - 1;
      }
      string r = String.Concat(a[p],a[s]);
      Console.WriteLine(r);
      return 0;
  }
}