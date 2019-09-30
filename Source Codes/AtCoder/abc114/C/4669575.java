import java.util.*;
public class Main {
	static int answer = 0;
	static int n;
	static int[] set = {3, 5, 7};
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		dfs(0);
		System.out.println(answer);
	}
	public static void dfs(long x) {
		if(x > n) return;
		String s = String.valueOf(x);
		if(s.contains("3") && s.contains("5") && s.contains("7"))
			answer++;
		for(int k : set)
			dfs(x*10 + k);
	}
}