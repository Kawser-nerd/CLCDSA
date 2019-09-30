using System;
using System.Collections.Generic;
using System.Linq;



namespace ConsoleApp1
{
    //?????
    class Program
    {
        static List<int[]> Nexts = new List<int[]>() { new int[2] { 0, 1 }, new int[2] { 0, -1 }, new int[2] { 1, 0 }, new int[2] { -1, 0 }, };
        static List<List<BlockClass>> Maze = new List<List<BlockClass>>();
        static List<BlockClass> Queue = new List<BlockClass>();
        static int counter = 0;

        static void Main(string[] args)
        {
            int[] hw = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

            List<BlockClass> list0 = new List<BlockClass>();
            Maze.Add(list0);
            for (int i = 0; i < hw[1] + 2; i++)
            {
                BlockClass tmpBlock = new BlockClass();
                list0.Add(tmpBlock);
                tmpBlock.x = 0;
                tmpBlock.y = i;
                tmpBlock.isRoad = false;
            }

            for (int i = 1; i <= hw[0]; i++)
            {
                List<BlockClass> tmpList = new List<BlockClass>();
                Maze.Add(tmpList);
                string line = Console.ReadLine();
                line = "#" + line + "#";

                for (int j = 0; j <= hw[1] + 1; j++)
                {
                    BlockClass tmpBlock = new BlockClass();
                    tmpList.Add(tmpBlock);
                    tmpBlock.x = i;
                    tmpBlock.y = j;
                    if (line[j] == '.') { tmpBlock.isRoad = true; counter++; }
                    else tmpBlock.isRoad = false;
                }
            }

            List<BlockClass> listlist = new List<BlockClass>();
            Maze.Add(listlist);
            for (int i = 0; i < hw[1] + 2; i++)
            {
                BlockClass tmpBlock = new BlockClass();
                listlist.Add(tmpBlock);
                tmpBlock.x = hw[0] + 1;
                tmpBlock.y = i;
                tmpBlock.isRoad = false;
            }

            Maze[hw[0]][hw[1]].isGoal = true;
            Maze[1][1].Min = 0;
            Queue.Add(Maze[1][1]);
            BFS(1, 1);


            if (Maze[hw[0]][hw[1]].Min == -1)
            { Console.WriteLine(-1); }
            else
            { Console.WriteLine(counter - Maze[hw[0]][hw[1]].Min - 1); }

            //

        }

        static void BFS(int x, int y)
        {
            Queue.RemoveAt(0);

            foreach (int[] Next in Nexts)
            {
                //??????
                if (!Maze[x + Next[0]][y + Next[1]].isRoad) continue;
                //???????????
                if (Maze[x + Next[0]][y + Next[1]].Min != -1) continue;

                //
                Maze[x + Next[0]][y + Next[1]].Min = Maze[x][y].Min + 1;
                Queue.Add(Maze[x + Next[0]][y + Next[1]]);
                
            }

            if (Queue.Count == 0)
            { return; }

            BFS(Queue[0].x, Queue[0].y);
        }

    }

    public class BlockClass
    {
        public int x;
        public int y;
        public int Min = -1;
        public bool isRoad;
        public bool isGoal;

        public BlockClass()
        { }
    }

}