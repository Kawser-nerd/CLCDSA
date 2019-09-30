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
        int matiCount = inpt[0];
        int roadCount = inpt[1];
        int railCount = inpt[2];

        this.RoadMatiList = new TreeNode[matiCount];
        this.RailMatiList = new TreeNode[matiCount];

        for (int i = 0; i < roadCount; i++) {
            inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a) - 1).ToArray();
            if(!Road.ContainsKey(inpt[0])) {
                Road.Add(inpt[0], new Dictionary<int, bool>());
            }
            if(!this.Road.ContainsKey(inpt[1])) {
                this.Road.Add(inpt[1], new Dictionary<int, bool>());
            }
            this.Road[inpt[0]][inpt[1]] = true;
            this.Road[inpt[1]][inpt[0]] = true;
        }
        for (int i = 0; i < railCount; i++) {
            inpt = Reader.ReadLine().Split(' ').Select(a => int.Parse(a) - 1).ToArray();
            if(!this.Rail.ContainsKey(inpt[0])) {
                this.Rail.Add(inpt[0], new Dictionary<int, bool>());
            }
            if(!this.Rail.ContainsKey(inpt[1])) {
                this.Rail.Add(inpt[1], new Dictionary<int, bool>());
            }
            this.Rail[inpt[0]][inpt[1]] = true;
            this.Rail[inpt[1]][inpt[0]] = true;
        }
        for (int i = 0; i < matiCount; i++) {
            if(this.RoadMatiList[i] != null) {
                continue;
            }
            this.RoadMatiList[i] = new TreeNode(i);
            Queue<TreeNode> que = new Queue<TreeNode>();
            que.Enqueue(this.RoadMatiList[i]);
            while(que.Count>0) {
                TreeNode curr = que.Dequeue();
                if(!this.Road.ContainsKey(curr.ID)) {
                    continue;
                }
                foreach(int next in this.Road[curr.ID].Keys) {
                    if(curr.Parent != null && curr.Parent.ID==next) {
                        continue;
                    }
                    if(RoadMatiList[next] != null) {
                        continue;
                    }
                    RoadMatiList[next] = curr.AddChild(next);
                    que.Enqueue(RoadMatiList[next]);
                }
            }
        }
        for (int i = 0; i < matiCount; i++) {
            if(this.RailMatiList[i] != null) {
                continue;
            }
            this.RailMatiList[i] = new TreeNode(i);
            Queue<TreeNode> que = new Queue<TreeNode>();
            que.Enqueue(this.RailMatiList[i]);
            while(que.Count>0) {
                TreeNode curr = que.Dequeue();
                if(!this.Rail.ContainsKey(curr.ID)) {
                    continue;
                }
                foreach(int next in this.Rail[curr.ID].Keys) {
                    if(RailMatiList[next]!=null) {
                        continue;
                    }
                    RailMatiList[next] = curr.AddChild(next);
                    que.Enqueue(RailMatiList[next]);
                }
            }
        }

        Dictionary<int, Dictionary<int, int>> groupCount = new Dictionary<int, Dictionary<int, int>>();
        for (int i = 0; i < matiCount; i++) {
            int roadGroup = this.RoadMatiList[i].Root.ID;
            int railGroup = this.RailMatiList[i].Root.ID;
            if(!groupCount.ContainsKey(roadGroup)) {
                groupCount.Add(roadGroup, new Dictionary<int, int>());
            }
            if(groupCount[roadGroup].ContainsKey(railGroup)) {
                groupCount[roadGroup][railGroup]++;
            } else {
                groupCount[roadGroup][railGroup] = 1;
            }
        }

        int[] cnt = new int[matiCount];
        for (int i = 0; i < matiCount; i++) {
            int roadGroup = this.RoadMatiList[i].Root.ID;
            int railGroup = this.RailMatiList[i].Root.ID;
            cnt[i] = groupCount[roadGroup][railGroup];
        }
        string ans = string.Join(" ", cnt);
        Console.WriteLine(ans);
    }

    private TreeNode[] RoadMatiList;
    private TreeNode[] RailMatiList;

    private Dictionary<int, Dictionary<int, bool>> Road = new Dictionary<int, Dictionary<int, bool>>();
    private Dictionary<int, Dictionary<int, bool>> Rail = new Dictionary<int, Dictionary<int, bool>>();

    private class TreeNode {
        public TreeNode Parent;
        public TreeNode Root;
        public List<TreeNode> Items = new List<TreeNode>();
        public int ID;
        public TreeNode(int id) {
            this.ID = id;
            this.Root = this;
        }
        public TreeNode AddChild(int id) {
            TreeNode tn = new TreeNode(id);
            this.Items.Add(tn);
            tn.Parent = this;
            if(this.Parent==null) {
                tn.Root = this;
            } else {
                tn.Root = this.Root;
            }
            return tn;
        }
        public TreeNode AddChild(TreeNode target) {
            this.Items.Add(target);
            target.Parent = this;
            if(this.Parent==null) {
                target.Root = this;
            } else {
                target.Root = this.Root;
            }
            return target;
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




7 4 4
1 2
2 3
2 5
6 7
3 5
4 5
3 4
6 7


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