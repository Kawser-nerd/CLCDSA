import java.io.*;
import java.lang.reflect.Array;
import java.math.*;
import java.security.KeyStore.Entry;
import java.util.*;
 
public class Main {
	private InputStream is;
	private PrintWriter out;
	int time = 0, dp[][], DP[][], dist[], prime[], start[], parent[], end[],
			val[], black[], arr[], arr1[][];
	long MOD = (long) (1e9 + 9);
	ArrayList<Integer>[] amp;
	boolean b[], b1[];
	Pair prr1[];
	char ch[][], c[];
	HashSet<Integer> hs1 = new HashSet<>(), hs2 = new HashSet<>();
 
	public static void main(String[] args) throws Exception {
		new Thread(null, new Runnable() {
			public void run() {
				try {
 
					// new Main().soln();
				} catch (Exception e) {
					System.out.println(e);
				}
			}
		}, "1", 1 << 26).start();
		new Main().soln();
	}
 
	int MAX = 1000010, N, K;
	double Q = 1;
	double a = 1 , fa = 0;
	long B = 0;
	PriorityQueue<Pair> pq;
	int Dp[][] = new int[1010][1010];
	int MOD1 = 1000000007, MOD2 = 1000000009;
	void solve() {
		int cnt = 0;
		long temp = 1;
		while(cnt<64){
			System.out.println("? "+temp);
			System.out.flush();
			String s = ns();
			if(temp >=10000000000L) break;
			if(s.equals("Y")){
				temp*=10;
				cnt++;
				continue;
			}
			long l = temp, r = temp*10;
			long ans = 1;
			while(l<=r){
				long mid = (l+r)/2;
				System.out.println("? "+mid);
				System.out.flush();
				String s1 = ns();
				if(s1.equals("Y")){
					ans = mid;
					r = mid-1;
				}
				else{
					l = mid+1;
				}
			}
			System.out.println("! "+ans/10);
			System.out.flush();
			return;
		}
		long temp1 = 10;
		int g = 0;
		while(g<=12){
			g++;
			System.out.println("? "+(temp1-1));
			System.out.flush();
			String s = ns();
			if(s.equals("N")){
				temp1*=10;
				continue;
			}
			else{
				System.out.println("! "+temp1/10);
				return;
			}
		}
	}
	int dfs(int x){
		b[x] = true;
		for(int i:amp[x]){
			if(!b[i]){
				parent[i] = x;
				dist[x] += dfs(i);
			}
		}
		return (++dist[x]);
	}
	void buildGraph(int n){
		while(n-->0){
			int x= ni()-1, y = ni()-1;
			amp[x].add(y);
			amp[y].add(x);
		}
	}
	void recur(int x, int y, int p){
		int val = 0;
		if(x>y || y<x) return;
		if(x>0){
			if(p==1){
				val = arr[x]-arr[x-1];
			}
			if(p==3){
				if(arr[x]-arr[x-1]<K){
					recur(x+1,y,3);
				}
				else val = arr[x]-arr[x-1];
			}
		}
		if(y<N){
			if(p==4){
				B += arr[y+1]-arr[y];
			}
			if(p==2){
				if(arr[y+1]-arr[y]<K){
					recur(x,y-1,2);
				}
				else val = arr[y+1]-arr[y];
			}
		}
		B += val;
		if(x==y){
			System.out.println(B+" "+a);
			fa += B*a;
		}
		//System.out.println(Q);
		a*=Q;
		recur(x+1,y,1);
		recur(x,y-1,2);
		a/=Q;
		a*=(1-Q);
		recur(x+1,y,3);
		recur(x,y-1,4);
		a/=(1-Q);
		B -= val;
		//System.out.println(a+" "+B);
	}
	class cell implements Comparable<cell>{
		char ch;
		int i;
		cell(char c, int x){
			ch = c;
			i = x;
		}
		public boolean equals(Object o) {
			cell other = (cell) o;
			return ((ch == other.ch && i == other.i));// || (v == other.u && u ==
			// other.v));
		}
		@Override
		public int compareTo(cell c) {
			if(this.ch<c.ch) return -1;
			if(this.ch==c.ch) {
				if(this.i<c.i)return 1;
				if(this.i==c.i) return 0;
				return -1;
			}
			return 1;
		}
 
		public String toString() {
			return "[u=" + ch + ", v=" + i + "]";
		}
		
	}
	int T[] = new int[100010], L[] = new int[100010];
	int P[][] = new int[100010][30];
 
