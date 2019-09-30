import com.sun.deploy.util.ArrayUtil;
import com.sun.tools.javac.util.ArrayUtils;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    /* IO */
    InputReader in;
    BufferedWriter out;
    StringTokenizer tok;
    StringBuilder ans;

    /* FIELDS */
    int n, k;
    double u;
    double p[];

    public static void main(String[] args) throws IOException {
        Main sol = new Main();
        sol.begin();
    }

    private void begin() throws IOException {
        // io
        boolean file = true;
        if (file)
            in = new InputReader(new FileInputStream("C-small-1-attempt0 (1).in"));
        else
            in = new InputReader(System.in);
        ans = new StringBuilder();


        int nCases = in.nextInt();
        for (int cas = 1; cas <= nCases; cas++) {
            n = in.nextInt();
            k = in.nextInt();
            u = Double.parseDouble(in.next());
            p = new double[n];
            for (int i = 0; i < n; i++) {
                p[i] = Double.parseDouble(in.next());
            }
            double max = solve();
            ans.append(String.format("Case #%d: %.12f\n", cas, max));
        }
        System.out.println(ans.toString());

        // output to file
        out = new BufferedWriter(new FileWriter("output.txt"));
        out.write(ans.toString());
        out.flush();
        out.close();
    }

    private double solve() {
        while (u > 0.0000000001) {
            Arrays.sort(p);
            double min = p[0];
            double next = 1.0;
            int countMin = 0;
            for (int i = 0; i < n; i++)
                if (p[i] == min) {
                    countMin++;
                } else {
                    next = p[i];
                    break;
                }
            double maxCan = (next - min) * countMin;
            double can = Math.min(maxCan, u);
            u -= can;
            for (int i = 0; i < countMin; i++)
                p[i] += can / countMin;

        }

        double product = 1;
        for (double x : p)
            product *= x;
        return product;
    }


}

class InputReader {
    BufferedReader reader;
    StringTokenizer tok;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tok = new StringTokenizer("");
    }

    public String next() {
        while (!tok.hasMoreTokens())
            try {
                tok = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        return tok.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }
}