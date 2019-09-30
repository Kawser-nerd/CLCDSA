package codeJamRound1B;


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeMap;


public class C {

	static int V, n, m, match[];	//n(left) + m(right) = V
	static ArrayList<Integer>[] adjList;	//size = n, idx = [0, n-1], val = [0, m-1]
	static boolean[] vis;
	static int go()
	{
		//build unweighted bipartite graph with directed edges left->right set
		int matches = 0;
		match = new int[m];
		Arrays.fill(match, -1);
		for(int i = 0; i < n; ++i)
		{
			vis = new boolean[n];
			matches += aug(i);
		}
		return matches;
	}
	
	static int aug(int u)	//returns 1 if an augment path is found
	{
		vis[u] = true;
		for(int v : adjList[u])
			if(match[v] == -1 || !vis[match[v]] && aug(match[v]) == 1)
			{
				match[v] = u;
				return 1;
			}
		return 0;
	}

	public static void main(String[] args) throws IOException 
	{
		Scanner sc = new Scanner(new FileReader("C-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter("problem_C.out"));
//		Scanner sc = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		
		int tc = sc.nextInt();
		for(int t = 1; t <= tc; ++t)
		{
			TreeMap<String, Integer> left = new TreeMap<String, Integer>(), right = new TreeMap<String, Integer>();
			int edges = sc.nextInt();
			int[] u, v;
			u = new int[edges]; v = new int[edges];
			int idx1 = 0, idx2 = 0;
			for(int i = 0; i < edges; ++i)
			{
				String s1 = sc.next(), s2 = sc.next();
				Integer uu = left.get(s1), vv = right.get(s2);
				if(uu == null)
					left.put(s1, uu = idx1++);
				if(vv == null)
					right.put(s2, vv = idx2++);
				u[i] = uu; v[i] = vv;
			}
			
			n = idx1; m = idx2;
			adjList = new ArrayList[n];
			for(int i = 0; i < n; ++i)
				adjList[i] = new ArrayList<Integer>();
			for(int i = 0; i < edges; ++i)
				adjList[u[i]].add(v[i]);
			int matches = go();
			int ans = matches + n + m - matches * 2;
			out.printf("Case #%d: %d\n", t, edges - ans);
		}
		out.flush();
		out.close();

	}

	static class Scanner 
	{
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s){	br = new BufferedReader(new InputStreamReader(s));}
		
		public Scanner(FileReader r){	br = new BufferedReader(r);}

		public String next() throws IOException 
		{
			while (st == null || !st.hasMoreTokens()) 
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {return Integer.parseInt(next());}

		public long nextLong() throws IOException {return Long.parseLong(next());}

		public String nextLine() throws IOException {return br.readLine();}

		public double nextDouble() throws IOException
		{
			String x = next();
			StringBuilder sb = new StringBuilder("0");
			double res = 0, f = 1;
			boolean dec = false, neg = false;
			int start = 0;
			if(x.charAt(0) == '-')
			{
				neg = true;
				start++;
			}
			for(int i = start; i < x.length(); i++)
				if(x.charAt(i) == '.')
				{
					res = Long.parseLong(sb.toString());
					sb = new StringBuilder("0");
					dec = true;
				}
				else
				{
					sb.append(x.charAt(i));
					if(dec)
						f *= 10;
				}
			res += Long.parseLong(sb.toString()) / f;
			return res * (neg?-1:1);
		}

		public boolean ready() throws IOException {return br.ready();}


	}
}