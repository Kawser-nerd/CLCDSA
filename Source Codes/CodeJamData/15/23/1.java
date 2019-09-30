import java.io.BufferedWriter;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.Writer;
import java.io.IOException;
import java.io.InputStream;
import java.util.Collection;
import java.util.Locale;
import java.io.OutputStreamWriter;
import java.util.AbstractMap;
import java.util.Comparator;
import java.util.AbstractCollection;
import java.io.FileOutputStream;
import java.io.File;
import java.util.Set;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Random;
import java.io.FilenameFilter;
import java.util.Map;
import java.io.PrintStream;
import java.util.AbstractSet;

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
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        Scheduler scheduler = new Scheduler(in, out, () -> new Task() {
            int count;
            int[] at;
            int[] size;
            int[] start;

            long answer;

            public void read(InputReader in) {
                count = in.readInt();
                at = new int[count];
                size = new int[count];
                start = new int[count];
                IOUtils.readIntArrays(in, at, size, start);
            }

            public void solve() {
                answer = ArrayUtils.sumArray(size);
                Set<Long> finishTimes = new EHashSet<>();
                for (int i = 0; i < count; i++) {
                    for (int j = start[i]; j < start[i] + size[i]; j++) {
                        long weFinish = (360L - at[i]) * j;
                        finishTimes.add(weFinish);
                    }
                }
                long[] times = new long[finishTimes.size()];
                int ind = 0;
                for (long i : finishTimes) {
                    times[ind++] = i;
                }
                Arrays.sort(times);
                SumIntervalTree tree = new SumIntervalTree(times.length);
                for (int i = 0; i < count; i++) {
                    for (int j = start[i]; j < start[i] + size[i]; j++) {
                        long weFinish = (360L - at[i]) * j;
                        for (long current = weFinish + 360L * j; ; ) {
                            int at = Arrays.binarySearch(times, current);
                            if (at < 0) {
                                at = -at - 1;
                            }
                            if (at >= times.length) {
                                break;
                            }
                            if (tree.query(at, at) >= answer) {
                                break;
                            }
                            long here = (times[at] - current) / (360L * j) + 1;
                            tree.update(at, times.length - 1, here);
                            current += 360L * j * here;
                        }
                    }
                }
                for (int i = 0; i < count; i++) {
                    for (int j = start[i]; j < start[i] + size[i]; j++) {
                        long weFinish = (360L - at[i]) * j;
                        int at = Arrays.binarySearch(times, weFinish);
                        tree.update(0, at - 1, 1);
                    }
                }
                for (int i = 0; i < times.length; i++) {
                    answer = Math.min(answer, tree.query(i, i));
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

	public static void readIntArrays(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

}

class ArrayUtils {

	public static long sumArray(int[] array) {
		long result = 0;
		for (int element : array)
			result += element;
		return result;
	}

}

class EHashSet<E> extends AbstractSet<E> {
    private static final Object VALUE = new Object();
    private final Map<E, Object> map;

	public EHashSet() {
		this(4);
	}

	public EHashSet(int maxSize) {
		map = new EHashMap<E, Object>(maxSize);
	}

	public boolean contains(Object o) {
        return map.containsKey(o);
	}

	public boolean add(E e) {
		if (e == null)
			return false;
		return map.put(e, VALUE) == null;
	}

	public boolean remove(Object o) {
		if (o == null)
			return false;
		return map.remove(o) != null;
	}

	public void clear() {
        map.clear();
	}

	public Iterator<E> iterator() {
        return map.keySet().iterator();
	}

	public int size() {
		return map.size();
	}
}

class SumIntervalTree extends LongIntervalTree {
	private final long[] array;

    public SumIntervalTree(int size) {
        super(size);
		array = null;
    }

	protected long initValue(int index) {
		if (array == null) {
			return 0;
		}
		return array[index];
	}

	protected long joinValue(long left, long right) {
        return left + right;
    }

    protected long joinDelta(long was, long delta) {
        return was + delta;
    }

    protected long accumulate(long value, long delta, int length) {
        return value + delta * length;
    }

    protected long neutralValue() {
        return 0;
    }

    protected long neutralDelta() {
        return 0;
    }
}

abstract class IntervalTree {
	protected int size;

	public IntervalTree(int size, boolean shouldInit) {
		this.size = size;
		int nodeCount = Math.max(1, Integer.highestOneBit(size) << 2);
		initData(size, nodeCount);
		if (shouldInit)
			init();
	}

	protected abstract void initData(int size, int nodeCount);
	protected abstract void initAfter(int root, int left, int right, int middle);
	protected abstract void initBefore(int root, int left, int right, int middle);
	protected abstract void initLeaf(int root, int index);
	protected abstract void updatePostProcess(int root, int left, int right, int from, int to, long delta, int middle);
	protected abstract void updatePreProcess(int root, int left, int right, int from, int to, long delta, int middle);
	protected abstract void updateFull(int root, int left, int right, int from, int to, long delta);
	protected abstract long queryPostProcess(int root, int left, int right, int from, int to, int middle, long leftResult, long rightResult);
	protected abstract void queryPreProcess(int root, int left, int right, int from, int to, int middle);
	protected abstract long queryFull(int root, int left, int right, int from, int to);
	protected abstract long emptySegmentResult();

	public void init() {
		if (size == 0)
			return;
		init(0, 0, size - 1);
	}

	private void init(int root, int left, int right) {
		if (left == right) {
			initLeaf(root, left);
		} else {
			int middle = (left + right) >> 1;
			initBefore(root, left, right, middle);
			init(2 * root + 1, left, middle);
			init(2 * root + 2, middle + 1, right);
			initAfter(root, left, right, middle);
		}
	}

	public void update(int from, int to, long delta) {
		update(0, 0, size - 1, from, to, delta);
	}

	protected void update(int root, int left, int right, int from, int to, long delta) {
		if (left > to || right < from)
			return;
		if (left >= from && right <= to) {
			updateFull(root, left, right, from, to, delta);
			return;
		}
		int middle = (left + right) >> 1;
		updatePreProcess(root, left, right, from, to, delta, middle);
		update(2 * root + 1, left, middle, from, to, delta);
		update(2 * root + 2, middle + 1, right, from, to, delta);
		updatePostProcess(root, left, right, from, to, delta, middle);
	}

	public long query(int from, int to) {
		return query(0, 0, size - 1, from, to);
	}

	protected long query(int root, int left, int right, int from, int to) {
		if (left > to || right < from)
			return emptySegmentResult();
		if (left >= from && right <= to)
			return queryFull(root, left, right, from, to);
		int middle = (left + right) >> 1;
		queryPreProcess(root, left, right, from, to, middle);
		long leftResult = query(2 * root + 1, left, middle, from, to);
		long rightResult = query(2 * root + 2, middle + 1, right, from, to);
		return queryPostProcess(root, left, right, from, to, middle, leftResult, rightResult);
	}
}

interface TaskFactory {
	public Task newTask();
}

class EHashMap<E, V> extends AbstractMap<E, V> {
	private static final int[] shifts = new int[10];

	private int size;
	private HashEntry<E, V>[] data;
	private int capacity;
	private Set<Entry<E, V>> entrySet;

	static {
		Random random = new Random(System.currentTimeMillis());
		for (int i = 0; i < 10; i++)
			shifts[i] = 1 + 3 * i + random.nextInt(3);
	}

	private void setCapacity(int size) {
		capacity = Integer.highestOneBit(4 * size);
        data = new HashEntry[capacity];
	}

	public EHashMap(int maxSize) {
		setCapacity(maxSize);
		entrySet = new AbstractSet<Entry<E, V>>() {
			public Iterator<Entry<E, V>> iterator() {
				return new Iterator<Entry<E, V>>() {
					private HashEntry<E, V> last = null;
                    private HashEntry<E, V> current = null;
                    private HashEntry<E, V> base = null;
                    private int lastIndex = -1;
					private int index = -1;

					public boolean hasNext() {
                        if (current == null) {
                            for (index++; index < capacity; index++) {
                                if (data[index] != null) {
                                    base = current = data[index];
                                    break;
                                }
                            }
                        }
                        return current != null;
					}

					public Entry<E, V> next() {
						if (!hasNext())
							throw new NoSuchElementException();
                        last = current;
                        lastIndex = index;
                        current = current.next;
                        if (base.next != last)
                            base = base.next;
						return last;
					}

					public void remove() {
						if (last == null)
							throw new IllegalStateException();
                        size--;
                        if (base == last)
                            data[lastIndex] = last.next;
                        else
                            base.next = last.next;
					}
				};
			}

			public int size() {
				return size;
			}
		};
	}

	public Set<Entry<E, V>> entrySet() {
		return entrySet;
	}

	public void clear() {
		Arrays.fill(data, null);
		size = 0;
	}

	private int index(Object o) {
		return getHash(o.hashCode()) & (capacity - 1);
	}

	private int getHash(int h) {
		int result = h;
		for (int i : shifts)
			result ^= h >>> i;
		return result;
	}

	public V remove(Object o) {
		if (o == null)
			return null;
		int index = index(o);
        HashEntry<E, V> current = data[index];
        HashEntry<E, V> last = null;
        while (current != null) {
            if (current.key.equals(o)) {
                if (last == null)
                    data[index] = current.next;
                else
                    last.next = current.next;
                size--;
                return current.value;
            }
            last = current;
            current = current.next;
        }
        return null;
	}

	public V put(E e, V value) {
		if (e == null)
			return null;
		int index = index(e);
        HashEntry<E, V> current = data[index];
        if (current != null) {
            while (true) {
                if (current.key.equals(e)) {
                    V oldValue = current.value;
                    current.value = value;
                    return oldValue;
                }
                if (current.next == null)
                    break;
                current = current.next;
            }
        }
        if (current == null)
            data[index] = new HashEntry<E, V>(e, value);
        else
            current.next = new HashEntry<E, V>(e, value);
        size++;
        if (2 * size > capacity) {
            HashEntry<E, V>[] oldData = data;
            setCapacity(size);
            for (HashEntry<E, V> entry : oldData) {
                while (entry != null) {
                    HashEntry<E, V> next = entry.next;
                    index = index(entry.key);
                    entry.next = data[index];
                    data[index] = entry;
                    entry = next;
                }
            }
        }
		return null;
	}

	public V get(Object o) {
		if (o == null)
			return null;
		int index = index(o);
        HashEntry<E, V> current = data[index];
		while (current != null) {
			if (current.key.equals(o))
                return current.value;
            current = current.next;
        }
		return null;
	}

	public boolean containsKey(Object o) {
        if (o == null)
            return false;
        int index = index(o);
        HashEntry<E, V> current = data[index];
        while (current != null) {
            if (current.key.equals(o))
                return true;
            current = current.next;
        }
        return false;
	}

	public int size() {
		return size;
	}

	private static class HashEntry<E, V> implements Entry<E, V> {
		private final E key;
		private V value;
        private HashEntry<E, V> next;

        private HashEntry(E key, V value) {
            this.key = key;
            this.value = value;
        }


        public E getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }

        public V setValue(V value) {
            V oldValue = this.value;
            this.value = value;
            return oldValue;
        }
    }
}

abstract class LongIntervalTree extends IntervalTree {
    protected long[] value;
    protected long[] delta;

    protected LongIntervalTree(int size) {
        this(size, true);
    }

	public LongIntervalTree(int size, boolean shouldInit) {
		super(size, shouldInit);
	}

	protected void initData(int size, int nodeCount) {
		value = new long[nodeCount];
		delta = new long[nodeCount];
	}

	protected abstract long joinValue(long left, long right);
    protected abstract long joinDelta(long was, long delta);
    protected abstract long accumulate(long value, long delta, int length);
    protected abstract long neutralValue();
    protected abstract long neutralDelta();

    protected long initValue(int index) {
        return neutralValue();
    }

	protected void initAfter(int root, int left, int right, int middle) {
		value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
		delta[root] = neutralDelta();
	}

	protected void initBefore(int root, int left, int right, int middle) {
	}

	protected void initLeaf(int root, int index) {
		value[root] = initValue(index);
		delta[root] = neutralDelta();
	}

	protected void updatePostProcess(int root, int left, int right, int from, int to, long delta, int middle) {
		value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
	}

	protected void updatePreProcess(int root, int left, int right, int from, int to, long delta, int middle) {
		pushDown(root, left, middle, right);
	}

	protected void pushDown(int root, int left, int middle, int right) {
		value[2 * root + 1] = accumulate(value[2 * root + 1], delta[root], middle - left + 1);
		value[2 * root + 2] = accumulate(value[2 * root + 2], delta[root], right - middle);
		delta[2 * root + 1] = joinDelta(delta[2 * root + 1], delta[root]);
		delta[2 * root + 2] = joinDelta(delta[2 * root + 2], delta[root]);
		delta[root] = neutralDelta();
	}

	protected void updateFull(int root, int left, int right, int from, int to, long delta) {
		value[root] = accumulate(value[root], delta, right - left + 1);
		this.delta[root] = joinDelta(this.delta[root], delta);
	}

	protected long queryPostProcess(int root, int left, int right, int from, int to, int middle, long leftResult, long rightResult) {
		return joinValue(leftResult, rightResult);
	}

	protected void queryPreProcess(int root, int left, int right, int from, int to, int middle) {
		pushDown(root, left, middle, right);
	}

	protected long queryFull(int root, int left, int right, int from, int to) {
		return value[root];
	}

	protected long emptySegmentResult() {
		return neutralValue();
	}
}

