// int????????????
// ???????==????.equals????
// String????next();???

import java.util.Scanner;

public class Main {

	public static void main(String args[]) throws InterruptedException {
		    Scanner sc = new Scanner(System.in);


		    int n = sc.nextInt();
		    String[] a = new String[n];
 		    String[][] s = new String[n][n];
		    for(int i = 0; i < n; i++) {
		    	a[i] = sc.next();
		    	for(int j = 0; j < n; j++) {
		    		s[(n-1)-i][j] = a[i].substring(j, j+1);
		    	}
		    }
		    for(int i = 0; i < n; i++) {
		    	for(int j = 0; j < n; j++ ) {
		    		System.out.print(s[j][i]);
		    	}
		    	System.out.print("\n");
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