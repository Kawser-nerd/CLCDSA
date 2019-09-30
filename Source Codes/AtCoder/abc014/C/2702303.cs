using System;
class Program{
    static void Main(string[] args){
        int s=int.Parse(Console.ReadLine());
        int[][] b = new int[s][];
        int[] arr = new int[1000002];
        for (int i=0;i<s;i++){
            b[i] = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            arr[b[i][0]]++;
            arr[b[i][1]+1]--;
        }
        
        int sd = arr[0];

        for (int i = 1; i < 1000001; i++){
            arr[i] += arr[i-1];
            if (arr[i]>sd) { sd = arr[i]; }
        }

        Console.WriteLine(sd);
    }
}