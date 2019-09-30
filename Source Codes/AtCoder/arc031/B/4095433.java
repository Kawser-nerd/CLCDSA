import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

public class Main {
	
//	public static Set<String> mem = new HashSet<String>();
//	public static boolean[] mem_1 = new boolean[100];
//	public static boolean[] mem_2 = new boolean[100];
//	public static Set<Integer> mem = new TreeSet<Integer>();
//	public static Map<String, Integer> mem_1= new HashMap<String, Integer>();
//	public static Map<String, Integer> mem_2 = new HashMap<String, Integer>();
	
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
//    	String[] a = new String[10];
    	boolean[][] c = new boolean[12][12];
    	boolean[][] c_org = new boolean[12][12];
    	
    	// ?????true ????
    	public void down(int y, int x) {	// 1 <= x, y <= 10
    		if(c[y][x] == false)	return;
			c[y][x] = false;
			if(c[y-1][x])	down(y-1, x);
			if(c[y][x-1])	down(y, x-1);
			if(c[y][x+1])	down(y, x+1);
			if(c[y+1][x])	down(y+1, x);
    	}
    	// ??????????????????????????
    	public boolean check() {
        	for(int i=1; i < 11; i++) {
            	for(int j=1; j < 11; j++) {
            		if(c[i][j])		return false;
            	}
        	}
        	return true;
    	}
    	// ??????
    	public void copy() {
    		for(int k=0; k < 10; k++) {
    			for(int l=0; l < 10; l++) {
    				c[k+1][l+1] = c_org[k+1][l+1]; 
    			}
    		}
    	}
    	
    	public void solve(int testNumber, MyInput in, PrintWriter out) {
        	boolean ans = false;
//        	char[] s = in.nextDChar();
        	String a = null;
        	for(int i=0; i < 10; i++) {
        		a = in.nextString();
//        		out.println(a);
        		for(int j=0; j < 10; j++) {
        			if(a.charAt(j) == 'o') {
        				c_org[i+1][j+1] = true;
        			}
        		}
        	}
        	LOOP:
        	for(int i=0; i < 10; i++) {
            	for(int j=0; j < 10; j++) {
            		copy();
            		if(!c[i+1][j+1]) {
            			c[i+1][j+1] = true;
            			down(i+1, j+1);
            			if(check()) {
            				ans = true;
            				break LOOP;
            			}
            		}
            	}
        	}
        	if(ans)		out.println("YES");
        	else		out.println("NO");
        }
    }
    // ======================================================================
    
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