	void process3(int N) {
		int i, j;
 
		// we initialize every element in P with -1
		for (i = 0; i < N; i++)
			for (j = 0; 1 << j < N; j++)
				P[start[i]][j] = -1;
 
		// the first ancestor of every node i is T[i]
		for (i = 0; i < N; i++)
			P[start[i]][0] = T[i];
 
		// bottom up dynamic programing
		for (j = 1; 1 << j < N; j++)
			for (i = 0; i < N; i++)
				if (P[start[i]][j - 1] != -1)
					P[start[i]][j] = P[P[start[i]][j - 1]][j - 1];
	}
 
	int query(int p, int q) {
		int tmp = 0, log = 0, i = 0;
 
		// if p is situated on a higher level than q then we swap them
		if (L[p] < L[q])
			tmp = p;
		p = q;
		q = tmp;
 
		// we compute the value of [log(L[p)]
		for (log = 1; 1 << log <= L[p]; log++)
			;
		log--;
 
		// we find the ancestor of node p situated on the same level
		// with q using the values in P
		for (i = log; i >= 0; i--)
			if (L[p] - (1 << i) >= L[q])
				p = P[p][i];
 
		if (p == q)
			return p;
 
		// we compute LCA(p, q) using the values in P
		for (i = log; i >= 0; i--)
			if (P[p][i] != -1 && P[p][i] != P[q][i])
				p = P[p][i];
		q = P[q][i];
 
		return T[p];
	}
 
 
	long ans = 0;
 
	void recur(int i, int k, long sum) {
		if (k > K)
			return;
		if (k == K) {
			ans = Math.max(ans, sum);
		}
		for (int j = i; j < N; j++) {
 
			recur(j + 1, k + 1, sum);
		}
	}
 
	long[] mul(long arr[][], long temp[]) {
		long ans[] = new long[temp.length];
		for (int i = 0; i < arr.length; i++) {
			long sum = 0;
			for (int j = 0; j < arr.length; j++) {
				sum = (sum + arr[i][j] * temp[j]) % MOD;
			}
			ans[i] = sum;
		}
		return ans;
	}
 
	void printMat(long arr[][]) {
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr.length; j++) {
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
		System.out.println("-----");
	}
 
