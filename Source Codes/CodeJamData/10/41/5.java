import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class a implements Runnable {
	BufferedReader in;
	BufferedWriter out;
	
	final static int MAX = 600;
	final static int POS = 220;
	
	public int testPosition( int n, int[] x, int[] y, int[][] a, int xx, int yy ) {
		int result = 0;
		for( int i = 0; i < n; i++ ) {
			int sx = 2 * xx - x[i];
			int sy = 2 * yy - y[i];
			if( (a[x[i]][sy] >= 0 && a[x[i]][sy] != a[x[i]][y[i]]) ||
				(a[sx][y[i]] >= 0 && a[sx][y[i]] != a[x[i]][y[i]])) 
			{
				return 100000;
			}
			int r = Math.abs(xx - x[i]) + Math.abs(yy - y[i]);
			if( r > result ) result = r;
		}
		return result + 1;
	}
	
	public void solve() throws Exception 
	{
		int n = Integer.parseInt(readword());
		int a[][] = new int[MAX][MAX];
		
		int sx = POS;
		int sy = POS;
		for( int i = 0; i < MAX; i++ ) {
			Arrays.fill(a[i], -100);
		}
		int count = 0;
		int xx[] = new int[10000];
		int yy[] = new int[10000];
		for( int i = 0; i < 2*n-1; i++ ) {
			int elems = n - Math.abs(i-n+1);
			for( int cury = sy; elems > 0; cury += 2, elems--) {
				a[sx][cury] = Integer.parseInt(readword());
				xx[count] = sx;
				yy[count++] = cury;
			}
			sx++;
			if( i < n - 1 ) {
				sy--;
			} else sy++;
		}
		int result = 100000;
		for( int i = POS - n - 1; i <= POS + 2 * n + 1; i++ ) {
			for( int j = POS - n -1; j <= POS + 2*n + 1; j++ ) {
				int r = testPosition(count, xx,yy,a,j,i);
				if( r < result ) result = r;
			}
		}
		out.write((result*result - n*n) + "\n");
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
		new Thread(new a()).start();
	}
}
