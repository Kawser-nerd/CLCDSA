import java.util.List;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.NoSuchElementException;
import java.io.Writer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author ogiekako
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("taskc.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("taskc.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		MyScanner in = new MyScanner(inputStream);
		MyPrintWriter out = new MyPrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    static BigInteger[] answer;

    static {
        List<BigInteger> list = new ArrayList<BigInteger>();
        for (int n = 1; n <= 50; n++) {
            char[] cs = new char[n];
            if (n % 2 == 0) make(cs, 0, 0, list);
            else {
                for (int d = 0; d <= 3; d++) {
                    cs[n / 2] = (char) ('0' + d);
                    make(cs, 0, d * d, list);
                }
            }
        }
        answer = new BigInteger[list.size()];
        for (int i = 0; i < answer.length; i++){
            answer[i] = list.get(i).multiply(list.get(i));
        }
        Arrays.sort(answer);
    }

    private static void make(char[] cs, int i, int sum, List<BigInteger> list) {
        if (sum >= 10) return;
        int n = cs.length;
        int j = n - 1 - i;
        if (!(i < j)) {
            list.add(new BigInteger(String.valueOf(cs)));
        } else {
            for (int d = 0; d <= 2; d++) {
                if (d == 0 && i == 0) continue;
                cs[i] = cs[j] = (char) ('0' + d);
                make(cs, i + 1, sum + d * d * 2, list);
            }
        }
    }

    public void solve(int testNumber, MyScanner in, MyPrintWriter out) {
        BigInteger A = in.nextBigInteger(), B = in.nextBigInteger();
        int res = solve(B.add(BigInteger.ONE)) - solve(A);
        out.printFormat("Case #%d: %d\n", testNumber, res);
    }

    private int solve(BigInteger A) {
        int p = Arrays.binarySearch(answer, A);
        if (p >= 0) return p;
        else return -p - 1;
    }
}

class MyScanner {
    private final InputStream in;

    public MyScanner(InputStream in) {
        this.in = in;
    }

    int bufLen;
    int bufPtr;
    byte[] buf = new byte[1024];

    public int read() {
        if (bufLen == -1)
            throw new InputMismatchException();
        if (bufPtr >= bufLen) {
            bufPtr = 0;
            try {
                bufLen = in.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (bufLen <= 0)
                return -1;
        }
        return buf[bufPtr++];
    }

    private char[] strBuf = new char[65536];

    public String next() {
        int strLen = 0;
        int c;
        do {
            c = read();
            if (c == -1) throw new NoSuchElementException();
        } while (Character.isWhitespace(c));
        do {
            if (strLen + 1 >= strBuf.length) {
                char[] tmp = new char[strBuf.length * 2];
                System.arraycopy(strBuf, 0, tmp, 0, strBuf.length);
                strBuf = tmp;
            }
            strBuf[strLen++] = (char) c;
            c = read();
        } while (c != -1 && !Character.isWhitespace(c));
        return new String(strBuf, 0, strLen);
    }


    public BigInteger nextBigInteger() {
        return new BigInteger(next());
    }

    }

class MyPrintWriter {
    PrintWriter out;

    public MyPrintWriter(OutputStream outputStream) {
        out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public MyPrintWriter(Writer writer) {
        out = new PrintWriter(writer);
    }

    public void close() {
        out.close();
    }

    public void printFormat(String format, Object... args) {
        out.printf(format,args);
    }

}

