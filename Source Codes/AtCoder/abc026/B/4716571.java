import java.util.*;

public class Main{
    public static final double PI = 3.1415926535;
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	List<Integer> list = new ArrayList<>();
	for ( int i = 0; i < N; i++ ) {
	    int R = sc.nextInt();
	    list.add(R);
	}
	Collections.sort(list,Comparator.reverseOrder());

	double ans = 0;
	for ( int i = 0; i < N; i++ ) {
	    if ( i % 2 == 0 ) {
		ans += PI*list.get(i)*list.get(i);
	    } else {
		ans -= PI*list.get(i)*list.get(i);
	    }
	}
	System.out.println(ans);
	    
    }
}