	void printMat(long arr[]) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
		System.out.println("-----");
	}
 
	long[][] matMul(int n, long arr[][], long y) {
		long iden[][] = new long[n][n];
		for (int i = 0; i < n; i++)
			iden[i][i] = 1;
		// printMat(iden);
		while (y > 0) {
			if (y % 2 == 1) {
				iden = mul(n, iden, arr);
				// printMat(iden);
				y--;
			} else {
				arr = mul(n, arr, arr);
				// printMat(arr);
				y /= 2;
			}
		}
		return iden;
	}
 
	long[][] mul(int n, long a1[][], long a2[][]) {
		long temp[][] = new long[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				long sum = 0;
				for (int k = 0; k < n; k++) {
					sum = (sum + a1[i][k] * a2[k][j]) % MOD;
				}
				temp[i][j] = sum;
			}
		}
		return temp;
	}
 
	void seive(int n) {
		b = new boolean[n + 1];
		prime = new int[n + 1];
		for (int i = 2; i * i <= n; i++) {
			if (!b[i]) {
				for (int j = 2 * i; j <= n; j += i) {
					if (!b[j]) {
						b[j] = true;
						prime[j] = i;
					}
				}
			}
		}
	}
 
	int binarySearch1(int arr[], int x) {
		int ans = -1;
		int low = 0, high = arr.length - 1;
		while (high >= low) {
			int mid = (low + high) / 2;
			if (arr[mid] >= x) {
				ans = mid;
				high = mid - 1;
			} else
				low = mid + 1;
		}
		return ans;
	}
 
	int binarySearch2(Integer arr[], int x) {
		int ans = -1;
		int low = 0, high = arr.length - 1;
		while (high >= low) {
			int mid = (low + high) / 2;
			if (arr[mid] >= x) {
				ans = mid;
				low = mid + 1;
			} else
				high = mid - 1;
		}
		return ans + 1;
	}
 
	int cntEven(String str) {
		int cnt = 0;
		for (int i = str.length() - 1; i >= 0; i--) {
			if ((str.charAt(i) - '0') % 2 == 0) {
				cnt++;
			}
		}
		return cnt;
	}
 
	int max = 0;
 
	int getParent(int x) {
		// System.out.println(x+" "+parent[x]);
		if (parent[x] != x) {
			parent[x] = getParent(parent[x]);
		}
		return parent[x];
	}
 
	class Pair implements Comparable<Pair> {
		int u;
		int v, r, i;
 
		Pair(int u, int v, int r, int i) {
			this.u = u;
			this.v = v;
			this.r = r;
			this.i = i;
		}
 
		Pair(int u, int v, int r) {
			this.u = u;
			this.v = v;
			this.r = r;
		}
 
		Pair(int u, int v) {
			this.u = u;
			this.v = v;
		}
 
		public int hashCode() {
			return Objects.hash();
		}
 
		public boolean equals(Object o) {
			Pair other = (Pair) o;
			return ((u == other.u && v == other.v));// || (v == other.u && u ==
			// other.v));
		}
 
		public int compareTo(Pair other) {
			//return Long.compare(r, other.r);
			 return Long.compare(u, other.u) != 0 ? (Long.compare(u, other.u))
			 : (Long.compare(v, other.v));
			// :(Long.compare(other.r, r))) ;
		}
 
	}
 
	int min(int x, int y) {
		if (x < y)
			return x;
		return y;
	}
 
	int max(int x, int y) {
		if (x > y)
			return x;
		return y;
	}
 
 
	long modInverse(long a, long mOD2) {
		return power(a, mOD2 - 2, mOD2);
	}
 
	long power(long x, long y, long m) {
		if (y == 0)
			return 1;
		long p = power(x, y / 2, m) % m;
		p = (p * p) % m;
 
		return (y % 2 == 0) ? p : (x * p) % m;
	}
 
	boolean isPrime(int x) {
		for (int i = 2; i * 1L * i <= x; i++)
			if (x % i == 0)
				return false;
		return true;
	}
 
	public long gcd(long a, long b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}
 
	void failFn(String str, int arr[]) {
		int len = 0;
		arr[0] = 0;
		int i = 1;
		while (i < arr.length) {
			if (str.charAt(i) == str.charAt(len)) {
				arr[i++] = ++len;
				continue;
			}
			if (len == 0) {
				arr[i] = len;
				i++;
				continue;
			}
			if (str.charAt(i) != str.charAt(len)) {
				len = arr[len - 1];
			}
		}
	}
 
	static class ST1 {
		int arr[], st[], size;
 
		ST1(int a[]) {
			arr = a.clone();
			size = 10 * arr.length;
			st = new int[size];
			build(0, arr.length - 1, 1);
		}
 
		void build(int ss, int se, int si) {
			if (ss == se) {
				st[si] = arr[ss];
				return;
			}
			int mid = (ss + se) / 2;
			int val = 2 * si;
			build(ss, mid, val);
			build(mid + 1, se, val + 1);
			st[si] = (st[val] + st[val + 1]);
		}
 
		int get(int ss, int se, int l, int r, int si) {
			if (l > se || r < ss || l > r)
				return Integer.MAX_VALUE;
			if (l <= ss && r >= se)
				return st[si];
			int mid = (ss + se) / 2;
			int val = 2 * si;
			return (get(ss, mid, l, r, val) + get(mid + 1, se, l, r, val + 1));
		}
	}
 
	static class ST {
		int arr[], lazy[], n;
 
		ST(int a) {
			n = a;
			arr = new int[10 * n];
			lazy = new int[10 * n];
		}
 
		void up(int l, int r, int val) {
			update(0, n - 1, 0, l, r, val);
		}
 
		void update(int l, int r, int c, int x, int y, int val) {
			if (lazy[c] != 0) {
				lazy[2 * c + 1] ^= lazy[c];
				lazy[2 * c + 2] ^= lazy[c];
				if (l == r)
					arr[c] ^= lazy[c];
				lazy[c] = 0;
			}
			if (l > r || x > y || l > y || x > r)
				return;
			if (x <= l && y >= r) {
				if ((r - l + 1) % 2 == 1)
					lazy[c] ^= val;
				return;
			}
			int mid = l + r >> 1;
		update(l, mid, 2 * c + 1, x, y, val);
		update(mid + 1, r, 2 * c + 2, x, y, val);
		arr[c] = (arr[2 * c + 1] + arr[2 * c + 2]);
		}
 
		int an(int ind) {
			return ans(0, n - 1, 0, ind);
		}
 
		int ans(int l, int r, int c, int ind) {
			if (lazy[c] != 0) {
				lazy[2 * c + 1] += lazy[c];
				lazy[2 * c + 2] += lazy[c];
				if (l == r)
					arr[c] += lazy[c];
				lazy[c] = 0;
			}
			if (l == r)
				return arr[c];
			int mid = l + r >> 1;
		if (mid >= ind)
			return ans(l, mid, 2 * c + 1, ind);
		return ans(mid + 1, r, 2 * c + 2, ind);
		}
	}
	static long[] array;
	public static class FenwickTree {
 
		 // 1-indexed array, In this array We save cumulative
		// information to perform efficient range queries and
		// updates
 
		public FenwickTree(int size) {
			array = new long[size + 1];
		}
		int getSum(int index)
		{
			int sum = 0; // Iniialize result
 
			// index in BITree[] is 1 more than the index in arr[]
			index = index + 1;
 
			// Traverse ancestors of BITree[index]
			while (index>0)
			{
				// Add current element of BITree to sum
				sum ^= array[index];
 
				// Move index to parent node in getSum View
				index -= index & (-index);
			}
			return sum;
		}
		public long rsq(int ind) {
			assert ind > 0;
			long sum = 0;
			ind = ind+1;
			while (ind > 0) {
				sum ^= array[ind];
				// Extracting the portion up to the first significant one of the
				// binary representation of 'ind' and decrementing ind by that
				// number
				ind -= ind & (-ind);
			}
			return sum;
		}
 
		public long rsq(int a, int b) {
			assert b >= a && a > 0 && b > 0;
			return rsq(b) ^ rsq(a - 1);
		}
 
		public void update(int ind, long value) {
			assert ind > 0;
			ind = ind+1;
			while (ind < array.length) {
				array[ind] ^= value;
				// Extracting the portion up to the first significant one of the
				// binary representation of 'ind' and incrementing ind by that
				// number
				ind += ind & (-ind);
			}
		}
 
		public int size() {
			return array.length - 1;
		}
	}
 
	public static int[] shuffle(int[] a, Random gen) {
		for (int i = 0, n = a.length; i < n; i++) {
			int ind = gen.nextInt(n - i) + i;
			int d = a[i];
			a[i] = a[ind];
			a[ind] = d;
		}
		return a;
	}
 
	long power(long x, long y, int mod) {
		long ans = 1;
		while (y > 0) {
			if (y % 2 == 0) {
				x = (x * x) % mod;
				y /= 2;
			} else {
				ans = (x * ans) % mod;
				y--;
			}
		}
		return ans;
	}
 
	void soln() {
		is = System.in;
		out = new PrintWriter(System.out);
		long s = System.currentTimeMillis();
		solve();
		out.close();
		out.flush();
		tr(System.currentTimeMillis() - s + "ms");
	}
 
	// To Get Input
	// Some Buffer Methods
	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;
 
	private int readByte() {
		if (lenbuf == -1)
			throw new InputMismatchException();
		if (ptrbuf >= lenbuf) {
			ptrbuf = 0;
			try {
				lenbuf = is.read(inbuf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (lenbuf <= 0)
				return -1;
		}
		return inbuf[ptrbuf++];
	}
 
	private boolean isSpaceChar(int c) {
		return !(c >= 33 && c <= 126);
	}
 
	private int skip() {
		int b;
		while ((b = readByte()) != -1 && isSpaceChar(b))
			;
		return b;
	}
 
	private double nd() {
		return Double.parseDouble(ns());
	}
 
	private char nc() {
		return (char) skip();
	}
 
	private String ns() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != '
			// ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
 
	private char[] ns(int n) {
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while (p < n && !(isSpaceChar(b))) {
			buf[p++] = (char) b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
 
	private char[][] nm(int n, int m) {
		char[][] map = new char[n][];
		for (int i = 0; i < n; i++)
			map[i] = ns(m);
		return map;
	}
 
	private int[] na(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = ni();
		return a;
	}
 
	private int ni() {
		int num = 0, b;
		boolean minus = false;
		while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
			;
		if (b == '-') {
			minus = true;
			b = readByte();
		}
 
		while (true) {
			if (b >= '0' && b <= '9') {
				num = num * 10 + (b - '0');
			} else {
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
 
	private long nl() {
		long num = 0;
		int b;
		boolean minus = false;
		while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
			;
		if (b == '-') {
			minus = true;
			b = readByte();
		}
 
		while (true) {
			if (b >= '0' && b <= '9') {
				num = num * 10 + (b - '0');
			} else {
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
 
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
 
	private void tr(Object... o) {
		if (!oj)
			System.out.println(Arrays.deepToString(o));
	}
}