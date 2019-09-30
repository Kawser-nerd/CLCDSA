using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace snap
{
    class Node
    {
        Dictionary<string, Node> folders;

        public Node()
        {
            folders = new Dictionary<string, Node>();
        }

        public int Mkdir(string[] path, int i)
        {
            if (path.Length == i)
                return 0;

            int res = 0;
            Node node = null;
            if (folders.TryGetValue(path[i], out node) == false)
            {
                node = new Node();
                folders[path[i]] = node;
                res++;
            }
            res += node.Mkdir(path, i + 1);
            return res;
        }
    }
    class A
    {
        public static void Main()
        {
            Dictionary<char, int> dic = new Dictionary<char, int>();
            string temp = Console.ReadLine();
            string[] t;
            int T = int.Parse(temp);
            for (int tc = 0; tc < T; tc++)
            {
                temp = Console.ReadLine();
                t = temp.Split(' ');
                int N = int.Parse(t[0]);
                int M = int.Parse(t[1]);
                
                Node root = new Node();

                for (int i = 0; i < N; i++)
                {
                    temp = Console.ReadLine();
                    t = temp.Split('/');
                    root.Mkdir(t, 1);
                }

                int res = 0;
                for (int i = 0; i < M; i++)
                {
                    temp = Console.ReadLine();
                    t = temp.Split('/');
                    res += root.Mkdir(t, 1);
                }
                Console.WriteLine("Case #{0}: {1}", tc + 1, res);

            }
        }
    }
}
