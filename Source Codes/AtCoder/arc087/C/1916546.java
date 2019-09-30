import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static void solve()
	{
//		int n = 20;
//		int[] nim = new int[n+1];
//		for(int i = 1;i <= n;i++){
//			BitSet bs = new BitSet();
//			bs.set(nim[0]);
//			int x = 0;
//			for(int j = i-1;j >= 0;j--){
//				x ^= nim[j];
//				bs.set(x);
//			}
//			nim[i] = bs.nextClearBit(0);
//			tr(i, nim[i]);
//		}
		int n = ni();
		long m = nl();
		TrieByLink trie = new TrieByLink();
		for(int i = 0;i < n;i++){
			trie.add(ns().toCharArray());
		}
		
		win = 0;
		dfs(trie.root, 0, m);
		out.println(win == 0 ? "Bob" : "Alice");
	}
	
	static long win;
	
	static void dfs(TrieByLink.Node cur, int dep, long m)
	{
		if(cur.firstChild != null){
			if(cur.firstChild.next == null){
//				tr(m-dep, (m-dep)&-(m-dep));
				win ^= (m-dep)&-(m-dep);
			}
			for(TrieByLink.Node nex = cur.firstChild;nex != null;nex = nex.next){
				dfs(nex, dep+1, m);
			}
		}
	}
	
	public static class TrieByLink {
		public Node root = new Node((char)0, 0);
		public int gen = 1;
		public static final char[] atoz = "abcdefghijklmnopqrstuvwxyz".toCharArray();
		
		public static class Node
		{
			public int id;
			public char c;
			public Node next, firstChild;
			public int hit = 0;
			
			public Node fail;
			
			public Node(char c, int id)
			{
				this.id = id;
				this.c = c;
			}
			
			public String toString(String indent)
			{
				StringBuilder sb = new StringBuilder();
				sb.append(indent + id + ":" + c);
				if(hit != 0)sb.append(" H:" + hit);
				if(fail != null)sb.append(" F:" + fail.id);
				sb.append("\n");
				for(Node c = firstChild;c != null; c = c.next){
					sb.append(c.toString(indent + "  "));
				}
				return sb.toString();
			}
		}
		
		public void add(char[] s)
		{
			Node cur = root;
			Node pre = null;
			for(char c : s){
				pre = cur; cur = cur.firstChild;
				if(cur == null){
					cur = pre.firstChild = new Node(c, gen++);
				}else{
					for(;cur != null && cur.c != c;pre = cur, cur = cur.next);
					if(cur == null)cur = pre.next = new Node(c, gen++);
				}
			}
			cur.hit++;
		}
		
		public void buildFailure()
		{
			root.fail = null;
			Queue<Node> q = new ArrayDeque<Node>();
			q.add(root);
			while(!q.isEmpty()){
				Node cur = q.poll();
				inner:
				for(Node ch = cur.firstChild;ch != null; ch = ch.next){
					q.add(ch);
					for(Node to = cur.fail; to != null; to = to.fail){
						for(Node lch = to.firstChild;lch != null; lch = lch.next){
							if(lch.c == ch.c){
								ch.fail = lch;
								ch.hit += lch.hit; // propagation of hit
								continue inner;
							}
						}
					}
					ch.fail = root;
				}
			}
		}
		
		public Node next(Node cur, char c)
		{
			for(;cur != null;cur = cur.fail){
				for(Node ch = cur.firstChild;ch != null; ch = ch.next){
					if(ch.c == c)return ch;
				}
			}
			return root;
		}
		
		public int[][] ngMatrix(char[] cs)
		{
			int[] map = new int[128];
			Arrays.fill(map, -1);
			for(int i = 0;i < cs.length;i++)map[cs[i]] = i;
			
			int[][] a = new int[gen+1][gen+1];
			Node[] nodes = toArray();
			for(int i = 0;i < gen;i++){
				if(nodes[i].hit > 0)continue;
				int nohit = cs.length;
				boolean[] ved = new boolean[cs.length];
				for(Node cur = nodes[i];cur != null;cur = cur.fail){
					for(Node ch = cur.firstChild;ch != null; ch = ch.next){
						if(map[ch.c] >= 0 && !ved[map[ch.c]]){
							ved[map[ch.c]] = true;
							if(ch.hit == 0)a[ch.id][i]++;
							nohit--;
						}
					}
				}
				a[0][i] += nohit;
			}
			Arrays.fill(a[gen], 1);
			return a;
		}
		
		public int[][] okMatrix(char[] cs)
		{
			int[] map = new int[128];
			Arrays.fill(map, -1);
			for(int i = 0;i < cs.length;i++)map[cs[i]] = i;
			
			int[][] a = new int[gen+1][gen+1];
			Node[] nodes = toArray();
			for(int i = 0;i < gen;i++){
				if(nodes[i].hit > 0)continue;
				int nohit = cs.length;
				boolean[] ved = new boolean[cs.length];
				for(Node cur = nodes[i];cur != null;cur = cur.fail){
					for(Node ch = cur.firstChild;ch != null; ch = ch.next){
						if(map[ch.c] >= 0 && !ved[map[ch.c]]){
							ved[map[ch.c]] = true;
							if(ch.hit > 0){
								a[gen][i]++;
							}else{
								a[ch.id][i]++;
							}
							nohit--;
						}
					}
				}
				a[0][i] += nohit;
			}
			a[gen][gen]++;
			return a;
		}
		
		public void search(char[] q)
		{
			Node cur = root;
			outer:
			for(char c : q){
				for(;cur != null;cur = cur.fail){
					for(Node ch = cur.firstChild;ch != null; ch = ch.next){
						if(ch.c == c){
							// ch.hit
							cur = ch;
							continue outer;
						}
					}
				}
				cur = root;
			}
		}
		
		public int countHit(char[] q)
		{
			Node cur = root;
			int hit = 0;
			outer:
			for(char c : q){
				for(;cur != null;cur = cur.fail){
					for(Node ch = cur.firstChild;ch != null; ch = ch.next){
						if(ch.c == c){
							hit += ch.hit; // add hit
							cur = ch;
							continue outer;
						}
					}
				}
				cur = root;
			}
			return hit;
		}
		
		public Node[] toArray()
		{
			Node[] ret = new Node[gen];
			ret[0] = root;
			for(int i = 0;i < gen;i++){
				Node cur = ret[i];
				if(cur.next != null)ret[cur.next.id] = cur.next;
				if(cur.firstChild != null)ret[cur.firstChild.id] = cur.firstChild;
			}
			return ret;
		}
		
		public String toString()
		{
			return root.toString("");
		}
	}
	
	public static void main(String[] args) throws Exception
	{
		long S = System.currentTimeMillis();
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
		long G = System.currentTimeMillis();
		tr(G-S+"ms");
	}
	
	private static boolean eof()
	{
		if(lenbuf == -1)return true;
		int lptr = ptrbuf;
		while(lptr < lenbuf)if(!isSpaceChar(inbuf[lptr++]))return false;
		
		try {
			is.mark(1000);
			while(true){
				int b = is.read();
				if(b == -1){
					is.reset();
					return true;
				}else if(!isSpaceChar(b)){
					is.reset();
					return false;
				}
			}
		} catch (IOException e) {
			return true;
		}
	}
	
	private static byte[] inbuf = new byte[1024];
	static int lenbuf = 0, ptrbuf = 0;
	
	private static int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private static boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
//	private static boolean isSpaceChar(int c) { return !(c >= 32 && c <= 126); }
	private static int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private static double nd() { return Double.parseDouble(ns()); }
	private static char nc() { return (char)skip(); }
	
	private static String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private static char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private static char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private static int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private static int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private static long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private static void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}