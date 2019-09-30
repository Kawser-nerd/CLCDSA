import java.io.*;
import java.lang.reflect.Array;
import java.math.*;
import java.security.KeyStore.Entry;
import java.util.*;


  public class Main {
	private InputStream is;
	private PrintWriter out;
	int time = 0, dp[][], DP[][], prime[], start[], parent[], end[], val[], black[], arr[], arr1[][];
	long  MOD = (long)(1e9+7);
	ArrayList<Integer>[] amp;
	boolean b[], b1[];
	Pair prr[];
	char ch[][],c[];
	HashSet<Integer> hs1 = new HashSet<>(), hs2 = new HashSet<>();

	public static void main(String[] args) throws Exception {
		new Thread(null, new Runnable() {
		public void run() {
			try {

		//new Main().soln();
		} catch (Exception e) {
				System.out.println(e);
			}
		}
	}, "1", 1 << 26).start();
		new Main().soln();
	}
	int MAX = 1000010, N, K, p = 1;
	PriorityQueue<Pair> pq;
	int Dp[][] = new int[1010][1010];
	void solve() {
		int H = ni(), W = ni(), h = ni(), w = ni();
		int l = H*W;
		int arr[][] = new int[H+1][W+1];
		for(int i = 1;i<=H;i++){
			for(int j = 1; j<= W; j++) arr[i][j] = 500;
		}
		if(H%h==0 && W%w==0){
			out.println("No");
			return;
		}
		if(h*w==1){
			out.println("No");
			return;
		}
		if(h==H || h==1){
			if(W%w==0){
				System.out.println("No");
				return;
			}
		}
		if(w==W || w==1){
			if(H%h==0){
				System.out.println("No");
				return;
			}
		}
		if(h*w==2){
			if(w==2){
				if(W%2==1){
					out.println("Yes");
					for(int i = 1;i<=H;i++){
						for(int j = 2;j<=W;j+=2){
							arr[i][j] = -501;
						}
					}
					for(int i = 1;i<=H;i++){
						for(int j = 1;j<=W;j++){
							out.print(arr[i][j]+" ");
						}
						out.println();
					}
				}
				else out.println("No");
			}
			else{
				if(H%2==1){
					out.println("Yes");
					for(int i = 1;i<=W;i++){
						for(int j = 2;j<=H;j+=2){
							arr[j][i] = -501;
						}
					}
					for(int i = 1;i<=H;i++){
						for(int j = 1;j<=W;j++){
							out.print(arr[i][j]+" ");
						}
						out.println();
					}
				}
				else out.println("No");
			}
		}
		else{
			int y = ((h*w-1)*500)+1;
			if(l==y){
				out.println("No");
			}
			else{
				out.println("Yes");
				for(int i = h; i<=H;i+=h){
					for(int j = w; j<= W;j+=w){
						arr[i][j] = -y;
					}
				}
				long sum = 0;
				for(int i = 1;i<=H;i++){
					for(int j = 1;j<=W;j++){
					//	sum += arr[i][j];
						out.print(arr[i][j]+" ");}out.println();
					
				}
			//	out.println(sum+"*");
			}
		}
	}
	String isNice(String[] str){
		String ans = "Nice";
		TreeSet<String> hs = new TreeSet<>();
		for(String s : str) hs.add(s);
		if(hs.size()>2){
			return "Not Nice";
		}
		if(hs.size()==1){
			return ans;
		}
		String str1 = hs.pollFirst(), str2 = hs.pollFirst();
		for(int i =0;i<str1.length();i++){
			if(str1.charAt(i)==str2.charAt(i)) return "Not Nice";
		}
		return ans;
	}
	String get(String s, String t){
		char ch1[] = s.toCharArray();
		PriorityQueue<Character> pq = new PriorityQueue<>(Collections.reverseOrder());
		for(char ch : t.toCharArray()) pq.add(ch);
		for(int i = 0; i< ch1.length; i++){
			if(pq.isEmpty()) break;
			char c = pq.peek();
			if(c>ch1[i]){
				ch1[i] = c;
				pq.poll();
			}
		}
		return new String(ch1);
	}
	class Node{
		Node left, right;
		int data;
		Node(int x){
			data = x;
		}
	}
	class BST{
		Node root;
		Node pre;
		void insert(int x){
			if(root==null){
				root = new Node(x);
				return;
			}
			Node temp = root;
			Node prev = temp;
			while(temp!=null){
				int y = temp.data;
				prev = temp;
				if(y>x) temp = temp.left;
				if(y<x) temp = temp.right;
			}
			if(prev.data>x) prev.left = new Node(x);
			else prev.right = new Node(x);
		}
		Node search(int x){
			Node temp = root;
			pre = null;
			while(temp!=null){
				int y = temp.data;
				if(y==x) return temp;
				pre = temp;
				if(y>x) temp = temp.left;
				if(y<x) temp = temp.right;
			}
			return null;
		}
		void delete(int x){
			Node n = search(x);
			if(n==null){
				System.out.println("No such element");
			}
			else if(n.left==null && n.right==null){
				if(pre!=null){
					if(pre.data>x) pre.left = null;
					else pre.right = null;
				}
				else root = null;
			}
			else if(n.left==null){
				while(n.right!=null){
					
				}
			}
			else if(n.right==null){
				
			}
			else{
				
			}
		}
		void inOrder(Node n){
			if(n==null) return;
			inOrder(n.left);
			System.out.print(n.data+"->");
			inOrder(n.right);
		}
	}
	void dfs(int x){
		//System.out.println(x+" "+hs1);
		boolean[] b = new boolean[arr1[x].length];
		for(int i = 0; i<arr1[x].length;i++){
			int val = arr1[x][i];
			if(val>0 && !hs1.contains(val)){
				hs1.add(val);
				b[i] = true;
			}
			else if(hs1.contains(val*-1)){
				hs1.remove(val*-1);
				b[i] = true;
			}
		}
		//System.out.println(x+" * "+hs1);
		end[x] = hs1.size();
		for(int i : amp[x])
			dfs(i);
		for(int i = 0; i<arr1[x].length; i++){
			if(b[i]){
				int val = arr1[x][i];
				if(val>0){
					if(hs1.contains(val)) hs1.remove(val);
				}
				else hs1.add(val*-1);
			}
		}
		//System.out.println(hs1+" "+x);
	}
	long[] mul(long arr[][], long temp[]){
		long ans[] = new long[temp.length];
		for(int i = 0; i<arr.length;i++){
			long sum = 0;
			for(int j = 0; j<arr.length;j++){
				sum = (sum+arr[i][j]*temp[j])%MOD;
			}
			ans[i] = sum;
		}
		return ans;
	}
	void printMat(long arr[][]){
		for(int i = 0; i< arr.length; i++){
			for(int j = 0; j < arr.length ;j++){
				System.out.print(arr[i][j]+" ");
			}
			System.out.println();
		}
		System.out.println("-----");
	}
	void printMat(long arr[]){
		for(int i = 0; i< arr.length; i++){
				System.out.print(arr[i]+" ");
		}
		System.out.println();
		System.out.println("-----");
	}
	long[][] matMul(int n, long arr[][], long y){
		long iden[][] = new long[n][n];
		for(int i= 0; i< n; i++) iden[i][i] = 1;
		//printMat(iden);
		while(y>0){
			if(y%2==1){
				iden = mul(n,iden,arr);
				//printMat(iden);
				y--;
			}
			else{
				arr = mul(n,arr,arr);
				//printMat(arr);
				y/=2;
			}
		}
		return iden;
	}
	long[][] mul(int n , long a1[][], long a2[][]){
		long temp[][] = new long[n][n];
		for(int i = 0; i< n; i++){
			for(int j = 0; j<n; j++){
				long sum = 0;
				for(int k = 0; k<n;k++){
					sum = (sum+a1[i][k]*a2[k][j])%MOD;
				}
				temp[i][j] = sum;
			}
		}
		return temp;
	}
	void seive(int n){
		b = new boolean[n+1];
		prime = new int[n+1];
		for(int i = 2;i*i<=n;i++){
			if(!b[i]){
				for(int j = 2*i; j<=n;j+=i){
					if(!b[j]){
						b[j] = true;
						prime[j] = i;
					}
				}
			}
		}
	}
	int binarySearch1(int arr[], int x){
		int ans = -1;
		int low = 0, high = arr.length-1;
		while(high>=low){
			int mid = (low+high)/2;
			if(arr[mid]>=x){
				ans = mid;
				high = mid-1;
			}
			else low = mid+1;
		}
		return ans;
	}
	int binarySearch2(Integer arr[], int x){
		int ans = -1;
		int low = 0, high = arr.length-1;
		while(high>=low){
			int mid = (low+high)/2;
			if(arr[mid]>=x){
				ans = mid;
				low = mid+1;
			}
			else high = mid-1;
		}
		return ans+1;
	}
	int cntEven(String str){
		int cnt = 0;
		for(int i = str.length()-1; i >= 0; i--){
			if((str.charAt(i)-'0')%2==0){
				cnt++;
			}
		}
		return cnt;
	}
	int max = 0;
	int getParent(int x){
		//System.out.println(x+" "+parent[x]);
		if(parent[x]!=x){
			parent[x] = getParent(parent[x]);
		}
		return parent[x];
	}
	class Pair implements Comparable<Pair>{
		int u;
		int v, r;
		Pair(int u, int v, int r){
			this.u = u;
			this.v = v;
			this.r = r;
		}
		Pair(int u, int v){
			this.u = u;
			this.v = v;
		}public int hashCode() {
			return Objects.hash();
		}
		public boolean equals(Object o) {
			Pair other = (Pair) o;
			return ((u == other.u && v == other.v));// || (v == other.u && u == other.v));
		}
		public int compareTo(Pair other) {
			return Long.compare(u, other.u);
			//return Long.compare(u, other.u) != 0 ? (Long.compare(u, other.u)) : (Long.compare(v, other.v) != 0 ? (Long.compare(v, other.v)) :(Long.compare(other.r, r))) ;
		}	
		public String toString() {
			return "[u=" + u + ", v=" + v + "]";
		}
	}
	int min(int x,int y){
		if(x<y) return x;
		return y;
	}
	int max(int x,int y){
		if(x>y) return x;
		return y;
	}
	void buildGraph(int m){
		while(m-->0)
		{
			int x = ni()-1, y = ni()-1;
			amp[x].add(y);
			amp[y].add(x);
		}
	}
	long modInverse(long a, long mOD2){
        return  power(a, mOD2-2, mOD2);
	}
	long power(long x, long y, long m)
	{
		if (y == 0)
    return 1;
	long p = power(x, y/2, m) % m;
	p = (p * p) % m;

	return (y%2 == 0)? p : (x * p) % m;
	}
	boolean isPrime(int x){
		for(int i = 2;i*1L*i<=x;i++) if(x%i==0) return false;
		return true;
	}
	public long gcd(long a, long b){
		if(b==0) return a;
		return gcd(b,a%b);
	}
	void failFn(String str, int arr[]){
		int len = 0;
		arr[0] = 0;
		int i = 1;
		while(i<arr.length){
			if(str.charAt(i)==str.charAt(len)){
				arr[i++] = ++len;
				continue;
			}
			if(len == 0){
				arr[i] = len;
				i++;
				continue;
			}
			if(str.charAt(i)!=str.charAt(len)){
				len = arr[len-1];
			}
		}
	}
	static class ST1{
		int arr[], st[], size;
		ST1(int a[]){
			arr = a.clone();
			size = 10*arr.length;
			st = new int[size];
			build(0,arr.length-1,1);
		}
		void build(int ss, int se, int si){
			if(ss==se){
				st[si] = arr[ss];
				return;
			}
			int mid = (ss+se)/2;
			int val = 2*si;
			build(ss,mid,val); build(mid+1,se,val+1);
			st[si] = (st[val]+ st[val+1]);
		}
		int get(int ss, int se, int l, int r, int si){
			if(l>se || r<ss || l>r) return Integer.MAX_VALUE;
			if(l<=ss && r>=se) return st[si];
			int mid = (ss+se)/2;
			int val = 2*si;
			return (get(ss,mid,l,r,val)+ get(mid+1,se,l,r,val+1));
		}
	}
	static class ST{
		int arr[],lazy[],n;
		ST(int a){
			n = a;
			arr = new int[10*n];
			lazy = new int[10*n];
		}
		void up(int l,int r,int val){
			update(0,n-1,0,l,r,val);
		}
		void update(int l,int r,int c,int x,int y,int val){
			if(lazy[c]!=0){
				lazy[2*c+1]+=lazy[c];
				lazy[2*c+2]+=lazy[c];
				if(l==r)
					arr[c]+=lazy[c];
				lazy[c] = 0;
			}
			if(l>r||x>y||l>y||x>r)
				return;
			if(x<=l&&y>=r){
				lazy[c]+=val;
				return ;
			}
			int mid = l+r>>1;
			update(l,mid,2*c+1,x,y,val);
			update(mid+1,r,2*c+2,x,y,val);
			arr[c] = (arr[2*c+1]+ arr[2*c+2]);
		}
		int an(int ind){
			return ans(0,n-1,0,ind);
		}
		int ans(int l,int r,int c,int ind){
			if(lazy[c]!=0){
				lazy[2*c+1]+=lazy[c];
				lazy[2*c+2]+=lazy[c];
				if(l==r)
					arr[c]+=lazy[c];
				lazy[c] = 0;
			}
			if(l==r)
				return arr[c];
			int mid = l+r>>1;
			if(mid>=ind)
				return ans(l,mid,2*c+1,ind);
			return ans(mid+1,r,2*c+2,ind);
		}
	}
	public static class FenwickTree {
		
	    long[] array; // 1-indexed array, In this array We save cumulative information to perform efficient range queries and updates

	    public FenwickTree(int size) {
	        array = new long[size + 1];
	    }
	    public long rsq(int ind) {
	        assert ind > 0;
	        long sum = 0;
	        while (ind > 0) {
	            sum += array[ind];
	            //Extracting the portion up to the first significant one of the binary representation of 'ind' and decrementing ind by that number
	            ind -= ind & (-ind);
	        }
	        return sum;
	    }
	    public long rsq(int a, int b) {
	        assert b >= a && a > 0 && b > 0;
	        return rsq(b) - rsq(a - 1);
	    }
	    public void update(int ind, long value) {
	        assert ind > 0;
	        while (ind < array.length) {
	            array[ind] += value;
	            //Extracting the portion up to the first significant one of the binary representation of 'ind' and incrementing ind by that number
	            ind += ind & (-ind);
	        }
	    }
	    public int size() {
	        return array.length - 1;
	    }
	}
	public static int[] shuffle(int[] a, Random gen){
		for(int i = 0, n = a.length;i < n;i++)
		{ 
			int ind = gen.nextInt(n-i)+i; 
			int d = a[i]; 
			a[i] = a[ind];
			a[ind] = d; 
		} 
	return a; 
	}
	long power(long x, long y, int mod){
		long ans = 1;
		while(y>0){
			if(y%2==0){
				x = (x*x)%mod;
				y/=2;
			}
			else{
				ans = (x*ans)%mod;
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