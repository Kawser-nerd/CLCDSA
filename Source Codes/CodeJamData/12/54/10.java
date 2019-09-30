import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class D {
	public static boolean is_r(char c) {
		return r(c) != '\0';
	}
	public static char r(char c) {
		if(c=='o') return '0';
		if(c=='i') return '1';
		if(c=='e') return '3';
		if(c=='a') return '4';
		if(c=='s') return '5';
		if(c=='t') return '7';
		if(c=='b') return '8';
		if(c=='g') return '9';
		return '\0';
	}
	static int[] O;
	static int[] I;
	static Set<String> S;
	static Set<Character> X;
	public static void add(String s) {
		if(S.contains(s)) return;
		S.add(s);
		O[s.charAt(0)]++;
		I[s.charAt(1)]++;
		X.add(s.charAt(0));
		X.add(s.charAt(1));
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int cas=1; cas<=T; cas++) {
			int k = in.nextInt();
			String text = in.next();
			O = new int[256];
			I = new int[256];
			X = new HashSet<Character>();
			S = new HashSet<String>();
			for(int i=0; i+2<=text.length(); i++) {
				if(S.contains(text.substring(i,i+2))) continue;
				char c1 = text.charAt(i);
				char c2 = text.charAt(i+1);
				add(""+c1+c2);
				if(is_r(c1))
					add(""+r(c1)+c2);
				if(is_r(c2))
					add(""+c1+r(c2));
				if(is_r(c1) && is_r(c2))
					add(""+r(c1)+r(c2));
			}
			int need_out = 0;
			int need_in = 0;
			for(char c:X) {
				if(I[c] == O[c]) continue;
				if(I[c] > O[c])
					need_in += I[c]-O[c];
				if(O[c] > I[c])
					need_out += O[c]-I[c];
			}
			
			System.out.printf("Case #%d: %d\n", cas, 1+S.size()+Math.max(0, Math.max(need_out,need_in)-1));
		}
	}
}
