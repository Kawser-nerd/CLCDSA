using System;
using System.Linq;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using System.Text;
 
public class Program
{
    public void Proc() {
        Reader.IsDebug = false;
        int treeCount = int.Parse(Reader.ReadLine());
        this.TreeList = new TreeNode[treeCount+1];
        for(int i=0; i<treeCount-1; i++) {
            int[] inpt = Reader.ReadLine().Split(' ').Select(a=>int.Parse(a)).ToArray();
            if(!this.Road.ContainsKey(inpt[0])) {
                this.Road.Add(inpt[0], new Dictionary<int, bool>());
            }
            this.Road[inpt[0]].Add(inpt[1], true);
            if(!this.Road.ContainsKey(inpt[1])) {
                this.Road.Add(inpt[1], new Dictionary<int, bool>());
            }
            this.Road[inpt[1]].Add(inpt[0], true);
        }

        this.Build(1);
        long ans = this.TreeList[1].dic[true] + this.TreeList[1].dic[false];
        ans = ans % Mod;
        Console.WriteLine(ans);
    }

    private void Build(int idx) {
        if(this.TreeList[idx] == null) {
            this.TreeList[idx] = new TreeNode(idx);
        }
        foreach(int cld in this.Road[idx].Keys) {
            if(this.TreeList[idx].Parent != null && this.TreeList[idx].Parent.ID == cld) {
                continue;
            }
            this.TreeList[cld] = new TreeNode(cld);
            this.TreeList[cld].Parent = this.TreeList[idx];
            this.TreeList[idx].Items.Add(this.TreeList[cld]);
            Build(cld);
        }
        if(TreeList[idx].Items.Count == 0) {
            TreeList[idx].dic[true] = 1;
            TreeList[idx].dic[false] = 1;
        } else {
            long black = 1;
            long white = 1;
            foreach(TreeNode cld in this.TreeList[idx].Items) {
                black *= cld.dic[false];
                black = black % Mod;
            }
            dic.Clear();
            white = this.GetVal(this.TreeList[idx].Items, 0);
            this.TreeList[idx].dic[true] = black;
            this.TreeList[idx].dic[false] = white;
        }
    }

    private Dictionary<int, long> dic = new Dictionary<int, long>();
    private long GetVal(List<TreeNode> list, int idx) {
        if(dic.ContainsKey(idx)) {
            return dic[idx];
        }
        long ans = 0;
        if(idx == list.Count-1) {
            ans = list[idx].dic[true];
            ans += list[idx].dic[false];
            ans = ans % Mod;
        } else {
            long tmp = GetVal(list, idx+1);
            ans += (tmp * list[idx].dic[true] % Mod);
            ans = ans % Mod;
            ans += (tmp * list[idx].dic[false] % Mod);
            ans = ans % Mod;
        }
        dic[idx] = ans;
        return ans;
    }

    private const long Mod = 1000000000 + 7;
    private TreeNode[] TreeList;

    private class TreeNode {
        public Dictionary<bool, long> dic = new Dictionary<bool, long>();
        public TreeNode Parent = null;
        public int ID;

        public List<TreeNode> Items = new List<TreeNode>();

        public TreeNode(int id) {
            this.ID = id;
        }
    }

    private Dictionary<int, Dictionary<int, bool>> Road = new Dictionary<int, Dictionary<int, bool>>();


    public class Reader {
        public static bool IsDebug = true;

        public static long[] GetLongs(char delimiter) {
            string inpt = Reader.ReadLine();
            return inpt.Split(delimiter).Select(a=>long.Parse(a)).ToArray();
        }

        public static long[] GetLongs() {
            return GetLongs(' ');
        }
        private static System.IO.StringReader SReader;
        private static string InitText = @"



10
7 9
8 1
9 6
10 8
8 6
10 3
5 8
4 8
2 5


";
        public static string ReadLine() {
            if(IsDebug) {
                if(SReader == null) {
                    SReader = new System.IO.StringReader(InitText.Trim());
                }
                return SReader.ReadLine();
            } else {
                return Console.ReadLine();
            }
        }
    }
    public static void Main(string[] args)
    {
        Program prg = new Program();
        prg.Proc();
    }
}