import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class C implements CodeJamStyleOneCaseSolver{
	
	private static final JavaHashMapFactory MF = new JavaHashMapFactory();
	private static final JavaHashSetFactory SF = new JavaHashSetFactory();
	int r, n, m, k;
	int[][] q= new int[8000][12];
	
	public void input(Scanner in) {
		r = in.nextInt();
		n = in.nextInt();
		m = in.nextInt();
		k = in.nextInt();
		for(int i : Range.get(r))
			for(int j : Range.get(k))
				q[i][j] = in.nextInt();
	}
	
	
	Map<DynamicArray<Integer>, Set<Integer>> map = MF.create();
	
	public void fill(DynamicArray<Integer> cards) {
		if(cards.size() == n) {
			DynamicArray<Integer> c = DynamicArray.create();
			c.addToLastAll(cards);
			Set<Integer> set = SF.create();
			for(int i=0;i<(1<<n);i++) {
				int p = 1;
				for(int j : Range.get(m))
					if(BitUtil.isSet(i, j))
						p *= c.get(j);
				set.insert(p);
			}
			map.put(c, set);
		} else {
			for(int i=2;i<=m;i++) {
				if(cards.isEmpty() || ReadableArrayUtil.getLast(cards) <= i) {
					cards.addToLast(i);
					fill(cards);
					cards.removeLast();
				}
			}
		}
	}
	
	public String solve() {
		DynamicArray<Integer> cards = DynamicArray.create();
		fill(cards);
		String res = "";		
		for(int i : Range.get(r)) {
			DynamicArray<Integer> r = null;
			for(Entry<DynamicArray<Integer>, Set<Integer>> e : map) {
				boolean ok = true;
				for(int j : Range.get(k)) {
					int p = q[i][j];
//					System.out.println(p);
					if(!e.getValue().contains(p))
						ok = false;
				}
				
//				System.out.println(e.getKey() + " " + e.getValue() + " " + ok);
				if(ok) {
					r = e.getKey();
				}
			}
			res += "\n";
			for(int v : r) {
				res += v;
			}
		}
		return res;
	}

	public static void main(String[] args) throws Exception {
		CodeJamProblemSolverLauncher.launch(1, "C-example.in", new CodeJamStyleOneCaseSolverFactory() {
			public CodeJamStyleOneCaseSolver createSolver() {
				return new C();
			}
		});
	}

}

class BitUtil {

	static public boolean isSet(int v, int pos) {
		return (v & 1<<pos) != 0;
	}

	static public int set(int v, int p) {
		return v | (1<<p);
	}

	static public int toggle(int v, int p) {
		if(isSet(v, p))
			return v - (1<<p);
		else
			return v + (1<<p);
	}

}

class CodeJamProblemSolverLauncher {

	public static void launch(int threadNumber, String inputFileNameOnDesktop, CodeJamStyleOneCaseSolverFactory factory, Integer... caseNumbers) throws Exception {
		String outputFileNameOnDesktop = inputFileNameOnDesktop.substring(0, inputFileNameOnDesktop.length()-3) + ".out";
		String desktopDir = System.getProperty("user.home") + "/Desktop";
		String inputFile = desktopDir + "/" + inputFileNameOnDesktop;
		String outputFile = desktopDir + "/" + outputFileNameOnDesktop;
		CodeJamStyleProblemSolverLauncher.launch(threadNumber, inputFile, outputFile, factory, caseNumbers);
	}

}

interface CodeJamStyleOneCaseSolverFactory {
	CodeJamStyleOneCaseSolver createSolver();
}

interface CodeJamStyleOneCaseSolver {
	void input(Scanner in);
	String solve();
}

class CodeJamStyleProblemSolverLauncher {
	
