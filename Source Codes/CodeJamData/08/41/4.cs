using System;

public class booltree
{
    public static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());

        for (int cs = 1; cs <= N; cs++)
        {
            string[] parts = Console.ReadLine().Split();
            int M = int.Parse(parts[0]);
            bool V = parts[1].Trim() == "1";

            Node[] nodes = new Node[M];
            for (int i = 0; i < (M - 1) / 2; i++)
            {
                parts = Console.ReadLine().Split();
                nodes[i] = new Node(parts[0].Trim() == "1", parts[1].Trim() == "1");
            }

            for (int i = (M - 1) / 2; i < M; i++)
            {
                nodes[i] = new Node(Console.ReadLine().Trim() == "1");
            }

            for (int i = 0; i < (M - 1) / 2; i++)
            {
                nodes[i].left = nodes[((i + 1) * 2) - 1];
                nodes[i].right = nodes[(i + 1) * 2];
            }
            int ans = nodes[0].MinChanges(V);
            Console.WriteLine("Case #" + cs + ": " + (ans == -1 ? "IMPOSSIBLE" : ans.ToString()));
        }
    }

    public class Node
    {
        public Node left, right;
        public bool value, andgate, changable;

        public Node(bool val)
        {
            value = val;
        }

        public Node(bool andor, bool change)
        {
            andgate = andor;
            changable = change;
        }

        public int MinChanges(bool wishval)
        {
            if (left == null)
            {
                if (wishval == value)
                    return 0;
                return -1;
            }
            else
            {
                if (andgate)
                {
                    if (wishval)
                    {
                        int leftnum = left.MinChanges(true);
                        int rightnum = right.MinChanges(true);
                        if (leftnum == -1)
                        {
                            if (changable && rightnum != -1)
                                return rightnum + 1;
                            return -1;
                        }
                        if (rightnum == -1)
                        {
                            if (changable && leftnum != -1)
                                return leftnum + 1;
                            return -1;
                        }
                        int best = leftnum + rightnum;
                        if (changable)
                        {
                            best = Math.Min(best, Math.Min(leftnum, rightnum) + 1);
                        }
                        return best;
                    }
                    else
                    {
                        int leftnum = left.MinChanges(false);
                        int rightnum = right.MinChanges(false);
                        if (leftnum != -1 && (leftnum <= rightnum || rightnum == -1))
                            return leftnum;
                        if (rightnum != -1 && (rightnum <= leftnum || leftnum == -1))
                            return rightnum;
                        return -1;
                    }
                }
                else
                {
                    if (wishval)
                    {
                        int leftnum = left.MinChanges(true);
                        int rightnum = right.MinChanges(true);
                        if (leftnum != -1 && (leftnum <= rightnum || rightnum == -1))
                            return leftnum;
                        if (rightnum != -1 && (rightnum <= leftnum || leftnum == -1))
                            return rightnum;
                        return -1;
                    }
                    else
                    {
                        int leftnum = left.MinChanges(false);
                        int rightnum = right.MinChanges(false);
                        if (leftnum == -1)
                        {
                            if (changable && rightnum != -1)
                                return rightnum + 1;
                            return -1;
                        }
                        if (rightnum == -1)
                        {
                            if (changable && leftnum != -1)
                                return leftnum + 1;
                            return -1;
                        }
                        int best = leftnum + rightnum;
                        if (changable)
                        {
                            best = Math.Min(best, Math.Min(leftnum, rightnum) + 1);
                        }
                        return best;
                    }
                }
            }
        }
    }
}