import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(bf.readLine());
        int[] a = new int[n];
        int[] b = new int[n];
        long sum = 0;
        int min = Integer.MAX_VALUE;
        for(int i=0; i<n; i++) {
          StringTokenizer st = new StringTokenizer(bf.readLine());
          a[i] = Integer.parseInt(st.nextToken());
          b[i] = Integer.parseInt(st.nextToken());
          if(a[i] > b[i]) {
            if(b[i] < min) min = b[i];
          }
          sum += a[i];
        }
        if(min == Integer.MAX_VALUE) out.println(0);
        else out.println((sum - min));

        // int[] a = new int[n];
        // for(int i=0; i<n; i++) a[i] =  Integer.parseInt(st.nextToken());

        out.close(); System.exit(0);
    }


}