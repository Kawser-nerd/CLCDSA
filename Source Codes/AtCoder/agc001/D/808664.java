import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.InputStream;
import java.util.List;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.util.Collections;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author ilyakor
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[m];
        int dec = 0;
        for (int i = 0; i < m; ++i) {
            a[i] = in.nextInt();
            dec += a[i] % 2;
        }
        dec += n % 2;
        if (dec > 2) {
            out.printLine("Impossible");
            return;
        }
        ArrayList<Integer> A = new ArrayList<>();
        ArrayList<Integer> B = new ArrayList<>();
        ArrayList<Integer> odds = new ArrayList<>();
        for (int x : a) {
            if (x % 2 == 0) {
                A.add(x);
                B.add(x);
            } else {
                odds.add(x);
            }
        }

        if (odds.size() > 0) {
            int x = odds.get(0);
            if (x > 1) B.add(x - 1);
            A.add(x);
        } else {
            int z = B.get(B.size() - 1);
            B.set(B.size() - 1, 1);
            if (z - 2 > 0) B.add(z - 2);
        }

        if (odds.size() > 1) {
            int x = odds.get(1);
            Collections.reverse(B);
            B.add(x + 1);
            Collections.reverse(B);
            Collections.reverse(A);
            A.add(x);
            Collections.reverse(A);
        } else {
            Collections.reverse(B);
            B.add(1);
            Collections.reverse(B);
        }
        for (int x : A)
            out.print(x + " ");
        out.printLine();
        out.printLine(B.size());
        for (int x : B)
            out.print(x + " ");
        out.printLine();
    }
}

class InputReader {
    private InputStream stream;
    private byte[] buffer = new byte[10000];
    private int cur;
    private int count;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public static boolean isSpace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public int read() {
        if (count == -1) {
            throw new InputMismatchException();
        }
        try {
            if (cur >= count) {
                cur = 0;
                count = stream.read(buffer);
                if (count <= 0)
                    return -1;
            }
        } catch (IOException e) {
            throw new InputMismatchException();
        }
        return buffer[cur++];
    }

    public int readSkipSpace() {
        int c;
        do {
            c = read();
        } while (isSpace(c));
        return c;
    }

    public int nextInt() {
        int sgn = 1;
        int c = readSkipSpace();
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res = res * 10 + c - '0';
            c = read();
        } while (!isSpace(c));
        res *= sgn;
        return res;
    }

}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0) {
                writer.print(' ');
            }
            writer.print(objects[i]);
        }
    }

    public void printLine(Object... objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }

}