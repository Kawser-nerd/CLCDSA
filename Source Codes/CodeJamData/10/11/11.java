import java.io.*;
import java.math.*;
import java.util.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class A {
	static final boolean _PRACTICE = !true;
	static final boolean _SAMPLE = !true;
	static final boolean _SMALL = !true;
	static final String _PROBLEM = "A";

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int oo = sc.nextInt();
		for (int o = 1; o <= oo; o++) {
			System.err.println(o);
			System.out.printf("Case #%d: ", o);
			int n=sc.nextInt(),K=sc.nextInt();
			char[][]cs=new char[n][];
			for (int i = 0; i < n; i++) {
				cs[i]=sc.next().toCharArray();
			}
			for (int i = 0; i < n; i++) {
				for(int j=n-1;j>=0;j--){
					for (int k = j; k >= 0; k--) {
						if(cs[i][k]!='.'){
							char t=cs[i][k];cs[i][k]=cs[i][j];cs[i][j]=t;
							break;
						}
					}
				}
			}
//			for (int i = 0; i < n; i++) {
//				debug(cs[i]);
//			}
			boolean[] bs=new boolean[2];
			for (int l = 0; l < 2; l++) {
				char c = ps[l];
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						for (int d = 0; d < 4; d++) {
							boolean ok=true;
							for (int k = 0; k < K; k++) {
								int x = i+dx[d]*k,y=j+dy[d]*k;
								if(0<=x&&x<n&&0<=y&&y<n&&cs[x][y]==c);
								else ok=false;
							}
							if(ok)bs[l]=true;
						}
					}
				}
			}
			if(bs[0]&&bs[1]){
				System.out.println("Both");
			}
			else if(bs[0]){
				System.out.println("Blue");
			}
			else if(bs[1]){
				System.out.println("Red");
			}
			else{
				System.out.println("Neither");
			}
		}
	}
	char[] ps={'B','R'};
	int[] dx={0,1,1,1};
	int[] dy={1,-1,0,1};
	
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
					new A().run();
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
					new A().run();
				}
			} else {
				System.setIn(new FileInputStream(_LARGENAME() + ".in"));
				System.setOut(new PrintStream(_LARGENAME() + ".out"));
				new A().run();
			}
		} else
			new A().run();
	}

	private static String _LARGENAME() {
		return _PROBLEM + "-large" + (_PRACTICE ? "-practice" : "");
	}

	private static String _SMALLNAME(int a) {
		return _PROBLEM + "-small" + (_PRACTICE ? a == 0 ? "-practice" : "" : "-attempt" + a);
	}
}
