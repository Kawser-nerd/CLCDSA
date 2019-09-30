import java.io.*;
import java.util.regex.Pattern;
import java.util.StringTokenizer;
import java.util.Locale;

/**
 * @author Roman
 */
public class C implements Runnable {

    static {
        Locale.setDefault(Locale.ENGLISH);
    }

    public static final String PROBLEM_ID = "C";

    private class ProblemSolver {

        int CYCLES = 500;

        int n;
        double[] x, y, z, p, pInv;
        static final double EPS = 1e-10;

        private double estimate(double cx, double cy, double cz) {
            double result = 0.0;
            for (int i = 0; i < n; i++) {
                double current = Math.abs(x[i] - cx) + Math.abs(y[i] - cy) + Math.abs(z[i] - cz);
                current *= pInv[i];
                result = Math.max(result, current);
            }
            return result;
        }

        private void solveOne() throws IOException {
            n = nextInt();
            x = new double[n];
            y = new double[n];
            z = new double[n];
            p = new double[n];
            pInv = new double[n]; 
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();        
                y[i] = nextInt();
                z[i] = nextInt();
                p[i] = nextInt();
                pInv[i] = 1.0 / p[i];
            }

            double cx = 0, cy = 0, cz = 0;
            double answer = Double.POSITIVE_INFINITY;
            double step = 1e7;
            for (int cycles = 0; cycles < CYCLES; cycles++) {

                for (int mv = 0; mv < 10; mv++) {
                    for (int dx = -1; dx <= 1; dx++)
                        for (int dy = -1; dy <= 1; dy++)
                            for (int dz = -1; dz <= 1; dz++) {
                                double px = cx + step * dx;
                                double py = cy + step * dy;
                                double pz = cz + step * dz;
                                double t = estimate(px, py, pz);
                                if (t < answer) {
                                    answer = t;
                                    cx = px;
                                    cy = py;
                                    cz = pz;
                                }
                            }
                }

                step /= 2.0;
            }

            out.printf("%.6f", answer + EPS);
        }

        public void solve() throws Throwable {
            int tc = nextInt();
            for (int t = 0; t < tc; t++) {
                System.out.println(t);

                out.print("Case #" + (t + 1) + ": ");
                solveOne();
                out.println();
            }
        }

    }

    public static final String PROBLEM_IN_SUFFIX = ".in";
    public static final String PROBLEM_OUT_SUFFIX = ".out";
    public static final Pattern PROBLEM_FILE_PATTERN = Pattern.compile("^" + PROBLEM_ID + ".*" + PROBLEM_IN_SUFFIX + "$", Pattern.CASE_INSENSITIVE);

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tokenizer;

    private String nextLine() throws IOException {
        return in.readLine();
    }

    private String nextToken() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            String line = nextLine();
            if (line == null) {
                return null;
            }
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    private int nextInt() throws IOException {
        String token = nextToken();
        return Integer.parseInt(token);
    }

    private void solveFile() throws Throwable {
        tokenizer = new StringTokenizer("");
        new C.ProblemSolver().solve();
    }

    private void solve(String fileName) {
        try {
            in = new BufferedReader(new FileReader(fileName));
            out = new PrintWriter(new FileWriter(fileName + PROBLEM_OUT_SUFFIX));

            solveFile();

            in.close();
            out.close();
        } catch (Throwable t) {
            t.printStackTrace();
        }
    }

    public void run() {
        File dir = new File(".");
        FilenameFilter filter = new FilenameFilter() {
            public boolean accept(File file, String name) {
                return PROBLEM_FILE_PATTERN.matcher(name).matches();
            }
        };
        String[] children = dir.list(filter);
        if (children != null) {
            for (String file : children) {
                solve(file);
            }
        }
    }

    public static void main(String[] args) {
        new Thread(new C()).start();
    }

}
