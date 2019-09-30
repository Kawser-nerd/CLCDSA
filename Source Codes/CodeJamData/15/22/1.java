import java.io.BufferedWriter;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.OutputStreamWriter;
import java.io.PrintStream;
import java.io.FileOutputStream;
import java.io.File;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Egor Kulikov (egor@egork.net)
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
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        Scheduler scheduler = new Scheduler(in, out, () -> new Task() {
            int rowCount;
            int columnCount;
            int count;

            int answer;

            public void read(InputReader in) {
                rowCount = in.readInt();
                columnCount = in.readInt();
                count = in.readInt();
            }

            public void solve() {
                if (2 * count <= rowCount * columnCount + 1) {
                    answer = 0;
                    return;
                }
                answer = rowCount * (columnCount - 1) + columnCount * (rowCount - 1);
                int free = rowCount * columnCount - count;
                if (rowCount == 1 || columnCount == 1) {
                    answer -= free * 2;
                    return;
                }
                if (2 * count == rowCount * columnCount + 3) {
                    answer = 3;
                    return;
                }
                int times4 = ((rowCount - 2) * (columnCount - 2) + 1) / 2;
                answer -= Math.min(times4, free) * 4;
                free -= Math.min(times4, free);
                int times3 = ((rowCount - 2) / 2 + (columnCount - 2) / 2) * 2;
                if (rowCount % 2 + columnCount % 2 == 1) {
                    times3++;
                }
                answer -= Math.min(times3, free) * 3;
                free -= Math.min(times3, free);
                answer -= free * 2;
            }

            public void write(OutputWriter out, int testNumber) {
                out.printLine("Case #" + testNumber + ":", answer);
            }
        }, 4);
    }
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	public int readInt() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}

}

class Scheduler {
	private final AtomicInteger testsRemaining;
	private final AtomicInteger threadsRemaining;

	public Scheduler(InputReader in, OutputWriter out, TaskFactory factory, int numParallel) {
		try {
			testsRemaining = new AtomicInteger(in.readInt());
			threadsRemaining = new AtomicInteger(numParallel);
			Task[] tasks = new Task[testsRemaining.get()];
			for (int i = 0; i < tasks.length; i++) {
				tasks[i] = factory.newTask();
			}
			for (Task task : tasks) {
				task.read(in);
				new Thread(() -> {
					boolean freeThread = false;
					synchronized (this) {
						do {
							try {
								wait(10);
							} catch (InterruptedException ignored) {
							}
							if (threadsRemaining.get() != 0) {
								synchronized (threadsRemaining) {
									if (threadsRemaining.get() != 0) {
										threadsRemaining.decrementAndGet();
										freeThread = true;
									}
								}
							}
						} while (!freeThread);
					}
					task.solve();
					System.err.println(testsRemaining.decrementAndGet());
					threadsRemaining.incrementAndGet();
				}).start();
			}
			synchronized (this) {
				while (testsRemaining.get() > 0) {
					wait(10);
				}
			}
			for (int i = 0; i < tasks.length; i++) {
				tasks[i].write(out, i + 1);
			}
		} catch (InterruptedException e) {
			throw new RuntimeException(e);
		}
	}
}

interface Task {
	public void read(InputReader in);
	public void solve();
	public void write(OutputWriter out, int testNumber);
}

interface TaskFactory {
	public Task newTask();
}

