using System;
public class P{
  public static void Main(){
    var s=Console.ReadLine().Split();
    var a=new {a=int.Parse(s[0]),b=int.Parse(s[1]),c=int.Parse(s[2])};
    Console.WriteLine(a.c/(a.a<a.b?a.a:a.b));
  }
}