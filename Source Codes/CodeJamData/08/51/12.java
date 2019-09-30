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
	int med = 300;
	boolean result[][] = new boolean[med*2][med*2];
	boolean result2[][] = new boolean[med*2][med*2];
	boolean result3[][] = new boolean[med*2][med*2];
	public void solve() throws Exception {
		int n = Integer.parseInt(readword());
		for(int i = 0; i < med*2; i++) {
			Arrays.fill(result[i], false);
			Arrays.fill(result2[i],false);
			Arrays.fill(result3[i], false);
		}
		int curx = 0;
		int cury = 0;
		int curdir = 0;
		int calcX[] = new int[med*2];
		int calcY[] = new int[med*2];
		for( int i = 0; i < n; i++) {
			String st = readword();
			int repCount = iread();
			for( int j = 0; j < repCount; j++) {
				for( int k = 0; k < st.length(); k++) {
					if( st.charAt(k) == 'L') curdir = (curdir + 1) % 4;
					if( st.charAt(k) == 'R') curdir = (curdir + 3) % 4;
					if( st.charAt(k) == 'F') {
						int nx = curx + dx[curdir];
						int ny = cury + dy[curdir];
						if( nx == curx) {
							result[nx+med][Math.min(ny,cury)+med] = true;
							calcY[Math.min(ny,cury)+med]++;
						} else {
							result2[Math.min(nx,curx)+med][ny+med] = true;
							calcX[Math.min(nx,curx)+med]++;
						}
						curx = nx;
						cury = ny;
					}
				}
			}
		}
		for( int i = 0; i < 2*med; i++) {
			int cnt = 0;
			for( int j = 0; j < 2*med; j++) {
				if( result2[i][j]) cnt++;
				if( cnt%2 == 0 && calcX[i] != cnt && cnt != 0 ) result3[i][j] = true;
			}
		}
		for( int j = 0; j < 2*med; j++) {
			int cnt = 0;
			for( int i = 0; i < 2*med; i++) {
				if( result[i][j]) cnt++;
				if( cnt%2 == 0 && calcY[j] != cnt && cnt != 0 ) result3[i][j] = true;
			}
		}
		int answer = 0;
		for( int i = 0; i < 2*med; i++) {
			for( int j = 0; j < 2*med; j++) {
				if(result3[i][j]) answer++;
			}
		}
		out.write(answer + "\n");
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
