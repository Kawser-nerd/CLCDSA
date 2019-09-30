import java.awt.*;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.List;
import java.util.Queue;

import static java.lang.Math.max;
import static java.lang.Math.min;


public class Main implements Runnable{

    // SOLUTION AT THE TOP OF CODE!!!
    // HACK ME PLEASE IF YOU CAN!!!
    // PLEASE!!!
    // PLEASE!!!
    // PLEASE!!!

    private final static boolean FIRST_INPUT_STRING = false;
    private final static boolean MULTIPLE_TESTS = true;
    private final boolean ONLINE_JUDGE = !new File("input.txt").exists();
//    private final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;

    private final static int MAX_STACK_SIZE = 128;

    private final static boolean OPTIMIZE_READ_NUMBERS = false;

    ///////////////////////////////////////////////////////////////////////

    private final static Random rnd = new Random();
    private final static String fileName = "";

    private static long MODULO = 1000 * 1000 * 1000 + 7;

    // THERE SOLUTION STARTS!!!
    private void solve() {
        int n = readInt();

        int d1 = readInt();
        int d2 = readInt();

        List<Point> answer = f(n, d1, d2);
        for (Point point : answer) {
            out.println(point.x + " " + point.y);
        }
    }

    static List<Point> f(int n, int d1, int d2) {
        int size = 2 * n;
        int totalSize = size * size;

        int[] colors = new int[totalSize];

        int[] ds = { d1, d2 };
        for (int i = 0; i < ds.length; ++i) {
            int d = ds[i];
            List<Point> deltas = new ArrayList<>();

            for (int dx = -size + 1; dx <= size - 1; ++dx) {
                for (int dy = -size + 1; dy <= size - 1; ++dy) {
                    int sum = dx * dx + dy * dy;
                    if (sum == d) deltas.add(new Point(dx, dy));
                }
            }

//            GraphBuilder graphBuilder = GraphBuilder.createInstance(totalSize);

            int[] distances = new int[totalSize];
            Arrays.fill(distances, -1);

            Queue<Integer> queue = new ArrayDeque<>();

            for (int x = 0; x < size; ++x) {
                for (int y = 0; y < size; ++y) {
                    int v = x * size + y;
                    if (distances[v] != -1) continue;

                    queue.add(v);
                    distances[v] = 0;

                    while (queue.size() > 0) {
                        int from = queue.poll();

                        int fromX = from / size, fromY = from % size;

                        for (Point delta : deltas) {
                            int xx = fromX + delta.x;
                            int yy = fromY + delta.y;

                            if (!checkCell(xx, size, yy, size)) continue;

                            int vv = xx * size + yy;
                            if (distances[vv] != -1) continue;

                            queue.add(vv);
                            distances[vv] = distances[from] ^ 1;
//                        graphBuilder.addEdge(v, vv);
                        }
                    }
                }
            }

//            int[][] graph = graphBuilder.build();



//            for (int v = 0; v < graph.length; ++v) {
//                if (distances[v] != -1) continue;
//
//                queue.add(v);
//                distances[v] = 0;
//
//                while (queue.size() > 0) {
//                    int from = queue.poll();
//                    for (int to : graph[from]) {
//                        if (distances[to] != -1) continue;
//                        distances[to] = distances[from] ^ 1;
//                        queue.add(to);
//                    }
//                }
//            }

            for (int v = 0; v < totalSize; ++v) {
                colors[v] |= (distances[v] << i);
            }
        }

        int[] sizes = new int[4];
        for (int color : colors) sizes[color]++;

        for (int color = 0; color < 4; ++color) {
            if (sizes[color] >= n * n) {
                List<Point> answer = new ArrayList<>();
                for (int v = 0; answer.size() < n * n && v < colors.length; ++v) {
                    if (colors[v] == color) {
                        answer.add(new Point(v / size, v % size));
                    }
                }

                return answer;
            }
        }

        throw new UnsupportedOperationException();
    }

    long inverse(long x) {
        return binpow(x, MODULO - 2);
    }

    long binpow(long base, long power) {
        if (power == 0) return 1;
        if ((power & 1) == 0) {
            long half = binpow(base, power >> 1);
            return mult(half, half);
        } else {
            long prev = binpow(base, power - 1);
            return mult(prev, base);
        }
    }

    /////////////////////////////////////////////////////////////////////

    private static long add(long a, long b) { return (a + b) % MODULO; }
    private static long subtract(long a, long b) { return add(a, MODULO - b % MODULO); }
    private static long mult(long a, long b) { return (a * b) % MODULO; }

    /////////////////////////////////////////////////////////////////////

    public void run(){
        try{
            timeInit();
            Locale.setDefault(Locale.US);

            init();

            if (ONLINE_JUDGE) {
                solve();
            } else {
                do {
                    try {
                        timeInit();
                        solve();
                        time();

                        out.println();
                        out.flush();
                    } catch (NumberFormatException e) {
                        break;
                    } catch (NullPointerException e) {
                        if (FIRST_INPUT_STRING) break;
                        else throw e;
                    }
                } while (MULTIPLE_TESTS);
            }

            out.close();
            time();
        }catch (Exception e){
            e.printStackTrace(System.err);
            System.exit(-1);
        }
    }

    /////////////////////////////////////////////////////////////////////

