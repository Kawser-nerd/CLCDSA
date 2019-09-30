import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {
    static long R,B,x,y;
    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        R = sc.nextLong();
        B = sc.nextLong();
        x = sc.nextLong();
        y = sc.nextLong();
        long hi = Math.min(R,B)+1;
        if(y>B&&x>R){
            System.out.println(0);
            System.exit(0);
        }
        long lo = 1;
        long mid;
        while(hi-lo>1){
            mid = (lo+hi)/2;
            if(check(mid)) lo = mid;
            else hi = mid;
        }
        System.out.println(lo);
    }
    static boolean check(long target){ //
        long temp;
        if(R-target<0) return false;
        long upper = (R-target)/(x-1);
        long lower;
        temp = target-B;
        if(temp>=0){
            lower = target+temp%(y-1)==0?temp/(y-1):(temp/(y-1)+1);
        } else{
            // Java???????“?0??”
            lower = target+temp/(y-1);
        }
        return lower<=upper&&lower<=target;
    }
}