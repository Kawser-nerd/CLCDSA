import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List; 

class Main{ 

	static int dfs1(int v, int p){
		for(Edge e: edges[v]){
			if(e.to==p)continue;
			e.size = dfs1(e.to, v);
			dist[v]=Math.max(dist[v], e.size);
		}
		return dist[v]+1;
	}
	static void dfs2(int v, int dis_p, int p){
		for(Edge e: edges[v])if(e.to==p)e.size=dis_p+1;
		edges[v].sort((a,b)->b.size-a.size);
		dist[v]=edges[v].get(0).size;
		for(int i=0;i<edges[v].size();++i){
			Edge e = edges[v].get(i);
			if(e.to==p)continue;
			if(i==0)dfs2(e.to,  edges[v].size()==1 ? 0:edges[v].get(1).size, v);
			else dfs2(e.to, dist[v], v);
		}
	}

	static int rank[];

	static void fillRank(int v, int r, int p){
		rank[r]=Math.max(rank[r], edges[v].size()-1);
		for(Edge e: edges[v])if(e.to!=p)fillRank(e.to, r+1, v);
	}

	static class Edge{
		int to,size=-1;
		Edge(int t){to=t;}
	}
	static int[] dist;
	static List<Edge> edges[];

	static void solve(){ 
		int n = ni();
		dist = new int[n];
		edges = new List[n];
		for(int i=0;i<n;++i)edges[i]=new ArrayList<>();
		for(int i=0;i<n-1;++i){
			int a = ni()-1;
			int b = ni()-1;
			edges[a].add(new Edge(b));
			edges[b].add(new Edge(a));
		}
		dfs1(0, -1);
		dfs2(0, 0, -1);
		List<Integer> roots = new ArrayList<>();
		roots.add(0);
		for(int i=1;i<n;++i){
			if(dist[i] == dist[roots.get(0)])roots.add(i);
			else if(dist[i] < dist[roots.get(0)]){
				roots.clear();roots.add(i);
			}
		}
		rank = new int[100];
		Arrays.fill(rank, -1);
		long ansn=1;
		if(roots.size()==2){
			fillRank(roots.get(0), 0, roots.get(1));
			fillRank(roots.get(1), 0, roots.get(0));
			for(int i=0;i<100;++i)if(rank[i]>=0)ansn*=(long)(Math.max(1, rank[i]));
			ansn*=2;
		}else{
			int root = roots.get(0);
			fillRank(root, 0, -1);
			rank[0]++;
			for(int i=0;i<100;++i)if(rank[i]>=0)ansn*=(long)(Math.max(1, rank[i]));

			for(Edge e: edges[root]){
				long res = 1;
				Arrays.fill(rank, -1);
				fillRank(e.to, 0, root);
				fillRank(root, 0, e.to);
				for(int i=0;i<100;++i)if(rank[i]>=0)res*=(long)(Math.max(1, rank[i]));
				res*=2;
				ansn=Math.min(ansn, res);
			}
		}
		for(int i=99;i>=0;--i){
			if(rank[i]>=0){
				out.println((i+1)+" "+ansn);
				return;
			}
		}
	} 
 
 
 
 
	public static void main(String[] args){ 
		 solve(); 
		 out.flush(); 
	 } 
	 private static InputStream in = System.in; 
	 private static PrintWriter out = new PrintWriter(System.out); 
 
	 private static final byte[] buffer = new byte[1<<15]; 
	 private static int ptr = 0; 
	 private static int buflen = 0; 
	 private static boolean hasNextByte(){ 
		 if(ptr<buflen)return true; 
		 ptr = 0; 
		 try{ 
			 buflen = in.read(buffer); 
		 } catch (IOException e){ 
			 e.printStackTrace(); 
		 } 
		 return buflen>0; 
	 } 
	 private static int readByte(){ if(hasNextByte()) return buffer[ptr++]; else return -1;} 
	 private static boolean isSpaceChar(int c){ return !(33<=c && c<=126);} 
	 private static int skip(){int res; while((res=readByte())!=-1 && isSpaceChar(res)); return res;} 
 
	 private static double nd(){ return Double.parseDouble(ns()); } 
	 private static char nc(){ return (char)skip(); } 
	 private static String ns(){ 
		 StringBuilder sb = new StringBuilder(); 
		 for(int b=skip();!isSpaceChar(b);b=readByte())sb.append((char)b); 
		 return sb.toString(); 
	 } 
	 private static int[] nia(int n){ 
		 int[] res = new int[n]; 
		 for(int i=0;i<n;++i)res[i]=ni(); 
		 return res; 
	 } 
	 private static long[] nla(int n){ 
		 long[] res = new long[n]; 
		 for(int i=0;i<n;++i)res[i]=nl(); 
		 return res; 
	 } 
	 private static int ni(){ 
		 int res=0,b; 
		 boolean minus=false; 
		 while((b=readByte())!=-1 && !((b>='0'&&b<='9') || b=='-')); 
		 if(b=='-'){ 
			 minus=true; 
			 b=readByte(); 
		 } 
		 for(;'0'<=b&&b<='9';b=readByte())res=res*10+(b-'0'); 
		 return minus ? -res:res; 
	 } 
	 private static long nl(){ 
		 long res=0,b; 
		 boolean minus=false; 
		 while((b=readByte())!=-1 && !((b>='0'&&b<='9') || b=='-')); 
		 if(b=='-'){ 
			 minus=true; 
			 b=readByte(); 
		 } 
		 for(;'0'<=b&&b<='9';b=readByte())res=res*10+(b-'0'); 
		 return minus ? -res:res; 
	} 
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.