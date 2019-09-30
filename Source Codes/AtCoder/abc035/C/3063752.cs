using System;
using System.Collections.Generic;
using System.Linq;

public class Hello{
    public static void Main(){
        var input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var N = input[0];
        var Q = input[1];
        var board = new int[N + 2];
        var sum = new int[N + 2];
        sum[0] = 0;
        var ans = "";
        
        for(var i = 0;i < Q;i++){
            var a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var l = a[0];
            var r = a[1];
            board[l]++;
            board[r + 1]--;
        }
        for(var i = 1;i < N + 2;i++){
            sum[i] = sum[i - 1] + board[i];
        }
        for(var i = 1;i <= N;i++){
            Console.Write((sum[i] % 2 == 1) ? "1" : "0");
        }
        Console.WriteLine();
        
        
    }
}