/*
 * ????????????????????AtCoder Regular Contest(ARC) ????????????????
 * ?????????????????????????????????????????????????????????
 * ????????????????????????????????1 ????????????????????????
 * ??? 1 ????????????????????????????????????????????
 * ???????????????????????????????????????????????????????????????
 * ???????????????? ARC ????????????????????????????????????
 * ???????????? ARC ??????????????? ARC ?????????????????? 
 */

import java.util.*;
	public class Main{
        public static void main(String[] args){
            Scanner sc = new Scanner(System.in);
            //??
            int n = Integer.parseInt(sc.next());
            
            for(int i=2; i<n; i++){
            	if(n%i == 0){
            		System.out.println("NO");
                    sc.close();
                    return;
            	}
            }
            
            //??
            System.out.println("YES");
            sc.close();
        }
    }