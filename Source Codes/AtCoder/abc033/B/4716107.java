import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	String[] s = new String[N];
	int[] num = new int[N];
	for ( int i = 0; i < N; i++ ) {
	    s[i] = sc.next();
	    num[i] = sc.nextInt();
	}
	int sum = 0;
	int max = -1;
	int index = -1;
	for ( int i = 0; i < N; i++ ) {
	    sum += num[i];
	    if ( max < num[i] ) {
		max = num[i];
		index = i;
	    }
	}

	if ( sum/2 < max ) {
	    System.out.println(s[index]);
	} else {
	    System.out.println("atcoder");
	}
    }
}