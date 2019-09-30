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
        
        String w = sc.next();
        int[] alpc = new int[26];
        boolean b = true;
        for (int i = 0; i < w.length(); i++) {
            alpc[w.charAt(i)-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (alpc[i] % 2 != 0) {
                b = false;
                break;
            }
        }
        if (b) {
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }

        sc.close();
    }

}