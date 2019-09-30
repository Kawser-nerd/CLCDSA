import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.concurrent.*;

public class B {
    private static String FILENAME = null;
    static {
        //FILENAME = "B-sample";
        //FILENAME = "B-small";
        FILENAME = "B-large";
    }

    public static void main(String[] args) {
        new B().run();
    }

    private PrintStream out;
    private final BufferedReader reader;
    private StringTokenizer tokenizer = new StringTokenizer("");

    public B() {
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
        private int W;
        private int L;
        private final List<Person> R;

        // Do all input reading here!!
        public Solver(int caseNumber) {
            this.caseNumber = caseNumber;
            N = getInt();
            W = getInt();
            L = getInt();
            R = new ArrayList<Person>();
            for (int i = 0; i < N; i++) {
                R.add(new Person(i, getInt()));
            }
        }

        // Do no reading here! This is run async!
        // Solve the actual problem here
        public String call() throws Exception {
            debug("solving case %d", caseNumber);
            Collections.sort(R, new Comparator<Person>() {
                public int compare(Person person, Person person1) {
                    return person.radius - person1.radius;
                }
            });
            int X[] = new int[N];
            int Y[] = new int[N];

            int x = 0;
            int y = 0;
            int curMax = 0;
            boolean firstCol = true;
            for (Person p : R) {
                if (x + p.radius > W) {
                    x = 0;
                    if (firstCol) {
                        y += curMax;
                        firstCol = false;
                    } else {
                        y += 2 * curMax;
                    }
                    curMax = 0;
                }
                int preMoveX = x == 0 ? 0 : p.radius;
                int preMoveY = firstCol ? 0 : p.radius;
                X[p.num] = x + preMoveX;
                Y[p.num] = y + preMoveY;
                if (y + preMoveY > L) {
                    throw new RuntimeException(String.format("%d, %d, %d", p.num, X[p.num], Y[p.num]));
                }
                x += preMoveX + p.radius;
                curMax = Math.max(curMax, p.radius);
            }

            StringBuffer sb = new StringBuffer();
            for (int i = 0; i < N; i++) {
                sb.append(X[i]).append(" ").append(Y[i]).append(" ");
            }
            sb.setLength(sb.length() - 1);
            return sb.toString();
        }

        private class Person {
            private final int num;
            private final int radius;

            public Person(int num, int radius) {
                this.num = num;
                this.radius = radius;
            }
        }
    }
}
