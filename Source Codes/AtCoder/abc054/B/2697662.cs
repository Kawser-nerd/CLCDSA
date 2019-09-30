using System;
using System.Collections.Generic;
public class Hello{
    public static void Main(){
        var array = Array.ConvertAll(Console.ReadLine().Split(' '),int.Parse);
        var n = array[0];
        var m = array[1];
        var A = new string[n];
        var B = new string[m];
        var Hash = new HashSet<string>();
        var target = "";
        for(var i = 0;i < n;i++){
            A[i] = Console.ReadLine();
        }
        
        for(var i = 0;i < m;i++){
            B[i] = Console.ReadLine();
            target += B[i];
        }
        
        for(var a = 0;a < n - m + 1;a++){
            for(var b = 0;b < n - m + 1;b++){
                var temp = "";
                for(var y = 0;y < m;y++){
                       temp += A[a + y].Substring(b,m); 
                }
                Hash.Add(temp);
            }
        }
        
        if(Hash.Contains(target)){
            Console.WriteLine("Yes");
        }else{
            Console.WriteLine("No");
        }
       
    }
}