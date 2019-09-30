import java.util.Scanner;
	
 
public class Main{
 
	public static void main(String args[])throws Exception{
		Scanner sc = new Scanner(System.in);
		
	    int K = sc.nextInt();
	    long[] a = new long[K];
	    for(int i=0;i<K;i++){
	    	a[i] = sc.nextInt();
	    }
	    long max = 2;
	    long min = 2;
	    
	    for(int i=K-1;i>=0;i--){
	    	min = ((min-1)/a[i]+1)*a[i];
	    	max = ((max)/a[i])*a[i] + a[i]-1;
	    			if(min>max){
	    				System.out.println(-1);
	    				return;
	    			}
	    	
	    }
	    System.out.println(min + " " + max);
		
		
	}
 
}