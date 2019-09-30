
import java.io.*;
import java.util.*;

public class GCJ_A {
	static final String FILENAME = "A-large";
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
			out.print("Case #"+i+": ");
			solve();
		}
		in.close();
		out.close();
    }
    static void solve() throws IOException {
    	long n = readInt();
    	if (n == 0) {
    		out.println("INSOMNIA");
    		return;
    	}
    	int g = 0;
    	boolean[] ts = new boolean[10];
    	long m = 0;
    	while (g < 10) {
    		m += n;
    		long k = m;
    		while (k > 0) {
    			int d = (int)(k%10);
    			if (!ts[d]) {
    				ts[d] = true;
    				g++;
    			}
    			k /= 10;
    		}
    	}
    	out.println(m);
    }
}