	public static void launch(final int threadNumber, String inputFilePath, String outputFilePath, final CodeJamStyleOneCaseSolverFactory factory, Integer... caseIndices) throws Exception {
		final Object lock = new Object();
		final long startTime = System.currentTimeMillis();
		final Scanner in = new Scanner(new File(inputFilePath));
		final int casen = in.nextInt();
		final int[] nextIndex = {0}; 
		final String[] results = new String[casen];
		final java.util.Set<Integer> caseIndexToSolve = createCaseIndicesToSolve(casen, caseIndices);
		ExecutorService executor = Executors.newFixedThreadPool(threadNumber);
		for(int i=0;i<casen;i++) {
			executor.execute(new Runnable() {
				public void run() {
					int casei;
					String result = null;
					{
						CodeJamStyleOneCaseSolver caseSolver = factory.createSolver();
						synchronized(lock) {
							caseSolver.input(in);
							casei = nextIndex[0]++;
						}
						if(caseIndexToSolve.contains(casei+1))
							result = caseSolver.solve();
					}
					if(result != null) {
						synchronized(lock) {
							results[casei] = result;
							int solved = countNotNull(results);
							outputProgess(startTime, solved, caseIndexToSolve.size());
						}
					}
				}
			});
		}
		executor.shutdown();
		executor.awaitTermination(Long.MAX_VALUE, TimeUnit.SECONDS);
		printLine();
		outputResult(results, outputFilePath);
		printLine();
		System.out.println("Output is written to " + outputFilePath);
	}

	private static java.util.Set<Integer> createCaseIndicesToSolve(int casen, Integer... caseIndices) {
		final java.util.Set<Integer> set = new java.util.TreeSet<Integer>();
		if(caseIndices.length == 0) {
			for(int i=1;i<=casen;i++)
				set.add(i);
		} else {
			for(int v : caseIndices) {
				if(v < 1 || v > casen)
					throw new RuntimeException("invalid case index : " + v);
				set.add(v);
			}
		}
		return set;
	}

	private static void printLine() {
		for(int i=0;i<100;i++)
			System.out.print("-");
		System.out.println();
	}

	private static int countNotNull(final String[] results) {
		int solved = 0;
		for(String s : results)
			if(s != null)
				solved++;
		return solved;
	}

	private static void outputProgess(long startTime, int solved, int caseNumberToSolve) {
		long duration = System.currentTimeMillis() - startTime;
		long estimation = (long)Math.round((double)duration * caseNumberToSolve / solved / 1000);
		System.out.printf("%.03fs : %d/%d solved (estimated : %dm %ds)\n", (double)duration / 1000, solved,  caseNumberToSolve, estimation / 60, estimation % 60);
	}

	private static void outputResult(final String[] results, String outputFilePath) throws FileNotFoundException {
		PrintStream ps = new PrintStream(outputFilePath);
		for(int i=0;i<results.length;i++) {
			if(results[i] != null) {
				String line = String.format("Case #%d: %s", i+1, results[i]);
				System.out.println(line);
				ps.println(line);
			}
		}
		ps.close();
	}

}

class Range {

	public static Iterable<Integer> get(int len) {
		return IntSequenceIterable.create(0, 1, len);
	}

	public static Iterable<Integer> get(int from, int size) {
		return IntSequenceIterable.create(from, 1, size);
	}

}

class IntSequenceIterable {
	public static Iterable<Integer> create(final int from, final int step, final int size) {
		return new Iterable<Integer>() {
			public Iterator<Integer> iterator() {
				return new AbstractIterator<Integer>() {
					int nextIndex = 0;
					public boolean hasNext() {
						return nextIndex < size;
					}
					public Integer next() {
						return from + step * (nextIndex++);
					}
				};
			}
		};
	}
}

abstract class AbstractIterator<T> implements Iterator<T> {
	public final void remove() {
		throw new UnsupportedOperationException();
	}
}

class DynamicArray<T> implements StaticArray<T> {
	
	public static <T> DynamicArray<T> create() {
		return new DynamicArray<T>();
	}
	
	private T[] a;
	private int asize;
	
	
	@SuppressWarnings("unchecked")
	private void init(int cap) {
		asize = 0;
		a = (T[])new Object[Math.max(1, cap)];		
	}
	
	public DynamicArray() {
		init(1);
	}
	
	public DynamicArray(int initialCapacity) {
		init(initialCapacity);
	}
	
	public T get(int index) {
		return a[index];
	}	
	
	public void set(int index, T value) {
		a[index] = value;		
	}
	
	public int size() {
		return asize;
	}
	
	public void clear() {
		asize = 0;
	}
	
	@SuppressWarnings("unchecked")
	public void reserve(int size) {
		if(a.length < size) {
			T[] ta = (T[])new Object[size];
			for(int i=0;i<a.length;i++)
				ta[i] = a[i];
			a = ta;
		}
	}
	
