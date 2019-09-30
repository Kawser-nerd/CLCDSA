using System;
public class Hello{
    public static void Main(){
        string s = Console.ReadLine();
        //Console.WriteLine(s.Substring(0,s.Length / 2));
        //Console.WriteLine(s.Substring(s.Length / 2,s.Length / 2));
        s = s.Substring(0,s.Length - 1);
        
        while(s.Length > 0){
            if(s.Length % 2 == 0){
                if(s.Substring(0,s.Length / 2) == s.Substring(s.Length / 2,s.Length / 2)){
                    Console.WriteLine(s.Length);
                    return;
                }
            }
            s = s.Substring(0,s.Length - 1);
        }
    }
}