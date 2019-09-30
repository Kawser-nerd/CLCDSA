using System;
using System.Collections.Generic;
using System.Linq;
public class Hello{
    public static void Main(){
        var n = Console.ReadLine(); 
        var s = Console.ReadLine();
        var m = Console.ReadLine();
        var a = (s + " " + Console.ReadLine()).Split(' ').Select(int.Parse).ToList();
        var hash = new HashSet<int>();
        
        foreach(var i in a){
            hash.Add(i);
        }
        if(hash.Count != a.Count()){
            Console.WriteLine("NO");
        }else{
            Console.WriteLine("YES");
        }
    }
}