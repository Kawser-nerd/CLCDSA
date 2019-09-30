using System;
using System.Linq;
public class P{
  public static void Main(){
    var s=Console.ReadLine().Split().Select(int.Parse).ToArray();
    var a=Enumerable.Repeat(0,s[0]).ToArray();
    for(int i=0;i<s[1];i++){
      var b=Console.ReadLine().Split().Select(int.Parse).ToArray();
      a[b[0]-1]++;
      a[b[1]-1]++;
    }
    Console.WriteLine(string.Join("\n",a));
  }
}