import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    int n;
    double[] axs, ays, bxs, bys;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        axs = new double[n];
        ays = new double[n];
        bxs = new double[n];
        bys = new double[n];
        for (int i = 0; i < n; i++) {
            axs[i] = sc.nextDouble();
            ays[i] = sc.nextDouble();
        }
        for (int i = 0; i < n; i++) {
            bxs[i] = sc.nextDouble();
            bys[i] = sc.nextDouble();
        }
        solve();
    }

    void solve() {
        double cgax = 0;
        double cgay = 0;
        double cgbx = 0;
        double cgby = 0;
        for (int i = 0; i < n; i++) {
            cgax += axs[i];
            cgay += ays[i];
            cgbx += bxs[i];
            cgby += bys[i];
        }
        cgax /= n;
        cgay /= n;
        cgbx /= n;
        cgby /= n;
        double maxDistanceA = 0;
        for (int i = 0; i < n; i++) {
            double distance = distance(axs[i], ays[i], cgax, cgay);
            if (maxDistanceA < distance) {
                maxDistanceA = distance;
            }
        }
        double maxDistanceB = 0;
        for (int i = 0; i < n; i++) {
            double distance = distance(bxs[i], bys[i], cgbx, cgby);
            if (maxDistanceB < distance) {
                maxDistanceB = distance;
            }
        }
        System.out.println(maxDistanceB / maxDistanceA);
    }

    static double distance(double x, double y, double cgx, double cgy) {
        return Math.sqrt((x - cgx) * (x - cgx) + (y - cgy) * (y - cgy));
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}