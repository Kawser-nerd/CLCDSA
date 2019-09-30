using System;
using System.Collections.Generic;

public class C
{
	static int n;
	static Node[] nodes;

	public static void Main(string[] args)
	{
		int tests = int.Parse(Console.ReadLine());
		for(int testcase = 1; testcase <= tests; testcase++)
		{
			Console.Write("Case #{0}: ", testcase);
			string[] parts = Console.ReadLine().Split();
			n = int.Parse(parts[0]);
			nodes = new Node[n];
			for(int i = 0; i < n; i++)
				nodes[i] = new Node(i, int.Parse(Console.ReadLine()));
			int m = int.Parse(parts[1]);
			for(int i = 0; i < m; i++)
			{
				parts = Console.ReadLine().Split();
				int a = int.Parse(parts[0]) - 1;
				int b = int.Parse(parts[1]) - 1;
				nodes[a].nexts.Add(b);
				nodes[b].nexts.Add(a);
			}

			int[] order = new int[n];
			order[0] = 0;
			for(int i = 1; i < n; i++)
				if(nodes[i].zip < nodes[order[0]].zip)
					order[0] = i;
			Stack<int> stack = new Stack<int>();
			stack.Push(order[0]);
			bool[] removed = new bool[n];
			bool[] done = new bool[n];
			done[order[0]] = true;
			for(int i = 1; i < n; i++)
			{
				// Greedy find order[i]
				order[i] = -1;
				for(int j = 0; j < n; j++)
				{
					if(done[j]) continue;
					if((order[i] == -1 || nodes[j].zip < nodes[order[i]].zip)
						 && canstep(stack, removed, j))
							order[i] = j;
				}
				if(order[i] == -1)
				{
					Console.WriteLine("**** WRONG ****");
					Console.WriteLine(i);
					foreach(int j in stack) Console.Write(j+ " ");
					Console.WriteLine();
					for(int j = 0; j < n; j++)
						if(removed[j])
							Console.WriteLine("rem " + j);
					for(int j = 0; j < n; j++)
						if(done[j])
							Console.WriteLine("done " + j);
					for(int j = 0; j <= i; j++)
						Console.Write(order[j] + " ");
					Console.WriteLine();
					return;
				}
				done[order[i]] = true;
				
				// Now do the step
				while(!nodes[stack.Peek()].nexts.Contains(order[i]))
				{
					removed[stack.Peek()] = true;
					stack.Pop();
				}
				
				stack.Push(order[i]);
			}

			// Print result
			for(int i = 0; i < n; i++)
				Console.Write(nodes[order[i]].zip);
			Console.WriteLine();
		}
	}

	public static bool canstep(Stack<int> ostack, bool[] oremoved, int i)
	{
		Stack<int> stack = copystack(ostack);
		bool[] removed = new bool[n];
		oremoved.CopyTo(removed, 0);
		while(stack.Count > 0 && !nodes[stack.Peek()].nexts.Contains(i))
		{
			removed[stack.Peek()] = true;
			stack.Pop();
		}
		if(stack.Count == 0) return false;
		stack.Push(i);
		return stillpossible(stack, removed);
	}

	public static Stack<int> copystack(Stack<int> st)
	{
		return new Stack<int>(new Stack<int>(st)); // wtf, a lot of debugging time on this :-(
	}

	static bool[] curvisit;
	static bool[] curremoved;

	static void dfs(int i)
	{
		if(curvisit[i] || curremoved[i]) return;
		curvisit[i] = true;
		foreach(int j in nodes[i].nexts)
			dfs(j);
	}

	public static void printstack(Stack<int> stack, string name)
	{
		Console.Write(name);
		foreach(int i in stack) Console.Write(i+" ");
		Console.WriteLine();
	}

	public static bool stillpossible(Stack<int> curstack, bool[] removed)
	{

		curvisit = new bool[n];
		curremoved = removed;
		foreach(int i in curstack) dfs(i);
		for(int i = 0; i < n; i++)
			if(!curvisit[i] && !curremoved[i])
				return false;
		return true;
	}

	public class Node
	{
		public int i;
		public int zip;
		public List<int> nexts;

		public Node(int i, int zip)
		{
			this.i = 0;
			this.zip = zip;
			nexts = new List<int>();
		}
	}
}