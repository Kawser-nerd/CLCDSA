import java.util.*;
	public class Main{
        public static void main(String[] args){
            Scanner sc = new Scanner(System.in);
            //??
            int n = Integer.parseInt(sc.next());
            int a, b, flag = 0;
            long sum = 0;
            int min = 1000000001;
            
            for(int i=0; i<n; i++){
            	a = Integer.parseInt(sc.next());
            	b = Integer.parseInt(sc.next());
            	
            	sum += a;
            	if(a != b){
            		flag = 1;
            	}
            	if(a > b && min > b){
            		min = b;
            	}
            }
            
            if(flag == 0){
            	System.out.println(0);
            }else{
            	System.out.println(sum - min);
            }
            sc.close();
        }
    }