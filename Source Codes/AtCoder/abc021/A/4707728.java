import java.util.*;

public class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	List<Integer> list = new ArrayList<>();
	while(N>0) {
	    if ( N >= 8 ) {
		list.add(8);
		N -= 8;
	    } else if ( N >= 4 ) {
		list.add(4);
		N -= 4;
	    } else if ( N >=2 ) {
		list.add(2);
		N -= 2;
	    } else if ( N >= 1 ) {
		list.add(1);
		N--;
	    }
	}
	System.out.println(list.size());
	for ( Iterator it = list.iterator(); it.hasNext();) {
	    System.out.println(it.next());
	}
    }
}