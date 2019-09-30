import java.io.InputStreamReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
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
			final String regex = "A-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("a.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[]a= in.nextIntArray(n);
        int ans1 = 0;
        int m = 0;
        for (int i = 0; i < n - 1; i++) {
            ans1 += a[i]>a[i+1]?a[i]-a[i+1]:0;
            m = Math.max(m, a[i]-a[i+1]);
        }
        int ans2 = 0;
        for (int i = 0; i < n - 1; i++) {
            ans2 += Math.min(a[i],m);
        }
        out.printLine("Case #%d: %d %d",testNumber, ans1, ans2);
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

    public int[] nextIntArray(int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
            array[i] = nextInt();
        return array;
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

    public void printLine(String s) {
        writer.println(s);
    }

    public void printLine(String format, Object ... args) {
        printLine(String.format(format, args));
    }

}

