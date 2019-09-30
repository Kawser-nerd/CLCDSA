import java.io.InputStreamReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Locale;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.Reader;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "D-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("d.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskD solver = new TaskD();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int[][] ans = new int[7][7];
        for (int i = 0; i < answer.length; i++) {
            StringTokenizer tokenizer = new StringTokenizer(cases[i]);
            int a = Integer.parseInt(tokenizer.nextToken()), b = Integer.parseInt(tokenizer.nextToken());
            tokenizer = new StringTokenizer(answer[i]);
            tokenizer.nextToken();
            tokenizer.nextToken();
            ans[a][b] = Integer.parseInt(tokenizer.nextToken());
        }
        int a = in.readInt(), b = in.readInt();
        out.printf("Case #%d: %d\n", testNumber, ans[a][b]);
        }

    final String[] cases = {
            "2 3", 
            "2 4", 
            "2 5", 
            "2 6", 
            "3 3", 
            "3 4", 
            "3 5", 
            "3 6", 
            "4 3", 
            "4 4", 
            "4 5", 
            "4 6", 
            "5 3", 
            "5 4", 
            "5 5", 
            "5 6", 
            "6 3", 
            "6 4", 
            "6 5", 
            "6 6"};

    final String[] answer = {"Case #1: 2",
            "Case #2: 1",
            "Case #3: 1",
            "Case #4: 3",
            "Case #5: 2",
            "Case #6: 3",
            "Case #7: 2",
            "Case #8: 2",
            "Case #9: 3", 
            "Case #10: 1", 
            "Case #11: 1", 
            "Case #12: 5", 
            "Case #13: 3", 
            "Case #14: 3", 
            "Case #15: 1", 
            "Case #16: 5", 
            "Case #17: 6", 
            "Case #18: 4", 
            "Case #19: 2", 
            "Case #20: 19"};

    }

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(BufferedReader reader) {
        this.reader = reader;
    }

    public InputReader(Reader reader) {
        this(new BufferedReader(reader));
    }

    public InputReader(InputStream stream) {
        this(new InputStreamReader(stream));
    }

    private String nextLine() {
        String result;
        try {
            result = reader.readLine();
        } catch (IOException exception) {
            throw new RuntimeException(exception);
        }
        return result;
    }

    public String readWord() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(nextLine());
        }
        return tokenizer.nextToken();
    }

    public String next() {
        return readWord();
    }

    public int readInt() {
        return Integer.parseInt(readWord());
    }

}

class OutputWriter {
    private PrintWriter writer;

    public OutputWriter(PrintWriter writer) {
        this.writer = writer;
    }

    public OutputWriter(Writer writer) {
        this(new PrintWriter(writer));
    }

    public OutputWriter(OutputStream stream) {
        this(new OutputStreamWriter(stream));
    }

    public void printf(String format, Object...args) {
        writer.printf(format, args);
    }

    public void close() {
        writer.close();
    }
}

