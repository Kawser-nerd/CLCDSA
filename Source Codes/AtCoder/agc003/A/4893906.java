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
        int[] c = new int[4];
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'E') {
                c[0]++;
            }
            if (s.charAt(i) == 'W') {
                c[1]++;
            }
            if (s.charAt(i) == 'S') {
                c[2]++;
            }
            if (s.charAt(i) == 'N') {
                c[3]++;
            }
        }

        if ( (c[0] != 0 && c[1] != 0) || (c[0] == 0 && c[1] == 0) ) {
            if ( (c[2] != 0 && c[3] != 0) || (c[2] == 0 && c[3] == 0) ) {
                System.out.println("Yes");
            }else{
                System.out.println("No");
            }
        }else{
            System.out.println("No");
        }

        sc.close();
    }

}