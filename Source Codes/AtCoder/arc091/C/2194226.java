import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        // Scanner scan = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        // int n = Integer.parseInt(bf.readLine());
        StringTokenizer st = new StringTokenizer(bf.readLine());
        int n = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        if(a + b > n + 1) out.println("-1");
        else if(n > 1L*a*b) out.println("-1");
        else {
          StringBuilder sb = new StringBuilder();
          int[] lengths = new int[b];
          Arrays.fill(lengths, 1);
          lengths[0] = a;
          int count = a+b-1;
          for(int i=1; i<b; i++) {
            while(count < n) {
              lengths[i]++;
              count++;
              if(lengths[i] == a) break;
            }
          }

          int cur = n;
          for(int i=0; i<b; i++) {
            for(int j=cur-lengths[i]+1; j<=cur; j++)
              sb.append(j+" ");
            cur -= lengths[i];

          }
          out.println(sb.toString());
        }
        // int[] a = new int[n];
        // for(int i=0; i<n; i++) a[i] =  Integer.parseInt(st.nextToken());

        out.close(); System.exit(0);
    }


}