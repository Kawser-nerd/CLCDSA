import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class A implements Runnable {

	BufferedReader in;
	BufferedWriter out;
	static String inputFile = "";
	static String outputFile = "";
	
	public class Point {
		int x, y;
		Point( int x, int y ) {
			this.x = x; 
			this.y = y;
		}
	}
	
	int a[][];
	int color[][];
	
	static {
		inputFile = A.class.getName() + ".in";
		outputFile = A.class.getName() + ".out";
	}
	
	final static int dx[] = {-1,0,0,1};
	final static int dy[] = {0,-1,1,0};
	
	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}
	
	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}
	
	public long lread() throws Exception {
		return Long.parseLong(readword());
	}
	
	public String readword() throws Exception {
		int c = in.read();
		while( c >= 0 && c <= ' ' ) {
			c = in.read();
		}
		if( c < 0 ) return "";
		StringBuilder bld = new StringBuilder();
		while( c > ' ' ) {
			bld.append((char)c);
			c = in.read();
		}
		return bld.toString();
	}
	
	public Point getLowest( Point p ) {
		Point result = new Point( -1, -1 );
		int minH = 1000000000;
		for( int i = 0; i < 4; i++) {
			Point nn = new Point(p.x + dx[i],p.y + dy[i]);
			if( nn.x < 0 || nn.y < 0 || nn.x >= a.length || nn.y >= a[0].length ) continue;
			if( a[p.x][p.y] > a[nn.x][nn.y] ) {
				if( a[nn.x][nn.y] < minH ) {
					minH = a[nn.x][nn.y];
					result = nn;
				}
			}
		}
		return result;
	}
	
	public void dfs( Point p, int col ) {
		color[p.x][p.y] = col; 
		Point nn = getLowest(p);
		if( nn.x >= 0 && color[nn.x][nn.y] < 0) {
			dfs(nn,col);
		}
		for( int i = 0; i < 4; i++) {
			nn = new Point(p.x+dx[i],p.y+dy[i]);
			if( nn.x < 0 || nn.y < 0 || nn.x >= a.length || nn.y >= a[0].length ) continue;
			if( a[nn.x][nn.y] <= a[p.x][p.y] ) continue;
			Point temp = getLowest(nn);
			if( temp.x == p.x && temp.y == p.y && color[nn.x][nn.y]< 0 ) {
				dfs(nn,col);
			}
		}
	}
	public void solve() throws Exception {
		int n = iread();
		int m = iread();
		a = new int[n][m];
		for( int i = 0; i < n; i++) {
			for( int j = 0; j < m; j++) {
				a[i][j] = iread();
			}
		}
		color = new int[n][m];
		for( int i = 0; i < n; i++) {
			for( int j = 0; j < m; j++) {
				color[i][j] = -1;
			}
		}
		int curCol = 0;
		for( int i = 0; i < n; i++) {
			for( int j = 0; j < m; j++) {
				if( color[i][j] < 0 ) {
					dfs(new Point(i,j),curCol);
					curCol++;
				}
			}
		}
		for( int i = 0; i < n; i++) {
			for( int j = 0; j < m; j++) {
				out.write( (char)(color[i][j] + 'a') + " " );
			}
			out.write("\n");
		}
	}
	
	public void run() {
		try {
			in = new BufferedReader( new FileReader( inputFile ));
			out = new BufferedWriter( new FileWriter( outputFile ));
//			in = new BufferedReader( new InputStreamReader(System.in));
//			out = new BufferedWriter( new OutputStreamWriter(System.out));
			int tests = iread();
			for( int i = 0; i < tests; i++) {
				out.write("Case #" + (i+1) + ":\n");
				solve();
			}
			out.flush();
		} catch( Exception e ) {
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		new Thread( new A()).start();
	}

}
