using System;
public class P{
  public static void Main(){
    var s=Console.ReadLine().Split();
    int a=int.Parse(s[0]),b=int.Parse(s[1]);
    Console.WriteLine(b<a?(b+1)*a:b*(a+1));
  }
}