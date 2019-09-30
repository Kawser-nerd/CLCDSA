import java.util.function.IntBinaryOperator;
import java.io.FileInputStream;
import java.util.Arrays;
import java.util.OptionalInt;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "C-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("c.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Reader in = new Reader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    int[][] multMap = {{0,0,0,0,0},
            {0,  1,  2,  3,  4},
            {0,  2, -1,  4, -3},
            {0,  3, -4, -1,  2},
            {0,  4,  3, -2, -1}};
    int mult(int a, int b) {
        int sign = a * b > 0 ? 1 : -1;
        return multMap[Math.abs(a)][Math.abs(b)] * sign;
    }
    int pow(int a, long b) {
        int ans = 1;
        int q = a;
        for (; b > 0; b /= 2) {
            if (b % 2 == 1) ans = mult(ans, q);
            q = mult(q, q);
        }
        return ans;
    }
    public void solve(int testNumber, Reader in, PrintWriter out) {
        int l = in.nextInt();
        long x = in.nextLong();
        String s = in.next();
        int[] a = new int[l];
        for (int i = 0; i < l; i++) {
            char c = s.charAt(i);
            switch (c) {
                case 'i': a[i] = 2; break;
                case 'j': a[i] = 3; break;
                case 'k': a[i] = 4; break;
            }
        }
        int ml = Arrays.stream(a).reduce(this::mult).getAsInt();
        int al = pow(ml, x);
        String ans = "NO";
        if (al == -1) {
            int ii = 0;
            int ir = a[0];
            while (ir != 2 && ii < x * l - 1 && ii < 4 * l) {
                ii++;
                ir = mult(ir, a[ii % l]);
            }
            long ki = x * l - 1;
            int kr = a[l - 1];
            while (kr != 4 && ki > 0 && ki >= x * l - 4 * l) {
                ki--;
                kr = mult(a[(int)(ki % l)], kr);
            }
            if (ir == 2 && kr == 4 && ii + 1 < ki) ans = "YES";
        }
        out.printf("Case #%d: %s\n", testNumber, ans);
    }
}

class Reader {
    private BufferedReader in;
    private StringTokenizer st;
    public Reader(InputStream is) {
        in = new BufferedReader(new InputStreamReader(is));
    }
    public String next() {
        try {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(in.readLine());
            }
            return st.nextToken();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    public int nextInt() {
        return Integer.parseInt(next());
    }
    public long nextLong() {
        return Long.parseLong(next());
    }

}

