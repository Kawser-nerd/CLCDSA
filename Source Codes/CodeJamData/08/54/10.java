import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable {
	BufferedReader in;
	BufferedWriter out;
	final static int modulo = 10007;
	public String readword() throws IOException {
		int c = in.read();
		while( c >= 0 && c < ' ' ) c = in.read();
		if (c < 0) return "";
		StringBuilder builder = new StringBuilder();
		while (c > ' ') {
			builder.append((char)c);
			c = in.read();
		}
		return builder.toString();
	}
	
	public int iread() throws IOException {
		return Integer.parseInt(readword());
	}
	
	public double dread() throws IOException {
		return Double.parseDouble(readword());
	}
	
	public long calcFactDivisors( int n, int prime ) {
		long cur = prime;
		long res = 0;
		while( n >= cur ) {
			res += n / cur;
			cur = cur * prime;
		}
		return res;
	}
	
	public int pow( int n, int power ) {
		int res = 1;
		int cur = n;
		while( power != 0 ) {
			if( power % 2 == 1) {
				res = res * cur % modulo;
			}
			cur = (cur * cur) % modulo;
			power /= 2;
		}
		return res;
	}
	
	public void calc1( int num, int a[], boolean isReverse ) {
		if( isReverse ) {
			for( int i = 1; i < modulo; i++) {
				if( num < i ) break;
				a[reverse[i]] += (num + modulo - i) / modulo;
			}
			
		} else {
			for( int i = 1; i < modulo; i++) {
				if( num < i ) break;
				a[i] += (num + modulo - i) / modulo;
			}
		}
	}
	
	public int calculate( int dx, int dy ) {
		if( dx < 0 || dy < 0 ) return 0;
		if( (dx + dy ) % 3 != 0 ) return 0;
		int count = (dx + dy) / 3;
		int diff = Math.abs(dx - dy);
		if( count < diff || (count - diff) % 2 != 0 ) {
			return 0;
		}
		int elem = (count - diff) / 2;
		if( calcFactDivisors( count, modulo ) - calcFactDivisors( elem, modulo ) - calcFactDivisors( count - elem, modulo ) != 0) 
		{
			return 0;
		}
		int a[] = new int[modulo];
		calc1( count, a, false );
		calc1( elem, a, true );
		calc1( count - elem, a, true );
		int res = 1;
		for( int i = 1; i < modulo; i++) {
			res = res * pow( i, a[i] ) % modulo;
		}
		return res;
	}
	
	int precalc[][];
	int reverse[] = new int[modulo];
	public void initializeReverse() {
		for( int i = 1; i < modulo; i++) {
			for( int j = 1; j < modulo; j++) {
				if( i * j % modulo == 1 ) {
					reverse[i] = j;
					break;
				}
			}
		}
	}
	int sizex;
	int sizey;
	int xx[];
	int yy[];
	int n;
	int result;
	public void rec( int dep, int last, int sign, int curres ) {
		if( dep >= n-1 ) {
			curres = curres * precalc[last][n-1] % modulo;
			result = (result + modulo + curres * sign) % modulo;
			return;
		}
		rec(dep+1, last, sign, curres );
		rec(dep+1, dep, -sign, curres * precalc[last][dep] % modulo);
	}
	
	public void solve() throws Exception {
		sizex = iread();
		sizey = iread();
		n = iread();
		n+=2;
		xx = new int[n];
		yy = new int[n];
		for( int i = 1; i < n-1; i++) {
			xx[i] = iread();
			yy[i] = iread();
			if( (xx[i] == 1 && yy[i] == 1) || (xx[i] == sizex && yy[i] == sizey)) {
				out.write("0\n");
				return;
			}
		}
		xx[0] = 1;
		yy[0] = 1;
		xx[n-1] = sizex;
		yy[n-1] = sizey;
		for( int i = 0; i < n; i++) {
			for( int j = i+1; j < n; j++) {
				if( xx[i] > xx[j]) {
					int buf = xx[i];
					xx[i] = xx[j];
					xx[j] = buf;
					buf = yy[i];
					yy[i] = yy[j];
					yy[j] = buf;
				} else {
					if( xx[i] == xx[j] && yy[i] > yy[j] ) {
						int buf = xx[i];
						xx[i] = xx[j];
						xx[j] = buf;
						buf = yy[i];
						yy[i] = yy[j];
						yy[j] = buf;						
					}
				}
			}
		}
		precalc = new int[n+1][n+1];
		for( int i = 0; i < n; i++) {
			for( int j = i+1; j < n; j++) {
				precalc[i][j] = calculate( xx[j] - xx[i], yy[j] - yy[i] );
			}
		}
/*		for( int i = 0; i < n; i++) {
			for( int j = i+1; j < n; j++) {
				System.out.println( i + " " + j + " " + precalc[i][j]);
			}
		}*/
		result = 0;
		rec(1, 0, 1, 1);
		out.write(result + "\n");
	}	
	public void run() {
		try {
//			in = new BufferedReader(new InputStreamReader(System.in));
//			out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader("input.txt"));
			out = new BufferedWriter(new FileWriter("output.txt"));
			initializeReverse();
			int tn = iread();
			for( int i = 0; i < tn; i++) {
				out.write("Case #" + (i+1) + ": ");
				solve();
			}
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		new Thread(new Main()).start();
	}

}
