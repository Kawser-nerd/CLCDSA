import java.io.*;
import java.util.*;

public class Main {
    /**********************************************************************************************
     *                                            DEBUG                                           *
     **********************************************************************************************/
    private interface InputType {
        int STANDARD = 0;
        int FILE = 1;
        int HARDCODE = 2;
    }

    private final static int INPUT_TYPE = InputType.STANDARD;
    private final static String[] HARDCODE_INPUT = {
            "2 5 4",
            "2 6 3",
            "31 41 5",
    };
    private final static String FILE_INPUT_DIR = new File("").getAbsolutePath()
            + "/src/common/template";



    /**********************************************************************************************
     *                                             MAIN                                           *
     **********************************************************************************************/
    private static class Solver {
        private static final int MIN = -999_999_999;
        private static final int MAX = 999_999_999;

        public void solve(Reader in, PrintWriter out) throws IOException {
            int[] a = {in.nextInt(), in.nextInt(), in.nextInt()};
            Arrays.sort(a);

            int res = 0;

            int start = 3 * a[2];

            while (true) {
                int diff = start - a[0] - a[1] - a[2];
                if (diff % 2 == 0) {
                    res = diff/2;
                    break;
                } else {
                    start += 3;
                }
            }

            out.print(res);
        }
    }



    /**********************************************************************************************
     *                                           TEMPLATE                                         *
     **********************************************************************************************/
    public static void main(String[] args) throws IOException {
        PrintWriter out;
        Reader in;
        if (INPUT_TYPE == InputType.FILE) {
            for (File file : new File(FILE_INPUT_DIR).listFiles()) {
                if (file.getName().contains(".in")) {
                    solveFile(file.getAbsolutePath());
                }
            }
        } else if (INPUT_TYPE == InputType.HARDCODE) {
            for (String s : HARDCODE_INPUT) {
                solveHardCode(s);
            }
        } else { // STANDARD
            in = new Reader(System.in);
            out = new PrintWriter(System.out);
            new Solver().solve(in, out);
            out.flush();
        }
    }

    private static void solveHardCode(String input) throws IOException {
        // prepare
        Reader in = new Reader(new ByteArrayInputStream(input.getBytes()));
        PrintWriter out = new PrintWriter(System.out);
        out.println("===>>> INPUT");
        out.println(input + "\n\n");
        out.println("===>>> OUTPUT");

        // solve
        long start = System.currentTimeMillis();
        new Solver().solve(in, out);
        long end = System.currentTimeMillis();

        // log
        out.println("\n");
        out.println("===========");
        out.println("Took: " + (end - start) + "ms");
        out.println("====================================================================");
        out.println();
        out.println();
        // flush
        out.flush();
    }

    private static void solveFile(String inputPath) throws IOException {
        // prepare
        int idx = inputPath.lastIndexOf("in");
        String outputPath = inputPath.substring(0, idx) + "out";
        Reader in = new Reader(new FileInputStream(inputPath));
        PrintWriter out = new PrintWriter(new FileOutputStream(outputPath));

        // solve
        long start = System.currentTimeMillis();
        new Solver().solve(in, out);
        long end = System.currentTimeMillis();

        // flush to file
        out.flush();

        // replace with standard output for logging
        out = new PrintWriter(System.out);

        // log
        out.println("\n");
        out.println("Input path: " + inputPath);
        out.println("Output path: " + outputPath);
        out.println("===========");
        out.println("Took: " + (end - start) + "ms");
        out.println("====================================================================");
        out.flush();
    }

    /** Reader **/
    private static class Reader {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public Reader(InputStream input) {
            reader = new BufferedReader(
                    new InputStreamReader(input));
            tokenizer = new StringTokenizer("");
        }

        private String nextWord() throws IOException {
            while (!tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        private int nextInt() throws IOException {
            return Integer.parseInt(nextWord());
        }

        private long nextLong() throws IOException {
            return Long.parseLong(nextWord());
        }

        private double nextDouble() throws IOException {
            return Double.parseDouble(nextWord());
        }
    }
}