	@SuppressWarnings("unchecked")
	public void addToLast(T value) {
		if(a.length == asize) {
			T[] ta = (T[])new Object[asize*2];
			for(int i=0;i<asize;i++)
				ta[i] = a[i];
			a =ta;
		}
		a[asize++] = value;						
	}
	
	public void addToLastAll(Iterable<? extends T> values) {
		for(T v : values)
			addToLast(v);
	}
	
	public T removeLast() {
		T r = ReadableArrayUtil.getLast(this);
		a[--asize] = null;
		return r;
	}
	
	public boolean equals(Object obj) {
		return StrictEqualityChecker.isEquals(this, obj, new EqualityChecker<DynamicArray<T>>() {
			public boolean isEquals(DynamicArray<T> o1, DynamicArray<T> o2) {
				if(o1.size() != o2.size())
					return false;
				for(int i=0;i<o1.size();i++)
					if(!o1.get(i).equals(o2.get(i)))
						return false;		
				return true;
			}
		});
	}

	public int hashCode() {
		int r = 0;
		for(int i=0;i<size();i++)
			r ^= Int32Hash.hash(get(i).hashCode());
		return r;
	}

	public final boolean isEmpty() {
		return size() == 0;
	}

	public final Iterator<T> iterator() {
		return ReadableArrayIterator.create(this);
	}

	public final String toString() {
		return IterableUtil.toString(this);
	}
	
}

interface EqualityChecker<T> {
	boolean isEquals(T o1, T o2);
}

class Int32Hash {
	public static int hash(int key) {
		key = ~key + (key << 15); // key = (key << 15) - key - 1;
		key = key ^ (key >>> 12);
		key = key + (key << 2);
		key = key ^ (key >>> 4);
		key = key * 2057; // key = (key + (key << 3)) + (key << 11);
		key = key ^ (key >>> 16);
		return key;
	}
}

class IterableUtil {
	public static <T> String toString(Iterable<T> iterable) {
		StringBuilder sb = new StringBuilder();
		sb.append('(');
		boolean first = true;
		for(T v : iterable) {
			if(first)
				first = false;
			else
				sb.append(',');
			sb.append(v);
		}
		sb.append(')');
		return sb.toString();
	}
}

class StrictEqualityChecker {
	@SuppressWarnings("unchecked")
	public static <T> boolean isEquals(T me, Object you, EqualityChecker<T> ec) {
		if(me == you)
			return true;
		if(you == null)
			return false;
		if(you.getClass() != me.getClass())
			return false;
		return ec.isEquals(me, (T)you);
	}
}

class ReadableArrayIterator {
	public static <T> Iterator<T> create(final ReadableArray<T> a) {
		return new AbstractIterator<T>() {
			int p = 0;
			public boolean hasNext() {
				return p < a.size();
			}
			public T next() {
				return a.get(p++);
			}
		};
	}
}

interface ReadableArray<T> extends Container<T> {
	T get(int index);
}

interface Container<T> extends Iterable<T> {
	int size();
	boolean isEmpty();
}

class ReadableArrayUtil {

	public static <T> T getLast(ReadableArray<T> a) {
		return a.get(a.size()-1);
	}

	public static <T> T getFirst(ReadableArray<T> a) {
		return a.get(0);
	}

}

interface StaticArray<T> extends ReadableArray<T>{ // TODO 이름이 이상하다 그냥 Array로 바꾸자.
	void set(int index, T value);	
}

interface Entry<K, V> {
	K getKey();
	V getValue();
	void setValue(V v);
}

class JavaHashMapFactory implements MapFactory {

	public <K, V> Map<K, V> create() {
		return new MapWrapperForJavaMap<K, V>(new HashMap<K, V>());
	}
	
}

interface Map<K, V> extends Container<Entry<K, V>> {
	void clear(); 
	void put(K key, V value);
	void remove(K key);
	boolean containsKey(K key);
	V get(K key);
	Iterable<V> values();
	Iterable<K> keys();
}

interface MapFactory {
	<K,V> Map<K,V> create();
}

class MapWrapperForJavaMap<K, V> implements Map<K, V> {
	
	private final java.util.Map<K,V> map;
	
	public MapWrapperForJavaMap(java.util.Map<K,V> map) {
		this.map = map;				
	}

	public boolean containsKey(K key) {
		return map.containsKey(key);
	}

