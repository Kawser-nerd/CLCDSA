using System;


class A {
    public long f(long b, long n){
        long ans = 0;
        if(n<b){
            ans = n;
        } else {
            ans = f(b,n/b)+n%b;
        }
        return ans;
    }
    public long calc(long n, long s){
        
        if(n<s) return -1;
        if(n==s) return n+1;
        long up = (long)Math.Sqrt(n)+1;
        for(long i=2;i<up;i++){
            if(s==f(i,n)){
                return i;
            }
        }
        
        for(long i=up;i>0;i--){
            if( (i+n-s)%i==0){
                long b = (i+n-s)/i;
                if(s==f(b,n)){
                    return b;
                }
            } 
        }
        return -1;
        
    }
}

class Program {
    static void Main(string[] args){
        A a = new A();
        long n = long.Parse(Console.ReadLine());
        long s = long.Parse(Console.ReadLine());
        Console.WriteLine(a.calc(n,s));
    }
}