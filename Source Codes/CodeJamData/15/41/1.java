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
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        Scheduler scheduler = new Scheduler(in, out, () -> new Task() {
            int rowCount;
            int columnCount;
            char[][] grid;
            int answer;

            public void read(InputReader in) {
                rowCount = in.readInt();
                columnCount = in.readInt();
                grid = IOUtils.readTable(in, rowCount, columnCount);
            }

            public void solve() {
                answer = 0;
                for (int i = 0; i < rowCount; i++) {
                    for (int j = 0; j < columnCount; j++) {
                        if (grid[i][j] == '.') {
                            continue;
                        }
                        int mask = 15;
                        for (int k = 0; k < i; k++) {
                            if (grid[k][j] != '.') {
                                mask &= 14;
                            }
                        }
                        for (int k = i + 1; k < rowCount; k++) {
                            if (grid[k][j] != '.') {
                                mask &= 13;
                            }
                        }
                        for (int k = 0; k < j; k++) {
                            if (grid[i][k] != '.') {
                                mask &= 11;
                            }
                        }
                        for (int k = j + 1; k < columnCount; k++) {
                            if (grid[i][k] != '.') {
                                mask &= 7;
                            }
                        }
                        if (mask == 15) {
                            answer = -1;
                            return;
                        }
                        if (grid[i][j] == '^') {
                            answer += mask & 1;
                        } else if (grid[i][j] == 'v') {
                            answer += (mask >> 1) & 1;
                        } else if (grid[i][j] == '<') {
                            answer += (mask >> 2) & 1;
                        } else {
                            answer += (mask >> 3) & 1;
                        }
                    }
                }
            }

            public void write(OutputWriter out, int testNumber) {
                if (answer >= 0) {
                    out.printLine("Case #" + testNumber + ":", answer);
                } else {
                    out.printLine("Case #" + testNumber + ": IMPOSSIBLE");
                }
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

	public char readCharacter() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		return (char) c;
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

class IOUtils {

	public static char[] readCharArray(InputReader in, int size) {
		char[] array = new char[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readCharacter();
		return array;
	}

	public static char[][] readTable(InputReader in, int rowCount, int columnCount) {
		char[][] table = new char[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readCharArray(in, columnCount);
		return table;
	}

}

interface TaskFactory {
	public Task newTask();
}

