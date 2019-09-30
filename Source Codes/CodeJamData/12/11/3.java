import java.util.*;
import java.math.*;
import java.io.*;
import static java.lang.System.*;
import static java.lang.Math.*;
import static java.lang.Integer.*;
import static java.lang.Double.*;
import static java.lang.Long.*;

public class QA {
    static String[] parts(BufferedReader br) throws Exception {
        String line = br.readLine();
        if (line == null) return null;
        return line.trim().split("\\s+");
    }
    public static void main (String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        int z = parseInt(br.readLine().trim());
        double q[] = new double[1000000];
        for (int cas = 1; cas <= z; cas++) {
            String p[] = parts(br);
            int a = parseInt(p[0]);
            int b = parseInt(p[1]);
            p = parts(br);
            for (int i = 0; i < a; i++) {
                q[i] = parseDouble(p[i]);
            }
            double min = b + 2;
           
            double prb = 1;
            for (int back = a, i = 0; back >= 0; back--, i++) {
                double ans = back + back + b - a + 1 + (1 - prb) * (b + 1);
                //out.println(back + " " + i + " " + ans);
                if (min > ans) min = ans;
                if (i < b)
                    prb *= q[i];
            }
            
            out.println("Case #" + cas + ": " + String.format("%.8f", min));
        }
    }
}
