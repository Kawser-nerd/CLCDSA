import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable {
	BufferedReader in;
	BufferedWriter out;
	
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
	
	final static int dx[] = {1,0,-1,0};
	final static int dy[] = {0,1,0,-1};
	
	int shootx, shooty;
	public void shoot( int x, int y, int dir, String map[] ) {
		shootx = x;
		shooty = y;
		while( true ) {
			if( shootx < 0 || shootx >= map.length || shooty < 0 || shooty >= map[0].length()) break;
			if( map[shootx].charAt(shooty) == '#') break;
			shootx += dx[dir];
			shooty += dy[dir];
		}
		shootx -= dx[dir];
		shooty -= dy[dir];
	}
	
	public void solve() throws Exception {
		int n = iread();
		int m = iread();
		int xcake = 0;
		int ycake = 0;
		String map[] = new String[n];
		for( int i = 0; i < n; i++) {
			map[i] = readword();
		}
		
		int qx[] = new int[n*m*n*m];
		int qy[] = new int[n*m*n*m];
		int portx[] = new int[n*m*n*m];
		int porty[] = new int[n*m*n*m];
		int res[] = new int[n*m*n*m];
		boolean vis[][][][] = new boolean[n][m][n][m];
		for( int i = 0; i < n; i++) {
			for( int j = 0; j < m; j++) {
				if( map[i].charAt(j) == 'O' ){ 
					qx[0] = i;
					qy[0] = j;
					shoot(i,j,0,map);
					portx[0] = shootx;
					porty[0] = shooty;
				} else {
					if( map[i].charAt(j) == 'X') {
						xcake = i;
						ycake = j;
					}
				}
			}
		}
		
		int sq = 0;
		int fq = 0;
		while ( sq <= fq ) {
			int newfin = fq;
			for( int i = sq; i <= fq; i++ ) {
				if (qx[i] == xcake && qy[i] == ycake) {
					out.write(res[i] + "\n");
					return;
				}
				for( int j = 0; j < 4; j++) {
					shoot( qx[i], qy[i], j, map );
					if( !vis[qx[i]][qy[i]][shootx][shooty]) {
						vis[qx[i]][qy[i]][shootx][shooty] = true;
						newfin++;
						qx[newfin] = qx[i];
						qy[newfin] = qy[i];
						portx[newfin] = shootx;
						porty[newfin] = shooty;
						res[newfin] = res[i];
					}
				}
			}
			int newst = newfin + 1;
			for( int i = sq; i <= newst - 1; i++) {
				for( int j = 0; j < 4; j++) {
					int nx = qx[i] + dx[j];
					int ny = qy[i] + dy[j];
					if( nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx].charAt(ny) == '#') {
						nx = portx[i];
						ny = porty[i];
					}
					if(!vis[nx][ny][portx[i]][porty[i]]) {
						vis[nx][ny][portx[i]][porty[i]] = true;
						newfin++;
						res[newfin] = res[i] + 1;
						qx[newfin] = nx;
						qy[newfin] = ny;
						portx[newfin] = portx[i];
						porty[newfin] = porty[i];
					}
				}
			}
			sq = newst;
			fq = newfin;
		}
		out.write("THE CAKE IS A LIE\n");
	}
	
	public void run() {
		try {
//			in = new BufferedReader(new InputStreamReader(System.in));
//			out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader("input.txt"));
			out = new BufferedWriter(new FileWriter("output.txt"));
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

