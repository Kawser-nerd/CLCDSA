package gcj2012.r3;
import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.Scanner;

public class D {
	static String BASEPATH = "x:\\";
	static boolean LARGE = false;
	static String INPATH = BASEPATH + D.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	public void call()
	{
		int K = ni();
		char[] S = in.next().toCharArray();
		int n = S.length;
		boolean[][] g = new boolean[36][36];
		String E = "oi_eas_tbg";
		
		for(int i = 0;i < n-1;i++){
			g[S[i]-'a'][S[i+1]-'a'] = true;
			int ind0 = E.indexOf(S[i]);
			int ind1 = E.indexOf(S[i+1]);
			if(ind0 >= 0 && ind1 >= 0){
				g[26+ind0][26+ind1] = true;
			}
			if(ind0 >= 0){
				g[26+ind0][S[i+1]-'a'] = true;
			}
			if(ind1 >= 0){
				g[S[i]-'a'][26+ind1] = true;
			}
		}
		
		int[] dimin = new int[36];
		int[] dimout = new int[36];
		int l = 0;
		for(int i = 0;i < 36;i++){
			for(int j = 0;j < 36;j++){
				if(g[i][j]){
					dimin[j]++;
					dimout[i]++;
					l++;
				}
			}
		}
		
		boolean all0 = true;
		for(int i = 0;i < 36;i++){
			l += Math.max(dimin[i] - dimout[i], 0);
			if(dimin[i] != dimout[i])all0 = false;
		}
		out.println(l + (all0 ? 1 : 0));
		
//		outer:
//		while(true){
//			while(true){
//				boolean oh = false;
//				for(int i = 0;i < 36;i++){
//					if(dimout[i] > dimin[i]){
//						oh = true;
//						int cur = i;
//						l++;
//						while(dimout[cur] > 0){
//							dimout[cur]--;
//							for(int j = 0;j < 36;j++){
//								if(g[cur][j]){
//									dimin[j]--;
//									g[cur][j] = false;
//									cur = j;
//									break;
//								}
//							}
//						}
//					}
//				}
//				if(!oh)break;
//			}
//			for(int i = 0;i < 36;i++){
//				if(dimin[i] > 0 && dimout[i] > 0){
//					int cur = i;
//					l++;
//					while(dimout[cur] > 0){
//						dimout[cur]--;
//						for(int j = 0;j < 36;j++){
//							if(g[cur][j]){
//								dimin[j]--;
//								g[cur][j] = false;
//								cur = j;
//								break;
//							}
//						}
//					}
//					continue outer;
//				}
//			}
//			break;
//		}
//		for(int i = 0;i < 36;i++){
//			for(int j = 0;j < 36;j++){
//				if(g[i][j]){
//					tr("!!!!!!");
//				}
//			}
//		}
	}
	
	public static class DJSet { public int[] upper; public DJSet(int n){ upper = new int[n]; Arrays.fill(upper, -1);} public int root(int x){	return upper[x] < 0 ? x : (upper[x] = root(upper[x]));}	public boolean equiv(int x, int y){ return root(x) == root(y);} public void union(int x, int y){ x = root(x);y = root(y);if(x != y) { if(upper[y] < upper[x]) { int d = x; x = y; y = d;	} upper[x] += upper[y]; upper[y] = x;}} public int count(){	int ct = 0;	for(int i = 0;i < upper.length;i++){ if(upper[i] < 0)ct++; } return ct; }}
	
	Scanner in;
	PrintWriter out;
	int cas;
	
	public D(int cas, Scanner in, PrintWriter out)
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
			new D(i+1, in, out).call();
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