	public V get(K key) {
		return map.get(key);
	}

	public Iterable<K> keys() {
		return map.keySet();
	}

	public void put(K key, V value) {
		map.put(key, value);
	}

	public Iterable<V> values() {
		return map.values();
	}

	public void clear() {
		map.clear();
	}

	public boolean isEmpty() {
		return map.isEmpty();
	}

	public Iterator<Entry<K, V>> iterator() {
		return ConvertedDataIterator.create(map.entrySet().iterator(), new DataConverter<java.util.Map.Entry<K,V>, Entry<K,V>>() {
			public Entry<K, V> convert(java.util.Map.Entry<K, V> e) {
				return new EntryWrapper<K, V>(e);
			}
		});
	}

	public int size() {
		return map.size();
	}
	
	public void remove(K key) {
		map.remove(key);
	}
	
	public String toString() {
		return map.toString();
	}
	
	private static class EntryWrapper<K, V> implements Entry<K, V>, EqualityChecker<EntryWrapper<K,V>> {
		private java.util.Map.Entry<K, V> e;
		private EntryWrapper(java.util.Map.Entry<K, V> e) {
			this.e = e;
		}
		public K getKey() {
			return e.getKey();
		}
		public V getValue() { 
			return e.getValue();
		}
		public void setValue(V v) {
			e.setValue(v);						
		}
		public boolean equals(Object obj) {
			return StrictEqualityChecker.isEquals(this, obj, this);
		}
		public boolean isEquals(EntryWrapper<K, V> o1, EntryWrapper<K, V> o2) {
			return o1.getKey().equals(o2.getKey()) && o1.getValue().equals(o2.getValue());
		}
		public int hashCode() {
			return PairHash.hash(getKey().hashCode(), getValue().hashCode());
		}
	}

}

class ConvertedDataIterator {
	public static <T1, T2> Iterator<T2> create(final Iterator<T1> outerIterator, final DataConverter<T1, T2> extractor) {
		return new AbstractIterator<T2>() {
			public boolean hasNext() {
				return outerIterator.hasNext();
			}
			public T2 next() {
				return extractor.convert(outerIterator.next());
			}
		};
	}
}

interface DataConverter<T1, T2> {
	T2 convert(T1 v);
}

class PairHash {
	public static int hash(int h1, int h2) {
		return Int64Hash.hash6432shift((((long) h1) << 32) | h2);
	}
}

class Int64Hash {
	public static int hash6432shift(long key) { 
		// from http://www.concentric.net/~ttwang/tech/inthash.htm
		key = (~key) + (key << 18); // key = (key << 18) - key - 1;
		key = key ^ (key >>> 31);
		key = key * 21; // key = (key + (key << 2)) + (key << 4);
		key = key ^ (key >>> 11);
		key = key + (key << 6);
		key = key ^ (key >>> 22);
		return (int) key;
	}
}

class JavaHashSetFactory implements SetFactory {

	public <T> Set<T> create() {
		return new SetWrapper<T>(new HashSet<T>());
	}
	
}

interface Set<T> extends Container<T> {
	void clear();
	void insert(T v);
	void insertAll(Iterable<T> a);
	boolean contains(T v);
	void remove(T v);
}

interface SetFactory { // TODO SetFactory 와 ComparableSetFactory로 분리하기.
	<T> Set<T> create();
}

class SetWrapper<T> extends AbstractSet<T> {
	
	private final java.util.Set<T> set;
	
	public SetWrapper(java.util.Set<T> set) {
		this.set = set;
	}
	public void clear() {
		set.clear();		
	}
	
	public boolean contains(T v) {
		return set.contains(v);		
	}
	
	public void insert(T v) {
		set.add(v);
	}

	public Iterator<T> iterator() {
		return set.iterator();
	}
	
	public int size() {
		return set.size();
	}
	
	public void remove(T v) {
		set.remove(v);
	}
}

abstract class AbstractSet<T> implements Set<T> {

	final public void insertAll(Iterable<T> a) {
		for(T v : a)
			insert(v);
	}
	
	final public boolean isEmpty() {
		return size() == 0;
	}
	
	final public String toString() {
		Set<T> set = this;
		String r = "";
		for(T v : set) {
			if(!r.isEmpty())
				r += ",";
			r += v;			
		}
		return "{" + r + "}";
	}

}
