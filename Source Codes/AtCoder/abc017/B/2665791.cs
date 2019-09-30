using System;
public class Hello{
    public static void Main(){
        string s = Console.ReadLine();
        var i = 0;
        
        while(i < s.Length){
            if(s[i] == 'o' || s[i] == 'k' || s[i] == 'u'){
                i++;
            }else if(s[i] == 'c' && s[i + 1] == 'h'){
                i += 2;
            }else{
                Console.WriteLine("NO");
                return;
            }
        }
        Console.WriteLine("YES");
    }
}