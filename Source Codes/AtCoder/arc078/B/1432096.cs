using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

	public void Proc()
	{
        int itemCount = int.Parse(Reader.ReadLine());
        this.NodeList = new TreeNode[itemCount];
        for (int i = 0; i < itemCount - 1; i++) {
            int[] inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)-1).ToArray();
            inpt.ToList().ForEach(a=>{
                if(!RoadDic.ContainsKey(a)) {
                    RoadDic.Add(a, new List<int>());
                }
            });
            RoadDic[inpt[0]].Add(inpt[1]);
            RoadDic[inpt[1]].Add(inpt[0]);
        }
        NodeList[0] = new TreeNode(0);
        Queue<int> tsk = new Queue<int>();
        RoadDic[0].ForEach(a =>
        {
            NodeList[a] = new TreeNode(a);
            NodeList[0].AddItem(NodeList[a]);
            tsk.Enqueue(a);
        });
        for (int i = 0; i < itemCount; i++) {
            if(tsk.Count()==0) {
                break;
            }
            int id = tsk.Dequeue();
            TreeNode current = this.NodeList[id];
			if (!RoadDic.ContainsKey(current.ID))
			{
				return;
			}
			foreach (int key in this.RoadDic[current.ID])
			{
				if (key == current.Parent.ID)
				{
					continue;
				}
				NodeList[key] = new TreeNode(key);
				current.AddItem(NodeList[key]);
                tsk.Enqueue(key);
			}
		}
        int sunukeMinDepth = this.NodeList[itemCount - 1].Depth - (this.NodeList[itemCount - 1].Depth - 1) / 2;
        TreeNode sunukeRoot = this.NodeList[itemCount - 1];
        while(sunukeRoot.Depth != sunukeMinDepth) {
            sunukeRoot = sunukeRoot.Parent;
        }
        int sunukeCount = sunukeRoot.SubNodesCount + 1;
        int fenecCount = itemCount - sunukeCount;
        string ans = "Fennec";
        if (sunukeCount >= fenecCount) {
            ans = "Snuke";
        }
        Console.WriteLine(ans);
    }

    private TreeNode[] NodeList;

    private Dictionary<int, List<int>> RoadDic = new Dictionary<int, List<int>>();

    private class TreeNode {
        public int ID;
        public int Depth;
        public TreeNode Parent;
        public List<TreeNode> Items = new List<TreeNode>();
        public TreeNode(int id) {
            this.ID = id;
        }
        private Nullable<int> SubNodesCountValue = null;
        public int SubNodesCount {
            get{
                if(SubNodesCountValue == null) {
                    if(this.Items.Count == 0) {
                        this.SubNodesCountValue = 0;
                    } else {
                        this.SubNodesCountValue = this.Items.Select(a => a.SubNodesCount + 1).Sum();
                    }
                }
				return this.SubNodesCountValue.Value;
			}
        }
        public void AddItem(TreeNode item) {
            this.Items.Add(item);
            item.Parent = this;
            item.Depth = this.Depth + 1;
        }
    }


	public class Reader
	{
		private static StringReader sr;
		public static bool IsDebug = false;
		public static string ReadLine()
		{
			if (IsDebug)
			{
				if (sr == null)
				{
					sr = new StringReader(InputText.Trim());
				}
				return sr.ReadLine();
			}
			else
			{
				return Console.ReadLine();
			}
		}
		private static string InputText = @"
 


4
1 4
4 2
2 3


";
	}

	public static void Main(string[] args)
	{
#if DEBUG
		Reader.IsDebug = true;
#endif
		Program prg = new Program();
		prg.Proc();
	}
}