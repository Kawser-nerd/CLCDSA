//shakyo
using System;
public class Hello{
    public static void Main(){
        var A = Console.ReadLine();
        var B = Console.ReadLine();
        var C = Console.ReadLine();
        
        var pa = 0;
        var pb = 0;
        var pc = 0;
        
        var cur = A[pa++];
        char ans;
        
        while(true){
            if(cur == 'a'){
                if(pa == A.Length){
                    ans = 'A';
                    break;
                }else{
                    cur = A[pa++];
                }
            }else if(cur == 'b'){
                if(pb == B.Length){
                    ans = 'B';
                    break;
                }else{
                    cur = B[pb++];
                }
            }else{
                if(pc == C.Length){
                    ans = 'C';
                    break;
                }else{
                    cur = C[pc++];
                }
            }
        }
        
        Console.WriteLine(ans);
    }
}