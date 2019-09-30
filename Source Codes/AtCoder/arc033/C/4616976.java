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

    	int[] D = null;		// ????
    	int[] S = null;		// ???
    	int s_max = 0;
    	
    	public void init(int max, PrintWriter out) {
			s_max = (int)Math.sqrt(max) + 1;
//			s_max = (max + s_max - 1) / s_max;
//			out.println("max = " + max + "  s_max = " + s_max);
			D = new int[max];
			S = new int[s_max];
    	}
    	public void add(int i, int v, PrintWriter out) {
    		int cnt = i / s_max;
//    		out.println("D[" + i + "],  S[" + cnt + "]  += " + v);
    		D[i] += v;
    		S[cnt] += v;
//    		out.println("D[" + i + "] = " + D[i] + "  S[" + cnt + "] = " + S[cnt]);
    	}
    	// l, r ???0 ????x ???? y ?????
    	public int sum(int x, int y, PrintWriter out) {
    		int ans = 0;
    		int l = 0;
    		int r = 0;;
    		for(int i = 0; i < s_max; i++) {
    			l = i * s_max;
    			r = (i + 1) * s_max;
    			if(x <= l && r <= y) {
    				ans += S[i];		// ??????
    			} else if(y <= l || r <= x) {
    				continue;
    			} else {
    				for(int j=Math.max(x,  l) ; j < Math.min(y, r); j++) {
    					ans += D[j];	// ???????
    				}
    			}
    		}
//    		out.println("x = " + x + "  y = " + y + "  ans = " + ans);
    		return ans;
    	}
    	
    	public int search(int x) {
    		int total = 0;
    		int start = -1;
			for(int i = 0; i < s_max; i++) {		// ?????????
				if(total + S[i] >= x) {
					start = i * s_max;
					break;
				}
				total += S[i];
			}
			if(start == -1) {
				return -1;
			}
			for(int i = 0; i < s_max; i++) {		// ??????????
				total += D[start + i];
				if(total == x) {
					return start + i;
				}
			}
			return -1;
    	}
    	
		public void solve(int testNumber, MyInput in, PrintWriter out) {

			init(200000, out);			// ?????????

			int Q = in.nextInt();		// ????
			
			int T, X;
			int cnt = 0;
			for(int i=0; i < Q; i++) {
				T = in.nextInt();		// ??????????????
				X = in.nextInt();		// ?
//				out.println("T = " + T + "   X = " + X);
				if(T == 1) {								// ??????
					add(X - 1, 1, out);
				} else {
					cnt = search(X);
					if(cnt != -1) {
						out.println(cnt + 1);
						add(cnt, -1, out);
					}
				}
			}
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