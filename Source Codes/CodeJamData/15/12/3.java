import java.io.InputStreamReader;
import java.io.IOException;
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
			inputStream = new FileInputStream("taskb.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("taskb.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int barbers = in.nextInt();
        int place = in.nextInt();
        int[] time = new int[barbers];
        for (int i = 0; i < barbers; i++) {
            time[i] = in.nextInt();
        }
        long left = -1, right = (long) time[0] * place + 1;
        while (right - left > 1) {
            long mid = left + right >> 1;
            long men = menWhoStartedByThisTime(time, mid);
            if (men < place) {
                left = mid;
            } else {
                right = mid;
            }
        }

        long ourPosition = place - menWhoStartedByThisTime(time, left);
        for (int id = 0; id < barbers; id++) {
            if (right % time[id] == 0 && --ourPosition == 0) {
                out.println("Case #" + testNumber + ": " + (id + 1));
                return;
            }
        }
        throw new AssertionError();
    }

    private long menWhoStartedByThisTime(int[] barbers, long time) {
        long men = 0;
        for (int barberTime : barbers) {
            men += time / barberTime + 1;
        }
        return men;
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

