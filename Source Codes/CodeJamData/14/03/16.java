import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("c.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("c.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		C solver = new C();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class C {

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int rows = in.nextInt();
        int cols = in.nextInt();
        int mines = in.nextInt();
        out.println("Case #" + testNumber + ":");
        char[][] answer = solveSmart(rows, cols, mines);
        if (answer == null) {
            out.println("Impossible");
        } else {
            for (char[] row : answer) {
                out.println(row);
            }
        }

    }

    char[][] solveSmart(int rows, int cols, int mines) {
        if (rows > cols) {
            char[][] ansT = solveSmart(cols, rows, mines);
            if (ansT == null) {
                return null;
            }
            char[][] ans = new char[rows][cols];
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    ans[i][j] = ansT[j][i];
                }
            }
            return ans;
        }
        int free = rows * cols - mines;
        if (free == 0) {
            throw new AssertionError();
        }
        if (free == 1) {
            char[][] res = new char[rows][cols];
            for (char[] c : res) {
                Arrays.fill(c, '*');
            }
            res[0][0] = 'c';
            return res;
        }
        if (rows == 1) {
            char[] res = new char[cols];
            Arrays.fill(res, '*');
            Arrays.fill(res, 0, free, '.');
            res[0] = 'c';
            return new char[][]{res};
        }
        if (rows == 2) {
            if ((free & 1) != 0 || free == 2) {
                return null;
            }
            char[][] res = new char[2][cols];
            for (char[] c : res) {
                Arrays.fill(c, 0, free / 2, '.');
                Arrays.fill(c, free / 2, cols, '*');
            }
            res[0][0] = 'c';
            return res;
        }
        if (free == 2 || free == 3 || free == 5 || free == 7) {
            return null;
        }
        char[][] res = new char[rows][cols];
        for (char[] c : res) {
            Arrays.fill(c, '*');
        }

        if (free == 4 || free == 6) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < free / 2; j++) {
                    res[i][j] = '.';
                }
            }
            res[0][0] = 'c';
            return res;
        }

        int ok;
        if (free >= 2 * rows + 2) {
            ok = rows;
        } else {
            ok = (free - 2) / 2;
        }

        for (int i = 0; i < ok; i++) {
            Arrays.fill(res[i], 0, free / ok, '.');
        }
        for (int i = 0; i < free % ok; i++) {
            res[i][free / ok] = '.';
        }
        if (free % ok == 1) {
            res[rows - 1][free / ok - 1] = '*';
            res[1][free / ok] = '.';
        }
        res[0][0] = 'c';
        return res;
    }

}

class InputReader {
    BufferedReader br;
    StringTokenizer st;

    public InputReader(InputStream stream) {
        br = new BufferedReader(new InputStreamReader(stream));
    }

    public String next() {
        return nextToken();
    }

    public String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            String line = null;
            try {
                line = br.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

}

