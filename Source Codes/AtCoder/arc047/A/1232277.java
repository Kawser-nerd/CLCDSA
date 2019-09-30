import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);
	public static void main(String[] args) {
		int n=s.nextInt(),l=s.nextInt();
		String log=s.next();

		int tab=1,res=0;

		for(int i=0;i<n;i++) {
			tab+=log.charAt(i)=='+'?+1:-1;
			if(tab>l) {
				tab=1;
				res++;
			}
		}

		System.out.println(res);
	}
}