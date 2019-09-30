using System;

class Program
{
    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        string[] s = Console.ReadLine().Split(' ');
        int[] A = new int[N];
        for(int i=0;i<N; i++)?A[i] = int.Parse(s[i]);
        int odd = 0, sum = 0;
        while(odd == 0){
            for(int i=0; i<N; i++){
                if(A[i]%2 == 1) odd++;
                else A[i]/=2;
            }
            sum++;
        }
        Console.WriteLine(sum-1);
    }
}