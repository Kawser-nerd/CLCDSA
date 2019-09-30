import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int L=sc.nextInt();
		String S=sc.next();
		int crash=0;
		int browser=1;
		for(int i=0; i<S.length(); i++) {
			if(S.charAt(i)=='+') {
				browser++;
				if(browser>L) {
					crash++;
					browser=1;
				}
			}
			else if(S.charAt(i)=='-') {
				browser--;
			}
		}
		System.out.println(crash);
	}
}