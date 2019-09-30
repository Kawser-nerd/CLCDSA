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
        int n =  Integer.parseInt(st.nextToken());
        int m =  Integer.parseInt(st.nextToken());
        long ans = 0;
        if((n == 1) && (m == 1)) ans = 1;
        else if(n == 1) ans = (m-2);
        else if(m == 1) ans = (n-2);
        else ans = 1L*(m-2)*(n-2);

        System.out.println(ans);

        // int[] a = new int[n];
        // for(int i=0; i<n; i++) a[i] =  Integer.parseInt(st.nextToken());

        // out.close(); System.exit(0);
    }


}