import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main
{


	static class Edge
	{
		int u,v;
		public Edge(int u,int v)
		{
			this.u = u;
			this.v = v;
		}
	}
	static int times = 0;

	static class Query
	{
		int x,y,z;
		int id;

		public Query(int x,int y,int z,int id)
		{
			this.x = x;
			this.y = y;
			this.z = z;
			this.id = id;
		}
	}

	static int n,m;
	static ArrayList<Edge> edges = new ArrayList();
	static ArrayList<Query> queries = new ArrayList();
	static int ans[];
	static DSU dsu;


	static class Entry
	{
		int lo,hi;
		ArrayList<Query> cur;
		public Entry(int lo,int hi,ArrayList<Query> cur)
		{
			this.lo = lo;
			this.hi = hi;
			this.cur = cur;
		}
	}

	public static void solve(ArrayList<Query> que)
	{


		Queue<Entry> Q = new LinkedList();
		Q.add(new Entry(0, edges.size() - 1,que));
		while(!Q.isEmpty())
		{
			Entry e = Q.poll(); int lo =  e.lo, hi = e.hi;
			ArrayList<Query> cur = e.cur;
			if(lo == hi)
			{
				for(Query q : cur) ans[q.id] = lo;
				continue;
			}
			int mid = (lo + hi) / 2;

			
			if(dsu.get() > mid)
			{
				
				dsu = new DSU(n);
			}
		
			int ptr = dsu.get();
			while(ptr <= mid)
			{
				dsu.union(edges.get(ptr).u, edges.get(ptr).v);
				dsu.upd(ptr); ptr++;
			}
			ArrayList<Query> left = new ArrayList();
			ArrayList<Query> right = new ArrayList();
			for(Query q : cur)
			{
				int ans = 0;
				if(dsu.isSameSet(q.x, q.y))
					ans = dsu.getSetSize(q.x);
				else ans = dsu.getSetSize(q.x) + dsu.getSetSize(q.y);
				if(ans < q.z)
					right.add(q);
				else left.add(q);
			}
			Q.add(new Entry(lo,mid,left));
			Q.add(new Entry(mid + 1,hi,right));
		}



	}
	public static void main(String[]args)throws Throwable
	{
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt(); m = sc.nextInt();
		for(int i = 0 ; i < m ; ++i)
		{
			int u = sc.nextInt() - 1, v = sc.nextInt() - 1;
			edges.add(new Edge(u,v));
		}
		dsu = new DSU(n);
		int q = sc.nextInt();
		ans = new int[q];
		for(int i = 0 ; i < q ; ++i)
		{
			queries.add(new Query(sc.nextInt() - 1,sc.nextInt() - 1,sc.nextInt(),i));
		}
		solve(queries);
		PrintWriter out = new PrintWriter(System.out);
		for(int i = 0 ; i < q ; ++i)
		{
			out.println(ans[i] + 1);
		}
		out.flush();
		out.close();


	}

	static class Scanner
	{
		BufferedReader br;
		StringTokenizer st;


		Scanner(InputStream s)  { br = new BufferedReader(new InputStreamReader(s)); }
		public Scanner(String s) throws FileNotFoundException{	br = new BufferedReader(new FileReader(s));}


		String next() throws IOException
		{

			while(st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();

		}
		int nextInt() throws NumberFormatException, IOException { return Integer.parseInt(next()); }
		long nextLong() throws NumberFormatException, IOException { return Long.parseLong(next()); }



	}

	static class DSU 
	{
		int rank[];
		int parent[];
		int N;
		int till;
		int sets;
		int setsize[];

		public DSU(int N){
			this.N = N;
			sets = N;
			parent = new int[N];
			rank = new int[N];
			setsize = new int[N];
			for(int i=0;i<N;i++){ parent[i] = i; setsize[i] = 1; }

		}
		public void upd(int x)
		{
			this.till = x;
		}
		public int get()
		{
			return this.till;
		}


		public void union(int x,int y)
		{

			if(isSameSet(x,y)) return;
			sets--;
			int xp = getParent(x);
			int yp = getParent(y);
			if(rank[xp]>rank[yp]){ parent[yp] = xp; setsize[xp]+=setsize[yp];}
			else{
				if(rank[xp]==rank[yp]){
					rank[yp]++;
					parent[xp] = yp;
					setsize[yp]+=setsize[xp];
				}
				else
				{ parent[xp] =yp; setsize[yp] += setsize[xp]; }
			}

		}

		public int getParent(int x){
			if(x==parent[x]) return x;
			return parent[x] = getParent(parent[x]);
		}

		public boolean isSameSet(int x,int y){
			return getParent(x)==getParent(y);
		}

		public int numDisjointSets(){
			return sets;
		}
		public int getSetSize(int x){
			return setsize[getParent(x)];
		}



	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.