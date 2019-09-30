import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String S = sc.next();
		sc.close();
		
		if(N % 2 == 0) {
			System.out.println("-1");
			return;
		}
		String str = "abc";
		int offset = (N%6)%3;
		boolean flag = true;
		for(int i = 0;i < N;++i) {
			if(S.charAt(i) != str.charAt((offset+i)%3)) {
				flag = false;
				break;
			}
		}
		if(flag)
			System.out.println(N/2);
		else
			System.out.println("-1");
	}
}