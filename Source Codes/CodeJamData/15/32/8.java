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
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB extends GCJSolution {

  public void solve(int testNumber) {
    int K = in.nextInt();
    int L = in.nextInt();
    int S = in.nextInt();
    String keys = in.nextString();
    String target = in.nextString();

    double[] letterProb = new double[26];

    for (int i = 0; i < K; i++) {
      letterProb[keys.charAt(i) - 'A'] += 1.0 / K;
//      letterProb[keys.charAt(i) - 'A'] += 1.0;
    }
//    out.println(Arrays.toString(letterProb));

    double[][] map = new double[L + 1][L + 1];

    int[] pi = prefixFunction(target);
//    out.println(Arrays.toString(pi));

    int[] a = new int[L];
    for (int i = 0; i < L; i++) {
      a[i] = target.charAt(i) - 'A';
    }

    map[0][1] = letterProb[a[0]];
    map[0][0] = 1 - letterProb[a[0]];
//    map[0][0] = K - letterProb[a[0]];

    for (int i = 1; i < L; i++) {
      map[i][0] = 1;
//      map[i][0] = K;

      map[i][i + 1] = letterProb[a[i]];
      map[i][0] -= map[i][i + 1];

      if (a[pi[i - 1]] != a[i]) {
        map[i][pi[i - 1] + 1] = letterProb[a[pi[i - 1]]];
        map[i][0] -= map[i][pi[i - 1] + 1];
      }
    }

    for (int i = 0; i < L + 1; i++) {
      map[L][i] = map[pi[L - 1]][i];
    }

//    for (int i = 0; i < L + 1; i++) {
//      for (int j = 0; j < L + 1; j++) {
//        out.print(map[i][j] + " ");
//      }
//      out.println();
//    }

    double[] x = new double[L + 1];
    x[0] = 1;
    double avg = 0;
    for (int i = 0; i < S; i++) {
      double[] y = new double[L + 1];
      for (int j = 0; j < L + 1; j++) {
        for (int k = 0; k < L + 1; k++) {
          y[k] += map[j][k] * x[j];
        }
      }
      avg += y[L];
      x = y;
    }

    double max = 0;
    int t = 0;
    for (int i = 0; i < S; i++) {
      if (letterProb[a[t]] > 0) {
        t += 1;
      }
      if (t == L) {
        t = pi[L - 1];
        max += 1;
      }
    }

    out.println(max - avg);
  }

  int[] prefixFunction(String s) {
    int n = s.length();
    int[] pi = new int[n];
    for (int i = 1; i < n; i++) {
      int j = pi[i - 1];
      while (j > 0 && s.charAt(i) != s.charAt(j)) {
        j = pi[j - 1];
      }
      if (s.charAt(i) == s.charAt(j)) {
        j++;
      }
      pi[i] = j;
    }
    return pi;
  }

//  int getMaxPS(String a, String b)
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

