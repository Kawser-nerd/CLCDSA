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
        int n = sc.nextInt();
        int[] l = new int[n];
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = sc.nextInt()-1;
            r[i] = sc.nextInt()-1;
        }

        for (int i = 0; i < n; i++) {
            String tmp = "";
            for (int j = 0; j < s.length(); j++) {
                if (j < l[i] || j > r[i]) {
                    tmp += s.charAt(j);
                }else{
                    tmp += s.charAt(r[i] - (j-l[i]));
                }
            }
            s = tmp;
        }

        System.out.println(s);

        sc.close();
    }

}