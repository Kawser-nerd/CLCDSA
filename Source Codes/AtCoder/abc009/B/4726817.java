import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int max1 = -1,max2 =  -1;
	for ( int i = 0; i < N; i++ ) {
	    int a = sc.nextInt();
	    if ( max1 < a ) {
		max2 = max1;
		max1 = a;
	    } else if ( max2 < a && max1 > a  ) {
		max2 = a;
	    }
	}
	System.out.println(max2);
    }
}