import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String X=sc.next();
		int ngs=X.length();
		if(ngs==0) {
			System.out.println("YES");
			System.exit(0);
		}
		int cnt=0;
		for(cnt=0; cnt<ngs; cnt++) {
			if(X.charAt(cnt)=='o' || X.charAt(cnt)=='k' || X.charAt(cnt)=='u') {
				//
			}
			else if(X.charAt(cnt)=='c') {
				if(X.charAt(cnt+1)=='h') {
					cnt++;
				}
				else {
					System.out.println("NO");
					System.exit(0);
				}
			}
			else {
				System.out.println("NO");
				System.exit(0);
			}
		}
		System.out.println("YES");
	}
}