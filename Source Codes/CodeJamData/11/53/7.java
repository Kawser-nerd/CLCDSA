package _11R3;
import java.io.*;
import java.math.*;
import java.util.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class ProgramC {
	static final boolean _PRACTICE = !true;
	static final boolean _SAMPLE = !true;
	static final boolean _SMALL = !true;
	static final String _PROBLEM = "C";

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int oo = sc.nextInt();
		for (int o = 1; o <= oo; o++) {
			System.err.println(o);
			System.out.printf("Case #%d: ", o);
			solve(sc);
		}
	}

	private void solve(Scanner sc){
		h=sc.nextInt();w=sc.nextInt();
		seen=new boolean[h][w];
		decided=new boolean[h][w];
		board=new char[h][];
		for(int i=0;i<h;i++)board[i]=sc.next().toCharArray();
		System.out.println(calc());
		
		
	}
	int[] dx= {-1,-1,-1,0,0,1,1,1};
	int[] dy= {-1,0,1,-1,1,-1,0,1};
	String S="\\|/--/|\\";
	private int calc(){
		while(true) {
			boolean found=false;
			for(int i=0;i<h;i++)for(int j=0;j<w;j++)if(!seen[i][j]) {
				int cnt=0;
				int rd=-1,rx=-1,ry=-1;
				for(int d=0;d<8;d++) {
					int nx=i+dx[d],ny=j+dy[d];
					if(nx<0)nx+=h;
					if(nx>=h)nx-=h;
					if(ny<0)ny+=w;
					if(ny>=w)ny-=w;
					if(!decided[nx][ny] && board[nx][ny]==S.charAt(d)) {
						cnt++;
						rd = d;rx=nx;ry=ny;
					}
				}
				if(cnt==1) {
					found=true;
					seen[i][j]=true;
					decided[rx][ry]=true;
				}
				if(cnt==0) {
					return 0;
				}
			}
			if(!found)break;
		}
		for(int i=0;i<h;i++)for(int j=0;j<w;j++)if(!seen[i][j]) {
			for(int d=0;d<8;d++) {
				int nx=i+dx[d],ny=j+dy[d];
				if(nx<0)nx+=h;
				if(nx>=h)nx-=h;
				if(ny<0)ny+=w;
				if(ny>=w)ny-=w;
				if(!decided[nx][ny] && board[nx][ny]==S.charAt(d)) {
					seen[i][j]=true;
					decided[nx][ny]=true;
					int res = 2 * calc();
					if(res>=M)res-=M;
					return res;
				}
			}
		}
		return 1;
	}
	int M=1000003;
	int h,w;
	boolean[][] seen;
	boolean[][] decided;
	char[][] board;

	public static void main(String... args) throws IOException {
		if (!_SAMPLE) {
			if (_SMALL) {
				int i = 0;
				while (new File(_SMALLNAME(i) + ".in").exists())
					i++;
				i--;
				boolean test = false;
				if (new File(_SMALLNAME(i) + ".out").exists()) {
					System.err.println("overwrite?(y/n)");
					char c = (char) System.in.read();
					test = c != 'y';
				}
				if (test) {
					System.setIn(new FileInputStream(_SMALLNAME(i) + ".in"));
					System.setOut(new PrintStream(_PROBLEM + "-small-test.out"));
					new ProgramC().run();
					FileReader f1 = new FileReader(_PROBLEM + "-small-test.out");
					FileReader f2 = new FileReader(_SMALLNAME(i) + ".out");
					BufferedReader br1 = new BufferedReader(f1);
					BufferedReader br2 = new BufferedReader(f2);
					for (int j = 1;; j++) {
						String s1 = br1.readLine();
						String s2 = br2.readLine();
						if (s1 == null && s2 == null) {
							System.err.println("OK!");
							break;
						}
						if (s1 == null || s2 == null || !s1.equals(s2)) {
							System.err.println("failed at line " + j);
							System.err.println("expected " + s2);
							System.err.println("but " + s1);
							break;
						}
					}
				} else {
					System.setIn(new FileInputStream(_SMALLNAME(i) + ".in"));
					System.setOut(new PrintStream(_SMALLNAME(i) + ".out"));
					new ProgramC().run();
				}
			} else {
				System.setIn(new FileInputStream(_LARGENAME() + ".in"));
				System.setOut(new PrintStream(_LARGENAME() + ".out"));
				new ProgramC().run();
			}
		} else
			new ProgramC().run();
	}

	private static String _LARGENAME() {
		return _PROBLEM + "-large" + (_PRACTICE ? "-practice" : "");
	}

	private static String _SMALLNAME(int a) {
		return _PROBLEM + "-small" + (_PRACTICE ? a == 0 ? "-practice" : "" : "-attempt" + a);
	}
}