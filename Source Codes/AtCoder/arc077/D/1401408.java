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
	
	static void solve()
	{
		char[] s = ns().toCharArray();
		long L = nl()-1, R = nl()-1;
		int n = s.length;
		int ptn = 0;
		for(int i = 0;i < n;i++){
			ptn |= 1<<s[i]-'a';
		}
		if((ptn&ptn-1) == 0){
			for(int i = 0;i < 26;i++){
				if(ptn<<~i<0){
					out.print(R-L+1 + " ");
				}else{
					out.print(0 + " ");
				}
			}
			out.println();
			return;
		}
		
		int[] z = Z(s);
		int len = s.length;
		for(int i = 1;i < s.length/2;i++){
			if(z[s.length/2+i] == s.length/2-i){
				len = s.length/2+i;
				break;
			}
		}
		if(len == s.length){
			long[] f = new long[26];
			for(int i = 0;i < n;i++){
				f[s[i]-'a'] += (R+1) / s.length + ((R+1)%s.length > i ? 1 : 0);
				f[s[i]-'a'] -= L / s.length + (L%s.length > i ? 1 : 0);
			}
			for(int i = 0;i < 26;i++){
				out.print(f[i] + " ");
			}
			out.println();
			return;
		}
		
		char[] t = Arrays.copyOf(s, len*2);
		for(int j = 0;j < len;j++){
			t[j+len] = t[j];
		}
		int[] zt = Z(t);
		int lent = t.length;
		for(int i = 1;i < t.length/2;i++){
			if(zt[t.length/2+i] == t.length/2-i){
				lent = t.length/2+i;
				break;
			}
		}
		long[] vs = new long[100];
		vs[0] = len;
		vs[1] = lent;
		for(int i = 2;;i++){
			vs[i] = vs[i-1] + vs[i-2];
			if(vs[i] > 1e18){
				vs = Arrays.copyOf(vs, i);
				break;
			}
		}
		
		long[] f1 = count(R, vs, s);
		long[] f0 = count(L-1, vs, s);
		for(int i = 0;i < 26;i++){
			out.print(f1[i] - f0[i] + " ");
		}
		out.println();
		
	}
	
	public static int[] Z(char[] str)
	{
		int n = str.length;
		int[] z = new int[n];
		if(n == 0)return z;
		z[0] = n;
		int l = 0, r = 0;
		for(int i = 1;i < n;i++){
			if(i > r){
				l = r = i;
				while(r < n && str[r-l] == str[r])r++;
				z[i] = r-l; r--;
			}else{
				if(z[i-l] < r-i+1){
					z[i] = z[i-l];
				}else{
					l = i;
					while(r < n && str[r-l] == str[r])r++;
					z[i] = r-l; r--;
				}
			}
		}
		
		return z;
	}
	
	static long[] count(long z, long[] vs, char[] s)
	{
		long[][] ops = new long[][]{{0L, 1L}, {z+1, -1L}};
		for(int i = vs.length-1;i >= 0;i--){
			for(int j = ops.length-1;j >= 0;j--){
				if(ops[j][0] <= vs[i]){
					long sum = 0;
					for(int k = 0;k < ops.length;k++){
						if(ops[k][0] < vs[i]){
							sum += ops[k][1];
						}
					}
					for(int k = 0;k < ops.length;k++){
						ops[k][0] %= vs[i];
					}
					ops = Arrays.copyOf(ops, ops.length+2);
					ops[ops.length-2] = new long[]{0, sum};
					ops[ops.length-1] = new long[]{vs[i], -sum};
					Arrays.sort(ops, (x, y) -> Long.compare(x[0], y[0]));
					break;
				}
			}
		}
		long[] ret = new long[26];
		long h = 0;
		int p = 0;
		for(int i = 0;i < s.length;i++){
			while(p < ops.length && ops[p][0] <= i){
				h += ops[p++][1];
			}
			ret[s[i]-'a'] += h;
		}
		return ret;
	}
	
	public static Random gen = new Random();
	
	static public class Node
	{
		public long id;
		public long v; // value
		public long priority;
		public Node left, right, parent;
		
		public int count;
		
		public long add;
		public long sum;
		
		public Node(long id, long v)
		{
			this.id = id;
			this.v = v;
			priority = gen.nextLong();
			update(this);
		}
		
		@Override
		public String toString() {
			StringBuilder builder = new StringBuilder();
			builder.append("Node [v=");
			builder.append(v);
			builder.append(", count=");
			builder.append(count);
			builder.append(", parent=");
			builder.append(parent != null ? parent.v : "null");
			builder.append(", add=");
			builder.append(add);
			builder.append(", sum=");
			builder.append(sum);
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
		
		a.sum = a.v + a.add * a.count;
		if(a.left != null)a.sum += a.left.sum;
		if(a.right != null)a.sum += a.right.sum;
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
	
	public static long sum(Node a, int L, int R)
	{
		if(a == null || L >= R || L >= count(a) || R <= 0)return 0L;
		if(L <= 0 && R >= count(a)){
			return a.sum;
		}else{
			long ret = 0;
			ret += sum(a.left, L, R);
			ret += sum(a.right, L-count(a.left)-1, R-count(a.left)-1);
			if(L <= count(a.left) && count(a.left) < R)ret += a.v;
			ret += (Math.min(R, a.count) - L) * a.add;
			return ret;
		}
	}
	
	public static void add(Node a, int L, int R, long V)
	{
		if(a == null || L >= R || L >= count(a) || R <= 0)return;
		if(L <= 0 && R >= count(a)){
			a.add += V;
		}else{
			add(a.left, L, R, V);
			add(a.right, L-count(a.left)-1, R-count(a.left)-1, V);
			if(L <= count(a.left) && count(a.left) < R)a.v += V;
		}
		update(a);
	}
	
	public static void fall(Node a)
	{
		if(a == null)return;
		a.v += a.add;
		if(a.left != null){
			a.left.add += a.add;
			update(a.left);
		}
		if(a.right != null){
			a.right.add += a.add;
			update(a.right);
		}
		a.add = 0;
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
	
	public static Node insertb(Node root, Node x)
	{
		int ind = search(root, x.id);
		if(ind < 0){
			// insert
			ind = -ind-1;
			return insert(root, ind, x);
		}else{
			// add
			Node t = get(root, ind);
			t.v += x.v;
			while(t != null){
				update(t);
				t = t.parent;
			}
			return root;
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
	
	public static int lowerBound(Node a, long q)
	{
		int lcount = 0;
		while(a != null){
			if(a.id >= q){
				a = a.left;
			}else{
				lcount += count(a.left) + 1;
				a = a.right;
			}
		}
		return lcount;
	}

	
	public static int search(Node a, long q)
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
	
	public static Node[] nodes(Node a) { return nodes(a, new Node[count(a)], 0, count(a)); }
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