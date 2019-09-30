import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    static class Fast {
        BufferedReader br;
        StringTokenizer st;

        public Fast() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    public static void main(String args[]) throws Exception {
        Fast in = new Fast();
        int arr[] = new int[10];
        int n = in.nextInt(), k = in.nextInt();
        for (int i = 0; i < k; i++) {
            arr[in.nextInt()] = 1;
        }
        l:
        for (int i = n; i <10000000; i++) {
            String str = "" + i;
            for (int j = 0; j < str.length(); j++) {
                if (arr[str.charAt(j) - '0'] == 1) {
                    continue l;
                }
            }
            System.out.println(i);
            return;
        }
    }
}