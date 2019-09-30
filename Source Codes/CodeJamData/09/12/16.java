import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class CrossingTheRoad {

	private final static String FILE_IN = "road.in";
	private final static String FILE_OUT = "road.out";

	long s[][];
	long w[][];
	long t[][];
	int n, m;
	
	private void solve() throws Exception {

		Scanner sc = new Scanner(new File(FILE_IN));
		int testCount = Integer.parseInt(sc.nextLine());		
		PrintWriter pw = new PrintWriter(FILE_OUT);
		
		for (int testNum = 1; testNum <= testCount; ++ testNum){			
			n = sc.nextInt();
			m = sc.nextInt();
			
			s = new long [n][m];
			w = new long [n][m];
			t = new long [n][m];

			for (int i = 0; i < n; ++ i)
				for (int j = 0; j < m; ++ j){
					s[i][j] = sc.nextLong();
					w[i][j] = sc.nextLong();
					t[i][j] = sc.nextLong();
				}
			
			long dist[][] = new long[n + n][m + m];
			for (int i = 0;i < dist.length; ++ i){
				Arrays.fill(dist[i], Long.MAX_VALUE);
			}
			boolean was[][] = new boolean[n + n][m + m];
			dist[n + n - 1][0] = 0;

			int [] dx = new int[]{-1, 0, 1, 0};
			int [] dy = new int[]{0, 1, 0, -1};
			
			while (! was[0][m + m - 1]){
			
				int x = 0, y = 0;
				long minDist = Long.MAX_VALUE;
				
				for (int i = 0; i < n + n; ++ i)
					for (int j = 0; j < m + m; ++ j){
						if (! was[i][j] && dist[i][j] < minDist){
							
							minDist = dist[i][j];
							x = i;
							y = j;
						}
					}
				
				for (int dir = 0; dir < 4; ++ dir)
					if (x + dx[dir] >= 0 && x + dx[dir] < n + n)
						if (y + dy[dir] >= 0 && y + dy[dir] < m + m){
							
							long newDist = getDist(x, y, dir, minDist);
							if (dist[x + dx[dir]][y + dy[dir]] > newDist){
								dist[x + dx[dir]][y + dy[dir]] = newDist;
							}
						}
				
				was[x][y] = true;
			}
			long result = dist[0][m + m - 1];
			pw.println(String.format("Case #%d: %d", testNum, result));
		}
		
		pw.close();
		sc.close();
	}

	private long getDist(int x, int y, int dir, long time){
		
		if (x % 2 == 0){
			
			if (y % 2 == 0){
				if (dir == 0 || dir == 3){
					return time + 2;
				}
				else if (dir == 1){
					return getTime(time, s[x/2][y/2], w[x/2][y/2], t[x/2][y/2], 0);
				}
				else {
					return getTime(time, s[x/2][y/2], w[x/2][y/2], t[x/2][y/2], 1);					
				}
			}
			else {
				if (dir == 0 || dir == 1){
					return time + 2;
				}
				else if (dir == 2){
					return getTime(time, s[x/2][y/2], w[x/2][y/2], t[x/2][y/2], 1);
				}
				else {
					return getTime(time, s[x/2][y/2], w[x/2][y/2], t[x/2][y/2], 0);					
				}
			}
		}
		else {
			if (y % 2 == 0){
				if (dir == 2 || dir == 3){
					return time + 2;
				}
				else if (dir == 0){
					return getTime(time, s[x/2][y/2], w[x/2][y/2], t[x/2][y/2], 1);										
				}
				else {
					return getTime(time, s[x/2][y/2], w[x/2][y/2], t[x/2][y/2], 0);															
				}
			}
			else {
	
				if (dir == 1 || dir == 2){
					return time + 2;
				}
				else if (dir == 0){
					return getTime(time, s[x/2][y/2], w[x/2][y/2], t[x/2][y/2], 1);																				
				}
				else {
					return getTime(time, s[x/2][y/2], w[x/2][y/2], t[x/2][y/2], 0);																									
				}
			}
		}
	}
	
	private long getTime(long time, long s, long w, long t, int step){
		
		
		t %= s + w;
		long tt = ( + (time % (s + w)) - t + s + w) % (s + w);
		
		if (step == 1){
			if (tt < s){
				return time + 1;
			}
			else {
				return time + s + w - tt + 1;
			}
		}
		else {
			if (tt < s){
				return time + s - tt + 1;
			}
			else {
				return time + 1;
			}
		}
	}
	
	private long toBase(long num, long base) {

		long result = 0;
		while (num > 0) {
			result += (num % base) * (num % base);
			num /= base;
		}
		return result;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		new Thread(new Runnable() {

			@Override
			public void run() {
				// TODO Auto-generated method stub
				try {
					new CrossingTheRoad().solve();
				} catch (Exception e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}).start();
	}
}
