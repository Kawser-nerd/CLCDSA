import java.util.*;
     
    public class Main {
    	public static void main(String[] args) {
    		Scanner sc = new Scanner(System.in);
    		int n = sc.nextInt();
    		boolean[] prime = new boolean[1000];
    		/*	prime[i - 1] : i???	*/
    		prime[1 - 1] = false;
    		for(int i = 2; i <= 1000; i++)
    			prime[i - 1] = true;
    		for(int i = 1; i <= 1000; i++) {
    			if(prime[i - 1]) {
    				for(int j = 2; i*j <= 1000; j++)
    					prime[i*j - 1] = false;
    			}
    		}
    		int[] counter = new int[1000];
    		/*	n!????i?counter[i - 1]???	*/
    		for(int i = 1; i <= 1000; i++)
    			counter[i - 1] = 0;
    		for(int i = 1; i <= n; i++) {
    			for(int j = 1; j <= i; j++) {
    				if(prime[j - 1]) {
    					int x = i;
    					int count = 0;
    					while(x%j == 0) {
    						x = x/j;
    						count++;
    					}
    					counter[j - 1] += count;
    				}
    			}
    		}
    		long result = 1;
    		for(int i = 1; i <= 1000; i++)
    			result = (result*(counter[i - 1] + 1))%1000000007;
    		System.out.println(String.valueOf(result%1000000007));
    	}
    }