package gcj2011.r3;
import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Date;
import java.util.Queue;
import java.util.Scanner;

public class CLarge {
	static String BASEPATH = "x:\\gcj\\2011r3\\";
	static boolean LARGE = true;
	static String INPATH = BASEPATH + CLarge.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static int MOD = 1000003;
	static String INPUT = "";
	
	public void call()
	{
		int R = ni();
		int C = ni();
		char[][] map = new char[R][C];
		for(int i = 0;i < R;i++){
			map[i] = in.next().toCharArray();
		}
		
		int[][] can = new int[R][C];
		for(int j = 0;j < R;j++){
			for(int k = 0;k < C;k++){
				if(map[j][k] == '|'){
					can[(j+1)%R][k%C]++;
					can[(j+R-1)%R][k%C]++;
				}
				if(map[j][k] == '-'){
					can[j%R][(k+1)%C]++;
					can[j%R][(k+C-1)%C]++;
				}
				if(map[j][k] == '/'){
					can[(j+R-1)%R][(k+1)%C]++;
					can[(j+1)%R][(k+C-1)%C]++;
				}
				if(map[j][k] == '\\'){
					can[(j+R-1)%R][(k+C-1)%C]++;
					can[(j+1)%R][(k+1)%C]++;
				}
			}
		}
		
		Queue<Integer> q = new ArrayDeque<Integer>();
		for(int j = 0;j < R;j++){
			for(int k = 0;k < C;k++){
				if(can[j][k] == 0){
					out.println(0);
					return;
				}else if(can[j][k] == 1){
					q.add(j*C+k);
				}
			}
		}
		
		boolean[][] end = new boolean[R][C];
		char[] dir = "\\|/-?-/|\\".toCharArray();
		outer:
		while(q.size() > 0){
			int cur = q.poll();
			int r = cur / C;
			int c = cur % C;
			if(can[r][c] == 1){
				for(int j = -1;j <= 1;j++){
					for(int k = -1;k <= 1;k++){
						if(j == 0 && k == 0)continue;
						int nr = (r+j+R)%R;
						int nc = (c+k+C)%C;
						int code = (j+1)*3+k+1;
						if(dir[code] == map[nr][nc] && !end[nr][nc]){
							can[r][c] = 0;
							end[nr][nc] = true;
							int nnr = (nr+j+R)%R;
							int nnc = (nc+k+C)%C;
							can[nnr][nnc]--;
							if(can[nnr][nnc] == 1){
								q.add(nnr*C+nnc);
							}else if(can[nnr][nnc] == 0){
								out.println(0);
								return;
							}
							continue outer;
						}
					}
				}
			}
		}
		
		long ret = 1;
		for(int u = 0;u < R;u++){
			for(int v = 0;v < C;v++){
				if(!end[u][v]){
					int r = u, c = v;
					int sr = r, sc = c;
					if(map[r][c] == '|'){ sr = (r+1)%R;}
					if(map[r][c] == '-'){ sc = (c+1)%C;}
					if(map[r][c] == '/'){ sr = (r+R-1)%R; sc = (c+1)%C; }
					if(map[r][c] == '\\'){ sr = (r+1)%R; sc = (c+1)%C; }
					int len = 1;
					outer2:
					while(true){
						can[sr][sc] = 0;
						end[r][c] = true;
						for(int j = -1;j <= 1;j++){
							for(int k = -1;k <= 1;k++){
								if(j == 0 && k == 0)continue;
								int nr = (sr+j+R)%R;
								int nc = (sc+k+C)%C;
								int code = (j+1)*3+k+1;
								if((nr != r || nc != c) && dir[code] == map[nr][nc] && !end[nr][nc]){
									r = nr;
									c = nc;
									sr = (nr+j+R)%R;
									sc = (nc+k+C)%C;
									len++;
									if(can[sr][sc] == 2)continue outer2;
								}
							}
						}
						break;
					}
					ret = (ret*2)%MOD;
				}
			}
		}
		out.println(ret);
	}
	
	Scanner in;
	PrintWriter out;
	
	public CLarge(Scanner in, PrintWriter out)
	{
		this.in = in;
		this.out = out;
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
	
	public static void main(String[] args) throws Exception
	{
		long start = System.currentTimeMillis();
		
		Scanner in = INPUT.isEmpty() ? new Scanner(new File(INPATH)) : new Scanner(INPUT);
		PrintWriter out = INPUT.isEmpty() ? new PrintWriter(new File(OUTPATH)) : new PrintWriter(System.out);
		int n = in.nextInt();
		in.nextLine();
		
		for(int i = 0;i < n;i++){
			out.printf("Case #%d: ", i+1);
			new CLarge(in, out).call();
			out.flush();
			if(INPUT.isEmpty())System.err.println("case " + (i + 1) + " solved.\t");
		}
		
		long end = System.currentTimeMillis();
		System.out.println((end - start) + "ms");
	}
}
