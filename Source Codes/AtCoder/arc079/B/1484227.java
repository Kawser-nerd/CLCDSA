import java.util.*;

public class Main {
	
	private void doit(){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			long k = sc.nextLong();
			
			long n = 50;
			long base = (k / n) + n-1;
			int x = (int) (k % n);
			
			System.out.println(n);
			StringBuilder sb = new StringBuilder();
			for(int i = 0; i < x;i++){
				sb.append(" ");
				sb.append(base + n  - x + 1);
			}
			for(int i = 0; i < n - x; i++){				
				sb.append(" ");
				sb.append(base - x);
			}
			System.out.println(sb.substring(1));
			
		}
	}


	private void debug(Object... o) {
		System.out.println("debug = " + Arrays.deepToString(o));
	}

	public static void main(String[] args) {
		new Main().doit();
	}

}