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
        int len = sc.nextInt();
        List l = new ArrayList<String>();
        for (int i = 0; i+len <= s.length(); i++) {
            if (l.contains(s.substring(i, i+len))){
                
            }else{
                l.add(s.substring(i, i+len));
            }
        }
        System.out.println(l.size());


        sc.close();
    }

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.