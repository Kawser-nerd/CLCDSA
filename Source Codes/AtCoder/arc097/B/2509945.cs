using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
		int[] inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
		this.MaxNum = inpt[0];
		this.TreeNodes = new TreeNode[this.MaxNum];

		int roadCount = inpt[1];

		this.Items = Reader.ReadLine().Split(' ').Select(a => int.Parse(a) - 1).ToArray();
		for (int i = 0; i < roadCount; i++) {
			inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a) - 1).ToArray();
			inpt.ToList().ForEach(a =>
			{
				if(TreeNodes[a] == null) {
					this.TreeNodes[a] = new TreeNode(a);
				}
			});
			if(TreeNodes[inpt[0]].GetRoot().ID == TreeNodes[inpt[1]].GetRoot().ID) {
				continue;
			}
			TreeNodes[inpt[0]].GetRoot().Add(this.TreeNodes[inpt[1]].GetRoot());
		}

		int[] Pos = new int[this.MaxNum];
		for (int i = 0; i < this.MaxNum; i++) {
			Pos[Items[i]] = i;
		}

		int ans = 0;
		for (int i = 0; i < Items.Length; i++) {
			if(Items[i] == i) {
				ans++;
				continue;
			}
			int idx1 = Pos[i];
			int idx2 = i;

			int num1 = i;
			int num2 = Items[idx2];

			if(TreeNodes[idx1] == null || TreeNodes[idx2] == null) {
				continue;
			}
			if(TreeNodes[idx1].GetRoot().ID == TreeNodes[idx2].GetRoot().ID) {
				ans++;
				Pos[num1] = idx2;
				Pos[num2] = idx1;
				Items[idx2] = num1;
				Items[idx1] = num2;
			}
		}
		Console.WriteLine(ans);
	}

	private int[] Items;

	private int MaxNum;
	private TreeNode[] TreeNodes;

	private class TreeNode {
		private TreeNode Root;
		public int ID;
		private List<TreeNode> Items = new List<TreeNode>();
		public TreeNode(int n) {
			this.ID = n;
			this.Root = this;
		}

		public void Add(TreeNode sub) {
			this.Items.Add(sub);
			sub.Root = this.GetRoot();
		}

		public TreeNode GetRoot() {
			if(this.Root == this.Root.Root) {
				return this.Root;
			}
			this.Root = this.Root.GetRoot();
			return this.Root;
		}
	}

    public class Reader
    {
        static StringReader sr;
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


10 8
5 3 6 8 7 10 9 1 2 4
3 1
4 1
5 9
2 5
6 5
3 5
8 9
7 9


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