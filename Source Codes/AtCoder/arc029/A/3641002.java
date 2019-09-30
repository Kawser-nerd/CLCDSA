import java.util.Arrays;
import java.util.Scanner;

public class Main {


	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int[] t = new int[N];
		for(int i=0; i<N; i++) {
			t[i] = scan.nextInt();
		}
		scan.close();
		if(N==1) {
			System.out.println(t[0]);
		} else if(N==2) {
			System.out.println(Math.max(t[0], t[1]));
		} else if(N==3) {

			Arrays.sort(t);
			System.out.println(Math.max(t[0]+t[1], t[2]));
		} else {
			Arrays.sort(t);
			if(t[3]>=t[0]+t[1]+t[2]) {System.out.println(t[3]); return;}
			if(t[0]+t[3]>t[0]+t[1]+t[2]) {System.out.println(t[0]+t[1]+t[2]); return;}
			System.out.println(Math.max(t[0]+t[3], t[1]+t[2]));
		}
	}
}