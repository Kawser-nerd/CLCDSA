import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
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
	// ????? 2 <= N <= 100???????		1 <= M <= N *(N - 1) / 2???????
	//???????M ??????????	 ui, vi
	//
	// ????????????????
	// 
	// ?????????????????????????????????????
	//
    static class Solver {
		int N = 0;									// ???
		int M = 0;									// ???
		Map<Integer, List<Integer>> map = null;		// ???a --> ?b)
		Set<Integer> used = new HashSet<Integer>();	// ????????????

		// first ??????????????????????????
		int check(int first, int oya, PrintWriter out) {
//			out.println("start first = " + first);
			
			if(used.contains(first)) {				// ?????????????
//				out.println("????????????????");
				return 0;
			}
			used.add(first);						// ?????????
			
			List<Integer> list = map.get(first);
			if(list == null) {						// ???????1 ???
//				out.println("???????????????");
			    return 1;
			}
			int ans = 1;
			for(Integer next : list) {				// ???????????????
			    if(next != oya ) {               	// ??????
			    									// ????????????????
					ans = Math.min(ans, check(next, first, out));
			    }
			}
//			out.println("end  first = " + first + "  ans = " + ans);
			return ans;
    	}

    	public void solve(int testNumber, MyInput in, PrintWriter out) {
			int ans = 0;
			N = in.nextInt();
			M = in.nextInt();
			map = new HashMap<Integer, List<Integer>>();
			List<Integer> list = null;
			int u, v;
			for(int i=0; i < M; i++) {
				u = in.nextInt() - 1;
				v = in.nextInt() - 1;
				// u --> v
				list = map.get(u);
				if(list == null) {
					list = new ArrayList<Integer>();
					map.put(u, list);
				}
				list.add(v);
				// v --> u
				list = map.get(v);
				if(list == null) {
					list = new ArrayList<Integer>();
					map.put(v, list);
				}
				list.add(u);
			}

			for(int i=0; i < N; i++) {
				if(!used.contains(i)) {			// ?????????
					ans += check(i, -1, out);	// ??????????????????
//					out.println(" i = " + i + " --> ans = " + ans);
				}
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