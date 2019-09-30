import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int K = sc.nextInt();
        int[] a = new int[n];
        for(int i=0;i<n;i++) a[i]=sc.nextInt();
        System.out.println(help(a,K));
    }
    static String help(int[] a, int K){
        int n = a.length;
        int max = a[0];
        if(a[0]==K) return "POSSIBLE";
        int div = a[0];
        for(int i=1;i<n;i++){
            if(a[i]==K) return "POSSIBLE";
            max = Math.max(max,a[i]);
            div = gcd(div,a[i]);
        }
        if(max<K) return "IMPOSSIBLE";
        return (max-K)%div==0?"POSSIBLE":"IMPOSSIBLE";
    }
    static int gcd(int a, int b){
        if(a<b){
            int med = b;
            b=a;
            a=med;
        }
        while(a%b!=0){
            int s = a;
            a = b;
            b = s%a;
        }
        return b;
    }
}