import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.FileOutputStream;
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
			inputStream = new FileInputStream("A-large.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("A.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		A solver = new A();
		solver.solve(1, in, out);
		out.close();
	}
}

class A {
    class V {
        public V() {
            edges = new ArrayList<Integer>();
        }
        ArrayList<Integer> edges;
    }
	public void solve(int testNumber, InputReader in, OutputWriter out) {
        int cases = in.readInt();
        for(int C=1;C<=cases;C++) {
            boolean found = false;
            int N = in.readInt();
            V[] v = new V[N];
            for(int i=0;i<N;i++)v[i] = new V();
            for(int i=0;i<N;i++) {
                int many = in.readInt();
                for(int j=0;j<many;j++)v[i].edges.add(in.readInt()-1);
            }
            outer: for(int source=0;source<N;source++) {
                boolean[] visited = new boolean[N];
                visited[source] = true;
                int[] q = new int[N];
                q[0] = source;
                int h=0;
                int t=1;
                while(h<t) {
                    int now = q[h++];
                    for(int i=0;i<v[now].edges.size();i++) {
                        int next = v[now].edges.get(i);
                        if(visited[next]) {
                            found = true;
                            break outer;
                        }
                        else {
                            visited[next] = true;
                            q[t++]=next;
                        }
                    }
                }
            }
            out.printLine("Case #"+C+": "+(found?"Yes":"No"));
        }
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

