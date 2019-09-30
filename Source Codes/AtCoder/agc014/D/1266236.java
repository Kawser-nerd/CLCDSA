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

    // SOLUTION!!!
    // HACK ME PLEASE IF YOU CAN!!!
    // PLEASE!!!
    // PLEASE!!!
    // PLEASE!!!

    private final static Random rnd = new Random();
    private final static String fileName = "";

    int[][] graph;
    int[] parents;

    private void solve() {
        int n = readInt();

        GraphBuilder graphBuilder = GraphBuilder.createInstance(n);
        for (int i = 0; i < n - 1; ++i) {
            int from = readInt() - 1;
            int to = readInt() - 1;

            graphBuilder.addEdge(from, to);
        }

        this.graph = graphBuilder.build();

        int root = -1;
        for (int v = 0; v < n; ++v) {
            if (graph[v].length != -1) {
                root = v;
                break;
            }
        }

        if (-1 == root) {
            out.println("Second");
            return;
        }



        int[][] bfsResult = bfs(0);
        int maxV = 0;

        for (int v = 0; v < n; ++v) {
            if (bfsResult[0][v] > bfsResult[0][maxV]) {
                maxV = v;
            }
        }

        this.parents = new int[n];
        bfsResult = bfs(maxV);
        int maxV2 = 0;

        for (int v = 0; v < n; ++v) {
            if (bfsResult[0][v] > bfsResult[0][maxV2]) {
                maxV2 = v;
            }
        }

        List<Integer> way = new ArrayList<>();
        for (int cur = maxV2; cur != bfsResult[1][maxV]; cur = bfsResult[1][cur]) {
            way.add(cur);
        }

        root = way.get(way.size() / 2);
        dfs(root, -1);

        int[] neighbourCounts = new int[n];
        for (int v = 0; v < n; ++v) {
            neighbourCounts[v] = graph[v].length;
        }

        Queue<Integer> queue = new ArrayDeque<>();
        for (int v = 0; v < n; ++v) {
            if (neighbourCounts[v] == 1) queue.add(v);
        }

        final int WHITE = 1, BLACK = -1;
        int[] colors = new int[n];

        while (queue.size() > 0) {
            int leaf = queue.poll();
            if (colors[leaf] != 0) continue;

            int whitesCount = 0;
            for (int v : graph[leaf]) {
                if (colors[v] == WHITE) ++whitesCount;
            }

            if (graph[leaf].length == whitesCount) {
                out.println("First");
                return;
            }

            int parent = parents[leaf];
            colors[leaf] = BLACK;

            if (parent != -1 && colors[parent] == 0) {
                colors[parent] = WHITE;

                for (int to : graph[parent]) {
                    --neighbourCounts[to];
                    if (neighbourCounts[to] == 1) {
                        queue.add(to);
                    }
                }
            }
        }

        for (int v = 0; v < n; ++v) {
            if (colors[v] != WHITE) continue;

            int whitesCount = 0;
            for (int to : graph[v]) {
                if (colors[to] == WHITE) ++whitesCount;
            }

            if (graph[v].length == whitesCount) {
                out.println("First");
                return;
            }
        }

        out.println("Second");
    }

    int[][] bfs(int start) {
        int[] distances = new int[graph.length];
        int[] parents = new int[graph.length];
        Arrays.fill(parents, -1);

        boolean[] used = new boolean[graph.length];

        Queue<Integer> queue = new ArrayDeque<>();
        queue.add(start);
        used[start] = true;

        while (queue.size() > 0) {
            int from = queue.poll();
            for (int to : graph[from]) {
                if (used[to]) continue;

                distances[to] = distances[from] + 1;
                parents[to] = from;
                used[to] = true;
                queue.add(to);
            }
        }

        return new int[][] { distances, parents };
    }

    void dfs(int from, int parent) {
        parents[from] = parent;
        for (int to : graph[from]) {
            if (to == parent) continue;

            dfs(to, from);
        }
    }

    /////////////////////////////////////////////////////////////////////

    private final static boolean FIRST_INPUT_STRING = false;
    private final static boolean MULTIPLE_TESTS = true;
    private final boolean ONLINE_JUDGE = !new File("input.txt").exists();

    private final static int MAX_STACK_SIZE = 128;

    private final static boolean OPTIMIZE_READ_NUMBERS = false;

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
                tok = new StringTokenizer(readLine());
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
            graph[index] = new ArrayList<>();
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
                edges[v] = new ArrayList<>();
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

        void printWithSpace(double d){
            printf(formatWithSpace, d);
        }

        void printAll(double...d){
            for (int i = 0; i < d.length - 1; ++i){
                printWithSpace(d[i]);
            }

            print(d[d.length - 1]);
        }

        @Override
        public void println(double d){
            printlnAll(d);
        }

        void printlnAll(double... d){
            printAll(d);
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
    //////////////// Some useful constants and functions ////////////////
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

    private static boolean checkBit(int mask, int bit){
        return (mask & (1 << bit)) != 0;
    }
    private static boolean checkBit(long mask, int bit){
        return (mask & (1L << bit)) != 0;
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

    private static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    private static long gcd(long a, long b) {
        return (a == 0 ? b : gcd(b % a, a));
    }

    /////////////////////////////////////////////////////////////////////

    private static class MultiSet<ValueType> {

        public static <ValueType> MultiSet<ValueType> createMultiSet() {
            Map<ValueType, Integer> multiset = new HashMap<>();
            return new MultiSet<>(multiset);
        }

        private final Map<ValueType, Integer> multiset;
        private int size;

        public MultiSet(Map<ValueType, Integer> multiset) {
            this.multiset = multiset;
            this.size = 0;
        }

        public int size() {
            return size;
        }

        public void inc(ValueType value) {
            int count = get(value);
            multiset.put(value, count + 1);

            ++size;
        }

        public void dec(ValueType value) {
            int count = get(value);
            if (count == 0) return;

            if (count == 1) multiset.remove(value);
            else multiset.put(value, count - 1);

            --size;
        }

        public int get(ValueType value) {
            Integer count = multiset.get(value);
            return (count == null ? 0 : count);
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

        int getId(KeyType key) {
            Integer id = super.get(key);
            if (id == null) {
                super.put(key, id = size());
            }

            return id;
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
     * Generates list with values 0..<n
     * @param n - exclusive limit of sequence
     */
    private static List<Integer> order(int n) {
        List<Integer> sequence = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            sequence.add(i);
        }

        return sequence;
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.