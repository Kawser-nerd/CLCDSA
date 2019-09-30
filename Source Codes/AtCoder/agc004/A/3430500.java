// int????????????

// ???????==????.equals????

// String????next();???

import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String args[]) throws InterruptedException {
		    Scanner sc = new Scanner(System.in);

		    long[] a = new long[3];
		    for(int i = 0; i < 3; i++) {
		    	a[i] = sc.nextLong();
		    }
		    
		    if(a[0] % 2 == 0 || a[1] % 2 == 0 || a[2] % 2 == 0 ) {
		    	System.out.println(0);
		    }else {
		    	Arrays.sort(a);
		    	System.out.println(a[0] * a[1]);
		    }
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