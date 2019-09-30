import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int K = sc.nextInt();
        String ans = "IMPOSSIBLE";
        int div = sc.nextInt();
        int max = div;
        if(div==K) ans = "POSSIBLE";
        for(int i=1;i<n;i++){
            int cur = sc.nextInt();
            if(cur==K){
                ans = "POSSIBLE";
                break;
            }
            div = gcd(div,cur);
            max = Math.max(max,cur);
        }
        if(max>K&&(max-K)%div==0) ans = "POSSIBLE";
        System.out.println(ans);
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