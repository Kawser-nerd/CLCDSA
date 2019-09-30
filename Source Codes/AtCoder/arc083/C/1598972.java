import java.io.*;
import java.util.*;

public class Main {
	static List<Integer>[] graph;
	static int[] x;
	
	public static void main(String[] args) {
		StdIn in = new StdIn();
		int n=in.nextInt();
		graph = new List[n];
		for(int i=0; i<n; ++i)
			graph[i] = new ArrayList<Integer>();
		for(int i=1; i<n; ++i)
			graph[in.nextInt()-1].add(i);
		x = new int[n];
		for(int i=0; i<n; ++i)
			x[i] = in.nextInt();
		dfs(0);
		System.out.println("POSSIBLE");
	}
	
	static int[] dfs(int node) {
		List<int[]> childrenX = new ArrayList<int[]>();
		for(int child : graph[node]) {
			int[] childX = dfs(child);
			if(childX[0]>childX[1]) {
				childX[0]^=childX[1];
				childX[1]^=childX[0];
				childX[0]^=childX[1];
			}
			childrenX.add(childX);
		}
		int minSum=0, othSum=0;
		for(int[] childX : childrenX) {
			minSum+=childX[0];
			othSum+=childX[1];
		}
		if(minSum>x[node]) {
			System.out.println("IMPOSSIBLE");
			System.exit(0);
		}
		int rem=x[node]-minSum;
		//Find maxSum<=x[node]
		boolean[] dp = new boolean[rem+1];
		dp[0]=true;
		for(int[] childX : childrenX)
			for(int i=rem-(childX[1]-childX[0]); i>=0; --i)
				dp[i+(childX[1]-childX[0])]|=dp[i];
		int maxSum=0;
		for(int i=rem; i>0; --i) {
			if(dp[i]) {
				maxSum=i;
				break;
			}
		}
		return new int[]{x[node], othSum-maxSum};
	}
	
	interface Input {
		public String next();
		public String nextLine();
		public int nextInt();
		public long nextLong();
		public double nextDouble();
	}
	static class StdIn implements Input {
		final private int BUFFER_SIZE = 1 << 16;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;

		public StdIn() {
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		
		public StdIn(String filename) {
			try{
				din = new DataInputStream(new FileInputStream(filename));
			} catch(Exception e) {
				throw new RuntimeException();
			}
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		
		public String next() {
			int c;
			while((c=read())!=-1&&(c==' '||c=='\n'||c=='\r'));
			StringBuilder s = new StringBuilder();
			while (c != -1)
			{
				if (c == ' ' || c == '\n'||c=='\r')
					break;
				s.append((char)c);
				c=read();
			}
			return s.toString();
		}

		public String nextLine() {
			int c;
			while((c=read())!=-1&&(c==' '||c=='\n'||c=='\r'));
			StringBuilder s = new StringBuilder();
			while (c != -1)
			{
				if (c == '\n'||c=='\r')
					break;
				s.append((char)c);
				c = read();
			}
			return s.toString();
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
			{
				ret = ret * 10 + c - '0';
			}  while ((c = read()) >= '0' && c <= '9');

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

		public long nextLong() {
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			}
			while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}
		
		public long[] readLongArray(int n) {
			long[] ar = new long[n];
			for(int i=0; i<n; ++i)
				ar[i]=nextLong();
			return ar;
		}

		public double nextDouble() {
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();

			do {
				ret = ret * 10 + c - '0';
			}
			while ((c = read()) >= '0' && c <= '9');

			if (c == '.')
			{
				while ((c = read()) >= '0' && c <= '9')
				{
					ret += (c - '0') / (div *= 10);
				}
			}

			if (neg)
				return -ret;
			return ret;
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