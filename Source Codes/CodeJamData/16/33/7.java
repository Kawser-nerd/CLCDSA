package Round1;

import java.io.*;

/**
 * @auther chao
 * @date 16/5/8
 */
public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("/Users/chao/Downloads/C-large.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        FileWriter out = new FileWriter("/Users/chao/Desktop/C-large.txt");
        //PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        String s = in.readLine();
        int m = Integer.parseInt(s);
        int[] a = new int[3];
        for (int cases = 1; cases <= m; cases++) {
            String[] ss = in.readLine().split(" ");
            for (int i = 0; i < 3; i++) {
                a[i] = Integer.parseInt(ss[i]);
            }
            int k = Integer.parseInt(ss[3]);
            k = Math.min(k, a[2]);
            int ans = a[0]*a[1]*k;
            out.write("Case #" + cases+": "+ans+"\n");
            for (int i = 1; i <= a[0]; i++) {
                for (int j = 1; j <= a[1]; j++) {
                    for (int x = 0; x < k; x++) {
                        int val = (i+j+x-2)%a[2]+1;
                        out.write(i +" "+j+" "+val+"\n");
                    }
                }
            }
        }
        in.close();
        out.flush();
        out.close();
    }
}
