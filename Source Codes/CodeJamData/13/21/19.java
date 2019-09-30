package google.codejam2013.round1b;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Osmos {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(new OutputStreamWriter(System.out));

    Osmos() throws IOException {
        reader = new BufferedReader(new FileReader("A-large.in"));
        writer = new PrintWriter(new FileWriter("A-large.out"));
    }

    int[] readInts() throws IOException {
        String line = reader.readLine();
        String []s = line.split(" ");
        int[] ret = new int[s.length];
        for(int i = 0; i < s.length; i++) {
            ret[i] = Integer.parseInt(s[i]);
        }
        return ret;
    }

    int[] tt = null;
    int ti = 0;
    int readInt() throws IOException {
        if(tt == null || ti == tt.length) {
            tt = readInts();
            ti = 0;
        }
        return tt[ti++];
    }

    void solveTest(int test) throws IOException {
        writer.printf("Case #%d:", test);
        int a = readInt();
        int n = readInt();
        int[] b = readInts();
        Arrays.sort(b);
        int ans = n;
        for(int k = 0; k < n; k++) {
            int add = 0;
            int s = a;
            for(int i = 0; i < n - k; i++) {
                if(s > b[i]) {
                    s += b[i];
                }
                else {
                    if(s == 1) {
                        add = n;
                        break;
                    }
                    while(s <= b[i]) {
                        s = 2 * s - 1;
                        add++;
                    }
                    s += b[i];
                }
            }
            ans = Math.min(ans, k + add);
        }
        writer.println(" " + ans);
    }

    void solve() throws IOException {
        int t = readInt();
        for(int i = 1; i <= t; i++) {
            solveTest(i);
        }
        writer.flush();
    }

    public static void main(String[] args) throws IOException {
        new Osmos().solve();
    }
}
