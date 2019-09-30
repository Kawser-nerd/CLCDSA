import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.concurrent.*;

public class A {
    private static String FILENAME = null;
    static {
        //FILENAME = "A-sample";
        //FILENAME = "A-small";
        FILENAME = "A-large";
    }

    public static void main(String[] args) {
        new A().run();
    }

    private PrintStream out;
    private final BufferedReader reader;
    private StringTokenizer tokenizer = new StringTokenizer("");

    public A() {
        try {
            if (FILENAME == null) {
                out = System.out;
                reader = new BufferedReader(new InputStreamReader(System.in));
            } else {
                out = new PrintStream(new FileOutputStream("source/" + FILENAME + ".out"));
                reader = new BufferedReader(new FileReader("source/" + FILENAME + ".in"));
            }
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public void run() {
        try {
            runCases();
        } finally {
            out.close();
        }
    }

    public void debug(String s, Object... args) {
        System.err.printf("DEBUG: " + s + "\n", args);
    }

    private void runCases() {
        int numProcs = Runtime.getRuntime().availableProcessors();
        debug("num processors: %d", numProcs);
        ExecutorService service = Executors.newFixedThreadPool(numProcs);
        try {
            int cases = getInt();
            ArrayList<Future<String>> list = new ArrayList<Future<String>>();
            for (int c = 1; c <= cases; c++) {
                Solver solver = new Solver(c);
                list.add(service.submit(solver));
            }
            for (int c = 1; c <= cases; c++) {
                Future<String> future = list.get(c - 1);
                try {
                    String s = "Case #" + c + ": " + future.get();
                    out.println(s);
                    if (out != System.out) {
                        System.out.println(s);
                    }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                } catch (ExecutionException e) {
                    e.getCause().printStackTrace();
                }
            }
        } finally {
            service.shutdown();
            debug("done with all!");
        }
    }

    public String readLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public String getToken() {
        while (true) {
            if (tokenizer.hasMoreTokens()) {
                return tokenizer.nextToken();
            }
            String s = readLine();
            if (s == null) {
                return null;
            }
            tokenizer = new StringTokenizer(s, " \t\n\r");
        }
    }

    public double getDouble() {
        return Double.parseDouble(getToken());
    }

    public int getInt() {
        return Integer.parseInt(getToken());
    }

    public long getLong() {
        return Long.parseLong(getToken());
    }

    public BigInteger getBigInt() {
        return new BigInteger(getToken());
    }

    public BigDecimal getBigDec() {
        return new BigDecimal(getToken());
    }

    public class Solver implements Callable<String> {

        private final int caseNumber;
        private int N;
        private final int[] D;
        private final int[] L;
        private final int TARGET;

        // Do all input reading here!!
        public Solver(int caseNumber) {
            this.caseNumber = caseNumber;
            N = getInt();
            D = new int[N];
            L = new int[N];
            for (int i = 0; i < N; i++) {
                D[i] = getInt();
                L[i] = getInt();
            }
            TARGET = getInt();
        }

        // Do no reading here! This is run async!
        // Solve the actual problem here
        public String call() throws Exception {
            debug("solving case %d", caseNumber);
            int[] bestArc = new int[N + 1];
            bestArc[0] = D[0];
            if (2 * D[0] >= TARGET) {
                return "YES";
            }
            for (int i = 0; i < N - 1; i++) {
                for (int j = i + 1; j < N; j++) {
                    int dist = D[j] - D[i];
                    if (bestArc[i] >= dist) {
                        int curJArc = Math.min(L[j], dist);
                        if (curJArc > bestArc[j]) {
                            bestArc[j] = curJArc;
                            if (D[j] + curJArc >= TARGET) {
                                return "YES";
                            }
                        }
                    }
                }
            }
            return "NO";
        }
    }
}
