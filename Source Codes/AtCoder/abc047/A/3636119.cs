using System;
using System.Linq;
public class P{
  public static void Main(){
    var s=Console.ReadLine().Split().Select(int.Parse).OrderBy(x=>x).ToArray();
    Console.WriteLine((s[2]==s[1]+s[0])?"Yes":"No");
  }
}