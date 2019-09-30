import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Iterator;
import java.util.Scanner;
public class C  extends AbstractCodeJamSolver {
	
	static final long M = 100003;
	CombinationNumberTableWithModular<Int64> comb = new CombinationNumberTableWithModular<Int64>(Int64.one, new Int64(M));
	
	long[][] table = new long[501][501];
	
	long gettable(int i, int j) {
		if(table[i][j] == -1) {
			long item;
			if(i==1) {
				item = 1;
			} else {
				item = 0;
				for(int k=1;k<=i-1;k++)
					if(j-i >= i-k)
						item = (item + comb.get(j-i-1, i-1-k).toPrimitive() * gettable(k, i)) % M;
			}				
			table[i][j] = item;
		}
		return table[i][j];
	}	
	
	public void solve() {
		int casen = in.nextInt();
		
		for(int i=0;i<=500;i++)
			for(int j=0;j<=500;j++)
				table[i][j] = -1;
		
		for(int casei=1;casei<=casen;casei++) {
			int n = in.nextInt();
			long tot = 0;
			for(int i=1;i<=n-1;i++)
				tot = (tot + gettable(i, n)) % M;
			out.println("Case #" + casei + ": " + tot);
		}		
	}
	
	
	
	static public void main(String[] args) throws IOException {
		new C().launch("C-small-attempt0.in");
	}
}
abstract class AbstractCodeJamSolver {
	
	protected Scanner in;
	protected PrintStream out = System.out;

	abstract public void solve(); 
	
	protected void print(Object o) {
		out.print(o);
	}
	
	protected void println() {
		out.println();
	}
	
	protected void println(Object o) {
		out.println(o);
	}
	
	protected void printf(String f, Object... o) {
		out.format(f, o);
	}


	final public void launch(String inputFileName) throws FileNotFoundException {
		in = new Scanner(new File(inputFileName));
		solve();
	}
}

class CombinationNumberTableWithModular<T extends Int<T>> {
	
	private DynamicArray<DynamicArray<T>> table;
	private T one;
	private T mod;
	
	public CombinationNumberTableWithModular(T one, T mod) {
		this.one = one;
		this.mod = mod;
		table = new DynamicArray<DynamicArray<T>>();
	}
	
	public T get(int a, int b) {
		if(b > a/2) 
			return get(a, a-b);
		
		reserveTable(a, b);
		
		T item = table.get(a).get(b);
		if(item != null)
			return item;
		
		item = calc(a, b);
		
		table.get(a).set(b, item);
		return item;
	}

	private T calc(int a, int b) {
		if(b==0 || a==b)
			return one;
		else
			return get(a-1,b-1).plus(get(a-1,b)).mod(mod);
	}

	private void reserveTable(int a, int b) {
		while(table.size() <= a)
			table.addToLast(new DynamicArray<T>());
		while(table.get(a).size() <= b)
			table.get(a).addToLast(null);
	}
}
class DynamicArray<T> extends AbstractReadableArray<T>  implements StaticArray<T> {
	
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
	
	public void addToLastAll(Iterable<T> values) {
		for(T v : values)
			addToLast(v);
	}
	
	public T removeLast() {
		T r = last();
		a[--asize] = null;
		return r;
	}
	
}
abstract class AbstractReadableArray<T> extends AbstractContainer<T> implements ReadableArray<T> {
	
	final public boolean isEmpty() {
		return size() == 0;
	}
	
	final public T last() {
		return get(size()-1);
	}
	
	final public T first() {
		return get(0);
	}	
	
	final public Iterator<T> iterator() {
		return new AbstractIterator<T>() {
			int p = 0;
			public boolean hasNext() {
				return p < size();
			}
			public T next() {
				return get(p++);
			}
		};
	}
	
