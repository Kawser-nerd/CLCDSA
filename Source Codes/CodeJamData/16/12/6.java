import java.util.*;
import java.io.*;
import java.awt.Point;
import java.math.BigDecimal;
import java.math.BigInteger;

import static java.lang.Math.*;


public class B implements Runnable{
	
	final static Random rnd = new Random();
	
	// SOLUTION!!! 
	// HACK ME PLEASE IF YOU CAN!!!
	// PLEASE!!!
	// PLEASE!!!
	// PLEASE!!!
	
	static final int MAX_HEIGHT = 2500;
	
	void solve() {
		int n = readInt();
		int[] heightCounts = new int[MAX_HEIGHT + 1];
		for (int listIndex = 0; listIndex < 2 * n - 1; ++listIndex) {
			int[] heightsList = readIntArray(n);
			for (int height : heightsList) {
				++heightCounts[height];
			}
		}
		
		List<Integer> missedList = new ArrayList<Integer>();
		for (int height = 0; height <= MAX_HEIGHT; ++height) {
			if (heightCounts[height] % 2 == 1) {
				missedList.add(height);
			}
		}
		
		if (missedList.size() != n) {
			throw new RuntimeException();
		}
		
		for (int height : missedList) {
			out.print(height + " ");
		}
		out.println();
	}
	
	/////////////////////////////////////////////////////////////////////
	
	final boolean FIRST_INPUT_STRING = false;
	final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
	
	final static int MAX_STACK_SIZE = 128;
	
	/////////////////////////////////////////////////////////////////////
	
	public void run(){
		try{
			timeBegin = System.currentTimeMillis();
			Locale.setDefault(Locale.US);
			
			init();
			
			if (ONLINE_JUDGE) {
				solve();
			} else {
				int tests = readInt();
				for (int test = 1; test <= tests; ++test) {
					out.print("Case #" + test + ": ");
					solve();
				}
			}
			
			out.close();
			time();
		}catch (Exception e){
			e.printStackTrace(System.err);
			System.exit(-1);
		}
	}
	
	/////////////////////////////////////////////////////////////////////
	
	BufferedReader in;
	OutputWriter out;
	StringTokenizer tok = new StringTokenizer("");
	
	public static void main(String[] args){
		new Thread(null, new B(), "", MAX_STACK_SIZE * (1L << 20)).start();
	}
	
	/////////////////////////////////////////////////////////////////////
	
	void init() throws FileNotFoundException{
		Locale.setDefault(Locale.US);
		
		if (ONLINE_JUDGE){
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new OutputWriter(System.out);
		}else{
			in = new BufferedReader(new FileReader("input.txt"));
			out = new OutputWriter("output.txt");
		}
	}
	
	////////////////////////////////////////////////////////////////
	
	long timeBegin, timeEnd;

	void time(){
		timeEnd = System.currentTimeMillis();
		System.err.println("Time = " + (timeEnd - timeBegin));
	}
	
	void debug(Object... objects){
		if (ONLINE_JUDGE){
			for (Object o: objects){
				System.err.println(o.toString());
			}
		}
	}
	
	/////////////////////////////////////////////////////////////////////
	
	String delim = " ";
	
	String readLine() {
		try {
			return in.readLine();
		} catch (IOException e) {
			throw new RuntimeIOException(e);
		}
	}
	
	String readString() {
		try {
			while(!tok.hasMoreTokens()){
				tok = new StringTokenizer(readLine());
			}
			
			return tok.nextToken(delim);
		} catch (NullPointerException e) {
			return null;
		}
	}
	
	/////////////////////////////////////////////////////////////////
	
	final char NOT_A_SYMBOL = '\0';
	
	char readChar() {
		try {
			int intValue = in.read();
			
			if (intValue == -1){
				return NOT_A_SYMBOL;
			}
			
			return (char) intValue;
		} catch (IOException e) {
			throw new RuntimeIOException(e);
		}
	}
	
	char[] readCharArray() {
		return readLine().toCharArray();
	}
	
