package Round1;

import java.io.*;

/**
 * @auther chao
 * @date 16/5/8
 */
public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("/Users/chao/Downloads/A-large.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        FileWriter out = new FileWriter("/Users/chao/Desktop/A-large.txt");
        //PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        String s = in.readLine();
        int m = Integer.parseInt(s);
        int[] a = new int[26];
        for (int cases = 1; cases <= m; cases++) {
            int n = Integer.parseInt(in.readLine());
            int cnt = n;
            String[] ss = in.readLine().split(" ");
            for (int i = 0; i < ss.length; i++) {
                a[i] = Integer.parseInt(ss[i]);
            }
            out.write("Case #" +cases+":");
            while (cnt > 2) {
                int k = findMaxIndex(a, n);
                out.write(" " + (char)('A'+k));
                if (--a[k] == 0)
                    cnt--;
            }
            while(cnt > 0) {
                int k = findMaxIndex(a, n);
                out.write(" "+(char)('A'+k));
                if (--a[k] == 0) cnt--;
                k = findMaxIndex(a, n);
                out.write((char)('A'+k));
                if (--a[k] == 0) cnt--;
            }
            out.write("\n");

        }
        in.close();
        out.flush();
        out.close();
    }
    private static int findMaxIndex(int[] a, int n) {
        int num = -1;
        int k = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] > num) {
                num = a[i];
                k = i;
            }
        }
        return k;
    }
}
