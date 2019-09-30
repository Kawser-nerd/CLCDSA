import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    long h, w;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        h = sc.nextInt();
        w = sc.nextInt();
        solve();
    }

    void solve() {
        long minDiff = Long.MAX_VALUE;
        for (int i = 1; i < h; i++) {
            long firstArea = w * i;
            long diff = Long.MAX_VALUE;
            if ((h - i) % 2 == 0) {
                diff = Math.abs(firstArea - w * (h - i) / 2);
            } else {
                long secondArea = w * (h - i + 1) / 2;
                long thirdArea = w * ((h - i) / 2);
                if (secondArea >= firstArea && firstArea >= thirdArea) {
                    diff = secondArea - thirdArea;
                } else {
                    diff = Math.max(firstArea, secondArea) -
                            Math.min(firstArea, thirdArea);
                }
            }
            if (diff < minDiff) {
                minDiff = diff;
            }
            if (w % 2 == 0) {
                diff = Math.abs(firstArea - w / 2 * (h - i));
            } else {
                long secondArea = (w + 1) / 2 * (h - i);
                long thirdArea = w / 2 * (h - i);
                if (secondArea >= firstArea && firstArea >= thirdArea) {
                    diff = secondArea - thirdArea;
                } else {
                    diff = Math.max(firstArea, secondArea) -
                            Math.min(firstArea, thirdArea);
                }
            }
            if (diff < minDiff) {
                minDiff = diff;
            }
        }
        for (int i = 1; i < w; i++) {
            long firstArea = h * i;
            long diff = Long.MAX_VALUE;
            if ((w - i) % 2 == 0) {
                diff = Math.abs(firstArea - (w - i) * h / 2);
            } else {
                long secondArea = (w - i + 1) / 2 * h;
                long thirdArea = (w - i) / 2 * h;
                if (secondArea >= firstArea && firstArea >= thirdArea) {
                    diff = secondArea - thirdArea;
                } else {
                    diff = Math.max(firstArea, secondArea) -
                            Math.min(firstArea, thirdArea);
                }
            }
            if (diff < minDiff) {
                minDiff = diff;
            }
            if (h % 2 == 0) {
                diff = Math.abs(firstArea - h / 2 * (w - i));
            } else {
                long secondArea = (h + 1) / 2 * (w - i);
                long thirdArea = h / 2 * (w - i);
                if (secondArea >= firstArea && firstArea >= thirdArea) {
                    diff = secondArea - thirdArea;
                } else {
                    diff = Math.max(firstArea, secondArea) -
                            Math.min(firstArea, thirdArea);
                }
            }
            if (diff < minDiff) {
                minDiff = diff;
            }
        }
        System.out.println(minDiff);
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