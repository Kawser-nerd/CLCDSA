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
        String t = sc.next();
        boolean b = false;
        for (int i = 0; i < s.length(); i++) {
            if ((s.substring(i) + s.substring(0,i)).equals(t)){
                b = true;
            }
        }
        if (b) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

        sc.close();
    }

}