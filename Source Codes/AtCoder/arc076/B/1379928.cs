using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text;

public class Program
{

    public void Proc()
    {
        int nodeCount = int.Parse(Reader.ReadLine());
        this.TreeNodeList = new TreeNode[nodeCount];
        for (int i = 0; i < nodeCount; i++) {
            TreeNode t = new TreeNode(i, Reader.ReadLine().Split(' ').Select(a=>long.Parse(a)).ToArray());
            this.TreeNodeList[i] = t;
        }
        this.SortedX = TreeNodeList.OrderBy(a => a.X).ToArray();
        this.SortedY = TreeNodeList.OrderBy(a => a.Y).ToArray();
        List<Road> roadList = new List<Road>();
        for (int i = 1; i < nodeCount; i++) {
            roadList.Add(new Road(SortedX[i-1], SortedX[i]));
            roadList.Add(new Road(SortedY[i-1], SortedY[i]));
        }
        roadList = roadList.OrderBy(a => a.Length).ToList();
        int cnt = 1;
        long ans = 0;
        foreach(Road r in roadList) {
            if(r.t1.Root.ID == r.t2.Root.ID) {
                continue;
            }
            r.t1.Join(r.t2);
            ans += r.Length;
            cnt++;
            if(cnt >= nodeCount) {
                break;
            }
        }
        Console.WriteLine(ans);
	}

    private class Road {
        public TreeNode t1;
        public TreeNode t2;
        public long Length = 0;
        public Road(TreeNode t1, TreeNode t2) {
            this.t1 = t1;
            this.t2 = t2;
            this.Length = Math.Min(Math.Abs(t1.X - t2.X), Math.Abs(t1.Y - t2.Y));
        }
    }
    private TreeNode[] TreeNodeList;
    private TreeNode[] SortedX;
    private TreeNode[] SortedY;

    private class TreeNode {
		private TreeNode _root = null;
		public TreeNode Root
		{
			get
			{
                if(this._root != null) {
                    if(this._root.Parent == null) {
                        return this._root;
                    } else {
                        this._root = this._root.Parent.Root;
                    }
                } else {
                    if(this.Parent == null) {
                        return this;
                    } else {
                        this._root = this.Parent.Root;
                    }
                }
                return this._root;
			}
            set {
                this._root = value;
            }
		}
		public long GetLen(TreeNode target) {
            return Math.Min(Math.Abs(this.X - target.X), Math.Abs(this.Y - target.Y));
        }
        public TreeNode Parent;
        public List<TreeNode> Items = new List<TreeNode>();
        public int ID;
        public long X;
        public long Y;
        public TreeNode(int id, long[] pos) {
            this.ID = id;
            this.X = pos[0];
            this.Y = pos[1];
        }
        public void Join(TreeNode target) {
            if(this.Root.ID == target.Root.ID) {
                return; 
            } else if(this.Root.ID < target.Root.ID) {
                if(target.Parent != null) {
                    target.UpsideDown();
                }
				this.Items.Add(target);
				target.Parent = this;
				target.Root = this.Root;
			} else {
                target.Join(this);
            }
        }

        public void UpsideDown() {
            if(this.Parent == null) {
                return;
            }
            TreeNode n = this.Parent;
            this.Parent = null;
            this.Root = null;
            n.Items.Remove(this);
            n.UpsideDown();
            this.Items.Add(n);
            n.Parent = this;
            n.Root = this;
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




6
8 3
4 9
12 19
18 1
13 5
7 6


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