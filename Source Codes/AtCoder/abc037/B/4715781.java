import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	List<Integer> list = new ArrayList<>();

	int N = sc.nextInt();
	int Q = sc.nextInt();
	for ( int i = 0; i < N; i++ ) list.add(0);	
	for ( int i = 0; i < Q; i++ ) {
	    int L = sc.nextInt();
	    int R = sc.nextInt();
	    int T = sc.nextInt();
	    L--;R--;
	    for ( int j = L; j <= R; j++ ) list.set(j,T);
	}
	for ( Iterator it = list.iterator(); it.hasNext(); ) {
	    System.out.println(it.next());
	}
    }
}