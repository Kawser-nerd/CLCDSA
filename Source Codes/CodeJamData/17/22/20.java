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



public class GCJ2017R2BB {

    static StringTokenizer st;
    static BufferedReader br;
    static PrintWriter pw;

    static class Sort implements Comparable<Sort> {
        int ind, a;

        @Override
        public int compareTo(Sort o) {
            return o.a - a;
        }
        public Sort(int i, int an) {
            ind = i;
            a = an;
        }
    }

    static int tc = 0;
    public static void main(String[] args) throws IOException {
        //br = new BufferedReader(new InputStreamReader(System.in));
        //pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    	br = new BufferedReader(new FileReader(new File("B-large.in")));
        pw = new PrintWriter(new BufferedWriter(new FileWriter("B-large.out")));        
        int t = nextInt();
        for (tc = 1; tc <= t; ++tc)
        	solve();
        pw.close();
    }
        
    static final int N = 6;
    static String ch = "ROYGBV";
    static Sort[] s;
    private static void solve() throws IOException {
    	int n = nextInt();
    	s = new Sort[N];
    	int summa = 0;
    	for (int i = 0; i < N; ++i) {
    		s[i] = new Sort(i, nextInt());
    		summa += s[i].a;
    	}
    	String sb = "", sy = "", sr = "";
    	if (s[1].a > 0) {
    		if (s[4].a - 1 >= s[1].a) {
    			for (int i = 0; i < s[1].a; ++i)
    				sb += "BO";
    			sb += "B";
    			s[4].a -= s[1].a;
    			s[1].a = 0;
    		} else {
    			if (s[4].a == s[1].a && summa == 2 * s[4].a) {
        			for (int i = 0; i < s[1].a; ++i)
        				sb += "BO";
        			print(sb);
    			} else
    				print("IMPOSSIBLE");
    			return;
    		}
    	}
    	if (s[3].a > 0) {
    		if (s[0].a - 1 >= s[3].a) {
    			for (int i = 0; i < s[3].a; ++i)
    				sr += "RG";
    			sr += "R";
    			s[0].a -= s[3].a; 
    			s[3].a = 0;
    		} else {
    			if (s[0].a == s[3].a && summa == 2 * s[3].a) {
        			for (int i = 0; i < s[3].a; ++i)
        				sr += "RG";
        			print(sr);
    			} else
    				print("IMPOSSIBLE");
    			return;
    		}
    	}
    	if (s[5].a > 0) {
    		if (s[2].a - 1 >= s[5].a) {
    			for (int i = 0; i < s[5].a; ++i)
    				sy += "YV";
    			sy += "Y";
    			s[2].a -= s[5].a; 
    			s[5].a = 0;
    			
    		} else {
    			if (s[5].a == s[2].a && summa == 2 * s[5].a) {
        			for (int i = 0; i < s[5].a; ++i)
        				sy += "YV";
        			print(sy);
    			} else
    				print("IMPOSSIBLE");
    			return;
    		}
    	}
    	Arrays.sort(s);
    	if (s[0].a > s[1].a + s[2].a) {
    		print("IMPOSSIBLE");
    	} else {
    		int sum = s[0].a + s[1].a + s[2].a;
    		char[] ans = new char [sum];
    		for (int i = 0; i < sum; ++i) {
    			if (s[0].a > 0) {
    				--s[0].a;
    				ans[i] = ch.charAt(s[0].ind);
    				++i;
    				if (s[1].a >= s[2].a) {
    					--s[1].a;
    					ans[i] = ch.charAt(s[1].ind);
    				} else {
    					--s[2].a;
    					ans[i] = ch.charAt(s[2].ind);
    				}
    			} else {
    				ans[i] = (ans[i - 1] == ch.charAt(s[1].ind)) ? ch.charAt(s[2].ind) : ch.charAt(s[1].ind);
    			}
    		}
    		StringBuilder sbd = new StringBuilder();
    		for (int i = 0; i < sum; ++i) {
    			if (ans[i] == 'B' && !sb.equals("")) {
    				sbd.append(sb);
    				sb = "";
    			} else if (ans[i] == 'R' && !sr.equals("")) {
    				sbd.append(sr);
    				sr = "";
    			} else if (ans[i] == 'Y' && !sy.equals("")) {
    				sbd.append(sy);
    				sy = "";
    			} else {
    				sbd.append(ans[i]);
    			}
    		}
    		print(sbd.toString());
    	}
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