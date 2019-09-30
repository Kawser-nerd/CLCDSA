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
        static void Main(string[] args)
        {
            int[] rc = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int[] syx = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int[] gyx = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

            for (int i = 0; i < rc[0]; i++)
            {
                List<BlockClass> tmpList = new List<BlockClass>();
                Maze.Add(tmpList);
                string line = Console.ReadLine();

                for (int j = 0; j < rc[1]; j++)
                {
                    BlockClass tmpBlock = new BlockClass();
                    tmpList.Add(tmpBlock);
                    tmpBlock.x = i;
                    tmpBlock.y = j;
                    if (line[j] == '.') tmpBlock.isRoad = true;
                    else tmpBlock.isRoad = false;
                }
            }

            Maze[gyx[0] - 1][gyx[1] - 1].isGoal = true;
            Maze[syx[0] - 1][syx[1] - 1].Min = 0;
            Queue.Add(Maze[syx[0]][syx[1]]);
            BFS(syx[0] - 1, syx[1] - 1);

            //

        }

        static void BFS(int x, int y)
        {
            if (Maze[x][y].isGoal)
            {
                Console.WriteLine(Maze[x][y].Min);
                Environment.Exit(0);
            }
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