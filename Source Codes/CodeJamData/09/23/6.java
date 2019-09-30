import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class C implements Runnable {

	BufferedReader in;
	BufferedWriter out;
	static String inputFile = "";
	static String outputFile = "";
	
	static {
		inputFile = C.class.getName() + ".in";
		outputFile = C.class.getName() + ".out";
	}
	
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
	
	public class Elem {
		int link;
		char c1;
		public Elem( int x, int y, int value, int color ) {
			this.x = x;
			this.y = y;
			this.value = value;
			this.color = color;
			link = -1;
		}
		
		int x, y, value, color;
	}
	String ar = "+-";
	
	boolean vis[][][];
	String square[];
	Elem q[];
	
	final static int dx[] = {1,0,-1,0};
	final static int dy[] = {0,1,0,-1};
	final static int MAX = 500;
	
	boolean isValid( int x, int y ) {
		return x >= 0 && y >= 0 && x < square.length && y < square.length;
	}
	
	public int find( int value ) {
		int res = 0;
		while( true ) {
			if( value == q[res].value - MAX ) return res;
			res++;
		}
	}
	public void print( int index ) throws Exception {
		StringBuilder bld = new StringBuilder();
		while( true ) {
			bld.append( square[q[index].x].charAt(q[index].y));
			if( q[index].link != -1 ) {
				bld.append(q[index].c1);
				index = q[index].link;
			} else break;
		}
		String s = bld.toString();
		for( int i = s.length()-1; i >= 0; i--) {
			out.write(s.charAt(i));
		}
	}
	
	public void bfs() {
		int n = square.length;
		q = new Elem[n * n * MAX * 2];
		vis = new boolean[n][n][MAX*2];
		int last = -1;
		int current = 0;
		int curColor = 10;
		for( int i = '0'; i <= '9'; i++) {
			for( int j = 0; j < n; j++) {
				for( int k = 0; k < n; k++) {
					if( square[j].charAt(k) == i) {
						last++;
						q[last] = new Elem(j,k,i-'0'+MAX,i-'0');
						vis[j][k][i-'0'+MAX] = true;
					}
				}
			}
		}
		while( current <= last ) {
			int tmp = current;
			while( tmp <= last && q[tmp].color == q[current].color) tmp++;
			for( int i = 0; i < 2; i++ ){
				for( int j = '0'; j <= '9'; j++) {
					curColor++;
					for( int cc = current; cc < tmp; cc++ ){
						for( int dir1 = 0; dir1 < 4; dir1++ ){
							for( int dir2 = 0; dir2 < 4; dir2++) {
								int x1 = q[cc].x + dx[dir1];
								int y1 = q[cc].y + dy[dir1];
								int x2 = x1 + dx[dir2];
								int y2 = y1 + dy[dir2];
								if( isValid(x1,y1) && isValid(x2,y2) && ar.charAt(i) == square[x1].charAt(y1)
										&& square[x2].charAt(y2) == j) 
								{
									int newValue = 0;
									if( i == 0 ) {
										newValue = q[cc].value + j - '0';
									} else newValue = q[cc].value - j + '0';
									if( newValue < 0 || newValue >= 2 * MAX ) continue;
									if( !vis[x2][y2][newValue]) {
										vis[x2][y2][newValue] = true;
										last++;
										q[last] = new Elem(x2,y2,newValue,curColor);
										q[last].link = cc;
										q[last].c1 = ar.charAt(i);
									}
								}
									
							}
						}
					}
				}
			}
			current = tmp;
		}
	}
	
	public void solve() throws Exception {
		int n = Integer.parseInt(readword());
		int queryCount = iread();
		square = new String[n];
		for( int i = 0; i < n; i++) {
			square[i] = readword();
		}
		bfs();
		for( int i = 0; i < queryCount; i++) {
			int q = iread();
			int ind = find(q);
			print(ind);
			out.write("\n");
		}
	}
	
	public void run() {
		try {
			in = new BufferedReader( new FileReader( inputFile ));
			out = new BufferedWriter( new FileWriter( outputFile ));
//			in = new BufferedReader( new InputStreamReader(System.in));
//			out = new BufferedWriter( new OutputStreamWriter(System.out));
			int tn = iread();
			for( int tc = 1; tc <= tn; tc++ ){
				out.write("Case #" + tc + ":\n");
				solve();
			}
			out.flush();
		} catch( Exception e ) {
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		new Thread( new C()).start();
	}

}
