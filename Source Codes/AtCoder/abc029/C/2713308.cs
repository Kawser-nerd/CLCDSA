using System;
using System.Collections.Generic;
using System.Linq;
public class Hello{
    public static void Main(){
        var MAX_LENGTH = int.Parse(Console.ReadLine());
        Dive("",MAX_LENGTH);
        
    }
    
    static void Dive(string prefix,int level){
        if(level == 0){
            Console.WriteLine(prefix);
        }else{
            foreach(var c in new char [3] {'a','b','c'}){
                Dive(prefix + c.ToString(),level - 1);
            }
        }
        
    }
}