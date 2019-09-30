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
import java.util.Arrays;
import java.io.InputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.OutputStreamWriter;
import java.io.PrintStream;
import java.util.Comparator;
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
            int count;
            int step;
            int[] sums;
            long answer;

            public void read(InputReader in) {
                count = in.readInt();
                step = in.readInt();
                sums = IOUtils.readIntArray(in, count - step + 1);
            }

            public void solve() {
                answer = 0;
                long[] start = new long[step];
                long[] delta = new long[step];
                for (int i = 0; i < step; i++) {
                    long current = 0;
                    long max = 0;
                    long min = 0;
                    for (int j = i; j + 1 < sums.length; j += step) {
                        current += sums[j + 1] - sums[j];
                        max = Math.max(max, current);
                        min = Math.min(min, current);
                    }
                    start[i] = -min;
                    delta[i] = max - min;
                }
                answer = ArrayUtils.maxElement(delta);
                long sum = -(sums[0] % step) + step;
                long freedom = 0;
                for (long i : start) {
                    sum += i;
                }
                for (long i : delta) {
                    freedom += answer - i;
                }
                if (sum % step != 0 && freedom + sum % step < step) {
                    answer++;
                }
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

class IOUtils {

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

}

class ArrayUtils {

	public static long maxElement(long[] array) {
		return array[maxPosition(array)];
	}

	public static int maxPosition(long[] array) {
		return maxPosition(array, 0, array.length);
	}

	public static int maxPosition(long[] array, int from, int to) {
		if (from >= to)
			return -1;
		long max = array[from];
		int result = from;
		for (int i = from + 1; i < to; i++) {
			if (array[i] > max) {
				max = array[i];
				result = i;
			}
		}
		return result;
	}

}

interface TaskFactory {
	public Task newTask();
}