	char[][] readCharField(int rowsCount) {
		char[][] field = new char[rowsCount][];
		for (int row = 0; row < rowsCount; ++row) {
			field[row] = readCharArray();
		}
		
		return field;
	}
	
	/////////////////////////////////////////////////////////////////
	
	int readInt() {
		return Integer.parseInt(readString());
	}
	
	int[] readIntArray(int size) {
		int[] array = new int[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readInt();
		}
		
		return array;
	}
	
	int[] readSortedIntArray(int size) {
		Integer[] array = new Integer[size];
		
		for (int index = 0; index < size; ++index) {
			array[index] = readInt();
		}
		Arrays.sort(array);
		
		int[] sortedArray = new int[size];
		for (int index = 0; index < size; ++index) {
			sortedArray[index] = array[index];
		}
		
		return sortedArray;
	}
	
	int[] readIntArrayWithDecrease(int size) {
		int[] array = readIntArray(size);
		
		for (int i = 0; i < size; ++i) {
			array[i]--;
		}
		
		return array;
	}
	
	///////////////////////////////////////////////////////////////////
	
	int[][] readIntMatrix(int rowsCount, int columnsCount) {
		int[][] matrix = new int[rowsCount][];
		
		for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
			matrix[rowIndex] = readIntArray(columnsCount);
		}
		
