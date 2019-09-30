package gcj2012.r1b;
import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Date;
import java.util.Queue;
import java.util.Scanner;
import java.util.TreeSet;

public class B {
	static String BASEPATH = "x:\\gcj\\";
	static boolean LARGE = true;
	static String INPATH = BASEPATH + B.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
	static String OUTPATH = BASEPATH + B.class.getSimpleName() + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
//	static String INPUT = "4\r\n" + 
//			"200 1 2\r\n" + 
//			"250 233\r\n" + 
//			"180 100\r\n" + 
//			"100 3 3\r\n" + 
//			"500 500 500\r\n" + 
//			"500 500 600\r\n" + 
//			"500 140 1000\r\n" + 
//			"10 10 10\r\n" + 
//			"10 10 490\r\n" + 
//			"10 10 10\r\n" + 
//			"100 3 3\r\n" + 
//			"500 100 500\r\n" + 
//			"100 100 500\r\n" + 
//			"500 500 500\r\n" + 
//			"10 10 10\r\n" + 
//			"10 10 10\r\n" + 
//			"10 10 10\r\n" + 
//			"100 2 2\r\n" + 
//			"1000 1000\r\n" + 
//			"1000 1000\r\n" + 
//			"100 900\r\n" + 
//			"900 100";
	
	public void call()
	{
		int h = ni();
		int n = ni(), m = ni();
		int[][] C = new int[n][m];
		int[][] F = new int[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				C[i][j] = ni();
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				F[i][j] = ni();
			}
		}
		
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		
		int[][][] cankayak = new int[n][m][4];
		for(int r = 0;r < n;r++){
			for(int c = 0;c < m;c++){
				for(int k = 0;k < 4;k++){
					cankayak[r][c][k] = -1;
				}
			}
		}
		
		for(int r = 0;r < n;r++){
			for(int c = 0;c < m;c++){
				for(int k = 0;k < 4;k++){
					int nr = r + dr[k], nc = c + dc[k];
					if(nr >= 0 && nr < n && nc >= 0 && nc < m){
						if(C[nr][nc] - F[nr][nc] < 50)continue;
						if(C[r][c] - F[r][c] < 50)continue;
						if(C[r][c] - F[nr][nc] < 50)continue;
						if(C[nr][nc] - F[r][c] < 50)continue;
						
						int min = h;
						min = Math.min(min, C[nr][nc]-50);
						min = Math.min(min, C[r][c]-50);
						cankayak[r][c][k] = min;
					}
				}
			}
		}
		
		final int[][] t = new int[n][m];
		for(int i = 0;i < n;i++){
			Arrays.fill(t[i], 99999999);
		}
		TreeSet<int[]> ts = new TreeSet<int[]>(new Comparator<int[]>(){
			public int compare(int[] a, int[] b){
				if(t[a[0]][a[1]] - t[b[0]][b[1]] != 0)return t[a[0]][a[1]] - t[b[0]][b[1]];
				return a[0]*10000+a[1]-(b[0]*10000+b[1]);
			}
		});
//		for(int r = 0;r < n;r++){
//			for(int c = 0;c < m;c++){
//				tr(r, c, cankayak[r][c]);
//			}
//		}
		
		t[0][0] = 0;
		Queue<int[]> q = new ArrayDeque<int[]>();
		q.add(new int[]{0, 0});
		while(!q.isEmpty()){
			int[] cur = q.poll();
			ts.add(cur);
			int r = cur[0], c = cur[1];
			for(int k = 0;k < 4;k++){
				int nr = r + dr[k], nc = c + dc[k];
				if(nr >= 0 && nr < n && nc >= 0 && nc < m && t[nr][nc] > 0 && cankayak[r][c][k] == h){
					q.add(new int[]{nr, nc});
					t[nr][nc] = 0;
				}
			}
		}
		
		while(!ts.isEmpty()){
			int[] cur = ts.pollFirst();
			int r = cur[0], c = cur[1];
			for(int k = 0;k < 4;k++){
				int nr = r + dr[k], nc = c + dc[k];
				if(nr >= 0 && nr < n && nc >= 0 && nc < m){
					if(cankayak[r][c][k] == -1)continue;
					int okt = h - cankayak[r][c][k];
					int got = Math.max(t[r][c], okt);
					int hh = Math.max(h - got, F[r][c]);
					int nt;
					if(hh - F[r][c] >= 20){
						nt = got + 10;
					}else{
						nt = got + 100;
					}
//					tr(r, c, nr, nc, t[r][c], nt, t[nr][nc]);
					
					if(nt < t[nr][nc]){
						int[] na = new int[]{nr, nc};
						ts.remove(na);
						t[nr][nc] = nt;
						ts.add(na);
					}
				}
			}
		}
		
		out.printf("%.9f\n", (double)t[n-1][m-1] / 10);
	}
	
	boolean isok(int fr, int fc, int nr, int nc, double h, int[][] C, int[][] F)
	{
		double ff = Math.max(F[fr][fc], h);
		double fn = Math.max(F[nr][nc], h);
		if(C[nr][nc] - fn < 50)return false;
		if(C[fr][fc] - fn < 50)return false;
		if(C[nr][nc] - ff < 50)return false;
		return true;
	}
	
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
