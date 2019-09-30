import java.util.*;

public class Main {
	static boolean[] comp = new boolean[1310];
	static ArrayList<Integer> list = new ArrayList<>();
	
	public static void main(String[] args) {
		sieve();
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		StringBuilder sb = new StringBuilder();
		
		for(int i = 0; i < N; i++) {
			if(i != 0)
				sb.append(" ");
			sb.append(list.get(i));
		}
		System.out.println(sb.toString());
	}
	
	public static void sieve() {
		for(int i = 2; i < comp.length; i++) {
			if(!comp[i]) {
				if(i % 5 == 3)
					list.add(i);
				for(int j = 2; i*j < comp.length; j++)
					comp[i*j] = true;
			}
		}
	}
}