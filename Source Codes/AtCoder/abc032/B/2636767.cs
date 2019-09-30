using System;
using System.Collections.Generic;
public class Hello{
    public static void Main(){
        string s = Console.ReadLine();
        int n = int.Parse(Console.ReadLine());
        var hash = new HashSet<string>();
        
        if(s.Length < n){
            Console.WriteLine(0);
            return;
        }
        
        for(var i = 0;i < s.Length - n + 1;i++){
            hash.Add(s.Substring(i,n));    
        }
        Console.WriteLine(hash.Count);
    }
}