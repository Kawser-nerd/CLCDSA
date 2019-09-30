using System;
using System.Linq;
public class P{
  public static void Main(){
    int n=int.Parse(Console.ReadLine());
    Console.WriteLine(string.Join("\n",Console.ReadLine().Split().Select((x,y)=>new{a=int.Parse(x),b=y+1}).OrderBy(x=>-x.a).Select(x=>x.b)));
  }
}