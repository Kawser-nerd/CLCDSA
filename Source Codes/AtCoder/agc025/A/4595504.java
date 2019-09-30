import java.io.BufferedReader;

import static java.util.Comparator.*;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.math.BigDecimal;
import java.util.AbstractMap;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;
import static java.util.Comparator.*;


public class Main {
	
	public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyInput in = new MyInput(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        
        Solver solver = new Solver();
        solver.solve(1, in, out);
        
        out.close();
    }
    
    // ======================================================================
    static class Solver {

    	int[][] D = null;
    	int[] S = null;
    	int s_max = 0;
    	
    	public void init(int max, PrintWriter out) {
			s_max = (int)Math.sqrt(max) + 1;
//			out.println("max = " + max + "  s_max = " + s_max);
			D = new int[s_max][s_max];
			S = new int[s_max];
    	}
    	public void add(int i, int v, PrintWriter out) {
    		int cnt_1 = i / s_max;
    		int cnt_2 = i - cnt_1 * s_max;
//    		out.println("cnt_1 = " + cnt_1 + "  cnt_2 = " + cnt_2);
    		D[cnt_1][cnt_2] += v;
    		S[cnt_1] += v;
    	}
    	// l, r ???0 ????l, r ????
    	public int sum(int l, int r, PrintWriter out) {
    		int l_cnt = (l / s_max);
    		int r_cnt = (r / s_max);
    		int ans = 0;
    		for(int i = l_cnt + 1; i <= r_cnt - 1; i++) {
    			ans += S[i];
    		}
    		if(l_cnt < r_cnt) {
	    		for(int i = (l - l_cnt * s_max); i < s_max; i++) {
	    			ans += D[l_cnt][i];
	    		}
	    		for(int i = 0; i < (r - r_cnt * s_max); i++) {
	    			ans += D[r_cnt][i];
	    		}
    		} else if(l_cnt == r_cnt) {
	    		for(int i = (l - l_cnt * s_max); i <  (r - r_cnt * s_max); i++) {
	    			ans += D[l_cnt][i];
	    		}
    		}
//    		out.println("l = " + l + "  r = " + r + "  ans = " + ans);
    		return ans;
    	}
    	
    	public int count(int X, PrintWriter out) {
    		int ans = 0;
    		int zan = X;
    		int wk = 0;
    		int W = 100000;
    		for(int i=0; i < 6; i++) {
	    		wk = zan / W;
	    		ans += wk;
	    		zan = zan - wk * W;
	    		W /= 10;
    		}
//    		out.println("count(" + X + ") = " + ans);
    		return ans;
    	}
    	
		public void solve(int testNumber, MyInput in, PrintWriter out) {
			int N = in.nextInt();
			
			int B = 0;
			int ans = 99999;
			for(int A = 1; A < N; A++) {
				B = N - A;
//				out.println("A = " + A + "  B = " +  B);
				ans = Math.min(ans, count(A, out) + count(B, out));
			}
			out.println(ans);
		}
    }
    // ======================================================================
    static class Pair<K, V> extends AbstractMap.SimpleEntry<K, V> {
        /** serialVersionUID. */
        private static final long serialVersionUID = 6411527075103472113L;

        public Pair(final K key, final V value) {
            super(key, value);
        }
        public String getString() {
            return "[" + getKey() + "] [" + getValue() + "]";
        }
     }    
    static class MyInput {
        private final BufferedReader in;
        private static int pos;
        private static int readLen;
        private static final char[] buffer = new char[1024 * 8];
        private static char[] str = new char[500 * 8 * 2];
        private static boolean[] isDigit = new boolean[256];
        private static boolean[] isSpace = new boolean[256];
        private static boolean[] isLineSep = new boolean[256];
 
        static {
            for (int i = 0; i < 10; i++) {
                isDigit['0' + i] = true;
            }
            isDigit['-'] = true;
            isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true;
            isLineSep['\r'] = isLineSep['\n'] = true;
        }
 
        public MyInput(InputStream is) {
            in = new BufferedReader(new InputStreamReader(is));
        }
 
        public int read() {
            if (pos >= readLen) {
                pos = 0;
                try {
                    readLen = in.read(buffer);
                } catch (IOException e) {
                    throw new RuntimeException();
                }
                if (readLen <= 0) {
                    throw new MyInput.EndOfFileRuntimeException();
                }
            }
            return buffer[pos++];
        }
 
        public int nextInt() {
            int len = 0;
            str[len++] = nextChar();
            len = reads(len, isSpace);
            int i = 0;
            int ret = 0;
            if (str[0] == '-') {
                i = 1;
            }
            for (; i < len; i++) ret = ret * 10 + str[i] - '0';
            if (str[0] == '-') {
                ret = -ret;
            }
            return ret;
        }
 
        public long nextLong() {
            int len = 0;
            str[len++] = nextChar();
            len = reads(len, isSpace);
            int i = 0;
            long ret = 0L;
            if (str[0] == '-') {
                i = 1;
            }
            for (; i < len; i++) ret = ret * 10 + str[i] - '0';
            if (str[0] == '-') {
                ret = -ret;
            }
            return ret;
        }
 
        public String nextString() {
        	String ret = new String(nextDChar()).trim();
            return ret;
        }
 
        public char[] nextDChar() {
            int len = 0;
            len = reads(len, isSpace);
            char[] ret = new char[len + 1];
            for (int i=0; i < len; i++)		ret[i] = str[i];
            ret[len] = 0x00;
            return ret;
        }
 
        public char nextChar() {
            while (true) {
                final int c = read();
                if (!isSpace[c]) {
                    return (char) c;
                }
            }
        }
 
        int reads(int len, boolean[] accept) {
            try {
                while (true) {
                    final int c = read();
                    if (accept[c]) {
                        break;
                    }
                    if (str.length == len) {
                        char[] rep = new char[str.length * 3 / 2];
                        System.arraycopy(str, 0, rep, 0, str.length);
                        str = rep;
                    }
                    str[len++] = (char) c;
                }
            } catch (MyInput.EndOfFileRuntimeException e) {
            }
            return len;
        }
 
        static class EndOfFileRuntimeException extends RuntimeException {
        }
    }
}