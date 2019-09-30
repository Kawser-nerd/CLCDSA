import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		String N = sc.next();

		String mae;
		String ato;
		if(N.length()%2==0) {
			mae = N.substring(0, N.length()/2);
			ato = N.substring(N.length()/2,N.length());
		}else {
			mae = N.substring(0,N.length()/2);
			ato = N.substring(N.length()/2+1,N.length());
		}

		int cnt = 0;
		boolean flg = true;
		for(int i=N.length()/2;i>0;i--) {
			if(mae.charAt(cnt)!=ato.charAt(i-1)) {
				flg = false;
			}
			cnt++;
		}

		System.out.println(flg?"YES":"NO");

	}

}