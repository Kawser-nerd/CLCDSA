import java.util.*;
import java.text.*;
import java.io.*;
import java.util.regex.*;
import java.math.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;
@SuppressWarnings("unchecked")
public class A{
	public static void main(String[] args) throws Exception{
		long time = System.currentTimeMillis();
		new A().go();
	//	System.out.printf("Time spent: %.3fs%n",(System.currentTimeMillis()-time)/1000.0);
	}
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int INT(Object o){ return Integer.parseInt(o.toString());}
	static void ST() throws Exception{ st = new StringTokenizer(in.readLine());}
	void go() throws Exception{
		int T = INT(in.readLine());
		for(int t = 1; t <= T; t++){
			ST();
			int n = st.countTokens();
			int[] bs = new int[n];
			for(int i = 0; i < n; i++) bs[i] = INT(st.nextToken());
			outer:
			for(int i = 2;;i++){
				for(int j = 0; j < n; j++) if(!yes(bs[j], i)) continue outer;
				System.out.printf("Case #%d: %d%n",t,i);
				break;
			}
		}
	}
	int[][] ok = new int[11][11814486];
	int UNDEFINED = 0;
	int YES = 1;
	int NO = 2;
	int DIRTY = 3;

	boolean yes(int base, int n){
		if(n == 1) return true;
		if(n < ok[base].length){
			if(ok[base][n] == DIRTY) return false;
			if(ok[base][n] == UNDEFINED){
				ok[base][n] = DIRTY;
				boolean ret = yes(base, conv(base, n));
				if(ret) ok[base][n] = YES;
				else ok[base][n] = NO;
				return ret;
			}
			return ok[base][n] == YES;
		}else{
			return yes(base, conv(base, n));
		}
	}

	int conv(int base, int n){
		int ret = 0;
		while(n != 0){
			int dig = n%base;
			n /= base;
			ret += dig*dig;
		}
		return ret;
	}

}