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
import java.util.List;
import java.util.StringTokenizer;
import java.util.concurrent.*;

public class C {
    private static String FILENAME = null;
    static {
        //FILENAME = "C-sample";
        FILENAME = "C-small";
        //FILENAME = "C-large";
    }

    public static void main(String[] args) {
        new C().run();
    }

    private PrintStream out;
    private final BufferedReader reader;
    private StringTokenizer tokenizer = new StringTokenizer("");

    public C() {
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

        private final int N;
        private final int caseNumber;
        private int[] SEEN;
        private List<Equation> equations;
        private long[] values;
        private boolean fail = false;

        // Do all input reading here!!
        public Solver(int caseNumber) {
            this.caseNumber = caseNumber;
            N = getInt();
            SEEN = new int[N - 1];
            for (int i = 0; i < N - 1; i++) {
                SEEN[i] = getInt() - 1;
            }
        }

        // Do no reading here! This is run async!
        // Solve the actual problem here
        public String call() throws Exception {
            debug("solving case %d", caseNumber);
            equations = new ArrayList<Equation>();
            for (int a = 0; a < N - 1; a++) {
                int b = SEEN[a];
                for (int i = a + 1; i < N; i++) {
                    if (i != b) {
                        equations.add(new Equation(i, b - a, a, b, b - i, i - a));
                    }
                }
            }
            for (int i = 0; i < 10000; i++) {
                String s = tryStuff();
                if (s != "Impossible") {
                    return s;
                }
            }
            return "Impossible";
        }

        private String tryStuff() {
            fail = false;
            values = new long[N];
            for (int i = 0; i < N; i++) {
                values[i] = (long) (100*N*Math.random());
            }
            for (int i = 0; i < 1000; i++) {
                if (bumpValues()) {
                    StringBuffer sb = new StringBuffer();
                    for (int j = 0; j < N; j++) {
                        if (j > 0) {
                            sb.append(" ");
                        }
                        sb.append(values[j]);
                    }
                    return sb.toString();
                }
                if (fail) {
                    return "Impossible";
                }
            }
            return "Impossible";
        }

        private boolean bumpValues() {
            for (Equation equation : equations) {
                long leftSide = equation.leftCoeff * values[equation.leftIndex];
                long rightSide = equation.rightIndex1Coeff * values[equation.rightIndex1] + equation.coeff2 * values[equation.rightIndex2];
                if (leftSide >= rightSide) {
                    values[equation.leftIndex] = rightSide / equation.leftCoeff;
                    if (rightSide % equation.leftCoeff == 0) {
                        values[equation.leftIndex]--;
                    }
                    if (values[equation.leftIndex] < 0) {
                        //debug("fail early");
                        fail = true;
                        return false;
                    }
                    return false;
                }
            }
            return true;
        }

        private class Equation {
            private final int leftIndex;
            long leftCoeff;

            private final int rightIndex1;
            private final int rightIndex2;
            final long rightIndex1Coeff;
            private final long coeff2;

            private Equation(int leftIndex, long leftCoeff, int rightIndex1, int rightIndex2, long rightIndex1Coeff, long coeff2) {
                this.leftIndex = leftIndex;
                this.leftCoeff = leftCoeff;
                this.rightIndex1 = rightIndex1;
                this.rightIndex2 = rightIndex2;
                this.rightIndex1Coeff = rightIndex1Coeff;
                this.coeff2 = coeff2;
            }
        }
    }
}
