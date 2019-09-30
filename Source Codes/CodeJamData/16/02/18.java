
import java.io.*;
import java.util.*;

public class GCJ_B {
	static final String FILENAME = "B-large";
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
    	String str = in.readLine();
    	int n = str.length();
    	int ans = str.charAt(n-1) == '-' ? 1:0;
    	for (int i = 1; i < n; i++)
    		if (str.charAt(i-1) != str.charAt(i))
    			ans++;
    	out.println(ans);
    }
}
