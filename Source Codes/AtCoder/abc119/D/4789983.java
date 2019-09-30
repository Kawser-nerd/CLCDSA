import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int a = sc.nextInt();
        int b = sc.nextInt();
        int q = sc.nextInt();
        TreeSet<Long> shrines = new TreeSet<Long>();
        TreeSet<Long> temples = new TreeSet<Long>();
        for (int i = 0; i < a; i++) {
            shrines.add(sc.nextLong());
        }
        for (int i = 0; i < b; i++) {
            temples.add(sc.nextLong());
        }
        for (int i = 0; i < q; i++) {
            long d = sc.nextLong();
            long min = (1L<<60);
            long dist = 0;
            Long closeShrine = 0L;
            Long closeTemple = 0L;

            closeShrine = shrines.ceiling(d);
            if (closeShrine != null) {
            dist += Math.abs(closeShrine - d);
                closeTemple = temples.ceiling(closeShrine);
                if (closeTemple != null) {
                    dist += Math.abs(closeTemple - closeShrine);
                    if (dist < min) {
                        min = dist;
                    }
                }
            }

            dist = 0;
            closeTemple = temples.ceiling(d);
            if (closeTemple != null) {
                dist += Math.abs(closeTemple - d);
                closeShrine = shrines.ceiling(closeTemple);
                if (closeShrine != null) {
                    dist += Math.abs(closeShrine - closeTemple);
                    if (dist < min) {
                        min = dist;
                    }
                }
            }

            dist = 0;
            closeShrine = shrines.floor(d);
            if (closeShrine != null) {
                dist += Math.abs(closeShrine - d);
                closeTemple = temples.floor(closeShrine);
                if (closeTemple != null) {
                    dist += Math.abs(closeTemple - closeShrine);
                    if (dist < min) {
                        min = dist;
                    }
                }
            }

            dist = 0;
            closeTemple = temples.floor(d);
            if (closeTemple != null) {
                dist += Math.abs(closeTemple - d);
                closeShrine = shrines.floor(closeTemple);
                if (closeShrine != null) {
                    dist += Math.abs(closeShrine - closeTemple);
                    if (dist < min) {
                        min = dist;
                    }
                }
            }

            dist = 0;
            closeShrine = shrines.ceiling(d);
            if (closeShrine != null) {
                dist += Math.abs(closeShrine - d);
                closeTemple = temples.floor(closeShrine);
                if (closeTemple != null) {
                    dist += Math.abs(closeTemple - closeShrine);
                    if (dist < min) {
                        min = dist;
                    }
                }
            }

            dist = 0;
            closeTemple = temples.ceiling(d);
            if (closeTemple != null) {
                dist += Math.abs(closeTemple - d);
                closeShrine = shrines.floor(closeTemple);
                if (closeShrine != null) {
                    dist += Math.abs(closeShrine - closeTemple);
                    if (dist < min) {
                        min = dist;
                    }
                }
            }

            dist = 0;
            closeShrine = shrines.floor(d);
            if (closeShrine != null) {
                dist += Math.abs(closeShrine - d);
                closeTemple = temples.ceiling(closeShrine);
                if (closeTemple != null) {
                    dist += Math.abs(closeTemple - closeShrine);
                    if (dist < min) {
                        min = dist;
                    }
                }
            }

            dist = 0;
            closeTemple = temples.floor(d);
            if (closeTemple != null) {
                dist += Math.abs(closeTemple - d);
                closeShrine = shrines.ceiling(closeTemple);
                if (closeShrine != null) {
                    dist += Math.abs(closeShrine - closeTemple);
                    if (dist < min) {
                        min = dist;
                    }
                }
            }

            System.out.println(min);
        }
    }

    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;
        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
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

        String nextLine()
        {
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