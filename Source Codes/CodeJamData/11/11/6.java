import com.sun.org.apache.xerces.internal.impl.dv.xs.YearDV;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

public class A {
    static String p = "Possible";
    static String b = "Broken";

    public static void main(String[] args) throws Exception {
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(
                    "a.in"
            )));
            int t = Integer.parseInt(in.readLine());

            PrintWriter out = new PrintWriter(new OutputStreamWriter(new FileOutputStream(
                    "aout.txt")));

            for (int tk = 0; tk < t; tk++) {
                String s = in.readLine();
                String[] data = s.split(" ");
                long n = Long.parseLong(data[0]);
                int d = Integer.parseInt(data[1]);
                int g = Integer.parseInt(data[2]);

                String res = get(n,d,g);
                System.out.println("tk = " + tk + " " + s + " " + res);
                out.println("Case #" + (tk+1) + ": " + res);
            }
            out.close();
        } catch (Exception e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    static String get(long n, int d, int g) {
        if (g ==100 && d ==100) {
            return p;
        }
        if (g ==100) {
            return b;
        }

        if (g ==0 && d ==0) {
            return p;
        }
        if (g ==0) {
            return b;
        }
        int limit = 100 >  n ? (int)n : 100;
        for (int t = 1; t <= limit; t++) {
            if (t*d %100 == 0) {
                return p;
            }
        }
        return b;
    }
}
