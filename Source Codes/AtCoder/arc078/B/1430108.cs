using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace ProCon
{

    class Program
    {
        static long[] Nums;
        static void Main(string[] args)
        {
            int Num = int.Parse(Console.ReadLine());
            Graph graph = new Graph(Num);
            for (int i = 0; i < Num - 1; ++i)
            {
                string[] input = Console.ReadLine().Split(' ');
                graph.AddLine(int.Parse(input[0]) - 1, int.Parse(input[1]) - 1, 1);
            }
            if(graph.NuruMain())
            {
                Console.WriteLine("Fennec");
            }
            else
            {
                Console.WriteLine("Snuke");
            }
        }
    }
    class Graph
    {
        class Node
        {
            public Node()
            {
                EdaNum = 0;
                Connect = new List<int>();
                Before = -1;
            }
            public void Add(int num)
            {
                Connect.Add(num);
            }
            public List<int> Connect;
            public int EdaNum;
            public int Before;
            public bool IsMain;
        }

        public Graph(int nodesNum)
        {
            Nodes = new Node[nodesNum];
            for(int i=0; i < nodesNum; ++i)
            {
                Nodes[i] = new Node();
            }
            MainLine = new List<int>();
        }
        public void AddLine(int i1, int i2, int cost)
        {
            Nodes[i1].Add(i2);
            Nodes[i2].Add(i1);
        }
        public bool NuruMain()
        {
            SearchTargetNode1(-1, 0, Nodes.Count() - 1);
            SearchTargetNode2(0, Nodes.Count() - 1);
            SearchTargetNode3(-1, 0, Nodes.Count() - 1);
            return GetSum();
        }
        private void SearchTargetNode1(int Before, int Target, int Dest)
        {
            Nodes[Target].Before = Before;
            foreach(int node in Nodes[Target].Connect)
            {
                if(Before != node)
                {
                    SearchTargetNode1(Target, node, Dest);
                }                
            }
        }
        private void SearchTargetNode2(int Target, int Dest)
        {
            int nodeindex = Dest;
            while(nodeindex != Target)
            {
                MainLine.Add(nodeindex);
                Nodes[nodeindex].IsMain = true;
                nodeindex = Nodes[nodeindex].Before;
            }
            Nodes[Target].IsMain = true;
            MainLine.Add(Target);
        }
        private int SearchTargetNode3(int Before, int Target, int Dest)
        {
            int Eda = 0;
            foreach (int node in Nodes[Target].Connect)
            {
                if (Before != node && Nodes[node].IsMain)
                {
                    SearchTargetNode3(Target, node, Dest);
                }
                else if (Before != node)
                {
                    Eda += SearchTargetNode3(Target, node, Dest) + 1;
                }
            }
            Nodes[Target].EdaNum = Eda;
            return Eda;
        }
        private bool GetSum()
        {
            MainLine.Reverse();
            int[] nums = new int[MainLine.Count()];
            int j = 0;
            foreach (int i in MainLine)
            {
                nums[j] = i;
                j++;
            }
            int fen = 0;
            int sun = 0;
            for(int i = 0; i < MainLine.Count(); ++i)
            {
                if( i < (MainLine.Count + 1) / 2)
                {
                    fen += Nodes[MainLine[i]].EdaNum + 1;
                }
                else
                {
                    sun += Nodes[MainLine[i]].EdaNum + 1;
                }
            }
            return fen > sun;
        }
        Node[] Nodes;
        List<int> MainLine;
    }
}