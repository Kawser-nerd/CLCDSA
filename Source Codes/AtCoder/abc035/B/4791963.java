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
        int t = sc.nextInt();
        int lr = 0;
        int ud = 0;
        int qc = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'L') {
                lr--;
            }else if(s.charAt(i) == 'R'){
                lr++;
            }else if (s.charAt(i) == 'D') {
                ud--;
            }else if(s.charAt(i) == 'U'){
                ud++;
            }else{
                qc++;
            }
        }
        if (lr < 0) {
            lr = lr*(-1);
        }
        if (ud < 0) {
            ud = ud*(-1);
        }
        if (t == 1) {
            //max
            System.out.println(lr+ud+qc);
        }else{
            //min
            if (qc >= lr + ud) {
                System.out.println((qc-(lr+ud))%2);
            }else{
                System.out.println(lr+ud-qc);
            }
        }

        sc.close();
    }

}