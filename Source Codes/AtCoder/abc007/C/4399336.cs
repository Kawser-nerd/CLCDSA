using System;
using System.Linq;
using System.Collections.Generic;
namespace ABC007_C2
{
    class Program
    {
        struct P{
            public int Y;
            public int X;
            public P(int y,int x){
                X = x;
                Y = y;
            }
        }
        

        static void Main(string[] args)
        {
            var ans = 0;
            //??????
            var input = Console.ReadLine().Split(' ');
            var R = int.Parse(input[0]);
            var C = int.Parse(input[1]);
            //?????????
            input = Console.ReadLine().Split(' ');
            var sy = int.Parse(input[0]) - 1;
            var sx = int.Parse(input[1]) - 1;
            //???????
            input = Console.ReadLine().Split(' ');
            var gy = int.Parse(input[0]) - 1;
            var gx = int.Parse(input[1]) - 1;

            int[] dy = new int[]{1,0,-1,0};//??????
            int[] dx = new int[]{0,1,0,-1};


            var cell = new string[R];
            for(var i = 0;i < R;i++){
                cell[i] = Console.ReadLine();
            }

            var isUsed = new bool[R,C];
            var steps = new int[R,C];
            steps[sy,sx] = 0;

            var queue = new Queue<P>();
            queue.Enqueue(new P(sy,sx));

            while(queue.Count > 0){
                var temp = queue.Dequeue();
                if(temp.Y == gy && temp.X == gx){
                    ans = steps[temp.Y,temp.X];
                    break;
                }
                for(var i = 0;i < 4;i++){
                    var y = temp.Y + dy[i];
                    var x = temp.X + dx[i];
                    if(cell[y][x] == '.' && !isUsed[y,x]){
                        queue.Enqueue(new P(y,x));
                        steps[y,x] = steps[temp.Y,temp.X] + 1;
                        isUsed[y,x] = true;
                    }
                    
                }

            }

            Console.WriteLine(ans);

        }
    }
}