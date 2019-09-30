using System;
public class Hello{
    static int GCD(int a,int b){
        int A = Math.Max(a,b);
        int B = Math.Min(a,b);
        
        while(A % B != 0){
            int C = A % B;
            A = B;
            B = C;
        }
        return B;
    }
    public static void Main(){
        int a = int.Parse(Console.ReadLine());
        int b = int.Parse(Console.ReadLine());
        int n = int.Parse(Console.ReadLine());
        
        int LCM = a * b / GCD(a,b);
        
        if(n % LCM == 0){
            Console.WriteLine(n);
        }else{
            Console.WriteLine((n / LCM  + 1) * LCM);
        }
        
    }
}