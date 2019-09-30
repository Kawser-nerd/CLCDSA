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
    // 1 <= R, C <= 50  : R = ????C = ??
    // Sy, Sx = ???????Gy, Gx = ???
    // C(y, x) :  . = ???# = ?
    //
    // ?????????????????
    //
    static class Solver {

    	boolean[][] c = new boolean[50][50];						// ???(true ???
    	Queue<Pair<Integer, Integer>> que = new ArrayDeque<>();		// ???
    	int[][] f = new int[50][50];								// ????????????????????????
    	
    	// ????????????????
    	public int calc(int sy, int sx, int gy, int gx) {
    		int y, x;
    		Pair<Integer, Integer> p = null;
    		f[sy][sx] = 0;								// ??????????
    		que.add(new Pair(sy, sx));					// ????????????
			while(que.peek() != null) {
				p = que.poll();
				y = p.getKey();
				x = p.getValue();
				if(y == gy && x == gx) {				// ???????
					break;
				}
				
    			if(!c[y-1][x] && f[y-1][x] < 0) {		// ?????????????????????????????
    				que.add(new Pair(y-1, x));
    				f[y-1][x] = f[y][x] + 1;			// ????????
    			}
    			if(!c[y][x-1] && f[y][x-1] < 0) {
    				que.add(new Pair(y, x-1));
    				f[y][x-1] = f[y][x] + 1;
    			}
    			if(!c[y][x+1] && f[y][x+1] < 0) {
    				que.add(new Pair(y, x+1));
    				f[y][x+1] = f[y][x] + 1;
    			}
    			if(!c[y+1][x] && f[y+1][x] < 0) {
    				que.add(new Pair(y+1, x));
    				f[y+1][x] = f[y][x] + 1;
    			}
			}
    		return f[gy][gx];							// ??????????
    	}
    	
    	public void solve(int testNumber, MyInput in, PrintWriter out) {
        	boolean ans = false;
    		int R = in.nextInt();			// ?
    		int C = in.nextInt();			// ?
    		int sy = in.nextInt();			// ????
    		int sx = in.nextInt();
    		int gy = in.nextInt();			// ???
    		int gx = in.nextInt();
//    		out.println(R + " "  + C + " "  + sy + " "  + sx + " "  + gy + " "  + gx);
        	String a = null;
        	for(int i=0; i < R; i++) {		// ????
        		a = in.nextString();
        		for(int j=0; j < C; j++) {
        			if(a.charAt(j) == '#') {
        				c[i][j] = true;		// ?
        			}
    				f[i][j] = -1;			// ???????????
        		}
        	}
        	out.println(calc(sy-1, sx-1, gy-1, gx-1));
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.