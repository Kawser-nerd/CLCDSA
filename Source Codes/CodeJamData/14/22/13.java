import java.io.StreamTokenizer;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Locale;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.Reader;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "B-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("b.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		TokenizerReader in = new TokenizerReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(@SuppressWarnings("UnusedParameters") int testNumber, TokenizerReader in, PrintWriter out) {
        final int A = in.nextInt(), B = in.nextInt(), K = in.nextInt();
        //Random r = new Random(); int A = r.nextInt(1000),B = r.nextInt(1000), K = r.nextInt(1000);
        long res = solve(A, B, K);
        //if (res != solveSimple(A, B, K)) throw new RuntimeException();
        out.println("Case #" + testNumber + ": " + res);
    }

    private long solve(long A, long B, long K) {
        long res = 0;
        long x = 0;
        for (int k = 30; k >= 0; --k) if (k < 0 || (A & (1L << k)) > 0) {
            long y = 0;
            for (int l = 30; l >= 0; --l) if (l < 0 || (B & (1L << l)) > 0) {
                res += count(x, k, y, l, K);
                if (l >= 0)
                    y ^= (1L << l);
            }

            if (k >= 0)
                x ^= (1L << k);
        }
        return res;
    }

    private long count(long x, int k, long y, int l, long M) {
        if (k < l) {
            int tmp = k;
            k = l;
            l = tmp;
            long t = x;
            x = y;
            y = t;
        }
        long leftMask = 0;
        for (int i = k; i <= 30; ++i)
            leftMask ^= (1L << i);

        long xFixed = x & leftMask;
        long yFixed = y & leftMask;
        long mFixed = M & leftMask;
        if ((xFixed & yFixed) < mFixed)
            return 1L << (k + l);
        if ((xFixed & yFixed) > mFixed)
            return 0;

        long numSame = 1, numLess = 0;
        for (int i = k-1; i >= l; --i) {
            if ((M & (1L << i)) > 0) {
                if ((y & (1L << i)) > 0) {
                    numLess += (numSame << (i - l));
                } else {
                    numLess += (numSame << (i - l + 1));
                    numSame = 0;
                    break;
                }
            } else {
                if ((y & (1L << i)) > 0) {

                } else {
                    numSame *= 2;
                }
            }
        }

        return (numLess << (2*l)) + numSame * count(l, M);
    }

    private long count(int k, long M) {
        long numSame = 1, numLess = 0;
        for (int i = k-1; i >= 0; --i) {
            if ((M & (1L << i)) > 0) {
                numLess += (3 * numSame) << (2 * i);
            } else {
                numSame *= 3;
            }
        }
        return numLess;
    }

}

class TokenizerReader extends StreamTokenizer {
    public TokenizerReader(InputStream in) {
        super(new BufferedReader(new InputStreamReader(in)));
        defaultConfig();
    }

    public String nextString() {
        try {
            nextToken();
        } catch (IOException e) {
            throw new RuntimeException("nextString: exception in line " + lineno(), e);
        }
        return sval;
    }

    public String next() {
        return nextString();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public void defaultConfig() {
        resetSyntax();
        wordChars(33, 126);
        whitespaceChars(0, ' ');
    }

}

