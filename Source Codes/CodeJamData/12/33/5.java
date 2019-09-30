import java.util.Map;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.TreeMap;
import java.util.ArrayList;
import java.io.PrintStream;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.Writer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("C-large.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("C.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		C solver = new C();
		solver.solve(1, in, out);
		out.close();
	}
}

class C {
    void debug(Object...os) { 
    // BEGIN CUT HERE
        System.out.println(Arrays.deepToString(os)); 
    // END CUT HERE
    }
    ArrayList<Pair<Long,Long>> A;
    ArrayList<Pair<Long,Long>> B;
    Map<Pair<Pair<Long,Long>,Pair<Long,Long>>,Long> dp;
    long solve(long a1, long am, long b1, long bm) {
        boolean changeA = false;
        boolean changeB = false;
        if(am==0) {
            a1++;
            changeA = true;
        }
        if(bm==0){
            b1++;
            changeB = true;
        }
        if(a1>=A.size() || b1>=B.size())return 0;
        if(changeA)am = A.get((int)a1).first;
        if(changeB)bm = B.get((int)b1).first;
        Pair<Pair<Long,Long>,Pair<Long,Long>> key = Pair.makePair(Pair.makePair(a1,am),Pair.makePair(b1,bm));
        Long entry = dp.get(key);
        if(entry==null) {
            long res = 0;
            long aType = A.get((int)a1).second;
            long bType = B.get((int)b1).second;
            if(aType == bType) {
                long many = Math.min(am,bm);
                res = many + solve(a1, am-many, b1, bm-many);
            }
            else {
                res = solve(a1,0,b1,bm);
                res = Math.max(res,solve(a1,am,b1,0));
            }
            entry = res;
            dp.put(key,entry);
        }
        return entry;
    }
    
	public void solve(int testNumber, InputReader in, OutputWriter out) {
        int cases = in.readInt();
        for(int C=1;C<=cases;C++) {
            debug("solve",C);
            dp = new TreeMap<Pair<Pair<Long, Long>, Pair<Long, Long>>, Long>();
            A = new ArrayList<Pair<Long, Long>>();
            B = new ArrayList<Pair<Long, Long>>();
            int N = in.readInt();
            int M = in.readInt();
            for(int i=0;i<N;i++) {
                A.add(Pair.makePair(in.readLong(),in.readLong()));
            }
            for(int i=0;i<M;i++) {
                B.add(Pair.makePair(in.readLong(), in.readLong()));
            }
            long res = solve(-1,0,-1,0);
            out.printLine("Case #"+C+": "+res);
        }
	}
}

class Pair<U, V> implements Comparable<Pair<U, V>> {
    public final U first;
    public final V second;
    public static<U, V> Pair<U, V> makePair(U first, V second) {
        return new Pair<U, V>(first, second);
    }
    private Pair(U first, V second) {
        this.first = first;
        this.second = second;
    }
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Pair pair = (Pair) o;
        return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);
    }
    public int hashCode() {
        int result = first != null ? first.hashCode() : 0;
        result = 31 * result + (second != null ? second.hashCode() : 0);
        return result;
    }
    public String toString() {
        return "(" + first + "," + second + ")";
    }
    public int compareTo(Pair<U, V> o) {
        int value = ((Comparable<U>)first).compareTo(o.first);
        if (value != 0)
            return value;
        return ((Comparable<V>)second).compareTo(o.second);
    }
}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public int readInt() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public long readLong() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public static boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    }

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(outputStream);
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void print(Object...objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(objects[i]);
        }
    }

    public void printLine(Object...objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }

}

