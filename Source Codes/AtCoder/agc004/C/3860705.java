import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.Reader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
*/public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		MyInput in = new MyInput(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		CANDGrid solver = new CANDGrid();
		solver.solve(1, in, out);
		out.close();
	}
static class CANDGrid   {
public void solve(int testNumber, MyInput in, PrintWriter out) {

        int h = in.nextInt(), w = in.nextInt();
        char[][] s = new char[h][w];
        for (int i = 0; i < h; i++) {
            s[i] = in.nextChars();
        }

        char[][] b = new char[h][w], r = new char[h][w];
        fill(b, '.');
        fill(r, '.');

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < (i % 2 == 0 ? w-1 : 1); j++) {
                b[i][j] = '#';
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = w-1; j >= (i % 2 == 0 ? w-1 : 1); j--) {
                r[i][j] = '#';
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (s[i][j] == '#') {
                    b[i][j] = '#';
                    r[i][j] = '#';
                }
            }
        }

        print(r, out);
        out.print("\n");
        print(b, out);

    }

void print(char[][] s, PrintWriter out) {
        for (int i = 0; i < s.length; i++) {
            for (int j = 0; j < s[0].length; j++) {
                out.print(s[i][j]);
            }
            out.print("\n");
        }
        out.print("\n");
    }

static void fill(char[][] a, char v) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                a[i][j] = v;
            }
        }
    }

}
static class MyInput   {
private   final BufferedReader in;
private   static int pos;
private   static int readLen;
private   static   final char[] buffer = new char[1024 * 8];
private   static char[] str = new char[500 * 8 * 2];
private   static boolean[] isDigit = new boolean[256];
private   static boolean[] isSpace = new boolean[256];
private   static boolean[] isLineSep = new boolean[256];
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
        for (; i < len; i++)
            ret = ret * 10 + str[i] - '0';
        if (str[0] == '-') {
            ret = -ret;
        }
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

public char[] nextChars() {
        int len = 0;
        str[len++] = nextChar();
        len = reads(len, isSpace);
        return Arrays.copyOf(str, len);
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

static class EndOfFileRuntimeException extends RuntimeException  {
}

}
}