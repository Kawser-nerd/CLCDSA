import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Set;
import java.util.Iterator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.StringTokenizer;
import java.util.HashSet;
import java.util.Collection;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("a.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("a.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		A solver = new A();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class A {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int row1 = in.nextInt() - 1;
        int[][] grid1 = new int[4][4];
        readIt(in, grid1);
        int row2 = in.nextInt() - 1;
        int[][] grid2 = new int[4][4];
        readIt(in, grid2);
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();
        for (int i: grid1[row1]) {
            set1.add(i);
        }
        for (int i: grid2[row2]) {
            set2.add(i);
        }
        set1.retainAll(set2);
        out.print("Case #"+testNumber+": ");
        if (set1.size() == 0) {
            out.println("Volunteer cheated!");
        } else if (set1.size() > 1){
            out.println("Bad magician!");
        } else {
            out.println(set1.iterator().next());
        }
    }

    private void readIt(InputReader in, int[][] grid1) {
        for (int i = 0; i < grid1.length; i++) {
            for (int j = 0; j < grid1[i].length; j++) {
                grid1[i][j] = in.nextInt();
            }
        }
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

