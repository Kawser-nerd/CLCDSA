/*
 * ???AtCoDeer??????TopCoDeer??????????????????? ?????? N ????????????????????????????????????????????
 * ???????????????????????????
 * 
 * (?) ????????(????????????)?(????????????)?????
 * 
 * ??????????????????(????????) ? (????????) ??? 
 * AtCoDeer?????????????????????????TopCoDeer????? N ???????????????????
 * AtCoDeer???????????????AtCoDeer???????????????? TopCoDeer????????????? s ????????
 * s ? i(1?i?N) ???? g???? i ?????TopCoDeer???????????? p?????????????????
 */

import java.util.*;
	public class Main{
		public static void main(String[] args){
            Scanner sc = new Scanner(System.in);
            //??
            String s = sc.next();
            int n = String.valueOf(s).length();
            int count = 0;
            
            for(int i=0; i<n; i++){
            	if(s.substring(i,i+1).equals("p")){
            		count++;
            	}
            }
            
            System.out.println(n/2 - count);
            sc.close();
		}
    }