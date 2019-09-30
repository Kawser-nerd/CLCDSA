using System;
using System.Linq;
public class P{
  public static void Main(){
    var s=Console.ReadLine().Split().Select(int.Parse).ToArray();
    int[] a=Enumerable.Repeat(0,s[0]).ToArray();
    for(int i=0;i<s[1];i++){
      var r=Console.ReadLine().Split().Select(int.Parse).ToArray();
       for(int f=r[0]-1;f<r[1];f++)a[f]=r[2];
    }
    foreach(int v in a)Console.WriteLine(v);
  }
}