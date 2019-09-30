package gcj2012.r3;
import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class B {
	static String BASEPATH = "x:\\";
	static boolean LARGE = false;
	static String INPATH = BASEPATH + B.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	static int[] dr = {0, 1, 1, 0, -1, -1};
	static int[] dc = {1, 1, 0, -1, -1, 0};
	
	public void call()
	{
		int s = ni(), m = ni();
		int n = 2*s-1;
		DJSet ds = new DJSet(n*n);
		boolean[][] f = new boolean[n][n];
		int[][] hand = new int[m][];
		for(int i = 0;i < m;i++){
			hand[i] = new int[]{ni()-1, ni()-1};
		}
		int[][] fs = makeFork(n);
		for(int i = 0;i < m;i++){
			int r = hand[i][0], c = hand[i][1];
			f[r][c] = true;
			for(int k = 0;k < 6;k++){
				int nr = r + dr[k], nc = c + dc[k];
				if(nr >= 0 && nr < n && nc >= 0 && nc < n && nr-nc < s && nc-nr < s && f[nr][nc]){
					ds.union(nr*n+nc, r*n+c);
				}
			}
			
			boolean hb = hasBridge(f, ds);
			boolean hf = hasFork(f, ds, fs);
			boolean hr = hasRing(f, ds);
			if(hb || hf || hr){
				String ret = "";
				if(hb){
					ret += "bridge";
				}
				if(hf){
					if(ret.length() > 0)ret += "-";
					ret += "fork";
				}
				if(hr){
					if(ret.length() > 0)ret += "-";
					ret += "ring";
				}
				out.println(ret + " in move " + (i+1));
				return;
			}
		}
		out.println("none");
	}
	
	boolean hasBridge(boolean[][] f, DJSet ds)
	{
		int n = f.length;
		int s = (n+1)/2;
		int[] U = {
				0*n+0, 0*n+s-1, (s-1)*n+0, (s-1)*n+n-1, (n-1)*n+s-1, (n-1)*n+n-1
		};
		for(int i = 0;i < 6;i++){
			for(int j = i+1;j < 6;j++){
				if(ds.equiv(U[i], U[j])){
					return true;
				}
			}
		}
		return false;
	}
	
	boolean hasRing(boolean[][] f, DJSet ds)
	{
		int n = f.length;
		int s = (n+1)/2;
		DJSet oh = new DJSet(n*n+1);
		int not = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(i-j < s && j-i < s && !f[i][j]){
					not++;
					if(i == 0 || j == 0 || i-j==s-1 || j-i==s-1 || i == n-1 || j == n-1){
						oh.union(i*n+j, n*n);
					}else{
						for(int k = 0;k < 6;k++){
							int nr = i + dr[k], nc = j + dc[k];
							if(nr >= 0 && nr < n && nc >= 0 && nc < n && nr-nc < s && nc-nr < s && !f[nr][nc]){
								oh.union(nr*n+nc, i*n+j);
							}
						}
					}
				}
			}
		}

		return -oh.upper[oh.root(n*n)] != not+1;
	}
	
	int[][] makeFork(int n)
	{
		int s = (n+1)/2;
		int[][] q = new int[6][s-2];
		int[] qp = new int[6];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(i-j < s && j-i < s){
					if(i == 0 && j > 0 && j < s-1){
						q[0][qp[0]++] = i*n+j;
					}
					if(j == 0 && i > 0 && i < s-1){
						q[1][qp[1]++] = i*n+j;
					}
					if(j-i == s-1 && i > 0 && j < n-1){
						q[2][qp[2]++] = i*n+j;
					}
					if(i-j == s-1 && j > 0 && i < n-1){
						q[3][qp[3]++] = i*n+j;
					}
					if(j == n-1 && i >= s && i < n-1){
						q[4][qp[4]++] = i*n+j;
					}
					if(i == n-1 && j >= s && j < n-1){
						q[5][qp[5]++] = i*n+j;
					}
				}
			}
		}
		return q;
	}

	boolean hasFork(boolean[][] f, DJSet ds, int[][] fs){
		int n = f.length;
		int s = (n+1)/2;
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		for(int i = 0;i < 6;i++){
			Set<Integer> set = new HashSet<Integer>();
			for(int j = 0;j < s-2;j++){
				int r = fs[i][j] / n;
				int c = fs[i][j] % n;
				if(f[r][c]){
					int root = ds.root(fs[i][j]);
					set.add(root);
				}
			}
			
			for(int v : set){
				if(!map.containsKey(v)){
					map.put(v, 0);
				}
				map.put(v, map.get(v) + 1);
			}
		}
		
		for(int v : map.values()){
			if(v >= 3){
				return true;
			}
		}
		return false;
	}
	
	public static class DJSet { public int[] upper; public DJSet(int n){ upper = new int[n]; Arrays.fill(upper, -1);} public int root(int x){	return upper[x] < 0 ? x : (upper[x] = root(upper[x]));}	public boolean equiv(int x, int y){ return root(x) == root(y);} public void union(int x, int y){ x = root(x);y = root(y);if(x != y) { if(upper[y] < upper[x]) { int d = x; x = y; y = d;	} upper[x] += upper[y]; upper[y] = x;}} public int count(){	int ct = 0;	for(int i = 0;i < upper.length;i++){ if(upper[i] < 0)ct++; } return ct; }}
	
	Scanner in;
	PrintWriter out;
	int cas;
	
	public B(int cas, Scanner in, PrintWriter out)
	{
		this.cas = cas;
		this.in = in;
		this.out = out;
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
	
	public static void main(String[] args) throws Exception
	{
		long start = System.currentTimeMillis();
		boolean real = INPUT.isEmpty();
		
		if(real){
			System.out.println("INPATH : " + INPATH);
			System.out.println("OUTPATH : " + OUTPATH);
		}
		Scanner in = real ? new Scanner(new File(INPATH)) : new Scanner(INPUT);
		PrintWriter out = real ? new PrintWriter(new File(OUTPATH)) : new PrintWriter(System.out);
		int n = in.nextInt();
		in.nextLine();
		
		for(int i = 0;i < n;i++){
			out.printf("Case #%d: ", i+1);
			new B(i+1, in, out).call();
			out.flush();
			if(real)System.err.println("case " + (i + 1) + " solved.\t");
		}
		
		long end = System.currentTimeMillis();
		System.out.println((end - start) + "ms");
		if(real){
			System.out.println("INPATH : " + INPATH);
			System.out.println("OUTPATH : " + OUTPATH);
		}
	}
}
