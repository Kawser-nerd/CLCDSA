/*
 * ??????????????? N ???????? i ?????????? (ai,bi) ??i ?????????? (ci,di) ???
 * 
 * ????????????? x ??????? x ???????? ?????? y ??????? y ?????????????????????
 * 
 * ??????????????????????????? ????1 ???????????????????????
 */

import java.util.*;
	public class Main{
        public static void main(String[] args){
            Scanner sc = new Scanner(System.in);
            //??
            int n = Integer.parseInt(sc.next());

            int[][] red = new int [n][2];
            int[][] blue = new int [n][2];
            
            for(int i=0; i<n; i++){
            	red[i][0] = Integer.parseInt(sc.next());
            	red[i][1] = Integer.parseInt(sc.next());
            }
            for(int i=0; i<n; i++){
            	blue[i][0] = Integer.parseInt(sc.next());
            	blue[i][1] = Integer.parseInt(sc.next());
            }
            Arrays.sort(red,  (a, b) -> Integer.compare(a[0], b[0]));
            Arrays.sort(blue, (a, b) -> Integer.compare(a[0], b[0]));
            //??
            System.out.println(calc(red, blue, n));
            sc.close();
        }
        
        public static int calc(int[][] red, int[][] blue, int n){
        	int ret = 0, maxtemp = -1, index = 0, maxindex = 0, flag = 0;
        	
        	for(int i=0; i<n; i++){
        		index = 0;
        		flag = 0;
        		maxtemp = -1;
        		while(index < n && red[index][0] < blue[i][0]){
        			if(maxtemp <= red[index][1] && red[index][1] < blue[i][1]){
        				maxtemp = red[index][1];
        				maxindex = index;
        				flag = 1;
        			}
        			index++;
        		}
        		
        		if(flag == 1){
        			ret++;
        			red[maxindex][1] = 201;
        		}
        	}
        	
            return ret;
        }
    }