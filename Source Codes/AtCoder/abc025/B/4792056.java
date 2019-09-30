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
        int a = sc.nextInt();
        int b = sc.nextInt();
        int cnt = 0;
        String[] ord = new String[n];
        int[] dis = new int[n];
        for (int i = 0; i < n; i++) {
            ord[i] = sc.next();
            dis[i] = sc.nextInt();
            if (dis[i] < a) {
                dis[i] = a;
            } else if(dis[i] > b){
                dis[i] = b;
            }
            if (ord[i].equals("East")) {
                cnt += dis[i];
            } else {
                cnt -= dis[i];
            }
        }

        if (cnt > 0) {
            System.out.print("East ");
        }else if(cnt < 0){
            System.out.print("West ");
        }
        System.out.println(Math.abs(cnt));
        
        

        sc.close();
    }

}