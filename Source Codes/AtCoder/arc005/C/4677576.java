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
    // 1 <= H, W <= 500  : H = ????W = ??
    // C(y, x) :  . = ???# = ? ??s = ??????g : ???
    //
    // ?????????????????????????????
    // 
    // ???????????????????????????????????????????
    //
    static class Solver {

    	int[] dx = { 0, 0, -1, 1 };
    	int[] dy = { -1, 1, 0, 0 };
    	
    	int H, W;
    	char[][] c = null;											// ??
    	int[][] f = null;											// ??????????????????
    	Deque<Pair<Integer, Integer>> deque = new ArrayDeque<>();		// ???
    	
    	// ????????????????
    	public boolean calc(int s_h, int s_w, int g_h, int g_w, PrintWriter out) {
    		int h, w, n_h, n_w;
    		Pair<Integer, Integer> p = null;
        	for(int i=0; i < H; i++) {							// ?????
        		for(int j=0; j < W; j++) {
        			f[i][j] = 99999;
        		}
        	}
   			f[s_h][s_w] = 0;									// ?????????

            deque.clear();
   			deque.add(new Pair(s_h, s_w));						// ????????????
			while(deque.peekFirst() != null) {
				p = deque.pollFirst();
				h = p.getKey();
				w = p.getValue();
//    			out.println("  y = " + h + "  x = " + w);
				if(h == g_h && w == g_w) {						// ???????
//        			out.println(" goal  -->   f(" + h + ", " + w + ") = " + f[h][w]);
					break;
				}
				for(int i=0; i < 4; i++) {
					n_h = h + dy[i];
					n_w = w + dx[i];
					if(n_h < 0 || n_h >= H || n_w < 0 || n_w >= W) {
						continue;
					}
					if(f[n_h][n_w] == 99999) {					// ???????????
						if(c[n_h][n_w] == '#') {
							deque.addLast(new Pair(n_h, n_w));	// ???????????
						} else {
							deque.addFirst(new Pair(n_h, n_w));	// ????
						}
					}
					if(c[n_h][n_w] == '#') {					// ?????????
						f[n_h][n_w] = Math.min(f[n_h][n_w], f[h][w] + 1);
					} else {
						f[n_h][n_w] = Math.min(f[n_h][n_w], f[h][w]);
					}
//					out.println("f[" + n_h + "][" + n_w + "] = " + f[n_h][n_w]);
				}
			}
    		return f[g_h][g_w] <= 2;							// ??????????????
    	}
    	
    	public void solve(int testNumber, MyInput in, PrintWriter out) {
        	int ans = 0;
    		H = in.nextInt();				// ?
    		W = in.nextInt();				// ?
        	c = new char[H][W];				// ??
        	f = new int[H][W];				// ??????????????????

    		int s_h = 0, s_w = 0;			// ????
    		int g_h = 0, g_w = 0;			// ???
        	String s = null;
        	for(int i=0; i < H; i++) {		// ????
        		s = in.nextString();
        		for(int j=0; j < W; j++) {
        			c[i][j] = s.charAt(j);	// ??????
        			if(c[i][j] == 's') {
        				s_h = i;
        				s_w = j;
        			} else if(c[i][j] == 'g') {
        				g_h = i;
        				g_w = j;
        			}
        		}
        	}
       		if(calc(s_h, s_w, g_h, g_w, out)) {
       			out.println("YES");
       		} else {
       			out.println("NO");
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