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
        Boolean bool = true;
        for (int i = 0; i < s.length(); i++) {
            char moji = s.charAt(i);
            if (moji == 'o' ||moji == 'k' ||moji == 'u' ) {
                continue;
            }else if(moji == 'c'){
                i++;
                moji = s.charAt(i);
                if (moji == 'h') {
                    continue;
                }else{
                    bool = false;
                    break;
                }
            }else{
                bool = false;
                break;
            }
        }

        if (bool) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }

        sc.close();
    }

}