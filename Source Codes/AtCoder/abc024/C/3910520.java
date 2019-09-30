import java.util.*;
import java.lang.*;

public class Main {
    
    static int n;   //???
    static int d;   //??????
    static int k;   //????
    static int[] l; //??????
    static int[] r; //??????
    static int[] s; //????
    static int[] t; //???
    
    public static void main (String args[]) {

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        d = sc.nextInt();
        k = sc.nextInt();
        l = new int[d];
        r = new int[d];
        s = new int[k];
        t = new int[k];
        
        int[] ans = new int[k];
        
        for (int i = 0; i < d; i++) {
            l[i] = sc.nextInt();
            r[i] = sc.nextInt();
        }
        
        for (int i = 0; i < k; i++) {
            s[i] = sc.nextInt();
            t[i] = sc.nextInt();
        }

        for (int i = 0; i < d; i++) {
            for (int j = 0; j < k; j++) {
                if (l[i] <= s[j] && s[j] <= r[i] &&
                    s[j] != t[j]) {
                    if (t[j] < s[j] && t[j] < l[i]) {
                        s[j] = l[i];
                    } else if ((t[j] < s[j] && l[i] <= t[j]) ||
                               (s[j] < t[j] && t[j] <= r[i])) {
                        s[j] = t[j];
                        ans[j] = i + 1;
                    } else if (s[j] < t[j] && r[i] < t[j]) {
                        s[j] = r[i];
                    }
                }
            }
        }
        
        for (int i = 0; i < k; i++) {
            System.out.println(ans[i]);
        }
    }
}