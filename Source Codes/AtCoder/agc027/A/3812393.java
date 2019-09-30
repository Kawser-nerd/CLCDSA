import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        int[] a = new int[n];
        for(int i=0;i<n;i++) a[i] = sc.nextInt();
        Arrays.sort(a);
        int ans = 0;
        for(int i=0;i<n;i++){
            x -= a[i];
            if(x<0) break;
            else ans++;
        }
        if(x>0) ans--;
        PrintWriter out = new PrintWriter(System.out);
        out.println(ans);
        out.flush();
    }
}