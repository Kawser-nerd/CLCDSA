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
        String[] name = new String[n];
        int ans = -1;
        String ansname = "";
        for (int i = 0; i < n; i++) {
            name[i] = sc.next();
        }
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (name[i].equals(name[j])) {
                    tmp++;
                }
            }
            if (ans < tmp) {
                ans = tmp;
                ansname = name[i];
            }
            tmp = 0;
        }
        
        System.out.println(ansname);

        sc.close();
    }

}