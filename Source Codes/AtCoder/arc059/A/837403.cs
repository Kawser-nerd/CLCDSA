using System;

class Program{
    static void Main(string[] args){
        
        int N = int.Parse(Console.ReadLine());
        string[] str = Console.ReadLine().Split(' ');
        int[] a = new int[N];
        int sum = 0;
        for(int i=0;i<N;i++){ 
            a[i] = int.Parse(str[i]);
            sum += a[i];
        }
        
        int c1 = sum/N;
        int c2 = c1 + 1;
        
        int ans1=0, ans2=0;
        for(int i=0;i<N;i++){
            ans1 += (a[i]-c1)*(a[i]-c1);
            ans2 += (a[i]-c2)*(a[i]-c2);
        }
        
        
        Console.WriteLine(Math.Min(ans1, ans2));
    }
}