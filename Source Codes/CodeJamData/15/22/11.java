import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.math.BigDecimal;
import java.util.List;
import java.math.BigInteger;
import java.io.OutputStream;
import java.util.Collections;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.io.FileInputStream;
import java.util.Arrays;
import java.util.AbstractList;
import java.io.InputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.OutputStreamWriter;
import java.io.FileOutputStream;
import java.io.File;
import java.util.RandomAccess;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Jacob Jiang
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
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int r = in.nextInt();
        int c = in.nextInt();
        int n = in.nextInt();
        int[][] block = new int[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if ((i + j) % 2 == 0) {
                    block[i][j] = -1;
                }
            }
        }
        long answer1 = work(r, c, n, block);
        ArrayUtils.fill(block, 0);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if ((i + j) % 2 == 1) {
                    block[i][j] = -1;
                }
            }
        }
        long answer2 = work(r, c, n, block);
        out.println("Case #" + testNumber + ": " + Math.min(answer1, answer2));
    }

    private long work(int r, int c, int n, int[][] block) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (block[i][j] == -1) {
                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {
                            if ((di == 0) ^ (dj == 0)) {
                                int ni = i + di;
                                int nj = j + dj;
                                if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
                                    block[ni][nj]++;
                                }
                            }
                        }
                    }
                }
            }
        }
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (block[i][j] != -1) {
                    list.add(block[i][j]);
                } else {
                    list.add(0);
                }
            }
        }
        Collections.sort(list);
        long answer = 0;
        for (int i = 0; i < n; i++) {
            answer += list.get(i);
        }
        return answer;
    }
}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1 << 16];
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

    public int nextInt() {
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
            res += c & 15;
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public String next() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    public static boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

}

class OutputWriter {
    private PrintWriter writer;

    public OutputWriter(OutputStream stream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(stream)));
    }

    public void println(String x) {
        writer.println(x);
    }

    public void close() {
        writer.close();
    }

}

class ArrayUtils {


    public static void fill(int[][] array, int val) {
        for (int[] subArray : array) {
            Arrays.fill(subArray, val);
        }
    }


}

