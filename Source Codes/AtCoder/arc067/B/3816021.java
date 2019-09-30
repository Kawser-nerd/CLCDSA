import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long A = sc.nextLong();
        long B = sc.nextLong();
        long[] x = new long[n];
        for(int i=0;i<n;i++) x[i]=sc.nextLong();
        long ans= 0;
        for(int i=0;i<n-1;i++){
            ans += Math.min(A*(x[i+1]-x[i]),B);
        }
        PrintWriter out = new PrintWriter(System.out);
        out.println(ans);
        out.flush();
    }
}