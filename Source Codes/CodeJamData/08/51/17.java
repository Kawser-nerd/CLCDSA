import java.io.*;
import java.util.regex.Pattern;
import java.util.StringTokenizer;
import java.util.Locale;
import java.util.Arrays;

/**
 * @author Roman
 */
public class A implements Runnable {

    static {
        Locale.setDefault(Locale.ENGLISH);
    }

    public static final String PROBLEM_ID = "A";

    int MAXC = 6666;
    int[] minX = new int[MAXC];
    int[] maxX = new int[MAXC];
    int[] minY = new int[MAXC];
    int[] maxY = new int[MAXC];

    int PTS = 1000000;
    int[] tx = new int[PTS];
    int[] ty = new int[PTS];
    int tt;

    int[] dx = new int[] {0, 1, 0, -1};
    int[] dy = new int[] {1, 0, -1, 0};

    private class ProblemSolver {

        private void update(int x1, int y1, int x2, int y2) {
            if (x1 == x2) {
                if (y1 > y2) {
                    int t = y1; y1 = y2; y2 = t;
                }
                minX[y1] = Math.min(minX[y1], x1);
                maxX[y1] = Math.max(maxX[y1], x1);
            } else {
                if (x1 > x2) {
                    int t = x1; x1 = x2; x2 = t;
                }
                minY[x1] = Math.min(minY[x1], y1);
                maxY[x1] = Math.max(maxY[x1], y1);
            }
        }

        private void solveOne() throws IOException {
            Arrays.fill(minX, Integer.MAX_VALUE);
            Arrays.fill(maxX, Integer.MIN_VALUE);
            Arrays.fill(minY, Integer.MAX_VALUE);
            Arrays.fill(maxY, Integer.MIN_VALUE);

            int l = nextInt();
            int cx = MAXC / 2;
            int cy = MAXC / 2;
            int d = 0;

            tt = 0;
            addPoint(cx, cy);

            for (int i = 0; i < l; i++) {
                char[] c = nextToken().toCharArray();
                int rep = nextInt();
                for (int j = 0; j < rep; j++)
                    for (char move : c) {
                        switch(move) {
                            case 'F':
                                int nx = cx + dx[d];
                                int ny = cy + dy[d];
                                update(cx, cy, nx, ny);
                                addPoint(nx, ny);
                                cx = nx;
                                cy = ny;
                                break;
                            case 'L':
                                d--;
                                if (d < 0) d += 4;
                                break;
                            case 'R':
                                d++;
                                if (d >= 4) d -= 4;
                                break;
                            default:
                                throw new IllegalStateException();
                        }

                    }
            }

            int answer = 0;
            for (int x = 0; x < MAXC; x++)
                for (int y = 0; y < MAXC; y++) {
                    boolean xx = minX[y] <= x && x < maxX[y];
                    boolean yy = minY[x] <= y && y < maxY[x];
                    if (xx || yy) {
                        answer++;
                    }
                }

            out.print(answer - square());
        }

        private int square() {
            int result = 0;
            for (int i = 0; i < tt; i++) {
                int j = i + 1;
                if (j >= tt) {
                    j = 0;
                }

                result += (tx[i] - tx[j]) * (ty[i] + ty[j]);
            }

            result = Math.abs(result) / 2;

            return result;
        }

        private void addPoint(int cx, int cy) {
            tx[tt] = cx;
            ty[tt] = cy;
            tt++;
        }

        public void solve() throws Throwable {
            int tc = nextInt();
            for (int t = 0; t < tc; t++) {
                System.out.println("Progress: #" + (t + 1) + " out of " + tc);

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
        new A.ProblemSolver().solve();
    }

    private void solve(String fileName) {
        try {
            System.out.println("Solving " + fileName);

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
        new Thread(new A()).start();
    }

}
