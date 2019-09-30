
import java.io.*;
import java.util.*;
import java.math.*;

public class GCJ_D {
	static final String FILENAME = "D-large";
	static BufferedReader in; static PrintWriter out; static StringTokenizer st;
	static void newST() throws IOException {st = new StringTokenizer(in.readLine());}
	static int stInt() {return Integer.parseInt(st.nextToken());}
	static int readInt() throws IOException {return Integer.parseInt(in.readLine());}
	static void println(Object o) {System.out.println(o);} static void println() {System.out.println();} static void print(Object o) {System.out.print(o);}
    public static void main(String[] args) throws IOException {
    	in = new BufferedReader(new FileReader(FILENAME+".in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter(FILENAME+".out")));
		int T = readInt();
		for (int i = 1; i <= T; i++) {
			out.print("Case #"+i+":");
			solve();
		}
		in.close();
		out.close();
    }
    static void solve() throws IOException {
    	newST();
    	int K = stInt(), C = stInt(), S = stInt();
    	int sin = (K+C-1)/C;
    	if (S < sin) {
    		out.println(" IMPOSSIBLE");
    		return;
    	}
    	S = sin;
    	BigInteger ans = BigInteger.ZERO;
    	for (int i = 0; i < S*C; i++) {
    		ans = ans.multiply(bigInt(K)).add(bigInt(i%K));
    		if ((i+1) % C == 0) {
    			ans = ans.add(BigInteger.ONE);
    			out.print(" " + ans);
    			ans = BigInteger.ZERO;
    		}
    	}
    	out.println();
    }
    static BigInteger bigInt(int n) {
    	return new BigInteger(Integer.toString(n));
    }
}
