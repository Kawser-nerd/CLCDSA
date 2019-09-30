import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int a = sc.nextInt(), b = sc.nextInt(), q = sc.nextInt();
		
		TreeSet<Long> t = new TreeSet<Long>(),
				s = new TreeSet<Long>();
		
		for (int i=0; i<a; i++) s.add(sc.nextLong());
		for (int i=0; i<b; i++) t.add(sc.nextLong());
		
		for (int i=0; i<q; i++) {
			long pos = sc.nextLong();
			Long tl = t.floor(pos), tr = t.ceiling(pos), 
					sl = s.floor(pos), sr = s.ceiling(pos);
			if (tl==null) tl = -1L<<60;
			if (tr==null) tr = 1L<<60;
			if (sl==null) sl = -1L<<60;
			if (sr==null) sr = 1L<<60;
			
			Long min = 1L<<60;
			
			min = Math.min(Math.max(pos - tl, pos - sl), Math.max(tr - pos, sr - pos));
			min = Math.min(min, (pos - tl) + (sr - pos) + Math.min((pos - tl), (sr - pos)));
			min = Math.min(min, (tr - pos) + (pos - sl) + Math.min((tr - pos), (pos - sl)));
			
			
			System.out.println(min);
			
		}
	}
}