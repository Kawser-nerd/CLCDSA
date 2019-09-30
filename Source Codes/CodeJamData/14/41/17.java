import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A implements Runnable {
	public static void main(String[] args) {
		new Thread(new A()).run();
	}

	BufferedReader br;
	StringTokenizer in;
	PrintWriter out;

	public String nextToken() throws IOException {
		while (in == null || !in.hasMoreTokens()) {
			in = new StringTokenizer(br.readLine());
		}

		return in.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

    public class File  implements Comparable<File> {
        int x, id;

        public File(int x, int id) {
            this.x = x;
            this.id = id;
        }

        public int compareTo(File f) {
            return x == f.x ? id - f.id : x - f.x;
        }
    }

	public void solve() throws IOException {
        int n = nextInt();
        int x = nextInt();

        TreeSet<File> ts = new TreeSet<File>();
        File[] s = new File[n];
        for (int i = 0; i < n; i++) {
            s[i] = new File(nextInt(), i);
            ts.add(s[i]);
        }

        Arrays.sort(s);

        int c = 0;
        for (int i =0; i < n; i++) {
            if (!ts.contains(s[i])) {
                continue;
            }

            ts.remove(s[i]);

            File f = ts.floor(new File(x - s[i].x, n));
            if (f != null) {
                ts.remove(f);
            }
            c++;
        }

        out.println(c);
	}

	public void run() {
		try {
			br = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");

			int t = nextInt();
			for (int i = 0; i < t; i++) {
				out.print("Case #" + (i + 1) + ": ");
				solve();
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}
