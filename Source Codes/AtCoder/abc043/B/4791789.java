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
        List l = new ArrayList<Integer>();
        for (int i = 0; i < w.length(); i++) {
            if (w.charAt(i) == 'B') {
                if (l.size() > 0){
                    l.remove(l.size()-1);
                }
            } else {
                l.add(w.charAt(i));
            }
        }
        for (int i = 0; i < l.size(); i++) {
            System.out.print(l.get(i));
        }
        System.out.println("");


        sc.close();
    }

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.