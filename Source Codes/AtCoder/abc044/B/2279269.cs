using System;
using System.Collections.Generic;
public class Hello{
    public static void Main(){
        string s = Console.ReadLine();
        Dictionary<char,int> d = new Dictionary<char,int>();
        for(int i = 0;i < s.Length;i++){
            if(d.ContainsKey(s[i])){
                d[s[i]]++;
            }else{
                d[s[i]] = 1;
            }
        }
        foreach(var x in d){
            if(x.Value % 2 == 1){
                Console.WriteLine("No");
                return;
            }
        }
        Console.WriteLine("Yes");
    }
}