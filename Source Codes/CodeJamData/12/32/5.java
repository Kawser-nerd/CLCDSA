import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
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
			inputStream = new FileInputStream("B-small-attempt1.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("B.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		B solver = new B();
		solver.solve(1, in, out);
		out.close();
	}
}

class B {
    double[] dp;
    double[] X;
    double[] T;
    int N;
    double A;
    double D;
    final double EPS = 1e-9;
	public void solve(int testNumber, InputReader in, OutputWriter out) {
        int cases = in.readInt();
        for(int C=1;C<=cases;C++) {
            D = in.readDouble();
            N = in.readInt()+1;
            dp = new double[N];
            X = new double[N];
            T = new double[N];
            X[0]=T[0] = 0;
            int AN = in.readInt();
            double[] AS = new double[AN];
            for(int i=0;i<N-1;i++) {
                T[i+1] = in.readDouble();
                X[i+1] = in.readDouble();
            }
            for(int i=0;i<AN;i++)AS[i] = in.readDouble();
            if(Math.abs(X[N-1]-D)>EPS) {
                double delta = (D-X[N-2])/(X[N-1]-X[N-2]);
                double nx = X[N-2]+(X[N-1]-X[N-2])*delta;
                double nt = T[N-2]+(T[N-1]-T[N-2])*delta;
                X[N-1]=nx;
                T[N-1]=nt;
            }
            double res = 0;
            out.printLine("Case #"+C+":");
            for(int a=0;a<AN;a++) {
                A = AS[a];
                double ttime = Math.sqrt(2*D/A);

                double left = 0.0;
                double right = 1e20;
                for(int i=0;i<500;i++) {
                    double mid = (left+right)/2;
                    boolean ok = true;
                    for(int j=0;j<N;j++) {
                        double tempTime = Math.sqrt(2*X[j]/A);
                        if(tempTime+mid<T[j]) {
                            ok=false;
                            break;
                        }
                    }
                    if(ok) {
                        right = mid;
                    }
                    else left = mid;
                }
                res = left+ttime;
                //debug(left);
                out.printLine(left+ttime);
            }
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

    public double readDouble() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (!isSpaceChar(c) && c != '.') {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        }
        if (c == '.') {
            c = read();
            double m = 1;
            while (!isSpaceChar(c)) {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                m /= 10;
                res += (c - '0') * m;
                c = read();
            }
        }
        return res * sgn;
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

