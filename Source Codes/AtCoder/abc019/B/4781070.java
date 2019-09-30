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
        
        String s = sc.next();
        int cnt = 1;
        String ans = "";
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i-1)){
                cnt++;
            }else{
                ans += String.valueOf(s.charAt(i-1)) +cnt;
                cnt = 1;
            }
            if (i == s.length()-1) {
                ans += String.valueOf(s.charAt(i)) + cnt;
            }
        }
        System.out.println(ans);

        sc.close();
    }

}