import java.io.*;
import java.util.*;

public class Main
{
    public static void main (String[] args) throws java.lang.Exception    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] a = new int[101];
        int s1 = 0,
            s2 = 0;
        for (int i=0 ; i<n ; i++) {
            st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            a[k]++;
            if (k%10 == 0) s2+= k;
            else s1 += k;
        }
        if (s1 == 0) {
            System.out.println(0);
            return;
        }
        if (s1%10 != 0) {
            System.out.println(s1+s2);
            return;
        }
        
        for (int i=1 ; i<=100 ; i++) {
            if (a[i] == 0 || i%10==0) continue;
            s1 -= i;
            break;
        }
        System.out.println(s1+s2);
    }
}