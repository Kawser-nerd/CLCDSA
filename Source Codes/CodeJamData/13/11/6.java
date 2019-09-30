import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
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
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		MyScanner in = new MyScanner(inputStream);
		MyPrintWriter out = new MyPrintWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    private MyScanner in;
    private MyPrintWriter out;
    private BigInteger TWO = BigInteger.valueOf(2);

    public void solve(int testNumber, MyScanner in, MyPrintWriter out) {
        this.in = in; this.out = out;
        if(testNumber == 1)prepare();
        out.printFormat("Case #%d: ", testNumber);
        System.err.println("case " + testNumber);
        solve();
    }

    private void prepare() {

    }

    private void solve(){
        BigInteger r = in.nextBigInteger(), t = in.nextBigInteger();
        BigInteger left = BigInteger.ONE, right = BigInteger.valueOf(Long.MAX_VALUE);
        do{
            BigInteger d = left.add(right).divide(TWO);
            BigInteger need = d.multiply(TWO.multiply(r).add(TWO.multiply(d)).subtract(BigInteger.ONE));
            if(need.compareTo(t) <= 0)left = d;
            else right = d;
        }while(right.subtract(left).compareTo(BigInteger.ONE) > 0);
        out.println(left);
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

    public void println(Object... os) {
        for (int i = 0; i < os.length - 1; i++) {
            out.print(os[i]);
            out.print(' ');
        }
        out.println(os[os.length - 1]);
    }

    public void close() {
        out.close();
    }

    public void printFormat(String format, Object... args) {
        out.printf(format,args);
    }

}

