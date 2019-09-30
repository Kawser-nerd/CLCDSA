import java.io.FileNotFoundException;
import java.util.Locale;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.File;
import java.io.Writer;
import java.io.FilenameFilter;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.FileReader;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.util.StringTokenizer;
import java.io.ByteArrayOutputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author abra
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
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA extends GCJSolution {

  public void solve(int testNumber) {
    int r = in.nextInt();
    int c = in.nextInt();
    int w = in.nextInt();

    int ans = 0;

    int perLine = c / w;
    ans += perLine * (r - 1);

    ans += perLine - 1;
    int x = c - (perLine - 1) * w;
    if (x == w) {
      ans += w;
    } else {
      ans += w + 1;
    }

    out.println(ans);
  }
}

abstract class GCJSolution extends SavingChelperSolution {

	public String processOutputPreCheck(int testNumber, String output) {
		return "Case #" + testNumber + ": " + output;
	}

	public String processOutputPostCheck(int testNumber, String output) {
		return output;
	}
}

class InputReader {

	BufferedReader br;
	StringTokenizer in;

  public InputReader(InputStream inputStream) {
		br = new BufferedReader(new InputStreamReader(inputStream));
	}

	boolean hasMoreTokens() {
		while (in == null || !in.hasMoreTokens()) {
			String s = nextLine();
			if (s == null) {
				return false;
			}
			in = new StringTokenizer(s);
		}
		return true;
	}

	public String nextString() {
		return hasMoreTokens() ? in.nextToken() : null;
	}

	public String nextLine() {
		try {
			in = null; // riad legacy
			return br.readLine();
		} catch (Exception e) {
			e.printStackTrace();
			return null;
		}
	}

	public int nextInt() {
		return Integer.parseInt(nextString());
	}

  public String next() {
		return nextString();
	}
}

abstract class SavingChelperSolution {

	protected int testNumber;

	public InputReader in;
	public OutputWriter out;

	private OutputWriter toFile;

	private boolean local = new File("chelper.properties").exists();

	public OutputWriter debug = local
			? new OutputWriter(System.out)
			: new OutputWriter(new OutputStream() {
				public void write(int b) {
				}
			});

	public SavingChelperSolution() {
		try {
			toFile = new OutputWriter("last_test_output.txt");
		} catch (FileNotFoundException e) {
			throw new RuntimeException(e);
		}
	}

	public abstract void solve(int testNumber);

	public abstract String processOutputPreCheck(int testNumber, String output);

	public abstract String processOutputPostCheck(int testNumber, String output);

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		this.testNumber = testNumber;

		ByteArrayOutputStream substituteOutContents = new ByteArrayOutputStream();
		OutputWriter substituteOut = new OutputWriter(substituteOutContents);

		this.in = in;
		this.out = substituteOut;

		solve(testNumber);
		substituteOut.flush();

		String result = substituteOutContents.toString();

		result = processOutputPreCheck(testNumber, result);
		out.print(result);
		out.flush();

		if (local) {
			debug.flush();

			result = processOutputPostCheck(testNumber, result);
			toFile.print(result);
			toFile.flush();
		}
	}

}

class OutputWriter extends PrintWriter {

  public OutputWriter(String fileName) throws FileNotFoundException {
		super(fileName);
	}

	public OutputWriter(OutputStream outputStream) {
		super(outputStream);
	}

}

