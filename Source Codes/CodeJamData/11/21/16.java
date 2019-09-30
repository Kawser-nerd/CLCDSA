import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class A implements Runnable {

    private static final String DIR = "E:\\isinev\\programming\\contests\\gcj\\11round1B\\";

    String problemName = A.class.getName();

    static final int inf = (int)1e9;

//	String fileName = String.format(DIR + "%s-statement", problemName);
    public char[][] c;
    public int n;
//	String fileName = String.format(DIR + "%s-small-attempt0", problemName);
	String fileName = String.format(DIR + "%s-large", problemName);

	public void run() {
		try {
			int nt = nextInt();
cases_loop:
			for (int it = 1; it <= nt; it++) {
                n = nextInt();
                c = new char[n][n];
                for (int i = 0; i < n; i++) {
                    c[i] = next().toCharArray();
                }
                double[] wp = new double[n];
                double[] owp = new double[n];
                double[] oowp = new double[n];

                for (int i = 0; i < n; i++) {
                    wp[i] = wp(i, -1);
                }
                for (int i = 0; i < n; i++) {
                    double a = 0;
                    double b = 0;
                    for (int j = 0; j < n; j++) {
                        if (i != j && c[i][j] != '.') {
                            a += wp(j, i);
                            b++;
                        }
                    }
                    owp[i] = a / b;
                }
                for (int i = 0; i < n; i++) {
                    double a = 0;
                    double b = 0;
                    for (int j = 0; j < n; j++) {
                        if (i != j && c[i][j] != '.') {
                            a += owp[j];
                            b++;
                        }
                    }
                    oowp[i] = a / b;
                }


				out.format("Case #%d:\n", it);
                for (int i = 0; i < n; i++) {
                    out.format("%.8f%n", .25 * wp[i] + .5 * owp[i] + .25 * oowp[i]);
                }
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			out.close();
		}
	}

    double wp(int team, int exclude) {
        double rs = 0;
        int rn = 0;
        for (int i = 0; i < n; i++) {
            if (i == exclude || c[team][i] == '.') {
                continue;
            }
            rn++;
            if (c[team][i] == '1') {
                rs++;
            }
        }
        return rs / (double) rn;
    }

	static {
		Locale.setDefault(Locale.US);
	}
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;
	public A() throws FileNotFoundException {
		in = new BufferedReader(new FileReader(new File(fileName + ".in")));
		out = new PrintWriter(fileName + ".out");
		st = new StringTokenizer("");
	}

	public static void main(String[] args) throws FileNotFoundException {
		new Thread(new A()).start();
	}

	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}
	int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(next());
	}
	double nextDouble() throws NumberFormatException, IOException {
		return Double.parseDouble(next());
	}
	long nextLong() throws NumberFormatException, IOException {
		return Long.parseLong(next());
	}
}