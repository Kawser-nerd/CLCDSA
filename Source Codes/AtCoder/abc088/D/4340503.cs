using System;
using System.Linq;
using System.Collections.Generic;

namespace Hello_World
{
    class Program
    {
        private struct Cell{
            public int X {get; set;}
            public int Y {get; set;}
            public Cell(int x, int y)
            {
                this.X = x;
                this.Y = y;
            }
        }
        static void Main(string[] args){
            var hw = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse); 
            var start = new Cell(1,1);
            var goal = new Cell(hw[0], hw[1]);
            var map = new char[hw[0]+2,hw[1]+2];
            int black = 0;
            for(int i=1; i<=hw[0]; i++){
                string row = Console.ReadLine();
                for(int j=1; j<=hw[1]; j++){
                    map[i,j] =row[j-1];
                    if(row[j-1]=='#') black++;
                }
            }
            var dir = new Cell[]{new Cell(0,1),new Cell(-1,0),new Cell(0,-1),new Cell(1,0)};
            var que = new Queue<Cell>();
            var visited = new Cell[hw[0]+2,hw[1]+2];
            que.Enqueue(start);
            visited[start.X, start.Y] = start;
            var goaled = false;
            while(!goaled && que.Count()>0){
                Cell target = que.Dequeue();
                foreach(Cell d in dir){
                        Cell next = new Cell(target.X+d.X, target.Y+d.Y);
                        if(map[next.X, next.Y] == '.' && visited[next.X, next.Y].X == 0){
                            visited[next.X, next.Y] = target;
                            if(next.X == goal.X && next.Y == goal.Y){goaled = true; break;} 
                            que.Enqueue(next);
                        }
                }
            }
            if(!goaled){
                Console.WriteLine(-1);
            }else{
                var pass = 0;
                var before = goal;
                while(before.X!=start.X || before.Y!=start.Y){
                    before = visited[before.X, before.Y];
                    pass++;
                }
                Console.WriteLine(hw[0]*hw[1]-black-(pass+1));
            }
        }   
    }
}