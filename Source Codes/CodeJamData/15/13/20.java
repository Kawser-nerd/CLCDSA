import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.Locale;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Andrey Rechitsky (arechitsky@gmail.com)
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
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    static double EPS = 1e-14;

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int []x = new int[n];
        int []y = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
        }

        out.printLine("Case #%d:",testNumber);
        for (int i = 0; i < n; i++) {
            Point[] points = new Point[2*n-2];
            for (int j = 0; j < n; j++) {
                if (i==j) continue;
                int j2 = j<i?j:j-1;
                points[2*j2] = new Point(x[i],y[i],x[j],y[j]);
                points[2*j2+1] = new Point(x[i],y[i],x[j],y[j]);
                points[2*j2+1].direction+=2* Math.PI;
            }
            Arrays.sort(points);
            int j2 = 0;
            int ans = n-1;
            for (int j1 = 0; j1 < n - 1; j1++) {
                while (points[j2].direction < points[j1].direction + Math.PI+EPS){
                    j2++;
                }
                ans = Math.min(ans, n-1-j2+j1);
            }
            out.printLine(ans);
        }
    }

    class Point implements Comparable<Point>{
        public int x, y;
        public double direction;

        public Point(int fx, int fy, int x, int y){
            this.x = x;
            this.y = y;
            direction = Math.atan2(y-fy,x-fx);
        }

        public int compareTo(Point o) {
            return Double.compare(direction, o.direction);
        }
    }
}

class FastScanner {

    private BufferedReader reader;
    private StringTokenizer st;

    public FastScanner(InputStream stream) {
        this.reader = new BufferedReader(new InputStreamReader(stream));
        this.st = new StringTokenizer("");
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public String next(){
        while (!st.hasMoreTokens()){
            st = new StringTokenizer(readLine());
        }
        return st.nextToken();
    }

    private String readLine() {
        try {
            String line = reader.readLine();
            if (line==null) throw new InputMismatchException();
            return line;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

}

class FastPrinter {
    private final PrintWriter writer;

    public FastPrinter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public void close() {
        writer.close();
    }

    public void printLine(long i) {
        writer.println(i);
    }

    public void printLine(String s) {
        writer.println(s);
    }

    public void printLine(String format, Object ... args) {
        printLine(String.format(format, args));
    }

}

