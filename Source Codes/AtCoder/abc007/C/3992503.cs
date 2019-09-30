using System;
using System.Linq;
using System.Collections.Generic;

public class Hello{
    public static void Main(){
        // Your code here!
        int[] a = Console.ReadLine().Split(' ').Select(d => int.Parse(d)).ToArray();
        int[] s = Console.ReadLine().Split(' ').Select(e => int.Parse(e)).ToArray();
        int[] g = Console.ReadLine().Split(' ').Select(f => int.Parse(f)).ToArray();
        int R = a[0];
        int C = a[1];
        int sy = s[0];
        int sx = s[1];
        int gy = g[0];
        int gx = g[1];
        
        char[,] matrix = new char[R,C];
        int[,] board = new int[R,C]; //????????????
        int[] moveRow = new int[]{1,0,-1,0}; //?????
        int[] moveCol = new int[]{0,1,0,-1}; //?????
        for(int r = 0; r < R; r++)//?
        {
            string line = Console.ReadLine();
            for(int c = 0; c < C; c++)//?
            {
                matrix[r, c] = line[c];
                
            }
        }
        
        //board????
        for(int r = 0; r < R; r++)
        {
            for(int c = 0; c < C; c++)
            {
                board[r, c] = -1;
            }
        }
        
        //board????????????0???
        board[sy - 1, sx - 1] = 0;
        
        //??????
        Queue<int> queueRow = new Queue<int>(); //?????
        Queue<int> queueCol = new Queue<int>(); //?????
        queueRow.Enqueue(sy - 1);
        queueCol.Enqueue(sx - 1);
        
        while(queueRow.Count > 0)
        {
            int y = queueRow.Dequeue();
            int x = queueCol.Dequeue();
            
            for(int i = 0; i < moveRow.Length; i++)
            {
                int nextY = y + moveRow[i];
                int nextX = x + moveCol[i];
                if(0 <= nextY && nextY < R
                && 0 <= nextX && nextX < C
                && board[nextY, nextX] == -1
                && matrix[nextY, nextX] == '.')
                {
                    board[nextY, nextX] = board[y, x] + 1; //??????????board[nextY, nextX]?????????
                    
                    queueRow.Enqueue(nextY);               //????nextX,nextY???
                    queueCol.Enqueue(nextX);
                    
                    
                }
            }
            
        }
        //?????
        /*
        for(int r = 0; r < R; r++)
        {
            for(int c = 0; c < C; c++)
            {
                Console.Write(board[r, c]);
            }
            Console.WriteLine();
        }
        */
        
        Console.WriteLine(board[gy - 1, gx - 1]);
        
    }
}