import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong(), b=sc.nextLong(), c=sc.nextLong();
        long ans = 0;
        if(a%2==1||b%2==1||c%2==1) ans = 0;
        else{
            if(a==b&&a==c) ans = -1;
            else{
                ans = help(a,b,c);
            }
        }
        System.out.println(ans);

    }
    static long help(long a, long b, long c){
        if(a%2==1||b%2==1||c%2==1) return 0;
        return 1+help(a/2+b/2,a/2+c/2,b/2+c/2);
    }
}