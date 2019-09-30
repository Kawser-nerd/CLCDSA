import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;

    static void solve() throws IOException {
    	double L=rd();
    	double X=rd();
    	double Y=rd();
    	double S=rd();
    	double D=rd();

    	if (X>=Y) {
        	out.println((L+D-S)%L/(Y+X));
    	} else {
        	out.println(Math.min((L+D-S)%L/(Y+X), (L+S-D)%L/(Y-X)));
    	}
    }


    public static void main(String[] args) throws IOException {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        tok = new StringTokenizer("");
        solve();
        out.close();
    }

    static String rs() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine(), " ");
        }
        return tok.nextToken();
    }

    static int ri() throws IOException {
        return Integer.parseInt(rs());
    }

    static long rl() throws IOException {
        return Long.parseLong(rs());
    }

    static double rd() throws IOException {
        return Double.parseDouble(rs());
    }

    static String[] rsa(int n) throws IOException {
        String[] res = new String[n];
        for (int i = 0; i < n; i++) {
            res[i] = rs();
        }
        return res;
    }

    static int[] ria(int n) throws IOException {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = ri();
        }
        return res;
    }

    static long[] rla(int n) throws IOException {
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            res[i] = rl();
        }
        return res;
    }
}