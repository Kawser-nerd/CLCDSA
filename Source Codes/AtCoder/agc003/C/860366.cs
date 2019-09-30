using System;

class P  {
    public int x, y;
    public P(int x, int y){
        this.x = x; this.y = y;
    }
    
}

class Program {
    static void Main(string[] args){
        int N = int.Parse(Console.ReadLine());
        P[] a = new P[N];
        for(int i=0;i<N;i++){
            a[i] = new P(int.Parse(Console.ReadLine()),i);
        }
        Array.Sort(a, (a1,b1)=>a1.x-b1.x);
        int calc = 0;
        for(int i=0;i<N;i+=2){
            calc += (a[i].y+i)%2;
        }
        Console.WriteLine(calc);
    }
}