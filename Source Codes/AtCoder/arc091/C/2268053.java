/*
 * 1,2,…,N ????????????????????????????????????????????????????????
 * 
 *     ??????????? A ???
 *     ??????????? B ???
 */

import java.util.*;
	public class Main{
		public static void main(String[] args){
            Scanner sc = new Scanner(System.in);
            //??
            int n = Integer.parseInt(sc.next());
            int a = Integer.parseInt(sc.next());
            int b = Integer.parseInt(sc.next());
            
            if(n < a+b-1 || (long)a*b < n){
            	System.out.println(-1);
            	sc.close();
            	return;
            }else if(b==1){
            	System.out.print(1);
            	
            	for(int i=1; i<n; i++){
        			System.out.print(" " + (i+1));
        		}
            	System.out.println("");
            	sc.close();
            	return;
            }
            
            int set = (n-a-b+1)/(b-1), remain = (n-a-b+1)%(b-1);
            
            for(int i=0; i<b; i++){
            	if(i==0){
            		System.out.print(b);
            		for(int j=1; j<a; j++){
            			if(j<set+1){
            				System.out.print(" " + (b*(j+1)));
            			}else{            			
            				System.out.print(" " + (b*(set+1) + remain + j - set));
            			}
            		}
            	}else if(i<=remain){
            		for(int j=0; j<set+1; j++){
            			System.out.print(" " + (b*(j+1)-i));
            		}
            		System.out.print(" " + (b*(set+1) - i + remain + 1));
            	}else{
            		for(int j=0; j<set+1; j++){
            			System.out.print(" " + (b*(j+1)-i));
            		}
            	}
            }
            
            System.out.println("");
            sc.close();
		}
    }