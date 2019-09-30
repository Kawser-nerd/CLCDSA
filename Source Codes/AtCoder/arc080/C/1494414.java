import java.io.*;
import java.util.*;

public class Main {
	static int[] p;
	static RmqSparseTable[] rmq = new RmqSparseTable[2];
	static PriorityQueue<Node> queue = new PriorityQueue<Node>();
	
	public static void main(String[] args) {
		StdIn in = new StdIn();
		int n=in.nextInt();
		p = in.readIntArray(n);
		int[] p0 = new int[n/2], p1 = new int[n/2];
		for(int i=0; i<n; ++i)
			if(i%2==0)
				p0[i/2]=p[i];
			else
				p1[i/2]=p[i];
		rmq[0] = new RmqSparseTable(p0);
		rmq[1] = new RmqSparseTable(p1);
		
		/*
		genPerm(0, n-1, null);
		List<Node> nodes = new ArrayList<Node>(n/2);
		while(!queue.isEmpty()) {
			Node node = queue.poll();
			nodes.add(node);
			if(node.parent==null)
				continue;
			++node.parent.childrenReady;
			if(node.parent.childrenReady==node.parent.children)
				queue.add(node.parent);
		}
		StringBuilder output = new StringBuilder();
		for(int i=n/2-1; i>=0; --i)
			output.append(nodes.get(i).a).append(' ').append(nodes.get(i).b).append(' ');
		System.out.println(output);
		//*/
		/*
		List<Integer> list = genPerm2(0, n-1);
		StringBuilder output = new StringBuilder();
		for(int i=0; i<n; ++i)
			output.append(list.get(i)).append(' ');
		System.out.println(output);
		//*/
		PriorityQueue<Range> ranges = new PriorityQueue<Range>();
		StringBuilder output = new StringBuilder();
		ranges.add(new Range(0, n-1, 2*rmq[0].minPos(0, (n-1)/2)));
		while(!ranges.isEmpty()) {
			Range range = ranges.poll();
			int min2=2*rmq[range.e%2].minPos((range.min+1)/2, range.e/2)+range.e%2;
			output.append(p[range.min]).append(' ').append(p[min2]).append(' ');
			if(range.min+1<min2) {
				ranges.add(new Range(range.min+1, min2-1, 2*rmq[range.e%2].minPos((range.min+1)/2, min2/2-1)+range.e%2));
				//System.out.println(2*rmq[range.e%2].minPos((range.min+1)/2, min2/2-1)+range.e%2);
			}
			if(range.min!=range.s)
				ranges.add(new Range(range.s, range.min-1, 2*rmq[range.s%2].minPos(range.s/2, range.min/2-1)+range.s%2));
			if(min2!=range.e)
				ranges.add(new Range(min2+1, range.e, 2*rmq[range.s%2].minPos((min2+1)/2, (range.e-1)/2)+range.s%2));
		}
		System.out.println(output);
	}
	
	static void genPerm(int s, int e, Node parent) {
		int modS=s%2, modE=e%2;
		//int i1=2*rmq[modS].minPos(s/2, (e-1)/2)+modS;
		//int i2=2*rmq[modE].minPos((i1+1)/2, e/2)+modE;
		int i1, i2;
		if(modS==0) {
			i1=2*rmq[0].minPos(s/2, e/2);
			i2=2*rmq[1].minPos(i1/2, e/2)+1;
		} else {
			i1=2*rmq[1].minPos(s/2, e/2-1)+1;
			i2=2*rmq[0].minPos(i1/2+1, e/2);
		}
		if(i1+1==i2) {
			queue.add(new Node(p[i1], p[i2], parent));
			if(parent!=null)
				++parent.children;
		} else {
			//Node node = new Node(p[i1], p[i2], parent);
			queue.add(new Node(p[i1], p[i2], parent));
			if(parent!=null)
				++parent.children;
			//genPerm(i1+1, i2-1, node);
			genPerm(i1+1, i2-1, null);
		}
		if(i1!=s) {
			genPerm(s, i1-1, parent);
		}
		if(i2!=e) {
			genPerm(i2+1, e, parent);
		}
	}
	
	static List<Integer> genPerm2(int s, int e) {
		int modS=s%2, modE=e%2;
		int i1, i2;
		if(modS==0) {
			i1=2*rmq[0].minPos(s/2, e/2);
			i2=2*rmq[1].minPos(i1/2, e/2)+1;
		} else {
			i1=2*rmq[1].minPos(s/2, e/2-1)+1;
			i2=2*rmq[0].minPos(i1/2+1, e/2);
		}
		List<Integer> list = new ArrayList<Integer>();
		list.add(p[i1]);
		list.add(p[i2]);
		List<Integer>[] subLists = new List[3];
		for(int i=0; i<3; ++i)
			subLists[i] = new ArrayList<Integer>();
		if(i1+1<i2)
			subLists[0]=genPerm2(i1+1, i2-1);
		if(i1!=s)
			subLists[1]=genPerm2(s, i1-1);
		if(i2!=e)
			subLists[2]=genPerm2(i2+1, e);
		int[] is = new int[3];
		while(true) {
			int minI=-1;
			for(int i=0; i<3; ++i) {
				if(is[i]<subLists[i].size()&&(minI==-1||subLists[minI].get(is[minI])>subLists[i].get(is[i]))) {
					minI=i;
				}
			}
			if(minI==-1)
				break;
			list.add(subLists[minI].get(is[minI]++));
			list.add(subLists[minI].get(is[minI]++));
		}
		return list;
	}
	
	static class Node implements Comparable<Node> {
		Node parent;
		int a, b, children, childrenReady;
		Node(int a, int b, Node parent) {
			this.a=a;
			this.b=b;
			this.parent=parent;
		}
		public int compareTo(Node node) {
			return -(a-node.a);
		}
	}
	
	static class Range implements Comparable<Range> {
		int s, e, min;
		Range(int s, int e, int min) {
			this.s=s;
			this.e=e;
			this.min=min;
		}
		public int compareTo(Range r) {
			return p[min]-p[r.min];
		}
	}
	
	static class RmqSparseTable {
		int[] logTable;
		int[][] rmq;
		int[] a;
		RmqSparseTable(int[] a) {
			this.a = a;
			int n = a.length;
			logTable = new int[n + 1];
			for (int i = 2; i <= n; i++)
				logTable[i] = logTable[i >> 1] + 1;
			rmq = new int[logTable[n] + 1][n];
			for (int i = 0; i < n; ++i)
				rmq[0][i] = i;
			for (int k = 1; (1 << k) < n; ++k) {
				for (int i = 0; i + (1 << k) <= n; i++) {
					int x = rmq[k - 1][i];
					int y = rmq[k - 1][i + (1 << k - 1)];
					rmq[k][i] = a[x] <= a[y] ? x : y;
				}
			}
		}
		int minPos(int i, int j) {
			int k = logTable[j - i];
			int x = rmq[k][i];
			int y = rmq[k][j - (1 << k) + 1];
			return a[x] <= a[y] ? x : y;
		}
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