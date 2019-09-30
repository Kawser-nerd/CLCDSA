import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String c[][] = new String[4][4];
	for ( int i = 0; i < 4; i++ ) {
	    c[i] = sc.nextLine().split(" ",0);
	}
	/*
	for ( int i = 0; i < 4; i++ ) {
	    for ( int j = 0; j < 4; j++ ) {
		System.out.print(c[i][j]);
		if ( j == 3 ) System.out.println();		
	    }

	}
	*/
	for ( int i = 3; i >= 0; i-- ) {
	    for ( int j = 3; j >= 0; j-- ) {
		if ( j == 0 ) System.out.println(c[i][j]);
		else System.out.print(c[i][j] + " ");
	    }
	}

    }
}