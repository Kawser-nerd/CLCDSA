import java.util.Scanner;
import java.util.TreeSet;

public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int M = sc.nextInt();
        long X = sc.nextLong();
        long Y = sc.nextLong();
        
        TreeSet<Long> a = new TreeSet<>();
		for (int i = 0; i < N; i++) {
			a.add(sc.nextLong());
		}
		
		TreeSet<Long> b = new TreeSet<>();
		for (int i = 0; i < M; i++) {
			b.add(sc.nextLong());
		}
		
		int ans = 0;
		
		long now = a.first() + X;
		boolean type = true;
		while(true) {
			if (type) {
				Long next = b.higher(now-1);
				
				if (next == null) {
					break;
				}
				
				now = next + Y;
				ans++;
			} else {
				Long next = a.higher(now-1);
				
				if (next == null) {
					break;
				}
				
				now = next + X;
			}
			
			type = !type;
		}
		
		
		System.out.println(ans);
    }
}