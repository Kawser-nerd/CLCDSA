import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main implements Runnable {


    private void solve() throws IOException {

        int N = nextInt();
        TreeSet<Integer> ts = new TreeSet<>();
        HashMap<Integer,Integer> hm = new HashMap<>();
        HashMap<Integer,Integer> times = new HashMap<>();
        int max = 0;
        for(int i = 0; i < N; ++i) {
            int cur = nextInt();
            max = Math.max(max, cur);
            ts.add(cur);
            if(!hm.containsKey(cur)) {
                hm.put(cur, i);
            }
            if(!times.containsKey(cur)) {
                times.put(cur, 1);
            } else {
                times.put(cur,times.get(cur) + 1);
            }
        }
        long[] ret = new long[N];
        while(true) {
            Integer need = ts.lower(max);
            if(need == null) {
                ret[(hm.get(max))] += (long)times.get(max) * (long)(max);
                break;
            } else {
                long diff = max - ts.lower(max);
                ret[(hm.get(max))] += (long)times.get(max) * (long)(diff);
                times.put(need,times.get(need) + times.get(max));
                if(hm.get(max) < hm.get(need)) {
                    hm.put(need,hm.get(max));
                }
                max = need;
            }
        }
        for(int i = 0; i < ret.length; ++i) {
            writer.println(ret[i]);
        }

    }



    public static void main(String[] args) {
        new Main().run();
    }

    BufferedReader reader;
    //    BufferedReader reader2;
    StringTokenizer tokenizer;
    PrintWriter writer;
    //    BufferedWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
//            reader = new BufferedReader(new FileReader("highcard.in"));
            //            reader2 = new BufferedReader(new FileReader("1.in"));
            tokenizer = null;
            writer = new PrintWriter(System.out);
//            writer = new     PrintWriter("highcard.out");
//                                                    writer = new BufferedWriter(System.out);
            //                        writer = new BufferedWriter(new OutputStreamWriter(System.out));
            solve();
            reader.close();
            //            reader2.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    short nextShort() throws IOException {
        return Short.parseShort(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }

        return tokenizer.nextToken();
    }

}