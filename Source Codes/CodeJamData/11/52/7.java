package _11R3;
import java.io.*;
import java.math.*;
import java.util.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class ProgramB {
	static final boolean _PRACTICE = !true;
	static final boolean _SAMPLE = !true;
	static final boolean _SMALL = !true;
	static final String _PROBLEM = "B";

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
		int n=sc.nextInt();
		int[] is=new int[10010];
		for(int i=0;i<n;i++)is[sc.nextInt()]++;
		if(n==0) {
			System.out.println(0);return;
		}
		int left=1,right=n+1;
		do {
			int mid=(left+right)/2;
			if(can(mid,is.clone(),n))left=mid;
			else right=mid;
		}while(right-left>1);
		System.out.println(left);
	}

	private boolean can(int mid,int[] is,int n){
		int[] last=new int[10010];
		for(int i=1;i<10005;i++) {
			if(is[i]>last[i-1]) {
				last[i] += last[i-1];
				is[i] -= last[i-1];
				int c = is[i];
				for(int j=0;j<mid;j++) {
					if(is[i+j]<c)return false;
					is[i+j] -= c;
				}
				last[i+mid-1]+=c;
			}else {
				last[i] += is[i];
				is[i] = 0;
			}
		}
		return true;
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
					new ProgramB().run();
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
					new ProgramB().run();
				}
			} else {
				System.setIn(new FileInputStream(_LARGENAME() + ".in"));
				System.setOut(new PrintStream(_LARGENAME() + ".out"));
				new ProgramB().run();
			}
		} else
			new ProgramB().run();
	}

	private static String _LARGENAME() {
		return _PROBLEM + "-large" + (_PRACTICE ? "-practice" : "");
	}

	private static String _SMALLNAME(int a) {
		return _PROBLEM + "-small" + (_PRACTICE ? a == 0 ? "-practice" : "" : "-attempt" + a);
	}
}