	@SuppressWarnings("unchecked")
	final public boolean equals(Object obj) {
		if(obj == null)
			return false;
		if(!(obj instanceof ReadableArray))
			return false;
		ReadableArray<T> o = (ReadableArray<T>) obj;
		if(size() != o.size())
			return false;
		for(int i=0;i<size();i++)
			if(!get(i).equals(o.get(i)))
				return false;		
		return true;
	}
	
	final public int hashCode() {
		int r = 0;
		for(int i=0;i<size();i++)
			r += get(i).hashCode();
		return r;
	}
	
	
		
}
abstract class AbstractContainer<T> implements Container<T> {

	final public String toString() {
		StringBuffer sb = new StringBuffer();
		sb.append('(');
		boolean first = true;
		for(T v : this) {
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
interface Container<T> extends Iterable<T> {
	int size();
	boolean isEmpty();
}
abstract class AbstractIterator<T> implements Iterator<T> {

	final public void remove() {
		throw new UnsupportedOperationException();
	}

}
interface ReadableArray<T> extends Container<T> {
	T get(int index);
	T last();
	T first();
}
interface StaticArray<T> extends ReadableArray<T>{
	void set(int index, T value);	
}
interface Int<T extends Int<T>> extends Multiplicative<T> {
	T mod(T v);
	T floorDivide(T v);
}
interface Multiplicative<T extends Multiplicative<T>> extends Additive<T> {
	T times(T a);
	T getOne();
	T get(int v);
	boolean isOne();
}
interface Additive<T extends Additive<T>> extends Number<T> {
	T plus(T v);
	T minus(T v);
	T getAddInvert();
	T getZero();
	boolean isPositive();
	boolean isZero();
	boolean isNegative();
	int getSign();
}
interface Number<T> extends Comparable<T> {
}
class Int64 extends AbstractMultiplicative<Int64> implements Int<Int64> {
	
	private final long v;
	
	public Int64(long v) {
		this.v = v;
	}
	
	protected int hashCodeForAdditive() {
		return (int)v;
	}

	public Int64 plus(Int64 t) {
		return new Int64(v + t.v);
	}
	
	public Int64 minus(Int64 t) {
		return new Int64(v - t.v);
	}
	
	public long toPrimitive() {
		return v;
	}
	
	public Int64 getAddInvert() {
		return new Int64(-v);
	}
	
	public int compareTo(Int64 o) {
		if(v > o.v)
			return 1;
		else if(v < o.v)
			return -1;
		return 0;
	}
	
	public String toString() {
		return Long.toString(v);
	}
	
	public Int64 getZero() {
		return zero;
	}
	
	public Int64 getOne() {
		return one;
	}
	
	public Int64 times(Int64 a) {
		return new Int64(v * a.v);
	}	
	
	public Int64 floorDivide(Int64 o) {
		return new Int64(v / o.v);
	}
	
	public Int64 mod(Int64 o) {
		return new Int64(v % o.v);
	}		
	
	static final public Int64 zero = new Int64(0);
	static final public Int64 one = new Int64(1);
}
abstract class AbstractMultiplicative<T extends Multiplicative<T>> extends AbstractAdditive<T> implements Multiplicative<T> {

	final public boolean isOne() {
		return equals(getOne());
	}
	
	final public T get(int v) { // O(log) 로 속도 향상시키고 테스트 작성할 것.
		T r = getOne();
		for(int i=0;i<v-1;i++)
			r = r.plus(getOne());
		return r;
	}
}
abstract class AbstractAdditive<T extends Additive<T>> implements Additive<T> {
	
	@SuppressWarnings("unchecked")
	final public boolean equals(Object obj) {
		return compareTo((T)obj) == 0; 
	}
	
	final public int hashCode() {
		return hashCodeForAdditive();
	}
	
	abstract protected int hashCodeForAdditive();
	
	final public boolean isPositive() {
		return getSign() > 0;
	}
	final public boolean isNegative() {
		return getSign() < 0;
	}
	final public boolean isZero() {
		return getSign() == 0;
	}
	final public int getSign() {
		return compareTo(getZero());
	}
}
