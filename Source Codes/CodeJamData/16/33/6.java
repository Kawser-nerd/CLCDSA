import java.util.ArrayList;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.FileInputStream;
import java.util.HashSet;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.io.BufferedReader;
import java.io.FilenameFilter;
import java.util.Map;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.File;
import java.util.Set;
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
    Map<Integer, Integer> pair = new HashMap<>();
    Set<Integer> trip = new HashSet<>();
    int k;

    boolean checkpair(int q) {
        if (!pair.containsKey(q)) pair.put(q, 0);
        if (pair.get(q) == k) return true;
        pair.put(q, pair.get(q) + 1);
        return false;
    }

    void print(PrintWriter out, int j, int p, int s) {
        out.println(j + " " + p + " " + s);
        if (trip.contains(j * 10000 + p * 100 + s)) out.println("TRIP BAD");
        trip.add(j * 10000 + p * 100 + s);
        if (checkpair(j * 10000 + p * 100)) out.println("PAIR BAD");
        if (checkpair(j * 10000 + s)) out.println("PAIR BAD");
        if (checkpair(p * 100 + s)) out.println("PAIR BAD");
    }

    public void solve(int testNumber, Reader in, PrintWriter out) {
        pair.clear(); trip.clear();
        int j = in.nextInt();
        int p = in.nextInt();
        int s = in.nextInt();
        k = in.nextInt();
        out.printf("Case #%d: %d\n", testNumber, j * p * Math.min(s, k));
        for (int kk = 1; kk <= Math.min(k, s); kk++) {
            for (int jj = 1; jj <= j; jj++) {
                for (int pp = 1; pp <= p; pp++) {
                    print(out, jj, pp, ((kk + jj + pp - 3) % s + 1));
                }
            }
        }
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

}

