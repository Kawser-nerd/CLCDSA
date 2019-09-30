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
        
        
        int n = sc.nextInt();
        int cnt = (n-1)/2;
        String s = sc.next();
        String make = "b";
        for (int i = 1; i <= cnt; i++) {
            if (i % 3 == 1) {
                make = "a" + make + "c";
            }else if(i % 3 == 2){
                make = "c" + make + "a";
            }else{
                make = "b" + make + "b";
            }
        }
        if (s.equals(make)) {
            System.out.println(cnt);
        }else{
            System.out.println(-1);
        }
        
        
        

        sc.close();
    }

}