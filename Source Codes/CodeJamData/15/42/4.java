import java.io.Reader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Comparator;
import java.io.Writer;
import java.io.IOException;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		KiddiePool solver = new KiddiePool();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class KiddiePool {

    static class WaterSource {
        int rate;
        int temp;

        public WaterSource(int rate, int temp) {
            this.rate = rate;
            this.temp = temp;
        }
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        System.err.println(testNumber);
        int n = in.nextInt();
        long V = Math.round(in.nextDouble() * 1e4);
        long X = Math.round(in.nextDouble() * 1e4) * V;
        int[] rate = new int[n];
        int[] temp = new int[n];
        boolean less = false;
        boolean greater = false;
        for (int i = 0; i < n; i++) {
            rate[i] = (int) Math.round(in.nextDouble() * 1e4);
            temp[i] = (int) Math.round(in.nextDouble() * 1e4);
            if (temp[i] * V <= X) less = true;
            if (temp[i] * V >= X) greater = true;
        }
        out.print("Case #" + testNumber + ": ");
        if (!less || !greater) {
            out.println("IMPOSSIBLE");
            return;
        }
        WaterSource[] w = new WaterSource[n];
        double sumRate = 0;
        for (int i = 0; i < n; i++) {
            sumRate += rate[i];
            w[i] = new WaterSource(rate[i], temp[i]);
        }
        Arrays.sort(w, new Comparator<WaterSource>() {
            public int compare(WaterSource o1, WaterSource o2) {
                return Integer.compare(o1.temp, o2.temp);
            }
        });
        double l = V / sumRate;
        double r = 1e10;
        for (int it = 0; it < 120; it++) {
            double mid = (l + r) * .5;
            if (l == mid || r == mid) break;
            double[] canGet = new double[n];
            for (int i = 0; i < n; i++) {
                canGet[i] = mid * w[i].rate;
            }
            double toGet = V;
            double tempMin = 0;
            for (int i = 0; i < n; i++) {
                double curGet = Math.min(toGet, canGet[i]);
                toGet -= curGet;
                tempMin += curGet * w[i].temp;
            }
            double tempMax = 0;
            toGet = V;
            for (int i = n - 1; i >= 0; i--) {
                double curGet = Math.min(toGet, canGet[i]);
                toGet -= curGet;
                tempMax += curGet * w[i].temp;
            }
//            System.out.println(tempMin + " " + tempMax);
            if (tempMin <= X && X <= tempMax){
                r = mid;
            } else {
                l = mid;
            }
        }
        out.println((l + r) * .5);
    }
}

class FastScanner extends BufferedReader {

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c < 0) {
            return null;
        }
        while (c >= 0 && !isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
    }

    public int nextInt() {
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int ret = 0;
        while (c >= 0 && !isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public String readLine() {
        try {
            return super.readLine();
        } catch (IOException e) {
            return null;
        }
    }

}

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }


}

