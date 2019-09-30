using System;
using System.Collections;
using System.Linq;
class Program
{
    static ArrayList s = new ArrayList();
    public static ArrayList DepthFirstSearch(Node root)
    {
        s.Add(root.x);
        root.Visited = true;
        if (root.Children != null)
        {
            for (int i = 0; i < root.Children.Count; i++)
            {
                if (!((Node)(root.Children[i])).Visited)
                {
                    DepthFirstSearch(((Node)root.Children[i]));
                }
            }
        }
        return s;
    }
    static void Main()
    {
        //???????
        int[] nm = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        int n = nm[0], m = nm[1];
        int[] p = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        int[][] xy = new int[m][];
        for (int i = 0; i < m; i++)
            xy[i] = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        //????
        Node[] v = new Node[n];
        for (int i = 0; i < n; i++)
            v[i] = new Node(i + 1);
        for (int i = 0; i < m; i++)
        {
            v[xy[i][0] - 1].Children.Add(v[xy[i][1] - 1]);
            v[xy[i][1] - 1].Children.Add(v[xy[i][0] - 1]);
        }
        ArrayList t = new ArrayList();
        for (int i = 0; i < n; i++)
        {
            if (!v[i].Visited)
            {
                t.Add(DepthFirstSearch(v[i]));
                s = new ArrayList();
            }
        }
        int ans = 0;
        for (int i = 0; i < t.Count; i++)
        {
            int[] nums = (int[])((ArrayList)t[i]).ToArray(typeof(int));
            int[] nums2 = new int[nums.Length];
            for (int j = 0; j < nums.Length; j++)
                nums2[j] = p[nums[j] - 1];
            Array.Sort(nums);
            Array.Sort(nums2);
            int a = 0, b = 0;
            for (; ; )
            {
                if (nums[a] == nums2[b])
                {
                    ans++;
                    a++;
                    b++;
                }
                else if (nums[a] > nums2[b])
                    b++;
                else
                    a++;
                if (a == nums.Length || b == nums.Length)
                    break;
            }
        }
        Console.WriteLine(ans);
    }
}
class Node //???
{
    public bool Visited { get; set; }
    public ArrayList Children = new ArrayList();
    public int x;
    public Node(int x) { this.x = x; }
}