    private BufferedReader in;
    private OutputWriter out;
    private StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args){
        new Thread(null, new Main(), "", MAX_STACK_SIZE * (1L << 20)).start();
    }

    /////////////////////////////////////////////////////////////////////

    private void init() throws FileNotFoundException{
        Locale.setDefault(Locale.US);

        if (ONLINE_JUDGE){
            if (fileName.isEmpty()) {
                in = new BufferedReader(new InputStreamReader(System.in));
                out = new OutputWriter(System.out);
            } else {
                in = new BufferedReader(new FileReader(fileName + ".in"));
                out = new OutputWriter(fileName + ".out");
            }
        }else{
            in = new BufferedReader(new FileReader("input.txt"));
            out = new OutputWriter("output.txt");
        }
    }

    ////////////////////////////////////////////////////////////////

    private long timeBegin;

    private void timeInit() {
        this.timeBegin = System.currentTimeMillis();
    }

    private void time(){
        long timeEnd = System.currentTimeMillis();
        System.err.println("Time = " + (timeEnd - timeBegin));
    }

    private void debug(Object... objects){
        if (ONLINE_JUDGE){
            for (Object o: objects){
                System.err.println(o.toString());
            }
        }
    }

    /////////////////////////////////////////////////////////////////////

    private String delim = " ";

    private String readLine() {
        try {
            return in.readLine();
        } catch (IOException e) {
            throw new RuntimeIOException(e);
        }
    }

    private String readString() {
        try {
            while(!tok.hasMoreTokens()){
                tok = new StringTokenizer(readLine(), delim);
            }

            return tok.nextToken(delim);
        } catch (NullPointerException e) {
            return null;
        }
    }

    /////////////////////////////////////////////////////////////////

    private final char NOT_A_SYMBOL = '\0';

    private char readChar() {
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

    private char[] readCharArray() {
        return readLine().toCharArray();
    }

    private char[][] readCharField(int rowsCount) {
        char[][] field = new char[rowsCount][];
        for (int row = 0; row < rowsCount; ++row) {
            field[row] = readCharArray();
        }

        return field;
    }

    /////////////////////////////////////////////////////////////////

    private long optimizedReadLong() {
        int sign = 1;
        long result = 0;
        boolean started = false;
        while (true) {
            try {
                int j = in.read();
                if (-1 == j) {
                    if (started) return sign * result;
                    throw new NumberFormatException();
                }

                if (j == '-') {
                    if (started) throw new NumberFormatException();
                    sign = -sign;
                }

                if ('0' <= j && j <= '9') {
                    result = result * 10 + j - '0';
                    started = true;
                } else if (started) {
                    return sign * result;
                }
            } catch (IOException e) {
                throw new RuntimeIOException(e);
            }
        }
    }

    private int readInt() {

        if (!OPTIMIZE_READ_NUMBERS) {
            return Integer.parseInt(readString());
        } else {
            return (int) optimizedReadLong();
        }
    }

    private int[] readIntArray(int size) {
        int[] array = new int[size];

        for (int index = 0; index < size; ++index){
            array[index] = readInt();
        }

        return array;
    }

    private int[] readSortedIntArray(int size) {
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

    private int[] readIntArrayWithDecrease(int size) {
        int[] array = readIntArray(size);

        for (int i = 0; i < size; ++i) {
            array[i]--;
        }

        return array;
    }

    ///////////////////////////////////////////////////////////////////

    private int[][] readIntMatrix(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = readIntArray(columnsCount);
        }

        return matrix;
    }

    private int[][] readIntMatrixWithDecrease(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = readIntArrayWithDecrease(columnsCount);
        }

        return matrix;
    }

    ///////////////////////////////////////////////////////////////////

    private long readLong() {
        if (!OPTIMIZE_READ_NUMBERS) {
            return Long.parseLong(readString());
        } else {
            return optimizedReadLong();
        }
    }

    private long[] readLongArray(int size) {
        long[] array = new long[size];

        for (int index = 0; index < size; ++index){
            array[index] = readLong();
        }

        return array;
    }

    ////////////////////////////////////////////////////////////////////

    private double readDouble() {
        return Double.parseDouble(readString());
    }

    private double[] readDoubleArray(int size) {
        double[] array = new double[size];

        for (int index = 0; index < size; ++index){
            array[index] = readDouble();
        }

        return array;
    }

    ////////////////////////////////////////////////////////////////////

    private BigInteger readBigInteger() {
        return new BigInteger(readString());
    }

    private BigDecimal readBigDecimal() {
        return new BigDecimal(readString());
    }

    /////////////////////////////////////////////////////////////////////

    private Point readPoint() {
        int x = readInt();
        int y = readInt();
        return new Point(x, y);
    }

    private Point[] readPointArray(int size) {
        Point[] array = new Point[size];

        for (int index = 0; index < size; ++index){
            array[index] = readPoint();
        }

        return array;
    }

    /////////////////////////////////////////////////////////////////////

    @Deprecated
    private List<Integer>[] readGraph(int vertexNumber, int edgeNumber) {
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

    private static class GraphBuilder {

        final int size;
        final List<Integer>[] edges;

        static GraphBuilder createInstance(int size) {
            List<Integer>[] edges = new List[size];
            for (int v = 0; v < size; ++v) {
                edges[v] = new ArrayList<Integer>();
            }

            return new GraphBuilder(edges);
        }

        private GraphBuilder(List<Integer>[] edges) {
            this.size = edges.length;
            this.edges = edges;
        }

        public void addEdge(int from, int to) {
            addDirectedEdge(from, to);
            addDirectedEdge(to, from);
        }

        public void addDirectedEdge(int from, int to) {
            edges[from].add(to);
        }

        public int[][] build() {
            int[][] graph = new int[size][];
            for (int v = 0; v < size; ++v) {
                List<Integer> vEdges = edges[v];
                graph[v] = castInt(vEdges);
            }

            return graph;
        }
    }

    private final static int ZERO_INDEXATION = 0, ONE_INDEXATION = 1;

    private int[][] readUnweightedGraph(int vertexNumber, int edgesNumber) {
        return readUnweightedGraph(vertexNumber, edgesNumber, ONE_INDEXATION, false);
    }

    private int[][] readUnweightedGraph(int vertexNumber, int edgesNumber,
                                        int indexation, boolean directed
    ) {
        GraphBuilder graphBuilder = GraphBuilder.createInstance(vertexNumber);
        for (int i = 0; i < edgesNumber; ++i) {
            int from = readInt() - indexation;
            int to = readInt() - indexation;

            if (directed) graphBuilder.addDirectedEdge(from, to);
            else graphBuilder.addEdge(from, to);
        }

        return graphBuilder.build();
    }

    private static class Edge {
        int to;
        int w;

        Edge(int to, int w) {
            this.to = to;
            this.w = w;
        }
    }

    private Edge[][] readWeightedGraph(int vertexNumber, int edgesNumber) {
        return readWeightedGraph(vertexNumber, edgesNumber, ONE_INDEXATION, false);
    }

    private Edge[][] readWeightedGraph(int vertexNumber, int edgesNumber,
                                       int indexation, boolean directed) {
        @SuppressWarnings("unchecked")
        List<Edge>[] graph = new List[vertexNumber];
        for (int v = 0; v < vertexNumber; ++v) {
            graph[v] = new ArrayList<Edge>();
        }

        while (edgesNumber --> 0) {
            int from = readInt() - indexation;
            int to = readInt() - indexation;
            int w = readInt();

            graph[from].add(new Edge(to, w));
            if (!directed) graph[to].add(new Edge(from, w));
        }

        Edge[][] graphArrays = new Edge[vertexNumber][];
        for (int v = 0; v < vertexNumber; ++v) {
            graphArrays[v] = graph[v].toArray(new Edge[0]);
        }

        return graphArrays;
    }

    /////////////////////////////////////////////////////////////////////

    private static class IntIndexPair {

        static Comparator<IntIndexPair> increaseComparator = new Comparator<Main.IntIndexPair>() {

            @Override
            public int compare(Main.IntIndexPair indexPair1, Main.IntIndexPair indexPair2) {
                int value1 = indexPair1.value;
                int value2 = indexPair2.value;

                if (value1 != value2) return value1 - value2;

                int index1 = indexPair1.index;
                int index2 = indexPair2.index;

                return index1 - index2;
            }
        };

        static Comparator<IntIndexPair> decreaseComparator = new Comparator<Main.IntIndexPair>() {

            @Override
            public int compare(Main.IntIndexPair indexPair1, Main.IntIndexPair indexPair2) {
                int value1 = indexPair1.value;
                int value2 = indexPair2.value;

                if (value1 != value2) return -(value1 - value2);

                int index1 = indexPair1.index;
                int index2 = indexPair2.index;

                return index1 - index2;
            }
        };

        static IntIndexPair[] from(int[] array) {
            IntIndexPair[] iip = new IntIndexPair[array.length];
            for (int i = 0; i < array.length; ++i) {
                iip[i] = new IntIndexPair(array[i], i);
            }

            return iip;
        }

        int value, index;

        IntIndexPair(int value, int index) {
            super();
            this.value = value;
            this.index = index;
        }

        int getRealIndex() {
            return index + 1;
        }
    }

    private IntIndexPair[] readIntIndexArray(int size) {
        IntIndexPair[] array = new IntIndexPair[size];

        for (int index = 0; index < size; ++index) {
            array[index] = new IntIndexPair(readInt(), index);
        }

        return array;
    }

    /////////////////////////////////////////////////////////////////////

    private static class OutputWriter extends PrintWriter {

        final int DEFAULT_PRECISION = 12;

        private int precision;
        private String format, formatWithSpace;

        {
            precision = DEFAULT_PRECISION;

            format = createFormat(precision);
            formatWithSpace = format + " ";
        }

        OutputWriter(OutputStream out) {
            super(out);
        }

        OutputWriter(String fileName) throws FileNotFoundException {
            super(fileName);
        }

        int getPrecision() {
            return precision;
        }

        void setPrecision(int precision) {
            precision = max(0, precision);
            this.precision = precision;

            format = createFormat(precision);
            formatWithSpace = format + " ";
        }

        String createFormat(int precision){
            return "%." + precision + "f";
        }

        @Override
        public void print(double d){
            printf(format, d);
        }
        
        @Override
        public void println(double d){
            print(d);
            println();
        }

        void printWithSpace(double d){
            printf(formatWithSpace, d);
        }

        void printAll(double...d){
            for (int i = 0; i < d.length - 1; ++i){
                printWithSpace(d[i]);
            }

            print(d[d.length - 1]);
        }

        void printlnAll(double... d){
            printAll(d);
            println();
        }
        
        void printAll(int... array) {
        	for (int value : array) {
        		print(value + " ");
        	}
        }
        
        void printlnAll(int... array) {
        	printAll(array);
        	println();
        }
        
        void printAll(long... array) {
        	for (long value : array) {
        		print(value + " ");
        	}
        }
        
        void printlnAll(long... array) {
        	printAll(array);
        	println();
        }
    }

    /////////////////////////////////////////////////////////////////////

    private static class RuntimeIOException extends RuntimeException {

        /**
         *
         */
        private static final long serialVersionUID = -6463830523020118289L;

        RuntimeIOException(Throwable cause) {
            super(cause);
        }
    }

    /////////////////////////////////////////////////////////////////////
    //////////////// Some useful constants andTo functions ////////////////
    /////////////////////////////////////////////////////////////////////

    private static final int[][] steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    private static final int[][] steps8 = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1},
            {-1, -1}, {1, 1}, {1, -1}, {-1, 1}
    };

    private static boolean checkCell(int row, int rowsCount, int column, int columnsCount) {
        return checkIndex(row, rowsCount) && checkIndex(column, columnsCount);
    }

    private static boolean checkIndex(int index, int lim){
        return (0 <= index && index < lim);
    }

    /////////////////////////////////////////////////////////////////////

    private static int getBit(long mask, int bit) { return (int)((mask >> bit) & 1); }
    private static boolean checkBit(long mask, int bit){
        return getBit(mask, bit) != 0;
    }

    /////////////////////////////////////////////////////////////////////

    private static long getSum(int[] array) {
        long sum = 0;
        for (int value: array) {
            sum += value;
        }

        return sum;
    }

    private static Point getMinMax(int[] array) {
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

    private static boolean isPrime(int x) {
        if (x < 2) return false;
        for (int d = 2; d * d <= x; ++d) {
            if (x % d == 0) return false;
        }

        return true;
    }
    private static int[] getPrimes(int n) {
        boolean[] used = new boolean[n];
        used[0] = used[1] = true;

        int size = 0;
        for (int i = 2; i < n; ++i) {
            if (!used[i]) {
                ++size;
                for (int j = 2 * i; j < n; j += i) {
                    used[j] = true;
                }
            }
        }

        int[] primes = new int[size];
        for (int i = 0, cur = 0; i < n; ++i) {
            if (!used[i]) {
                primes[cur++] = i;
            }
        }

        return primes;
    }

    /////////////////////////////////////////////////////////////////////

    int[] getDivisors(int value) {
        List<Integer> divisors = new ArrayList<Integer>();
        for (int divisor = 1; divisor * divisor <= value; ++divisor) {
            if (value % divisor == 0) {
                divisors.add(divisor);
                if (divisor * divisor != value) {
                    divisors.add(value / divisor);
                }
            }
        }

        return castInt(divisors);
    }

    /////////////////////////////////////////////////////////////////////

    private static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    private static long gcd(long a, long b) {
        return (a == 0 ? b : gcd(b % a, a));
    }

/////////////////////////////////////////////////////////////////////

    private interface MultiSet<ValueType> {

        int size();

        void inc(ValueType value);
        boolean dec(ValueType value);

        int count(ValueType value);
    }

    private static abstract class MultiSetImpl
            <ValueType, MapType extends Map<ValueType, Integer>>
            implements MultiSet<ValueType> {

        protected final MapType map;
        protected int size;

        protected MultiSetImpl(MapType map) {
            this.map = map;
            this.size = 0;
        }

        public int size() {
            return size;
        }

        public void inc(ValueType value) {
            int count = count(value);
            map.put(value, count + 1);

            ++size;
        }

        public boolean dec(ValueType value) {
            int count = count(value);
            if (count == 0) return false;

            if (count == 1) map.remove(value);
            else map.put(value, count - 1);

            --size;
            return true;
        }

        public int count(ValueType value) {
            Integer count = map.get(value);
            return (count == null ? 0 : count);
        }
    }

    private static class HashMultiSet<ValueType>
            extends MultiSetImpl<ValueType, Map<ValueType, Integer>> {

        public static <ValueType> MultiSet<ValueType> createMultiSet() {
            Map<ValueType, Integer> map = new HashMap<ValueType, Integer>();
            return new HashMultiSet<ValueType>(map);
        }

        HashMultiSet(Map<ValueType, Integer> map) {
            super(map);
        }
    }

    /////////////////////////////////////////////////////////////////////

    private interface SortedMultiSet<ValueType> extends MultiSet<ValueType> {

        ValueType min();
        ValueType max();

        ValueType pollMin();
        ValueType pollMax();

        ValueType lower(ValueType value);
        ValueType floor(ValueType value);

        ValueType ceiling(ValueType value);
        ValueType higher(ValueType value);
    }

    private static abstract class SortedMultiSetImpl<ValueType>
            extends MultiSetImpl<ValueType, NavigableMap<ValueType, Integer>>
            implements SortedMultiSet<ValueType> {

        SortedMultiSetImpl(NavigableMap<ValueType, Integer> map) {
            super(map);
        }

        @Override
        public ValueType min() {
            return (size == 0 ? null : map.firstKey());
        }

        @Override
        public ValueType max() {
            return (size == 0 ? null : map.lastKey());
        }

        @Override
        public ValueType pollMin() {
            ValueType first = min();
            if (first != null) dec(first);
            return first;
        }

        @Override
        public ValueType pollMax() {
            ValueType last = max();
            dec(last);
            return last;
        }

        @Override
        public ValueType lower(ValueType value) {
            return map.lowerKey(value);
        }

        @Override
        public ValueType floor(ValueType value) {
            return map.floorKey(value);
        }

        @Override
        public ValueType ceiling(ValueType value) {
            return map.ceilingKey(value);
        }

        @Override
        public ValueType higher(ValueType value) {
            return map.higherKey(value);
        }
    }

    private static class TreeMultiSet<ValueType>
            extends SortedMultiSetImpl<ValueType> {

        public static <ValueType> SortedMultiSet<ValueType> createMultiSet() {
            NavigableMap<ValueType, Integer> map = new TreeMap<ValueType, Integer>();
            return new TreeMultiSet<ValueType>(map);
        }

        public static <ValueType> SortedMultiSet<ValueType> createMultiSet(Comparator<ValueType> comparator) {
            NavigableMap<ValueType, Integer> map = new TreeMap<ValueType, Integer>(comparator);
            return new TreeMultiSet<ValueType>(map);
        }

        TreeMultiSet(NavigableMap<ValueType, Integer> map) {
            super(map);
        }
    }

    /////////////////////////////////////////////////////////////////////

    private static class IdMap<KeyType> extends HashMap<KeyType, Integer> {

        /**
         *
         */
        private static final long serialVersionUID = -3793737771950984481L;

        public IdMap() {
            super();
        }

        int register(KeyType key) {
            Integer id = super.get(key);
            if (id == null) {
                super.put(key, id = size());
            }

            return id;
        }

        int getId(KeyType key) {
            return get(key);
        }
    }

    /////////////////////////////////////////////////////////////////////

    private static class SortedIdMapper<ValueType extends Comparable<ValueType>> {

        private List<ValueType> values;

        public SortedIdMapper() {
            this.values = new ArrayList<ValueType>();
        }

        void addValue(ValueType value) {
            values.add(value);
        }

        IdMap<ValueType> build() {
            Collections.sort(values);

            IdMap<ValueType> ids = new IdMap<ValueType>();
            List<ValueType> uniqueValues = new ArrayList<ValueType>();

            for (int index = 0; index < values.size(); ++index) {
                ValueType value = values.get(index);
                if (index == 0 || values.get(index - 1).compareTo(value) != 0) {
                    ids.register(value);
                    uniqueValues.add(value);
                }
            }
            
            values = uniqueValues;

            return ids;
        }
    }

    /////////////////////////////////////////////////////////////////////

    private static int[] castInt(List<Integer> list) {
        int[] array = new int[list.size()];
        for (int i = 0; i < array.length; ++i) {
            array[i] = list.get(i);
        }

        return array;
    }

    private static long[] castLong(List<Long> list) {
        long[] array = new long[list.size()];
        for (int i = 0; i < array.length; ++i) {
            array[i] = list.get(i);
        }

        return array;
    }

    /////////////////////////////////////////////////////////////////////

    /**
     * Generates list with keys 0..<n
     * @param n - exclusive limit of sequence
     */
    private static List<Integer> order(int n) {
        List<Integer> sequence = new ArrayList<Integer>();
        for (int i = 0; i < n; ++i) {
            sequence.add(i);
        }

        return sequence;
    }

    /////////////////////////////////////////////////////////////////////

    interface Rmq {
        int getMin(int left, int right);
        int getMinIndex(int left, int right);
    }

    private static class SparseTable implements Rmq {

        private static final int MAX_BIT = 20;

        int n;
        int[] array;

        SparseTable(int[] array) {
            this.n = array.length;
            this.array = array;
        }

        int[] lengthMaxBits;
        int[][] table;

        int getIndexOfLess(int leftIndex, int rightIndex) {
            return (array[leftIndex] <= array[rightIndex])
                    ? leftIndex
                    : rightIndex;
        }

        SparseTable build() {
            this.lengthMaxBits = new int[n + 1];
            lengthMaxBits[0] = 0;
            for (int i = 1; i <= n; ++i) {
                lengthMaxBits[i] = lengthMaxBits[i - 1];
                int length = (1 << lengthMaxBits[i]);
                if (length + length <= i) ++lengthMaxBits[i];
            }

            this.table = new int[MAX_BIT][n];
            table[0] = castInt(order(n));

            for (int bit = 0; bit < MAX_BIT - 1; ++bit) {
                for (int i = 0, j = (1 << bit); j < n; ++i, ++j) {
                    table[bit + 1][i] = getIndexOfLess(
                            table[bit][i], table[bit][j]
                    );
                }
            }

            return this;
        }

        @Override
        public int getMinIndex(int left, int right) {
            int length = (right - left + 1);

            int bit = lengthMaxBits[length];
            int segmentLength = (1 << bit);

            return getIndexOfLess(
                    table[bit][left], table[bit][right - segmentLength + 1]
            );
        }

        @Override
        public int getMin(int left, int right) {
            return array[getMinIndex(left, right)];
        }
    }

    private static Rmq createRmq(int[] array) {
        return new SparseTable(array).build();
    }

    /////////////////////////////////////////////////////////////////////

    interface Lca {
        Lca build(int root);
        int lca(int a, int b);

        int height(int v);
    }

    private static class LcaRmq implements Lca {

        int n;
        int[][] graph;

        LcaRmq(int[][] graph) {
            this.n = graph.length;
            this.graph = graph;
        }

        int time;

        int[] order;
        int[] heights;
        int[] first;

        Rmq rmq;

        @Override
        public LcaRmq build(int root) {
            this.order = new int[n + n];
            this.heights = new int[n];

            this.first = new int[n];
            Arrays.fill(first, -1);

            this.time = 0;
            dfs(root, 0);

            int[] orderedHeights = new int[n + n];
            for (int i = 0; i < order.length; ++i) {
                orderedHeights[i] = heights[order[i]];
            }

            this.rmq = createRmq(orderedHeights);
            return this;
        }

        void dfs(int from, int height) {
            first[from] = time;
            order[time] = from;
            heights[from] = height;
            ++time;

            for (int to : graph[from]) {
                if (first[to] == -1) {
                    dfs(to, height + 1);

                    order[time] = from;
                    ++time;
                }
            }
        }

        @Override
        public int lca(int a, int b) {
            int aFirst = first[a], bFirst = first[b];
            int left = min(aFirst, bFirst), right = max(aFirst, bFirst);

            int orderIndex = rmq.getMinIndex(left, right);
            return order[orderIndex];
        }

        @Override
        public int height(int v) {
            return heights[v];
        }
    }

    private static class LcaBinary implements Lca {

        private static final int MAX_BIT = 20;

        int n;
        int[][] graph;

        int[] h;
        int[][] parents;

        LcaBinary(int[][] graph) {
            this.n = graph.length;
            this.graph = graph;
        }

        @Override
        public Lca build(int root) {
            this.h = new int[n];

            this.parents = new int[MAX_BIT][n];
            Arrays.fill(parents[0], -1);

            Queue<Integer> queue = new ArrayDeque<Integer>();

            queue.add(root);
            add(root, root);

            while (queue.size() > 0) {
                int from = queue.poll();
                for (int to : graph[from]) {
                    if (parents[0][to] == -1) {
                        add(from, to);
                        queue.add(to);
                    }
                }
            }

            return this;
        }

        void add(int parent, int v) {
            h[v] = h[parent] + 1;
            parents[0][v] = parent;
            for (int bit = 0; bit < MAX_BIT - 1; ++bit) {
                parents[bit + 1][v] = parents[bit][parents[bit][v]];
            }
        }

        @Override
        public int lca(int a, int b) {
            if (h[a] < h[b]) {
                int tmp = a;
                a = b;
                b = tmp;
            }

            int delta = h[a] - h[b];
            for (int bit = MAX_BIT - 1; bit >= 0; --bit) {
                if (delta >= (1 << bit)) {
                    delta -= (1 << bit);
                    a = parents[bit][a];
                }
            }

            if (a == b) return a;

            for (int bit = MAX_BIT - 1; bit >= 0; --bit) {
                int nextA = parents[bit][a], nextB = parents[bit][b];
                if (nextA != nextB) {
                    a = nextA;
                    b = nextB;
                }
            }

            return parents[0][a];
        }

        @Override
        public int height(int v) {
            return h[v];
        }
    }

    private static Lca createLca(int[][] graph, int root) {
        return new LcaRmq(graph).build(root);
    }

    /////////////////////////////////////////////////////////////////////

    private static class BiconnectedGraph {

        int n;
        int[][] graph;

        BiconnectedGraph(int[][] graph) {
            this.n = graph.length;
            this.graph = graph;
        }

        int time;
        int[] tin, up;

        boolean[] used;

        BiconnectedGraph build() {
            calculateTimes();
            condensateComponents();

            return this;
        }

        void calculateTimes() {
            this.tin = new int[n];
            this.up = new int[n];

            this.time = 0;

            this.used = new boolean[n];
            timeDfs(0, -1);
        }

        void timeDfs(int from, int parent) {
            used[from] = true;

            up[from] = tin[from] = time;
            ++time;

            for (int to : graph[from]) {
                if (to == parent) continue;

                if (used[to]) {
                    up[from] = min(up[from], tin[to]);
                } else {
                    timeDfs(to, from);
                    up[from] = min(up[from], up[to]);
                }
            }
        }

        int[] components;
        int[][] componentsGraph;

        int component(int v) { return components[v]; }

        int[][] toGraph() {
            return componentsGraph;
        }

        void condensateComponents() {
            this.components = new int[n];
            Arrays.fill(components, -1);

            for (int v = 0; v < n; ++v) {
                if (components[v] == -1) {
                    componentsDfs(v, v);
                }
            }

            GraphBuilder graphBuilder = GraphBuilder.createInstance(n);

            Set<Point> edges = new HashSet<Point>();
            for (int from = 0; from < n; ++from) {
                int fromComponent = components[from];

                for (int to : graph[from]) {
                    int toComponent = components[to];
                    if (fromComponent == toComponent) continue;

                    Point edge = new Point(fromComponent, toComponent);
                    if (edges.add(edge)) graphBuilder.addDirectedEdge(fromComponent, toComponent);
                }
            }

            this.componentsGraph = graphBuilder.build();
        }

        void componentsDfs(int from, int color) {
            components[from] = color;
            for (int to : graph[from]) {
                if (components[to] != -1) continue;

                if (tin[from] >= up[to] && tin[to] >= up[from]) {
                    componentsDfs(to, color);
                }
            }
        }
    }

    /////////////////////////////////////////////////////////////////////

    private static class VertexBiconnectedGraph {

        static class Edge {
            int to;
            int index;

            Edge(int to, int index) {
                this.to = to;
                this.index = index;
            }
        }

        int n, m;
        List<Edge>[] graph;
        List<Edge> edges;

        VertexBiconnectedGraph(int n) {
            this.n = n;
            this.m = 0;

            this.graph = new List[n];
            for (int v = 0; v < n; ++v) {
                graph[v] = new ArrayList<Edge>();
            }

            this.edges = new ArrayList<Edge>();
        }

        void addEdge(int from, int to) {
            Edge fromToEdge = new Edge(to, m);
            Edge toFromEdge = new Edge(from, m + 1);

            edges.add(fromToEdge);
            edges.add(toFromEdge);

            graph[from].add(fromToEdge);
            graph[to].add(toFromEdge);

            m += 2;
        }

        int time;

        boolean[] used;
        int[] tin, up;
        int[] parents;

        boolean[] isArticulation;

        boolean[] findArticulationPoints() {
            this.isArticulation = new boolean[n];

            this.used = new boolean[n];
            this.parents = new int[n];
            Arrays.fill(parents, -1);

            this.tin = new int[n];
            this.up = new int[n];

            this.time = 0;

            for (int v = 0; v < n; ++v) {
                if (!used[v]) {
                    articulationDfs(v, -1);
                }
            }

            return isArticulation;
        }

        void articulationDfs(int from, int parent) {
            used[from] = true;
            parents[from] = parent;

            ++time;
            up[from] = tin[from] = time;

            int childrenCount = 0;

            for (Edge e : graph[from]) {
                int to = e.to;

                if (to == parent) continue;

                if (used[to]) {
                    up[from] = min(up[from], tin[to]);
                } else {
                    ++childrenCount;

                    articulationDfs(to, from);
                    up[from] = min(up[from], up[to]);
                    if (up[to] >= tin[from] && parent != -1) {
                        isArticulation[from] = true;
                    }
                }
            }

            if (parent == -1 && childrenCount > 1) {
                isArticulation[from] = true;
            }
        }

        int[] edgeColors;
        int maxEdgeColor;

        int[] paintEdges() {
            this.edgeColors = new int[m];
            Arrays.fill(edgeColors, -1);

            this.maxEdgeColor = -1;

            this.used = new boolean[n];

            for (int v = 0; v < n; ++v) {
                if (!used[v]) {
                    ++maxEdgeColor;
                    paintDfs(v, maxEdgeColor, -1);
                }
            }

            return edgeColors;
        }

        void paintEdge(int edgeIndex, int color) {
            if (edgeColors[edgeIndex] != -1) return;

            edgeColors[edgeIndex] = edgeColors[edgeIndex ^ 1] = color;
        }

        void paintDfs(int from, int color, int parent) {
            used[from] = true;

            for (Edge e : graph[from]) {
                int to = e.to;
                if (to == parent) continue;

                if (!used[to]) {
                    if (up[to] >= tin[from]) {
                        int newColor = ++maxEdgeColor;
                        paintEdge(e.index, newColor);
                        paintDfs(to, newColor, from);
                    } else {
                        paintEdge(e.index, color);
                        paintDfs(to, color, from);
                    }
                } else if (up[to] <= tin[from]){
                    paintEdge(e.index, color);
                }
            }
        }

        Set<Integer>[] collectVertexEdgeColors() {
            Set<Integer>[] vertexEdgeColors = new Set[n];
            for (int v = 0; v < n; ++v) {
                vertexEdgeColors[v] = new HashSet<Integer>();
                for (Edge e : graph[v]) {
                    vertexEdgeColors[v].add(edgeColors[e.index]);
                }
            }

            return vertexEdgeColors;
        }

        VertexBiconnectedGraph build() {
            findArticulationPoints();
            paintEdges();
            createComponentsGraph();

            return this;
        }

        int[][] componentsGraph;

        void createComponentsGraph() {
            Set<Integer>[] vertexEdgeColors = collectVertexEdgeColors();

            int edgeColorShift = vertexEdgeColors.length;
            int size = vertexEdgeColors.length + maxEdgeColor + 1;

            GraphBuilder graphBuilder = GraphBuilder.createInstance(size);
            for (int v = 0; v < vertexEdgeColors.length; ++v) {
                for (int edgeColor : vertexEdgeColors[v]) {
                    graphBuilder.addEdge(v, edgeColor + edgeColorShift);
                }
            }

            this.componentsGraph = graphBuilder.build();
        }

        int[][] toGraph() {
            return componentsGraph;
        }
    }

    /////////////////////////////////////////////////////////////////////

    private static class DSU {

        int[] sizes;

        int[] ranks;
        int[] parents;

        static DSU createInstance(int size) {
            int[] sizes = new int[size];
            Arrays.fill(sizes, 1);

            return new DSU(sizes);
        }

        DSU(int[] sizes) {
            this.sizes = sizes;

            int size = sizes.length;

            this.ranks = new int[size];
            Arrays.fill(ranks, 1);

            this.parents = castInt(order(size));
        }

        int get(int v) {
            if (v == parents[v]) return v;
            return parents[v] = get(parents[v]);
        }

        boolean union(int a, int b) {
            a = get(a);
            b = get(b);

            if (a == b) return false;

            if (ranks[a] < ranks[b]) {
                int tmp = a;
                a = b;
                b = tmp;
            }

            parents[b] = a;
            sizes[a] += sizes[b];

            if (ranks[a] == ranks[b]) ++ranks[a];

            return true;
        }
    }

    /////////////////////////////////////////////////////////////////////
    
    static abstract class SegmentTree {
    	
    	int size;
    	boolean lazySupported; 
    	
    	boolean[] lazy;
    	long[] values;
    	
    	long[] tree;
    	
    	SegmentTree(int n, boolean lazySupported) {
    		this.size = n;
    		this.lazySupported = lazySupported;
    		
    		int treeSize = size << 2;
    		
    		this.tree = new long[treeSize];
    		
    		if (lazySupported) {
        		this.lazy = new boolean[treeSize];
        		this.values = new long[treeSize];	
    		}
    	}
    	
    	SegmentTree(int[] a, boolean lazySupported) {
    		this(a.length, lazySupported);
    	}
    	
    	abstract void updateValue(int v, int left, int right, long value);
    	
    	void setLazyValue(int v, long value) {
    		throw new UnsupportedOperationException();
    	}
    	
    	void pushVertex(int v, int vLeft, int vRight) {
    		if (lazy[v]) {
    			setLazyValue(vLeft, values[v]);
    			setLazyValue(vRight, values[v]);
    			
    			lazy[v] = false;
    			values[v] = 0;
    		}
    	}
    	
    	abstract void updateVertex(int v, int vLeft, int vRight);
    	
    	int[] a;
    	void buildTree(int[] a) {
    		this.a = a;
    		
    		buildTree(1, 0, size - 1);
    	}
    	
    	void buildTree(int v, int left, int right) {
    		if (left == right) {
    			updateValue(v, left, right, a[left]);
    		} else {
    			int mid = (left + right) >> 1;
    			int vLeft = (v << 1), vRight = (vLeft + 1);
    			
    			buildTree(vLeft, left, mid);
    			buildTree(vRight, mid + 1, right);
    			
    			updateVertex(v, vLeft, vRight);
    		}
    	}
    	
    	long value;
    	
    	int index;
    	void updateIndex(int index, long value) {
    		this.index = index;
    		this.value = value;
    		
    		updateTreeIndex(1, 0, size - 1);
    	}
    	
    	void updateTreeIndex(int v, int left, int right) {
    		if (left == right) {
    			updateValue(v, left, right, value);
    		} else {
    			int mid = (left + right) >> 1;
    			int vLeft = (v << 1), vRight = (vLeft + 1);
    			
    			if (index <= mid) updateTreeIndex(vLeft, left, mid);
    			else updateTreeIndex(vRight, mid + 1, right);
    			
    			updateVertex(v, vLeft, vRight);
    		}
    	}
    	
    	int start, end;
    	void updateSegment(int start, int end, long value) {
    		this.start = start;
    		this.end = end;
    		this.value = value;
    		
    		updateTreeSegment(1, 0, size - 1);
    	}

        void updateTreeSegment(int v, int left, int right) {
            if (start <= left && right <= end) {
                if (lazySupported) {
                    setLazyValue(v, value);
                } else {
                    updateValue(v, left, right, value);
                }
            } else {
                int mid = (left + right) >> 1;
                int vLeft = (v << 1), vRight = (vLeft + 1);

                if (lazySupported) pushVertex(v, vLeft, vRight);

                if (start <= mid) updateTreeSegment(vLeft, left, mid);
                if (mid < end) updateTreeSegment(vRight, mid + 1, right);

                updateVertex(v, vLeft, vRight);
            }
        }

        abstract void initResult(long... initResultValues);

        abstract void accumulateResult(int v, int left, int right);

        void accumulateIndexResult(int v, int left, int right) {
            accumulateResult(v, left, right);
        }

        void getIndex(int index, long... initResultValues) {
            this.index = index;

            initResult(initResultValues);

            getTreeIndex(1, 0, size - 1);
        }

        void getTreeIndex(int v, int left, int right) {
            if (lazySupported) {
                if (left == right) {
                    accumulateIndexResult(v, left, right);
                } else {
                    int mid = (left + right) >> 1;
                    int vLeft = (v << 1), vRight = (vLeft + 1);

                    pushVertex(v, vLeft, vRight);

                    if (index <= mid) getTreeIndex(vLeft, left, mid);
                    else getTreeIndex(vRight, mid + 1, right);

                    updateVertex(v, vLeft, vRight);
                }
            } else {
                while (left <= right) {
                    accumulateIndexResult(v, left, right);

                    if (left == right) break;

                    int mid = (left + right) >> 1;
                    int vLeft = (v << 1), vRight = (vLeft + 1);

                    if (index <= mid) {
                        v = vLeft;
                        right = mid;
                    } else {
                        v = vRight;
                        left = mid + 1;
                    }
                }
            }
        }
    	
    	void getSegment(int start, int end, long... initResultValues) {
    		this.start = start;
    		this.end = end;
    		
    		initResult(initResultValues);
    		
    		getTreeSegment(1, 0, size - 1);
    	}
    	
    	void getTreeSegment(int v, int left, int right) {
    		if (start <= left && right <= end) {
    			accumulateResult(v, left, right);
    		} else {
    			int mid = (left + right) >> 1;
				int vLeft = (v << 1), vRight = (vLeft + 1);
				
				if (lazySupported) pushVertex(v, vLeft, vRight);
				
				if (start <= mid) getTreeSegment(vLeft, left, mid);
				if (mid < end) getTreeSegment(vRight, mid + 1, right);
				
				if (lazySupported) updateVertex(v, vLeft, vRight);
    		}
    	}
    	
    	int[] toArray() {
    		this.a = new int[size];
    		
    		fillTreeArray(1, 0, size - 1);
    		
    		return a;
    	}
    	
    	void fillTreeArray(int v, int left, int right) {
    		if (left == right) {
    			a[left] = (int)(tree[v]);
    		} else {
    			int mid = (left + right) >> 1;
				int vLeft = (v << 1), vRight = (vLeft + 1);
				
				if (lazySupported) pushVertex(v, vLeft, vRight);
				
				fillTreeArray(vLeft, left, mid);
				fillTreeArray(vRight, mid + 1, right);
				
				if (lazySupported) updateVertex(v, vLeft, vRight);
    		}
    	}
    }
    
    /////////////////////////////////////////////////////////////////////

    static class Treap {

        static class Node {

            static int getCount(Node node) {
                return (node == null ? 0 : node.count);
            }

            static long getValue(Node node) {
                return (node == null ? 0 : node.value);
            }

            static long getSum(Node node) {
                return (node == null ? 0 : node.sum);
            }

            long priority;

            Node left, right;
            int count;

            long value, sum;
            boolean reversed;

            Node(long value) {
                this.priority = rnd.nextLong();
                this.count = 1;
                this.value = value;
                this.sum = value;
                this.reversed = false;
            }

            void update() {
                this.count = getCount(left) + getCount(right) + 1;
                this.sum = getSum(left) + getSum(right) + value;
            }

            void push() {
                if (reversed) {
                    Node tmp = left;
                    left = right;
                    right = tmp;

                    if (left != null) left.reversed ^= true;
                    if (right != null) right.reversed ^= true;

                    reversed = false;
                }
            }
        }

        Node root;
        Node[] splitParts;

        Treap() {
            this.root = null;
            this.splitParts = new Node[2];
        }

        void addValue(long value) {
            Node node = new Node(value);
            root = merge(root, node);
        }

        long getSegmentSum(int startInclusive, int endExclusive) {
            splitClear();
            split(root, endExclusive);

            Node leftMid = splitParts[0];
            Node right = splitParts[1];

            splitClear();
            split(leftMid, startInclusive);

            Node left = splitParts[0];
            Node mid = splitParts[1];

            long result = Node.getSum(mid);

            root = merge(left, mid);
            root = merge(root, right);

            return result;
        }

        void updateValue(Node node, int index, long delta) {
            if (node == null) return;

            node.push();

            int leftCount = Node.getCount(node.left);
            if (index < leftCount) updateValue(node.left, index, delta);
            else if (index == leftCount) node.value += delta;
            else updateValue(node.right, index - leftCount - 1, delta);

            node.update();
        }

        long getValueByIndex(Node node, int index) {
            Node result = getNodeByKey(node, index);
            return Node.getValue(result);
        }

        Node getNodeByKey(Node node, int key) {
            if (node == null) return null;

            node.push();

            int leftCount = Node.getCount(node.left);

            Node result;

            if (key < leftCount) result = getNodeByKey(node.left, key);
            else if (key == leftCount) result = node;
            else result = getNodeByKey(node.right, key - leftCount - 1);

            node.update();

            return result;
        }

        Node merge(Node left, Node right) {
            if (left == null) return right;
            if (right == null) return left;

            left.push();
            right.push();

            Node result;

            if (left.priority < right.priority) {
                left.right = merge(left.right, right);
                result = left;
            } else {
                right.left = merge(left, right.left);
                result = right;
            }

            result.update();

            return result;
        }

        void splitClear() {
            splitParts[0] = null;
            splitParts[1] = null;
        }

        void split(Node node, int key) {
            if (node == null) return;

            node.push();

            int leftCount = Node.getCount(node.left);
            if (key < leftCount) {
                split(node.left, key);

                node.left = splitParts[1];
                splitParts[1] = node;

            } else if (key == leftCount) {
                splitParts[0] = node.left;
                splitParts[1] = node;
                node.left = null;
            } else {
                split(node.right, key - leftCount - 1);

                node.right = splitParts[0];
                splitParts[0] = node;
            }

            node.update();
        }
    }

    /////////////////////////////////////////////////////////////////////
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.