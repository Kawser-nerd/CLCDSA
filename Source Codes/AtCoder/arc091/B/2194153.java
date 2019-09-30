import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        // Scanner scan = new Scanner(System.in);
        // PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        // int n = Integer.parseInt(bf.readLine());
        StringTokenizer st = new StringTokenizer(bf.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        long ans = 0;
        for(int b=1; b<=n; b++) {
          if(b <= k) continue;
          int remainders_per_b = b-1-k+1;
          ans += 1L * n/b * remainders_per_b;
          if(n % b >= k) ans += (n % b) - k + 1;
          if(k==0) ans--;
        }

        System.out.println(ans);
        // int[] a = new int[n];
        // for(int i=0; i<n; i++) a[i] =  Integer.parseInt(st.nextToken());

        // out.close(); System.exit(0);
    }


}