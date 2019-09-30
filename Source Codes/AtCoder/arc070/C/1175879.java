import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int[] x = new int[N];
		int[] a = new int[N];
		for(int i=0; i<N; i++) {
			x[i] = sc.nextInt();
			a[i] = sc.nextInt()-x[i];
		}

		PriorityQueue<Long> lset = new PriorityQueue<>(new Comparator<Long>() {
			public int compare(Long l1, Long l2) {
				return -Long.compare(l1, l2);
			}
		});
		lset.add((long)x[0]);
		long ladd = 0;
		
		PriorityQueue<Long> rset = new PriorityQueue<>();
		rset.add((long)x[0]);
		long radd = 0;
		
		long min = 0;
		
		for(int i=1; i<N; i++) {
			ladd -= a[i];
			radd += a[i-1];
			if(x[i] < lset.peek()+ladd) {
				min = min + (lset.peek()+ladd - x[i]);
				lset.add(x[i]-ladd);
				lset.add(x[i]-ladd);
				rset.add(lset.poll()+ladd-radd);
			} else if(rset.peek()+radd < x[i]) {
				min = min + (x[i] - (rset.peek()+radd));
				rset.add(x[i]-radd);
				rset.add(x[i]-radd);
				lset.add(rset.poll()+radd-ladd);
			} else {
				lset.add(x[i]-ladd);
				rset.add(x[i]-radd);
			}
		}
		System.out.println(min);
		
		sc.close();
	}
}