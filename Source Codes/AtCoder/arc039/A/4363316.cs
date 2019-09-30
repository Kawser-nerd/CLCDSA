using System;
using System.Linq;
public class Hello{
    static int ChangeMax(int n){
        if(n == 999){
            return n;
        }
        
        if(n / 100 != 9){
            return 900 + n % 100;
        }else if(n % 100 / 10 != 9){
            return 990 + n % 10;
        }else{
            return 999;
        }
        
    }
    
    static int ChangeMin(int n){
        if(n == 111){
            return n;
        }
        
        if(n / 100 != 1){
            return 100 + n % 100;
        }else if(n % 100 / 10 != 0){
            return 100 + n % 10;
        }else{
            return 100;
        }
    }
    public static void Main(){
        var input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var A = input[0];
        var B = input[1];
        var ans = Math.Max(ChangeMax(A) - B,A - ChangeMin(B));
        Console.WriteLine(ans);
        
    }
}