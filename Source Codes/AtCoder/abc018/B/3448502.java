import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		int N = sc.nextInt();
		int[][] operation = new int[N][2];
		for(int i = 0;i < N;++i) {
			operation[i][0] = sc.nextInt()-1;
			operation[i][1] = sc.nextInt()-1;
		}
		sc.close();
		
		for(int i = 0;i < N;++i)
			S = replace_reverse(S, operation[i][0], operation[i][1]);
		
		System.out.println(S);
	}
	
	private static String replace_reverse(String s, int l, int r) {
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i < l;++i)
			sb.append(s.charAt(i));
		for(int i = r;i >= l;--i)
			sb.append(s.charAt(i));
		if(r+1 < s.length())
			for(int i = r+1;i < s.length();++i)
				sb.append(s.charAt(i));
		return sb.toString();
	}
}