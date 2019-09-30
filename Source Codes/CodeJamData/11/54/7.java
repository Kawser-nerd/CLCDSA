package _11R3;
import java.io.*;
import java.math.*;
import java.util.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class ProgramD {
	static final boolean _PRACTICE = !true;
	static final boolean _SAMPLE = !true;
	static final boolean _SMALL = true;
	static final String _PROBLEM = "D";

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
		char[] cs = sc.next().toCharArray();
		int n=cs.length;
		int m=0;
		for(int i=0;i<n;i++)if(cs[i]=='?')m++;
		int[] is=new int[m];
		for(int i=0,j=0;i<n;i++)if(cs[i]=='?') {
			is[j++] = i;
		}
		for(int i=0;i<1<<m;i++) {
			for(int j=0;j<m;j++) {
				cs[is[j]] = ((i>>j&1)==1) ? '1' : '0';
			}
			long l = Long.valueOf(new String(cs),2);
			if(sq(l)){
				System.out.println(new String(cs));
				return;
			}
		}
		assert false;
	}

	private boolean sq(Long l){
		long a = (long)round(sqrt(l));
		return a*a==l;
	}

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
					new ProgramD().run();
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
					new ProgramD().run();
				}
			} else {
				System.setIn(new FileInputStream(_LARGENAME() + ".in"));
				System.setOut(new PrintStream(_LARGENAME() + ".out"));
				new ProgramD().run();
			}
		} else
			new ProgramD().run();
	}

	private static String _LARGENAME() {
		return _PROBLEM + "-large" + (_PRACTICE ? "-practice" : "");
	}

	private static String _SMALLNAME(int a) {
		return _PROBLEM + "-small" + (_PRACTICE ? a == 0 ? "-practice" : "" : "-attempt" + a);
	}
}