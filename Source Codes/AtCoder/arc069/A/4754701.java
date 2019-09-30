/*
* @Author Silviase(@silviasetitech)
* For ProCon
*/

import java.util.*;
import java.lang.*;
import java.math.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long s = sc.nextLong();
        long c = sc.nextLong();
        long ans = Math.min(s,c/2);
        s -= ans;
        c -= (ans * 2);
        
        if (s == 0) {
            ans += c/4;
        }

        System.out.println(ans);

        sc.close();
    }
}