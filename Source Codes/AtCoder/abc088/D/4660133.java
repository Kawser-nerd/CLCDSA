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
    // 2 <= H, W <= 50  : H = ????W = ??
    // C(y, x) :  . = ??????# = ????
    //
    // (0,0) --> (H, W) ??????????????????????????
    // ?????????????-1 ???
    //
    // ???????????(BFS)??????????????????
    //
    static class Solver {

    	int H, W, N;
    	char[][] c = null;											// ??
    	int[][] f = null;											// ????????????????????????
    	int wcnt = 0;												// ??????
    	Queue<Pair<Integer, Integer>> que = new ArrayDeque<>();		// ???
    	
    	// ????????????????
    	public int calc(int sy, int sx, int gy, int gx, PrintWriter out) {
    		int y, x;
    		Pair<Integer, Integer> p = null;
        	for(int i=0; i < H; i++) {		// ????
        		for(int j=0; j < W; j++) {
        			f[i][j] = -1;
        		}
        	}
   			f[sy][sx] = 0;								// ??????????

   			que.clear();
   			que.add(new Pair(sy, sx));					// ????????????
			while(que.peek() != null) {
				p = que.poll();
				y = p.getKey();
				x = p.getValue();
//				out.println(" y = " + y + "  x = " + x);
				if(y == gy && x == gx) {				// ???????
//				    out.println(" goal  count = " + f[y][x]);
					break;
				}
														// ?????????????????????????????????
    			if(y > 0 && c[y-1][x] != '#' && f[y-1][x] < 0) {
    				que.add(new Pair(y-1, x));
    				f[y-1][x] = f[y][x] + 1;			// ????????
    			}
    			if(x > 0 && c[y][x-1] != '#' && f[y][x-1] < 0) {
    				que.add(new Pair(y, x-1));
    				f[y][x-1] = f[y][x] + 1;
    			}
    			if(x < W - 1 && c[y][x+1] != '#' && f[y][x+1] < 0) {
    				que.add(new Pair(y, x+1));
    				f[y][x+1] = f[y][x] + 1;
    			}
    			if(y < H - 1 && c[y+1][x] != '#' && f[y+1][x] < 0) {
    				que.add(new Pair(y+1, x));
    				f[y+1][x] = f[y][x] + 1;
    			}
			}
//			out.println("  -->  ans = " + f[gy][gx]);
    		return f[gy][gx];							// ??????????
    	}
    	
    	public void solve(int testNumber, MyInput in, PrintWriter out) {
        	int ans = 0;
    		H = in.nextInt();				// ?
    		W = in.nextInt();				// ?
        	c = new char[H][W];				// ??
        	f = new int[H][W];				// ????????????????????????

        	String s = null;
        	for(int i=0; i < H; i++) {		// ????
        		s = in.nextString();
        		for(int j=0; j < W; j++) {
        			c[i][j] = s.charAt(j);	// ??????
        			if(c[i][j] == '.') {	// ????????
        				wcnt++;
        			}
        		}
        	}
//        	out.println("? = " + wcnt);
        	ans = calc(0, 0, H-1, W-1, out);
        	if(ans != -1) {
        		ans = wcnt - 2 - (ans-1);   // ????????????????????????????????
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.