/*
 * ?????N ???????? 2 ?? (a,b) ???????????????????? ?????a ? b ???????? K ????????????????
 * ???????????????????????????????
 */

import java.util.*;
	public class Main{
		public static void main(String[] args){
            Scanner sc = new Scanner(System.in);
            //??
            long n = Integer.parseInt(sc.next());
            long k = Integer.parseInt(sc.next());
            long ret = 0;
            
            // b(i??????)?k?????n??
            for(int i=(int)k+1; i<=n; i++){
            	// n/i??????????(i-k)?????????????n%i????????????????Math.max(k-1, 0)??????????????
            	ret += (n/i) * (i-k) + Math.max(0, n%i - Math.max(k, 1) + 1);
            }
            
            System.out.println(ret);
            sc.close();
		}
    }