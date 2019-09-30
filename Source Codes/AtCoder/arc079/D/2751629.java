import java.io.*;
import java.util.*;

public class Main {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	static List<Integer>[] adj;
	static boolean[] vis, act, ic;
	static List<Integer> cyc = new ArrayList<Integer>();
	static int[] a;
	
	public static void main(String[] args) {
		int n=in.nextInt();
		adj = new List[n];
		for(int i=0; i<n; ++i)
			adj[i] = new ArrayList<Integer>();
		for(int i=0; i<n; ++i)
			adj[in.nextInt()-1].add(i);
		vis = new boolean[n];
		act = new boolean[n];
		ic = new boolean[n];
		a = new int[n];
		for(int i=0; i<n; ++i)
			if(!vis[i]&&dfs1(i))
				break;
		cyc.remove(cyc.size()-1);
//		System.out.println(cyc);
		Arrays.fill(a, -1);
		a[cyc.get(0)]=n;
		if(dfs2(cyc.get(0))!=a[cyc.get(1)]) {
			System.out.println("POSSIBLE");
			return;
		}
		int a1=a[cyc.get(0)];
		Arrays.fill(a, -1);
		a[cyc.get(0)]=a1;
		if(dfs2(cyc.get(0))==a1)
			System.out.println("POSSIBLE");
		else
			System.out.println("IMPOSSIBLE");
		out.close();
	}
	
	static boolean dfs1(int u) {
		vis[u]=true;
		act[u]=true;
		for(int v : adj[u]) {
			if(act[v]) {
				cyc.add(v);
				ic[v]=true;
				cyc.add(u);
				ic[u]=true;
				return true;
			}
			if(dfs1(v)) {
				if(ic[v]&&v!=cyc.get(0)) {
					cyc.add(u);
					ic[u]=true;
				}
				return true;
			}
		}
		act[u]=false;
		return false;
	}
	
	static int dfs2(int u) {
		List<Integer> b = new ArrayList<Integer>();
		b.add(0);
		b.add(Integer.MAX_VALUE);
		for(int v : adj[u])
			b.add(a[v]==-1?dfs2(v):a[v]);
		Collections.sort(b);
		for(int i=0; ; ++i)
			if(b.get(i+1)>b.get(i)+1)
				return a[u]=b.get(i)+1;
	}
	
	static class StdIn {
    	final private int BUFFER_SIZE = 1 << 16;
    	private DataInputStream din;
    	private byte[] buffer;
    	private int bufferPointer, bytesRead;
    	public StdIn() {
    		din = new DataInputStream(System.in);
    		buffer = new byte[BUFFER_SIZE];
    		bufferPointer = bytesRead = 0;
    	}
    	public StdIn(InputStream in) {
    		try{
    			din = new DataInputStream(in);
    		} catch(Exception e) {
    			throw new RuntimeException();
    		}
    		buffer = new byte[BUFFER_SIZE];
    		bufferPointer = bytesRead = 0;
    	}
    	public int nextInt() {
    		int ret = 0;
    		byte c = read();
    		while (c <= ' ')
    			c = read();
    		boolean neg = (c == '-');
    		if (neg)
    			c = read();
    		do
    			ret = ret * 10 + c - '0';
    		while ((c = read()) >= '0' && c <= '9');

    		if (neg)
    			return -ret;
    		return ret;
    	}
    	public int[] readIntArray(int n) {
    		int[] ar = new int[n];
    		for(int i=0; i<n; ++i)
    			ar[i]=nextInt();
    		return ar;
    	}
    	private void fillBuffer() throws IOException {
    		bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
    		if (bytesRead == -1)
    			buffer[0] = -1;
    	}
    	private byte read() {
    		try{
    			if (bufferPointer == bytesRead)
    				fillBuffer();
    			return buffer[bufferPointer++];
    		} catch(IOException e) {
    			throw new RuntimeException();
    		}
    	}
    	public void close() throws IOException {
    		if (din == null)
    			return;
    		din.close();
    	}
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.