import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int ret = 0;
		for(int i = 1 ; i <= N ; i++) {
			ret += i;
		}
		int[] pn = new int[ret + 1];
		for(int i = 0 ; i < ret + 1 ; i++) pn[i] = 1;
		pn[1] = 0;
		int k = 2;
		while(k * k <= ret) {
			if(pn[k] == 1) {
				for(int i = k ; i <= ret / k ; i++) {
					pn[i * k] = 0;
				}
			}
			k++;
		}
		if(pn[ret] == 1) {
			System.out.println("WANWAN");
		} else {
			System.out.println("BOWWOW");
		}
	}
}