import java.util.*;
import java.io.*;
class Main {

	static int []col;
	static boolean [][]adj;
	static boolean []visited;
	static int inf=(int)1e4;
	
	static pair color (int u)
	{
		
		pair ans=new pair(col[u]);
		for(int v=0;v<visited.length;v++)
		{
			if(!adj[u][v])
				continue;
			if(col[v]==-1)
			{
				col[v]=1-col[u];
				ans.merge(color(v));
			}
			else if(col[v]==col[u])
				return new pair(inf,inf);
				
		}
		return ans;
	}
	public static void main(String[] args) throws IOException {
		Scanner sc=new Scanner(System.in);
		PrintWriter pw=new PrintWriter(System.out);
		int n=sc.nextInt(),m=sc.nextInt();
		adj=new boolean [n][n];
		visited=new boolean[n];
		for(int i=0;i<n;i++)
		{
			Arrays.fill(adj[i], true);
			adj[i][i]=false;
		}
		
		while(m-->0)
		{
			int u=sc.nextInt()-1,v=sc.nextInt()-1;
			adj[u][v]=adj[v][u]=false;
		}
		ArrayList<pair> pairs=new ArrayList();
		int cc=1;
		boolean [][]reachable=new boolean[n+1][n+1];
		// what values are reachable after processing i connected components
		reachable[0][0]=true;
		col=new int [n];
		Arrays.fill(col, -1);
		for(int i=0;i<n;i++)
			if(col[i]==-1)
			{
				col[i]=0;
				pair p=color(i);
				if(p.S>=inf)
				{
					System.out.println(-1);
					return;
				}
				pairs.add(p);
				for(int j=0;j<=n;j++)
					if(reachable[cc-1][j])
						reachable[cc][j+p.S]=reachable[cc][j+p.T]=true;
				cc++;
				
			}
		cc--;
		long ans=n*1L*(n-1);
		for(int i=0;i<=n;i++)
			if(reachable[cc][i])
			{
				long A=i,B=n-i;
				ans=Math.min(ans, A*(A-1)+B*(B-1));
			}
		pw.println(ans/2);
		
			
		
		
		pw.close();
		
	}
	static class pair
	{
		int S,T;
		pair(int x)
		{
			if(x==0)
				S++;
			else T++;
		}
		pair(int x,int y)
		{
			S=inf;T=inf;
		}
		void merge(pair other)
		{
			S+=other.S;
			T+=other.T;
		}
	}
	static class Scanner {
        StringTokenizer st;
        BufferedReader br;
 
        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }
 
        public Scanner(FileReader s) {
            br = new BufferedReader(s);
        }
 
        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }
 
        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
 
        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }
 
        public String nextLine() throws IOException {
            return br.readLine();
        }
        public boolean ready() throws IOException {return br.ready();}
        public double nextDouble() throws IOException {return Double.parseDouble(next());}
       
    }

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.