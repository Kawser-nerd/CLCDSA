import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	static Queue<Integer> q = new LinkedList<Integer>();

	static void Divisor(int M){
		for(int i=1; i<Math.sqrt(M); i++) {
			if(M%i!=0)	continue;
			q.add(i);
			q.add(M/i);
		}
		if(M%Math.sqrt(M) == 0)	q.add((int) Math.sqrt(M));
	}

    public static void main(String[] args) throws Exception {
    	try(Scanner sc = new Scanner(System.in)) {

    		int N = sc.nextInt();
    		int M = sc.nextInt();
    		Divisor(M);
    		int max = 0;
    		while(!q.isEmpty()) {
    			int s = q.remove();
    			if(M%s == 0 && M/s >= N) {
    				max = Math.max(max, s);
    			}
    		}
    		System.out.println(max);

    	}
    }
}