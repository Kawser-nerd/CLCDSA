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
        int len = sc.nextInt();
        List l = new ArrayList<String>();
        for (int i = 0; i < n; i++) {
            String tmp = sc.next();
            l.add(tmp);
        }
        Collections.sort(l);
        for (int i = 0; i < l.size(); i++) {
            System.out.print(l.get(i));
            if (i == l.size()-1) {
                System.out.println("");
            }
        }

        sc.close();
    }

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.