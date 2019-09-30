using System;

class main{
  public static int Main(){
      string[] a = Console.ReadLine().Split(' ');
      if( a[0] == a[1] && a[1] == a[2]){
        Console.WriteLine(a[0]);
      }else if( a[0] != a[1] && a[1] == a[2]){
        Console.WriteLine(a[0]);
      }else if( a[0] != a[1] && a[0] == a[2]){
        Console.WriteLine(a[1]);
      }else{
        Console.WriteLine(a[2]);
      }
      return 0;
  }
}