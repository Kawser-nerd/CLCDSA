package gcj;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class MainA {
    public static void reverse(int[] p) {
        int i = 0, j = p.length - 1;
        while (i < j) {
            int a = p[i];
            p[i] = p[j];
            p[j] = a;
            i++;
            j--;
        }
    }

    public static void main(String[] args) throws NumberFormatException,
            IOException {
        BufferedReader cin = new BufferedReader(
                new InputStreamReader(
                        new FileInputStream(
                                "D:\\topcoder\\eclipse-workspace\\ACM\\gcj\\A-small.in")));
        PrintWriter out = new PrintWriter(
                "D:\\topcoder\\eclipse-workspace\\ACM\\gcj\\Aout.txt");
        int testcase = Integer.parseInt(cin.readLine());
        for (int tst = 1; tst <= testcase; tst++) {
            int P, K, L;
            StringTokenizer st = new StringTokenizer(cin.readLine());
            P = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            L = Integer.parseInt(st.nextToken());
            int[] hits = new int[L];
            st = new StringTokenizer(cin.readLine());
            for (int i = 0; i < L; i++)
                hits[i] = Integer.parseInt(st.nextToken());
            Arrays.sort(hits);
            reverse(hits);
            long res=0;
            for(int i=0;i<hits.length;i++) {
                res+=(i/K+1)*hits[i];
            }
            out.println("Case #" + tst + ": " + res);
        }
        out.close();
    }
}
