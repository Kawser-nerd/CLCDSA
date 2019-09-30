import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;
	
 
public class Main{
 
	public static void main(String args[])throws Exception{
		Scanner sc = new Scanner(System.in);
		
	    int N = sc.nextInt();
	    long[] A = new long[N];
	    long[] B = new long[N];
	    HashMap<Long,Integer> map = new HashMap<Long,Integer>();
	    for(int i=0;i<N;i++){
	    	A[i] = sc.nextLong();
	    	B[i] = A[i];
	    	
	    }
	    Arrays.sort(A);
	    
	    for(int i=0;i<N;i++){
	    	map.put(A[i],i);
	    }
	    int ans = 0;
	    for(int i=0;i<N;i++){
	    	if(i%2 != map.get(B[i])%2){
	    		ans++;
	    	}
	    }
	    System.out.println(ans/2);
	   
		
	}
 
}