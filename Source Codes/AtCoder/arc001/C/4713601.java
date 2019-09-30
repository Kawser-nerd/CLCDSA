import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.AbstractMap;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;
import java.util.TreeSet;

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
    // 3 <= N <= 100 : ??????
    //
    // ????????????????????????????
    //  1. 'A', 'G', 'C', 'T' ??????
    //  2. 'AGC' ?????
    //  3. ????????????????'AGC' ?????
    // 
    // ??????????????????????????????????????????
    //
    static class Solver {

    	// ???????'A' = 0  'G' = 1  'C' = 2  'T' = 3
    	int N = 0;
    	long[][][][] dp = new long[4][4][4][100];
    	
    	public long calc(int c3, int c2, int c1, int depth, PrintWriter out) {
			out.println("c3 = " + c3 + "  c2 = " + c2 + "  c1 = " + c1 + "  depth = " + depth);
    		if(dp[c3][c2][c1][depth] >= 0) {
    			out.println("   return dp = " + dp[c1][c2][c3][depth]);
    			return dp[c1][c2][c3][depth];
    		}
    		if(depth >= 3 &&
    			((c3 == 0 &&  c2 == 1 && c1 == 2)			// A G C
    			|| (c3 == 1 &&  c2 == 0 && c1 == 2)			// G A C
       			|| (c3 == 0 &&  c2 == 2 && c1 == 1))) {		// A C G
    				dp[c3][c2][c1][depth] = 0;
    				return 0;
    		}
    		if(depth == N)	return 1L;

    		long ans = 0;
    		for(int c0 = 0; c0 < 4; c0++) {
    			if(depth >=3 &&
    				((c3 == 0 &&  c2 == 1 && c0 == 2)		// A G ? C
    				|| (c3 == 0 && c1 == 1 && c0 == 2)))	// A ? G C
    				continue;
    			ans += calc(c2, c1, c0, depth + 1, out);
    			ans %= 1000000007;
    		}
    		dp[c3][c2][c1][depth] = ans;
			out.println("   return ans = " + ans);
    		return (ans);
    	}
    	
    	public void solve(int testNumber, MyInput in, PrintWriter out) {
        	int ans = 0;
        	int A = in.nextInt();
        	int B = in.nextInt();
        	int diff = Math.abs(B - A);
        	while(true) {
        		if(diff >= 10) {
        			ans++;
        			diff -= 10;
        		} else {
        			break;
        		}
        	}
        	switch (diff) {
        	case 0:
        	    break;
			case 1:	case 5:
				ans++;
				break;
			case 2:	case 4:	case 6:	case 9:
				ans += 2;
				break;
			default:
				ans += 3;
				break;
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