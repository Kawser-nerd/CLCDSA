using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC030B
{
    class Node
    {
        static public int n;
        static public int[] h;
        static public List<int>[] connected;
        static public bool[] visited;

        int point;
        bool jewel;
        List<Node> children = new List<Node>();

        public Node(int point, bool jewel)
        {
            this.point = point;
            this.jewel = jewel;
        }

        public void MakeTree()
        {
            visited[point] = true;
            foreach(var i in connected[point])
            {
                if(visited[i] == false)
                {
                    bool j = (h[i] == 1) ? true : false;
                    Node node = new Node(i, j);
                    node.MakeTree();
                    children.Add(node);
                }
            }
        }

        public int GetPathLength()
        {
            int len = 0;
            foreach(var child in children)
            {
                if(child.hasJewel())
                {
                    len += child.GetPathLength() + 2;
                }
            }
            return len;
        }

        bool hasJewel()
        {
            if (jewel)
            {
                return true;
            }
            else
            {
                bool f = false;
                foreach(var child in children)
                {
                    if(child.hasJewel())
                    {
                        f = true;
                        break;
                    }
                }
                return f;
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int n, x;
            string[] vals = Console.ReadLine().Split(' ');
            n = int.Parse(vals[0]);
            x = int.Parse(vals[1]);
            int[] h = new int[n+1];
            vals = Console.ReadLine().Split(' ');
            for(int i=1; i <= n; i++)
            {
                h[i] = int.Parse(vals[i-1]);
            }

            List<int>[] connected = new List<int>[n + 1];
            for (int i = 1; i <= n; i++)
                connected[i] = new List<int>();
            for(int i=1; i <= n-1; i++)
            {
                vals = Console.ReadLine().Split(' ');
                int a = int.Parse(vals[0]);
                int b = int.Parse(vals[1]);
                connected[a].Add(b);
                connected[b].Add(a);
            }

            bool[] visited = new bool[n + 1];

            Node.n = n;
            Node.h = h;
            Node.connected = connected;
            Node.visited = visited;
            bool j = h[x] == 1 ? true : false;
            Node root = new Node(x,j);
            root.MakeTree();
            Console.WriteLine(root.GetPathLength());
        }
    }
}