		return matrix;
	}
	
	int[][] readIntMatrixWithDecrease(int rowsCount, int columnsCount) {
		int[][] matrix = new int[rowsCount][];
		
		for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
			matrix[rowIndex] = readIntArrayWithDecrease(columnsCount);
		}
		
		return matrix;
	}
	
	///////////////////////////////////////////////////////////////////
	
	long readLong() {
		return Long.parseLong(readString());
	}
	
	long[] readLongArray(int size) {
		long[] array = new long[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readLong();
		}
		
		return array;
	}
	
	////////////////////////////////////////////////////////////////////
	
	double readDouble() {
		return Double.parseDouble(readString());
	}
	
	double[] readDoubleArray(int size) {
		double[] array = new double[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readDouble();
		}
		
		return array;
	}
	
	////////////////////////////////////////////////////////////////////
		
	BigInteger readBigInteger() {
		return new BigInteger(readString());
	}
	
	BigDecimal readBigDecimal() {
		return new BigDecimal(readString());
	}
	
	/////////////////////////////////////////////////////////////////////
	
	Point readPoint() {
		int x = readInt();
		int y = readInt();
		return new Point(x, y);
	}
	
	Point[] readPointArray(int size) {
		Point[] array = new Point[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readPoint();
		}
		
		return array;
	}
	
	/////////////////////////////////////////////////////////////////////
	
	List<Integer>[] readGraph(int vertexNumber, int edgeNumber) {
		@SuppressWarnings("unchecked")
		List<Integer>[] graph = new List[vertexNumber];
		
		for (int index = 0; index < vertexNumber; ++index){
			graph[index] = new ArrayList<Integer>();
		}
		
		while (edgeNumber-- > 0){
			int from = readInt() - 1;
			int to = readInt() - 1;
			
			graph[from].add(to);
			graph[to].add(from);
		}
		
		return graph;
	}
	
	/////////////////////////////////////////////////////////////////////
	
	static class IntIndexPair {
		
		static Comparator<IntIndexPair> increaseComparator = new Comparator<IntIndexPair>() {
			
			@Override
			public int compare(IntIndexPair indexPair1, IntIndexPair indexPair2) {
				int value1 = indexPair1.value;
				int value2 = indexPair2.value;
				
				if (value1 != value2) return value1 - value2;
				
				int index1 = indexPair1.index;
				int index2 = indexPair2.index;
				
				return index1 - index2;
			}
		};
		
		static Comparator<IntIndexPair> decreaseComparator = new Comparator<IntIndexPair>() {
			
			@Override
			public int compare(IntIndexPair indexPair1, IntIndexPair indexPair2) {
				int value1 = indexPair1.value;
				int value2 = indexPair2.value;
				
				if (value1 != value2) return -(value1 - value2);
				
				int index1 = indexPair1.index;
				int index2 = indexPair2.index;
				
				return index1 - index2;
			}
		};
		
		int value, index;

		public IntIndexPair(int value, int index) {
			super();
			this.value = value;
			this.index = index;
		}		
		
		public int getRealIndex() {
			return index + 1;
		}
	}
	
	IntIndexPair[] readIntIndexArray(int size) {
		IntIndexPair[] array = new IntIndexPair[size];
		
		for (int index = 0; index < size; ++index) {
			array[index] = new IntIndexPair(readInt(), index);
		}
		
		return array;
	}
	
	/////////////////////////////////////////////////////////////////////
	
	static class OutputWriter extends PrintWriter {

		final int DEFAULT_PRECISION = 12;
		
		protected int precision;
		protected String format, formatWithSpace;
		
		{
			precision = DEFAULT_PRECISION;
			
			format = createFormat(precision);
			formatWithSpace = format + " ";
		}
		
		public OutputWriter(OutputStream out) {
			super(out);
		}

		public OutputWriter(String fileName) throws FileNotFoundException {
			super(fileName);
		}
		
		public int getPrecision() {
			return precision;
		}

		public void setPrecision(int precision) {
			precision = max(0, precision);
			this.precision = precision;
			
			format = createFormat(precision);
			formatWithSpace = format + " ";
		}
		
		private String createFormat(int precision){
			return "%." + precision + "f";
		}
		
		@Override
		public void print(double d){
			printf(format, d);
		}
		
		public void printWithSpace(double d){
			printf(formatWithSpace, d);
		}

		public void printAll(double...d){
			for (int i = 0; i < d.length - 1; ++i){
				printWithSpace(d[i]);
			}
			
			print(d[d.length - 1]);
		}
		
		@Override
		public void println(double d){
			printlnAll(d);
		}
		
		public void printlnAll(double... d){
			printAll(d);
			println();
		}
	}
	
	/////////////////////////////////////////////////////////////////////
	
	static class RuntimeIOException extends RuntimeException {

		/**
		 * 
		 */
		private static final long serialVersionUID = -6463830523020118289L;

		public RuntimeIOException(Throwable cause) {
			super(cause);
		}
	}
	
	/////////////////////////////////////////////////////////////////////
	//////////////// Some useful constants and functions ////////////////
	/////////////////////////////////////////////////////////////////////
	
	static final int[][] steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
	static final int[][] steps8 = {
			{-1, 0}, {1, 0}, {0, -1}, {0, 1},
			{-1, -1}, {1, 1}, {1, -1}, {-1, 1}
	};
	
	static final boolean checkCell(int row, int rowsCount, int column, int columnsCount) {
		return checkIndex(row, rowsCount) && checkIndex(column, columnsCount);
	}
	
	static final boolean checkIndex(int index, int lim){
		return (0 <= index && index < lim);
	}
	
	/////////////////////////////////////////////////////////////////////
	
	static final boolean checkBit(int mask, int bit){
		return (mask & (1 << bit)) != 0;
	}
	
	/////////////////////////////////////////////////////////////////////
	
	static final long getSum(int[] array) {
		long sum = 0;
		for (int value: array) {
			sum += value;
		}
		
		return sum;
	}
	
	static final Point getMinMax(int[] array) {
		int min = array[0];
		int max = array[0];
		
		for (int index = 0, size = array.length; index < size; ++index, ++index) {
			int value = array[index];
			
			if (index == size - 1) {
				min = min(min, value);
				max = max(max, value);
			} else {
				int otherValue = array[index + 1];
				
				if (value <= otherValue) {
					min = min(min, value);
					max = max(max, otherValue);
				} else {
					min = min(min, otherValue);
					max = max(max, value);
				}
			}
		}
		
		return new Point(min, max);
	}
	
	/////////////////////////////////////////////////////////////////////
	
	static class IdMap<KeyType> extends HashMap<KeyType, Integer> {

		/**
		 * 
		 */
		private static final long serialVersionUID = -3793737771950984481L;

		public IdMap() {
			super();
		}
		
		int getId(KeyType key) {
			Integer id = super.get(key);
			if (id == null) {
				super.put(key, id = size());
			}
			
			return id;
		}
	}
}

