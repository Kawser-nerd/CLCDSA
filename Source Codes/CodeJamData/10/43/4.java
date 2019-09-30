import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class c implements Runnable {
	BufferedReader in;
	BufferedWriter out;

	final static int INF = 10000000;
	
	public class Rect {
		int x1, y1, x2, y2;
		Rect(int x1, int y1, int x2, int y2) {
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
		}
		
		public boolean isOverlapped(int s1, int f1, int ss1, int ff1) {
			int ms = Math.max(s1, ss1);
			int mf = Math.min(f1,ff1);
			return mf - ms >= -1;
		}
		
		public boolean canJoin(Rect r) {
			if( !isOverlapped(x1,x2,r.x1,r.x2) || !isOverlapped(y1,y2,r.y1,r.y2)) {
				return false;
			}
			if( x1 == r.x2 + 1 && y1 == r.y2 + 1 ) return false;
			if( r.x1 == x2 + 1 && r.y1 == y2 + 1 ) return false;
			return true;
		}
	}
	
	int color[];
	public void join(int n, int c1, int c2 ) {
		for( int i = 0; i < n; i++ ) {
			if( color[i] == c2 ) {
				color[i] = c1;
			}
		}
	}
	
	public int simulate(int n, int a[][]) {
		int count = 0;
		while( true ) {
			boolean flag = false; 
			for( int i = 0; i < n; i++ ) {
				for( int j = 0; j < n; j++ ) {
					if( a[i][j] != 0 ) flag = true;
				}
			}
			if( !flag ) break;
			
			int next[][] = new int[n][n];
			for( int i = 0; i < n; i++ ) {
				for( int j = 0; j < n; j++ ) {
					if( a[i][j] == 1 ) {
						if( (i > 0 && a[i-1][j] != 0) || (j > 0 && a[i][j-1] != 0) ) next[i][j] = 1; else next[i][j] = 0;
					} else {
						if( (i > 0 && a[i-1][j] != 0) && (j > 0 && a[i][j-1] != 0)) next[i][j] = 1; else next[i][j] = 0;
					}
				}
			}
			a = next;
			count++;
		}
		return count;
	}
	
	public void solve2() throws Exception {
		int n = Integer.parseInt(readword());
		color = new int[n];
		Rect a[] = new Rect[n];
		for( int i = 0; i < n; i++ ) {
			color[i] = i;
			a[i] = new Rect(Integer.parseInt(readword()), Integer.parseInt(readword()), Integer.parseInt(readword()),
					Integer.parseInt(readword()));
		}		
		int tbl[][] = new int[120][120];
		for( int i = 0; i < n; i++ ) {
			for( int j = a[i].x1; j <= a[i].x2; j++ ) {
				for( int k = a[i].y1; k <= a[i].y2; k++ ) {
					tbl[j][k] = 1;
				}
			}
		}
		for( int i = 0; i <= 30; i++ ) {
			for( int j = 0; j <= 30; j++ ) {
				System.out.print(tbl[i][j]);
			}
			System.out.println();
		}
		out.write(simulate(120, tbl) + "\n");
	}
	
	public void solve() throws Exception 
	{
		int n = Integer.parseInt(readword());
		color = new int[n];
		Rect a[] = new Rect[n];
		for( int i = 0; i < n; i++ ) {
			color[i] = i;
			a[i] = new Rect(Integer.parseInt(readword()), Integer.parseInt(readword()), Integer.parseInt(readword()),
					Integer.parseInt(readword()));
		}
		
		for( int i = 0; i < n; i++ ) {
			for( int j = i+1; j < n; j++ ) {
				if( a[i].canJoin(a[j])) {
					join(n,color[i],color[j]);
				}
			}
		}
		int answer = 0;
		for( int i = 0; i < n; i++ ) {
			boolean hasColor = false;
			for( int j = 0; j < n; j++ ) {
				if( color[j] == i ) {
					hasColor = true;
					break;
				}
			}
			if( !hasColor ) {
				continue;
			}
			int maxX = -INF;
			int maxY = -INF;
			for( int j = 0; j < n; j++ ) {
				if( color[j] == i ) {
					maxX = Math.max(maxX, a[j].x2);
					maxY = Math.max(maxY, a[j].y2);
				}
			}
			for( int j = 0; j < n; j++ ) {
				if( color[j] == i ) {
					int tmp = maxX - a[j].x1 + maxY - a[j].y1;
					if( tmp > answer ) answer = tmp;
				}
			}
		}
		out.write((answer+1) + "\n");
	}
	
	public String readword() throws IOException {
		int c = in.read();
		while( c >= 0 && c <= ' ' ) c = in.read();
		if( c < 0 ) return "";
		StringBuilder bld = new StringBuilder();
		while( c > ' ' ) {
			bld.append((char)c);
			c = in.read();
		}
		return bld.toString();
	}
	
	public void run() {
		try {
			in = new BufferedReader(new FileReader(this.getClass().getName() + ".in"));
			out = new BufferedWriter(new FileWriter(this.getClass().getName() + ".out"));
			int tn = Integer.parseInt(readword());
			for(int i = 0; i < tn; i++ ) {
				out.write("Case #" + (i+1) + ": ");
				solve();
			}
			out.flush();
		} catch( Exception e ) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	public static void main(String[] args) {
		new Thread(new c()).start();
	}
}
