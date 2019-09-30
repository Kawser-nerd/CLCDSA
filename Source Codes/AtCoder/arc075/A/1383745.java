import java.io.*;
import java.util.*;

public class Main implements Runnable {

    private void solve() throws IOException {

        int N = nextInt();
        int[] arr = new int[N];
        for(int i = 0; i < N; ++i) arr[i] = nextInt();
        Arrays.sort(arr);
        int s = 0;
        for(int i : arr) s += i;
        if(s % 10 != 0) {
            writer.println(s);
        } else {
            for(int i = 0; i < arr.length; ++i) {
                if((arr[i] % 10 != 0)) {
                    writer.println((s - arr[i]));
                    return;
                }
            }
            writer.println(0);
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
//            reader = new BufferedReader(new FileReader("input.txt"));
            //            reader2 = new BufferedReader(new FileReader("1.in"));
            tokenizer = null;
            writer = new PrintWriter(System.out);
//            writer = new     PrintWriter("output.txt");
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