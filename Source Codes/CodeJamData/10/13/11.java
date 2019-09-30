import java.io.*;
import java.math.*;
import java.util.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class C {
	static final boolean _PRACTICE = !true;
	static final boolean _SAMPLE = !true;
	static final boolean _SMALL = !true;
	static final String _PROBLEM = "C";

	void debug(Object... os) {
//		System.err.println(deepToString(os));
	}
	int M = 1000010;
	boolean win(int n,int m){//n <= m
		if(n>m)return win(m,n);
		if(n==m)return false;
		if(2*n<=m)return true;
		return !win(m-n,n);
	}
	int calcl(int n){
		int l=n/2,r=n;
		do{
			int m=(l+r)/2;
			if(win(m,n)){
				l=m;
			}
			else{
				r=m;
			}
		}while(r-l>1);
		return r;
	}
	int calcr(int n){
		int l=n,r=2*n;
		do{
			int m=(l+r)/2;
			if(win(m,n)){
				r=m;
			}
			else{
				l=m;
			}
		}while(r-l>1);
		return r;
	}
	
	void run() {
//		for (int i = 1; i <= 100; i++) {
//			for (int j = i/2; j <= 2*i; j++) {
//				debug(i,j,win(i,j));
////				System.out.println(win(i,j));
//			}
//		}
		
		int[] l=new int[M];
		int[] r=new int[M];
		for (int i = 1; i < M; i++) {
			l[i] = calcl(i);
			r[i]= calcr(i);
//			debug(i,l[i],r[i]);
		}
		
		Scanner sc = new Scanner(System.in);
		int oo = sc.nextInt();
		for (int o = 1; o <= oo; o++) {
			System.err.println(o);
			System.out.printf("Case #%d: ", o);
			long res=0;
			int a1=sc.nextInt(),a2=sc.nextInt(),b1=sc.nextInt(),b2=sc.nextInt()+1;
			
			for (int i = a1; i <= a2; i++) {
//				for (int j = b1; j < b2; j++) {
//					if(win(i,j))res++;
//				}
//				
				res += calc(l[i],r[i],b2)-calc(l[i],r[i],b1);
			}
			System.out.println(res);
		}
	}
	int calc(int l,int r,int b){// < b
		debug(l,r,b);
		if(b<=r){
			if(b<=l)return b;
			return l;
		}
		return b-(r-l);
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
					new C().run();
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
					new C().run();
				}
			} else {
				System.setIn(new FileInputStream(_LARGENAME() + ".in"));
				System.setOut(new PrintStream(_LARGENAME() + ".out"));
				new C().run();
			}
		} else
			new C().run();
	}

	private static String _LARGENAME() {
		return _PROBLEM + "-large" + (_PRACTICE ? "-practice" : "");
	}

	private static String _SMALLNAME(int a) {
		return _PROBLEM + "-small" + (_PRACTICE ? a == 0 ? "-practice" : "" : "-attempt" + a);
	}
}
