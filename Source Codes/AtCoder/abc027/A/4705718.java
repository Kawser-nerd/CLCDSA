import java.util.*;

public class Main{
    public static void main(String[] args) {
	int num[] = new int[3];
	Scanner sc = new Scanner(System.in);
	for ( int i = 0; i < 3; i++ ) {
	    num[i] = sc.nextInt();
	}
	Arrays.sort(num);
	if ( num[0] == num[1] ) {
	    System.out.println(num[2]);
	} else {
	    System.out.println(num[0]);
	}
    }
}