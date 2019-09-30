using System;
public class Hello{
    public static void Main(){
        int n = int.Parse(Console.ReadLine());
        string s = Console.ReadLine();
        int cent = n / 2;
        if(n % 2 == 0){
            Console.WriteLine("-1");
            return;
        }
        for(int i = 0;i < cent;i++){
            if(i % 3 == 0 && s[cent - i] == 'b' && s[cent + i] == 'b'){
                continue; 
            }else if(i % 3 == 1 && s[cent - i] == 'a' && s[cent + i] == 'c'){
                continue;
            }else if(i % 3 == 2 && s[cent - i] == 'c' && s[cent + i] == 'a'){
                continue;
            }else{
                Console.WriteLine("-1");
                return;
            }
        }
        Console.WriteLine(cent);
        
    }
}