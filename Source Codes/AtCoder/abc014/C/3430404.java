// int????????????
// ???????==????.equals????
// String????next();???

import java.util.Scanner;

public class Main {

	public static void main(String args[]) throws InterruptedException {
		    Scanner sc = new Scanner(System.in);

		    int n = sc.nextInt();
		    int[] a = new int[1000001];
		    int[] shita = new int[n];
		    int[] ue = new int[n];
		    int m = 0;
		    
		    for(int i = 0; i < 1000001; i++) {
		    	a[i] = 0;
		    }
		    for(int i = 0; i < n; i++) {
		    	shita[i] = sc.nextInt();
		    	ue[i] = sc.nextInt();
		    	a[shita[i]]++;
		    	if(ue[i] != 1000000) {
		    		a[ue[i]+1]--;
		    	}
		    }
		    
		    for(int i = 0; i < 1000001; i++) {
		    	if(i > 0) {
		    		a[i] += a[i-1];
		    	}
		    	if(a[i] > m) {
		    		m = a[i];
		    	}
		    }
		    
		    System.out.println(m);
		    
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