import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static int mod = 1000000007;
	static long i2 = invl(2, mod);
	
	public static long invl(long a, long mod) {
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		return p < 0 ? p + mod : p;
	}
	
//	public static class XorShift extends Random {
//		private static final long serialVersionUID = 6806629989739663134L;
//		private long x=123456789, y=362436069, z=521288629, w=88675123;
//		public XorShift() {super(); x = System.nanoTime();}
//		public XorShift(long seed) {super(seed); x = seed;}
//		public synchronized void setSeed(long seed) {super.setSeed(seed); x = seed;}
//		protected int next(int bits){
//			long t=(x^x<<11)&(1L<<32)-1; x=y; y=z; z=w; w=(w^w>>>19^t^t>>>8)&(1L<<32)-1;
//			return (int)w>>>32-bits;
//		}
//	}

	
	static void solve()
	{
		gen = new Random(100000);
		int n = ni();
		int[] a = na(n);
		int z = 100005;
		Node[] stack = new Node[z];
		int sp = 0;
		long[] vals = new long[z];
		for(int i = 0;i < n;i++){
//			tr(i, a[i]);
			if(a[i] > 0){
				stack[sp++] = new Node(a[i]);
				vals[sp-1] = 0;
			}else if(a[i] == 0){
				long nv = vals[sp-2] + vals[sp-1];
				if(count(stack[sp-2]) < count(stack[sp-1])){
					nv += countLess(stack[sp-2], stack[sp-1]);
				}else{
					nv += countMore(stack[sp-1], stack[sp-2]);
				}
				Node un = mergeX(stack[sp-2], stack[sp-1]);
				sp--; sp--;
				stack[sp++] = un;
				vals[sp-1] = nv%mod;
//				tr("vals", vals[sp-1]);
			}else if(a[i] < 0){
				long num = (long)(-a[i])*(-a[i]-1)/2%mod;
//				tr(stack[sp-1].val, stack[sp-1].val2);
				vals[sp-1] = (vals[sp-1] * (-a[i]) + (stack[sp-1].val*stack[sp-1].val-stack[sp-1].val2) % mod * i2 % mod * num) % mod;
				if(vals[sp-1] < 0)vals[sp-1] += mod;
//				tr("vals", vals[sp-1]);
				mul(stack[sp-1], -a[i]);
				// c*(a+b)*k(k-1)/2+b*a..
			}
		}
		while(sp > 1){
			long nv = vals[sp-2] + vals[sp-1];
			if(count(stack[sp-2]) < count(stack[sp-1])){
				nv += countLess(stack[sp-2], stack[sp-1]);
			}else{
				nv += countMore(stack[sp-1], stack[sp-2]);
			}
//			tr(nv);
			Node un = mergeX(stack[sp-2], stack[sp-1]);
			sp--; sp--;
			stack[sp++] = un;
			vals[sp-1] = nv%mod;
		}
		out.println(vals[0]);
	}
	
	static long countLess(Node x, Node y)
	{
		if(x == null)return 0L;
		fall(x);
		return (countLess(x.left, y) + countLess(x.right, y) + countLess(y, x.id) * x.myval) % mod;
	}
	
	static long countLess(Node y, int id)
	{
		long ret = 0;
		while(y != null){
			fall(y);
			if(id < y.id){
				y = y.left;
			}else if(id == y.id){
				ret += val(y.left);
				break;
			}else{
				ret += val(y.left);
				ret += y.myval;;
				y = y.right;
			}
		}
		return ret%mod;
	}
	
	static long countMore(Node x, Node y)
	{
		if(x == null)return 0L;
		fall(x);
		return (countMore(x.left, y) + countMore(x.right, y) + countMore(y, x.id) * x.myval) % mod;
	}
	
	static long countMore(Node y, int id)
	{
		long ret = 0;
		while(y != null){
			fall(y);
			if(id > y.id){
				y = y.right;
			}else if(id == y.id){
				ret += val(y.right);
				break;
			}else{
				ret += val(y.right);
				ret += y.myval;;
				y = y.left;
			}
		}
		return ret%mod;
	}
	
	public static long val(Node a)
	{
		return a == null ? 0 : a.val;
	}
	
	static Node mergeX(Node x, Node y)
	{
		if(count(x) > count(y)){
			Node z = x; x = y; y = z;
		}
		while(count(x) > 0){
			Node first = get(x, 0);
			x = erase(x, 0);
			y = insertb(y, first);
		}
		return y;
	}
	
	public static Node insertb(Node root, Node x)
	{
		int ind = search(root, x.id);
		if(ind >= 0){
			Node t = get(root, ind);
			assert t.mul == 1;
			t.myval += x.myval;
			if(t.myval >= mod)t.myval -= mod;
			while(t != null){
				update(t);
				t = t.parent;
			}
			return root;
		}else{
			if(ind < 0)ind = -ind-1;
			return insert(root, ind, x);
		}
	}
	
	public static int search(Node a, int q)
	{
		int lcount = 0;
		while(a != null){
			fall(a);
			if(a.id == q){
				lcount += count(a.left);
				break;
			}
			if(q < a.id){
				a = a.left;
			}else{
				lcount += count(a.left) + 1;
				a = a.right;
			}
		}
		return a == null ? -(lcount+1) : lcount;
	}
	
	public static Random gen = new Random(10000000);
	
	static public class Node
	{
		public int id; // value
		public long priority;
		public Node left, right, parent;
		
		public int count;
		
		public long myval;
		public long mul;
		public long val;
		public long val2;
		
		public Node(int v)
		{
			this.id = v;
			this.myval = 1;
			this.mul = 1;
			priority = gen.nextLong();
			update(this);
		}
		
		@Override
		public String toString() {
			StringBuilder builder = new StringBuilder();
			builder.append("Node [v=");
			builder.append(id);
			builder.append(", count=");
			builder.append(count);
			builder.append(", parent=");
			builder.append(parent != null ? parent.id : "null");
			builder.append(", mul=");
			builder.append(val);
			builder.append(", val=");
			builder.append(val);
			builder.append("]");
			return builder.toString();
		}
	}

	public static Node update(Node a)
	{
		if(a == null)return null;
		a.count = 1;
		if(a.left != null)a.count += a.left.count;
		if(a.right != null)a.count += a.right.count;
		
		a.val = a.myval;
		if(a.left != null)a.val += a.left.val;
		if(a.right != null)a.val += a.right.val;
		a.val = a.val * a.mul % mod;
		
		a.val2 = a.myval * a.myval;
		if(a.left != null)a.val2 += a.left.val2;
		if(a.right != null)a.val2 += a.right.val2;
		a.val2 = a.val2 % mod * a.mul % mod * a.mul % mod;
		return a;
	}
	
	public static Node disconnect(Node a)
	{
		if(a == null)return null;
		a.left = a.right = a.parent = null;
		return update(a);
	}
	
	public static Node root(Node x)
	{
		if(x == null)return null;
		while(x.parent != null)x = x.parent;
		return x;
	}
	
	public static int count(Node a)
	{
		return a == null ? 0 : a.count;
	}
	
	public static void setParent(Node a, Node par)
	{
		if(a != null)a.parent = par;
	}
	
