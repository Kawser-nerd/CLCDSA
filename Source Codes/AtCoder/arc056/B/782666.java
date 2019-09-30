import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.NoSuchElementException;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Main {
	static final int INF = (int)1e9 + 7;
	int N,M,S;
	int[] cost;
	ArrayList<Integer>[] graph;
	
	private static class P implements Comparable<P>{
		int min,now;
		public P(int min,int now){
			this.min = min;
			this.now = now;
		}
		
		public int compareTo(P p){
			return p.now - this.now;
		}
	}
	
	public void solve() {
		N = nextInt();
		M = nextInt();
		S = nextInt() - 1;
		cost = new int[N];
		graph = new ArrayList[N];
		
		Arrays.fill(cost,-1);
		
		for(int i = 0;i < N;i++){
			graph[i] = new ArrayList<Integer>();
		}
 
		for(int i = 0;i < M;i++){
			int u = nextInt() - 1;
			int v = nextInt() - 1;
 
			graph[u].add(v);
			graph[v].add(u);
		}
		
		//??????????????i???????????????
		PriorityQueue<P> pq = new PriorityQueue<P>();
		boolean[] used = new boolean[N];
		pq.add(new P(S,S));
		
		while(pq.size() > 0){
			P p = pq.poll();
			
			if(used[p.now])continue;
			
			//p.now??????????????p.min?????????
			used[p.now] = true;
			cost[p.now] = p.min;
			//??????????
			for(int to : graph[p.now]){
				//Math.min(?????????????,????????)
				P q = new P(Math.min(p.min,to),to);
				pq.add(q);
			}
		}
		
		for(int i = 0;i < N;i++){
			if(cost[i] >= i)out.println(i + 1);
		}
 
	}
 
	public static void main(String[] args) {
		out.flush();
		new Main().solve();
		out.close();
	}
 
	/* Input */
	private static final InputStream in = System.in;
	private static final PrintWriter out = new PrintWriter(System.out);
	private final byte[] buffer = new byte[2048];
	private int p = 0;
	private int buflen = 0;
 
	private boolean hasNextByte() {
		if (p < buflen)
			return true;
		p = 0;
		try {
			buflen = in.read(buffer);
		} catch (IOException e) {
			e.printStackTrace();
		}
		if (buflen <= 0)
			return false;
		return true;
	}
 
	public boolean hasNext() {
		while (hasNextByte() && !isPrint(buffer[p])) {
			p++;
		}
		return hasNextByte();
	}
 
	private boolean isPrint(int ch) {
		if (ch >= '!' && ch <= '~')
			return true;
		return false;
	}
 
	private int nextByte() {
		if (!hasNextByte())
			return -1;
		return buffer[p++];
	}
 
	public String next() {
		if (!hasNext())
			throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		int b = -1;
		while (isPrint((b = nextByte()))) {
			sb.appendCodePoint(b);
		}
		return sb.toString();
	}
 
	public int nextInt() {
		return Integer.parseInt(next());
	}
 
	public long nextLong() {
		return Long.parseLong(next());
	}
 
	public double nextDouble() {
		return Double.parseDouble(next());
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.