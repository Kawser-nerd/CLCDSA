import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	double m = sc.nextDouble();
	double M = m/1000.0;
	if ( M < 0.1 ) {
	    System.out.println("00");
	} else if ( 0.1 <= M && M <= 5 ) {
	    int ans = (int)(M*10);
	    if ( ans <= 9 ) System.out.println("0"+ans);
	    else System.out.println(ans);
	} else if ( 6 <= M && M <= 30 ) {
	    System.out.println((int)M+50);
	} else if ( 35 <= M && M <= 70 ) {
	    System.out.println(((int)M-30)/5+80);
	} else if ( 70 < M ) {
	    System.out.println(89);
	}
    }
}