import java.util.*;
import java.io.*;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Book-Bambuk
 */
public class Solution {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        BufferedReader in = new BufferedReader(new FileReader("c:\\codejam\\cj2011_r1a_a\\input.txt"));
        PrintWriter out = new PrintWriter("c:\\codejam\\cj2011_r1a_a\\output.txt");
        int t = Integer.parseInt(in.readLine());
                int c, d;
        long n,pd,pg;
        List<Long> candies;
        for (int i = 0; i < t; i++) {
            String data = in.readLine();
            StringTokenizer st = new StringTokenizer(data);
            n = Long.parseLong(st.nextToken());
           pd = Long.parseLong(st.nextToken());
           pg = Long.parseLong(st.nextToken());
            String ans = solve(n,pd, pg);
            out.println("Case #" + String.valueOf(i + 1) + ": " + ans);

        }
        in.close();
        out.close();
    }

    private static String solve(long n, long pd, long pg) {
        String result = "Broken";

        if ((pg==100 && pd != 100)||(pg==0 && pd>0))
        {
            result = "Broken";
        }
        else
        {
            for (long i = n ;i>0; i--)
            {
                if ((i*pd) % 100 == 0)
                {
                   result = "Possible";
                   break;
                }
            }
        }

        return result;
    }

}
