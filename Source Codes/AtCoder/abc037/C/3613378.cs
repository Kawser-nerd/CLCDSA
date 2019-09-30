using System;
using System.Collections.Generic;
using System.Linq;
public class P{
  public static void Main(){
    var s=Console.ReadLine().Split().Select(int.Parse).ToArray();
  Console.WriteLine(Console.ReadLine().Split().Select((x,ind)=>{long a=long.Parse(x);return(new List<long>{ind+1,s[0]-ind,s[1],s[0]-s[1]+1}.Min()*a);}).Sum());
  }
}