//	public static int min(Node a, int L, int R)
//	{
//		if(a == null || L >= R || L >= count(a) || R <= 0)return Integer.MAX_VALUE / 2;
//		if(L <= 0 && R >= count(a)){
//			return a.min;
//		}else{
//			int lmin = min(a.left, L, R);
//			int rmin = min(a.right, L-count(a.left)-1, R-count(a.left)-1);
//			int min = Math.min(lmin, rmin) + a.add;
//			if(L <= count(a.left) && count(a.left) < R)min = Math.min(min, a.id);
//			return min;
//		}
//	}
	
	public static void mul(Node a, int V)
	{
		a.mul = a.mul * V % mod;
		update(a);
	}
	
	public static void fall(Node a)
	{
		if(a == null)return;
		if(a.left != null){
			a.left.mul *= a.mul;
			a.left.mul %= mod;
			update(a.left);
		}
		if(a.right != null){
			a.right.mul *= a.mul;
			a.right.mul %= mod;
			update(a.right);
		}
		a.myval = a.myval * a.mul % mod;
		a.mul = 1;
		update(a);
	}
	
	public static Node merge(Node a, Node b)
	{
		if(b == null)return a;
		if(a == null)return b;
		if(a.priority > b.priority){
			fall(a);
			setParent(a.right, null);
			setParent(b, null);
			a.right = merge(a.right, b);
			setParent(a.right, a);
			return update(a);
		}else{
			fall(b);
			setParent(a, null);
			setParent(b.left, null);
			b.left = merge(a, b.left);
			setParent(b.left, b);
			return update(b);
		}
	}
	
	// [0,K),[K,N)
	public static Node[] split(Node a, int K)
	{
		if(a == null)return new Node[]{null, null};
		fall(a);
		if(K <= count(a.left)){
			setParent(a.left, null);
			Node[] s = split(a.left, K);
			a.left = s[1];
			setParent(a.left, a);
			s[1] = update(a);
			return s;
		}else{
			setParent(a.right, null);
			Node[] s = split(a.right, K-count(a.left)-1);
			a.right = s[0];
			setParent(a.right, a);
			s[0] = update(a);
			return s;
		}
	}
	
	public static Node insert(Node a, int K, Node b)
	{
		if(a == null)return b;
		fall(a);
		if(b.priority < a.priority){
			if(K <= count(a.left)){
				a.left = insert(a.left, K, b);
				setParent(a.left, a);
			}else{
				a.right = insert(a.right, K-count(a.left)-1, b);
				setParent(a.right, a);
			}
			return update(a);
		}else{
			Node[] ch = split(a, K);
			b.left = ch[0]; b.right = ch[1];
			setParent(b.left, b);
			setParent(b.right, b);
			return update(b);
		}
	}
	
	// delete K-th
	public static Node erase(Node a, int K)
	{
		if(a == null)return null;
		if(K < count(a.left)){
			a.left = erase(a.left, K);
			setParent(a.left, a);
			return update(a);
		}else if(K == count(a.left)){
			fall(a);
			setParent(a.left, null);
			setParent(a.right, null);
			Node aa = merge(a.left, a.right);
			disconnect(a);
			return aa;
		}else{
			a.right = erase(a.right, K-count(a.left)-1);
			setParent(a.right, a);
			return update(a);
		}
	}
	
	public static Node get(Node a, int K)
	{
		while(a != null){
			fall(a);
			if(K < count(a.left)){
				a = a.left;
			}else if(K == count(a.left)){
				break;
			}else{
				K = K - count(a.left)-1;
				a = a.right;
			}
		}
		return a;
	}
	
	static Node[] Q = new Node[100];
	public static Node update(Node a, int K, int v)
	{
		int p = 0;
		while(a != null){
			Q[p++] = a;
			if(K < count(a.left)){
				a = a.left;
			}else if(K == count(a.left)){
				break;
			}else{
				K = K - count(a.left)-1;
				a = a.right;
			}
		}
		a.id = v;
		while(p > 0){
			update(Q[--p]);
		}
		return a;
	}
	
	public static int index(Node a)
	{
		if(a == null)return -1;
		int ind = count(a.left);
		while(a != null){
			Node par = a.parent;
			if(par != null && par.right == a){
				ind += count(par.left) + 1;
			}
			a = par;
		}
		return ind;
	}
	
	public static Node[] nodes(Node a) { return nodes(a, new Node[a.count], 0, a.count); }
	public static Node[] nodes(Node a, Node[] ns, int L, int R)
	{
		if(a == null)return ns;
		nodes(a.left, ns, L, L+count(a.left));
		ns[L+count(a.left)] = a;
		nodes(a.right, ns, R-count(a.right), R);
		return ns;
	}
	
	public static String toString(Node a, String indent)
	{
		if(a == null)return "";
		StringBuilder sb = new StringBuilder();
		sb.append(toString(a.left, indent + "  "));
		sb.append(indent).append(a).append("\n");
		sb.append(toString(a.right, indent + "  "));
		return sb.toString();
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