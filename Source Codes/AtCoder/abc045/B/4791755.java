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
        
        String a = sc.next();
        String b = sc.next();
        String c = sc.next();
        int ac = 0;
        int bc = 0;
        int cc = 0;
        char turn = 'a';

        while(true){
            if (turn == 'a') {
                turn = a.charAt(ac);
                ac++;
            }else if(turn == 'b'){
                turn = b.charAt(bc);
                bc++;
            }else{
                turn = c.charAt(cc);
                cc++;
            }
            if (ac == a.length() && turn == 'a') {
                System.out.println("A");
                break;
            }
            if (bc == b.length() && turn == 'b') {
                System.out.println("B");
                break;
            }
            if (cc == c.length() && turn == 'c') {
                System.out.println("C");
                break;
            }
        }

        sc.close();
    }

}