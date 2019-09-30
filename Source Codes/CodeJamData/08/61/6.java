import java.io.*;
import java.math.*;
import java.util.*;

public class A {

    static boolean contradict(int a[][], int acount, int b[][], int bcount, int tbhmin, int tbhmax, int tbwmin, int tbwmax) {
	//	System.out.println( tbhmin + "   " + tbhmax + "   " + tbwmin + "   " + tbwmax );
	for (int i=0; i < acount; i++) {
	    if (a[i][0] >= tbhmin && a[i][0] <= tbhmax && a[i][1] >= tbwmin && a[i][1] <= tbwmax) {
		return true;
	    }
	}
	return false;
    }

    public static void main(String[] args) {
	Scanner sc = new Scanner(new InputStreamReader(System.in));
	//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	int C = sc.nextInt();

	
	
	for (int caes=1; caes <= C; caes++) {

	    System.out.println("Case #" + caes + ":");

	    int N = sc.nextInt();

	    int bcount=0;
	    int acount=0;

	    int b[][] = new int[N][2];
	    int a[][] = new int[N][2];

	    int bhmin = 0;
	    int bhmax = 0;
	    int bwmin = 0;
	    int bwmax = 0;
	    

	    for (int i=0; i < N; i++) {

		int H = sc.nextInt();
		int W = sc.nextInt();
		String X = sc.next();

		boolean isBird = X.equals("BIRD");

		if (!isBird) sc.next();

		if (isBird) {
		    b[bcount][0] = H;
		    b[bcount][1] = W;
		    bcount++;

		    if (1 == bcount | H <= bhmin) bhmin = H;
		    if (1 == bcount | H >= bhmax) bhmax = H;
		    if (1 == bcount | W <= bwmin) bwmin = W;
		    if (1 == bcount | W >= bwmax) bwmax = W;
		} else {
		    a[acount][0] = H;
		    a[acount][1] = W;
		    acount++;
		}

		


	    }


	    
	    int M = sc.nextInt();

	    for (int i=0; i < M; i++) {

		int H = sc.nextInt();
		int W = sc.nextInt();

		if ((H >= bhmin && H <= bhmax && W >= bwmin && W <= bwmax) && bcount > 0) {
		    System.out.println("BIRD");
		} else {

		    int tbhmin = bhmin;
		    int tbhmax = bhmax;
		    int tbwmin = bwmin;
		    int tbwmax = bwmax;

		    if (0 == bcount | H <= tbhmin) tbhmin = H;
		    if (0 == bcount | H >= tbhmax) tbhmax = H;
		    if (0 == bcount | W <= tbwmin) tbwmin = W;
		    if (0 == bcount | W >= tbwmax) tbwmax = W;


		    if (contradict(a, acount, b, bcount, tbhmin, tbhmax, tbwmin, tbwmax)) {
			System.out.println("NOT BIRD");
		    } else {
			System.out.println("UNKNOWN");
		    }


		}

	    }
	    
	}
    }


}