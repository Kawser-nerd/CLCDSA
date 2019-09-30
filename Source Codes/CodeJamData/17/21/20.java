import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.Vector;
import java.util.regex.Matcher;
import java.util.regex.Pattern;



public class GCJ2017R1BA {

    static StringTokenizer st;
    static BufferedReader br;
    static PrintWriter pw;

    static int tc = 0;
    public static void main(String[] args) throws IOException {
        //br = new BufferedReader(new InputStreamReader(System.in));
        //pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    	br = new BufferedReader(new FileReader(new File("A-large.in")));
        pw = new PrintWriter(new BufferedWriter(new FileWriter("A-large.out")));        
        int t = nextInt();
        for (tc = 1; tc <= t; ++tc)
        	solve();
        pw.close();
    }
        
    private static void solve() throws IOException {
    	double d = nextDouble();
    	int n = nextInt();
    	double maxt = 0;
    	for (int i = 0; i < n; ++i) {
    		maxt = Math.max(maxt, (d - nextDouble()) / nextDouble());
    	}
    	print(d / maxt);
    }

    private static void print(Object ans) {
		pw.println("Case #" + tc + ": " + ans);
	}

	private static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
    private static long nextLong() throws IOException {
        return Long.parseLong(next());
    }
    private static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
    private static String next() throws IOException {
        while (st==null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
}