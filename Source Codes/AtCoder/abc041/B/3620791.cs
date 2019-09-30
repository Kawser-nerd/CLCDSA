using System;
public class P{
  public static void Main(){
    var s=Console.ReadLine().Split();
    Console.WriteLine((ulong.Parse(s[0])*ulong.Parse(s[1])%1000000007)*ulong.Parse(s[2])%1000000007);
  }
}