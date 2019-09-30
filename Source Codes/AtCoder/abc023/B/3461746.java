import java.util.Scanner;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int n=scanner.nextInt();
		String s=scanner.next();
		if(n%2==0) {
			System.out.println(-1);
			return;
		}
		for(int i=0;i<s.length()/2;i++) {
			char f=s.charAt(i);
			char b=s.charAt(s.length()-1-i);
			if((f=='b'&&b=='b')||(f=='a'&&b=='c')||(f=='c'&&b=='a'))
				continue;
			else {
				System.out.println(-1);
				return;
			}
		}
		System.out.println(s.length()/2);
	}
}