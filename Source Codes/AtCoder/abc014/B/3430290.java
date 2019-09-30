// int????????????
// ???????==????.equals????
// String????next();???

import java.util.Scanner;

public class Main {

	public static void main(String args[]) throws InterruptedException {
		    Scanner sc = new Scanner(System.in);

		    int n = sc.nextInt();
		    int x = sc.nextInt();
		    int[] a = new int[n];
		    int sum = 0;
		    
		    for(int i = 0; i < n; i++) {
		    	a[i] = sc.nextInt();
		    }
		    for(int i = 0; i < n; i++) {
		    	if(x % 2 == 1) {
		    		sum += a[i];
		    	}
		    	x /= 2;
		    	if(n == 0) {
		    		break;
		    	}
		    }
		    System.out.println(sum);
 
		    sc.close(); }

	public static  int gcd(int a, int b) {
	    if (a < b) {
	        int tmp = a;
	        a = b;
	        b = tmp;
	    }

	    int r = -1;
	    while (r != 0) {
	        r = a % b;
	        a = b;
	        b = r;
	    }

	    return a;
	}
}