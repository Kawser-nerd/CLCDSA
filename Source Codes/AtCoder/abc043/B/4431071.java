import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		char[] C = sc.next().toCharArray();
		String S = "";
		sc.close();
		for(int i=0;i<C.length;i++) {
			if(C[i]=='B') {if(S.length()>0)S=S.substring(0, S.length()-1);}
			else S+=C[i];
		}
		System.out.println(S);
	}
}