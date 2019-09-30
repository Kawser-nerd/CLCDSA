import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	List<Integer> list = new ArrayList<>();
	for ( int i = 0; i < N; i++ ) {
	    int n = sc.nextInt();
	    list.add(n);
	}
	int[] num = new int[100001];
	Arrays.fill(num,0);
	int ans = 0;
	for ( int i = 0; i < N; i++ ) {
	    if ( num[list.get(i)] == 1 ) {
		ans++;
	    } else {
		num[list.get(i)] = 1;
	    }
	}
	System.out.println(ans);
    }
}