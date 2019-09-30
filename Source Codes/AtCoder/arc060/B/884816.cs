using System;
using System.Collections.Generic;
class Solve{
    public long n;
    public long s;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        getinput();
        if(n <= s){
            if(n == s){
                Console.WriteLine(n+1);
            }
            else{
                Console.WriteLine(-1);
            }
        }
        else{
            long i;
            for(i=2;i*i<=n;i++){
                long sum = 0;
                long a = n;
                while(a > 0){
                    sum += a%i;
                    a /= i;
                }
                if(sum == s){
                    Console.WriteLine(i);
                    return;
                }
            }
            if(i > s)
                i = s;
            for(;i>=1;i--){
                if((n-s+i)%i == 0 && (n-s+i)/i > i && s-i < (n-s+i)/i){
                    Console.WriteLine((n-s+i)/i);
                    return;
                }
            }
            Console.WriteLine(-1);
        }
    }
    void getinput(){
        n = Int64.Parse(Console.ReadLine());
        s = Int64.Parse(Console.ReadLine());
    }    
}