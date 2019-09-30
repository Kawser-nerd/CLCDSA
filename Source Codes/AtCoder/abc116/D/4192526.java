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
    	
		List<Pair<Integer, Integer>> lP = new ArrayList<Pair<Integer, Integer>>();
		List<Pair<Integer, Integer>> lAns = new ArrayList<Pair<Integer, Integer>>();

    	public void solve(int testNumber, MyInput in, PrintWriter out) {
    		long ans = 0L;
    		int N = in.nextInt();
    		int K = in.nextInt();
    		int t, d;
    		for(int i=0; i < N; i++) {
    			t = in.nextInt();
    			d = in.nextInt();
    			lP.add(new Pair(new Integer(t), new Integer(d)));
    		}
    		// ?????????????
    		lP.sort(comparing(Pair::getValue, reverseOrder()));
//     		for(Pair<Integer, Integer> p : lP) {
//     		    out.println(p.getString());
//     		}

    		int i = 0;
    		// ??????????????
    		Map<Integer, Integer> mapK = new HashMap<Integer, Integer>();
    		// ??????????????????
    		Map<Integer, Pair<Integer, Integer>> mapZan = new LinkedHashMap<Integer, Pair<Integer, Integer>>();
    		Integer iWk = null;
    		for(Pair<Integer, Integer> p : lP) {
    			if(i < K) {
    				lAns.add(p);			// ?????????
    				if(mapK.containsKey(p.getKey())) {
    					iWk = mapK.get(p.getKey());
    					mapK.replace(p.getKey(), iWk + 1);
    				} else {
    					mapK.put(p.getKey(), new Integer(1));
    				}
    			} else {
    				if(!mapK.containsKey(p.getKey()) && !mapZan.containsKey(p.getKey())) {
    				    mapZan.put(p.getKey(), p);
    				}
    			}
				i++;
    		}
    		
    		// ?????????????????????????????????
    		PriorityQueue<Integer> Q = new PriorityQueue<Integer>(Comparator.reverseOrder());
			Pair<Integer, Integer> wk = null;
    		for(Integer key : mapZan.keySet()) {
    			wk = mapZan.get(key);
    			Q.add(wk.getValue());
    		}
    		
    		// ???
    		long sum = 0L;
    		Set<Integer> kind = new HashSet<Integer>();
    		for(Pair<Integer, Integer> p : lAns) {
    			sum += p.getValue();
    			kind.add(p.getKey());
//        		out.println("  " + p.getString());
    		}
//    		out.println(" total[" + sum + "]  kind[" + kind.size() + "]");
    		long k = kind.size();
    		ans = sum + (k * k);

    		// ????????????????????
			int cnt = 0;
			long ansW = 0L;
			for(int j = lAns.size() - 1; j >= 0; j--) {
				cnt = mapK.get(lAns.get(j).getKey());
				// ???????????
				if(cnt == 1)	continue;
				sum -= lAns.get(j).getValue();
				if(!Q.isEmpty()) {
					sum += Q.poll();
					k++;
					ans = Math.max(sum + (k * k), ans);
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