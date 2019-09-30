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
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    int b;
    long []m;
    long n;
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        b = in.nextInt();
        n = in.nextLong();
        m = in.nextLongArray(b);
        long l = 0;
        long r = n*100000;
        while (r-l>1){
            long med = l + (r-l)/2;
            if (check(med,n)){
                r = med;
            }
            else{
                l = med;
            }
        }
        if (check(l,n)) r = l;
        r--;
        int ans = -1;
        long count = n-1-calcs(r);
        for (int i = 0; i < b; i++) {
            if (r%m[i]==0) {
                if (count==0){
                    ans = i;
                    break;
                }
                else count--;
            }
        }
        if (ans==-1) throw new RuntimeException();
        out.printLine("Case #%d: %d", testNumber, ans+1);
    }

    boolean check(long t, long n){
        return calcs(t)>=n;
    }

    long calcs(long t){
        long c=0;
        for (int i = 0; i < b; i++) {
            c+=(t+m[i]-1)/m[i];
        }
        return c;
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

    public long nextLong() {
        return Long.parseLong(next());
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

    public long[] nextLongArray(int size) {
        long[] array = new long[size];
        for (int i = 0; i < size; i++)
            array[i] = nextLong();
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

