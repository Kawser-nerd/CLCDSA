using System;
public class P{
  public static void Main(){
    var a=Console.ReadLine().Split();
    int l=int.Parse(a[0]),h=int.Parse(a[1]),N=int.Parse(Console.ReadLine());
    for(int i=0;i<N;i++){int x=int.Parse(Console.ReadLine());Console.WriteLine(x>h?-1:x<l?l-x:0);}
  }
}