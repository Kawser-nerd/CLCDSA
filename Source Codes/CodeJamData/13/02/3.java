import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
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
			inputStream = new FileInputStream("taskb.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("taskb.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		MyScanner in = new MyScanner(inputStream);
		MyPrintWriter out = new MyPrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, MyScanner in, MyPrintWriter out) {
        int h = in.nextInt(), w = in.nextInt();
        int[][] map = new int[h][w];
        for(int i=0;i<h;i++)for(int j=0;j<w;j++)map[i][j] = in.nextInt();
        boolean res = true;
        for(int i=0;i<h;i++)for(int j=0;j<w;j++){
            boolean ok = true;
            for(int k=0;k<h;k++)if(map[k][j] > map[i][j])ok = false;
            boolean ok2 = true;
            for(int k=0;k<w;k++)if(map[i][k] > map[i][j])ok2 = false;
            if(!ok && !ok2)res = false;
        }
        out.printFormat("Case #%d: %s\n",testNumber, res?"YES":"NO");
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

    public int nextInt() {
        int c = read();
        if (c == -1) throw new NoSuchElementException();
        while (c != '-' && (c < '0' || '9' < c)) {
            c = read();
            if (c == -1) throw new NoSuchElementException();
        }
        if (c == '-') return -nextInt();
        int res = 0;
        do {
            res *= 10;
            res += c - '0';
            c = read();
        } while ('0' <= c && c <= '9');
        return res;
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

