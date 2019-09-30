import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] march = new long[5];
		for(int i = 0; i < N; i++) {
			String S = sc.next();
			if(S.charAt(0) == 'M')
				march[0] += 1;
			if(S.charAt(0) == 'A')
				march[1] += 1;
			if(S.charAt(0) == 'R')
				march[2] += 1;
			if(S.charAt(0) == 'C')
				march[3] += 1;
			if(S.charAt(0) == 'H')
				march[4] += 1;
		}
		long ans = 0;
		for(int i = 0; i < 3; i++) {
			for(int j = i+1; j < 4; j++) {
				for(int k = j+1; k < 5; k++) {
					ans += march[i]*march[j]*march[k];
				}
			}
		}
		System.out.println(ans);

	}

}