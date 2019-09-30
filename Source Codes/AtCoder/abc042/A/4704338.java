import java.util.*;

public class Main{
    public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	int num[] = new int[3];
	for ( int i = 0; i < 3; i++ ) {
	    num[i] = sc.nextInt();
	}

	int cnt5 = 0;
	int cnt7 = 0;
	for ( int i = 0; i < 3; i++ ) {
	    if ( num[i] == 5 ) cnt5++;
	    else if ( num[i] == 7 ) cnt7++;
	}
	if ( cnt5 == 2 && cnt7 == 1 ) {
	    System.out.println("YES");
	}else {
	    System.out.println("NO");
	}
	
    }
}