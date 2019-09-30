import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();

		dfs("", n);
	}

	static void dfs(String str, int n) {
		if (str.length() == n) {
			System.out.println(str);
			return;
		}
		dfs(str + "a", n);
		dfs(str + "b", n);
		dfs(str + "c", n);
	}
}