import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.AbstractMap;
import java.util.HashSet;
import java.util.Set;
import java.util.Stack;


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
	// ????? c : 10 ??????????o : ????x : ?
	//
	// ???????????????????????
	// 
	// ?????????????????????????????
	//
    static class Solver {
		char[][] c = null;		// ????
		int[][] mark = null;	// ??????????????

		// H, W ???????????? cnt ??????????????????
    	void setNumber(int H, int W, int num) {
			// ???????
			Stack<Pair<Integer, Integer>> stack = new Stack<Pair<Integer, Integer>>();
			Pair<Integer, Integer> p = new Pair(H, W);
			stack.push(p);					// ???????
			int h, w, sv;
			
			while(!stack.isEmpty()) {
				p = stack.pop();			// ?????????????
				h = p.getKey();
				w = p.getValue();
				mark[h][w] = num;
				// ??????????
	    		if(h > 0 && mark[h-1][w] != num && c[h-1][w] == 'o') {
	    			p = new Pair(h - 1, w);
	    			stack.push(p);
	    		}
	    		if(w > 0 && mark[h][w-1] != num && c[h][w-1] == 'o') {
	    			p = new Pair(h, w - 1);
	    			stack.push(p);
	    		}
	    		if(w < (10 - 1) && mark[h][w+1] != num && c[h][w+1] == 'o') {
	    			p = new Pair(h, w + 1);
	    			stack.push(p);
	    		}
	    		if(h < (10 - 1) && mark[h+1][w] != num && c[h+1][w] == 'o') {
	    			p = new Pair(h + 1, w);
	    			stack.push(p);
	    		}
			}
    	}
    	// ??????????????????????????????
    	boolean check(int h, int w, int cnt, Set<Integer> num) {
			// ???????????
    		num.clear();
    		if(h > 0 && mark[h-1][w] != 0) {
    			num.add(mark[h-1][w]);
    		}
    		if(w > 0 && mark[h][w-1] != 0) {
    			num.add(mark[h][w-1]);
    		}
    		if(w < (10 - 1) && mark[h][w+1] != 0) {
    			num.add(mark[h][w+1]);
    		}
    		if(h < (10 - 1) && mark[h+1][w] != 0) {
    			num.add(mark[h+1][w]);
    		}
    		if(num.size() >= cnt)	return true;
    		else					return false;
    	}
    	public void solve(int testNumber, MyInput in, PrintWriter out) {
			int ans = 0;
			c = new char[10][10];
			mark = new int[10][10];
			for(int h=0; h < 10; h++) {
				for(int w=0; w < 10; w++) {
					c[h][w] = in.nextChar();
				}
			}
			int cnt = 1;
			for(int h=0; h < 10; h++) {
				for(int w=0; w < 10; w++) {
				    if(c[h][w] == 'o' && mark[h][w] == 0)
    					setNumber(h, w, cnt++);		// ????????
				}
			}
 			Set<Integer> num = new HashSet<Integer>();
			for(int h=0; h < 10; h++) {			// ?????????????????????
				for(int w=0; w < 10; w++) {
					if(mark[h][w] != 0)
						num.add(mark[h][w]);
				}
			}
			cnt = num.size();
//			out.println("?????? = " + cnt);
			
			boolean flag = false;
			if(cnt == 1) {						// ????????
				flag = true;
			} else if(cnt > 4) {				//??????????????
				flag = false;
			} else {
				LOOP:
				for(int h=0; h < 10; h++) {
					for(int w=0; w < 10; w++) {
						if(mark[h][w] != 0) {	// ??????????
							continue;
						}
						if(check(h, w, cnt, num)) {	// h, w ??????????????
							flag = true;
							break LOOP;
						}
					}
				}
			}
			if(flag) {
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.