package gcj2012.r2;
import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class D {
	static String BASEPATH = "x:\\gcj\\";
	static boolean LARGE = false;
	static String INPATH = BASEPATH + D.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	public void call()
	{
		int n = ni(), m = ni();
		char[][] b = new char[n][];
		for(int i = 0;i < n;i++){
			b[i] = in.next().toCharArray();
		}
		
		int[][] co = new int[10][];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(b[i][j] >= '0' && b[i][j] <= '9'){
					co[b[i][j]-'0'] = new int[]{i, j};
					b[i][j] = '.';
				}
			}
		}
		
		int[] dr = { 0, -1, 0 };
		int[] dc = { 1, 0, -1 };
		out.println();
		for(int z = 0;z < 10;z++){
			if(co[z]!= null){
				int[][] q = new int[n*m][];
				boolean[][] ped = new boolean[n][m];
				ped[co[z][0]][co[z][1]] = true;
				int s = 1;
				q[0] = new int[]{co[z][0], co[z][1]};
				for(int p = 0;p < s;p++){
					int[] cur = q[p];
					int r = cur[0], c = cur[1];
					for(int k = 0;k < 3;k++){
						int nr = r + dr[k], nc = c + dc[k];
						if(nr >= 0 && nr < n && nc >= 0 && nc < m && b[nr][nc] == '.' && !ped[nr][nc]){
							ped[nr][nc] = true;
							q[s++] = new int[]{nr, nc};
						}
					}
				}
				int[][] po = Arrays.copyOf(q, s);
				cache = new HashSet<Long>();
				if(dfs(po, co[z][0], co[z][1], n, m, b)){
					out.println(z + ": " + s + " Lucky");
				}else{
					out.println(z + ": " + s + " Unlucky");
				}
			}
		}
	}
	
	Set<Long> cache;
	
	boolean dfs(int[][] po, int gr, int gc, int h, int w, char[][] b)
	{
		int n = po.length;
		boolean all = true;
		for(int i = 0;i < n;i++){
			if(po[i][0] == gr && po[i][1] == gc){
			}else{
				all = false;
			}
		}
		if(all)return true;
		
		long H = 0;
		for(int i = 0;i < n;i++){
			H = H * 31 + po[i][0];
			H = H * 31 + po[i][1];
		}
		if(cache.contains(H))return false;
		cache.add(H);
		
		int[] dr = { 0, 1, 0 };
		int[] dc = { 1, 0, -1 };
		outer:
		for(int k = 0;k < 3;k++){
			int[][] nex = new int[n][2];
			for(int i = 0;i < n;i++){
				int r = po[i][0], c = po[i][1];
				int nr = r + dr[k], nc = c + dc[k];
				if(nr >= 0 && nr < h && nc >= 0 && nc < w && b[nr][nc] == '.'){
					nex[i][0] = nr;
					nex[i][1] = nc;
					if(nr > gr)continue outer;
				}else{
					nex[i][0] = r;
					nex[i][1] = c;
				}
			}
			if(dfs(nex, gr, gc, h, w, b))return true;
		}
		return false;
	}
	
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
