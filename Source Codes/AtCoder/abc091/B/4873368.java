import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();

		String[] S = new String[N];

		for(int i=0;i<N;i++) {

			S[i] = sc.next();
		}

		int M = sc.nextInt();

		String[] T = new String[M];

		for(int i=0;i<M;i++) {

			T[i] = sc.next();
		}

		//???
		String tkhs = "";

		int ans = 0;

		int score = 0;

		for(int i=0;i<N;i++) {

			tkhs = S[i];

			score = 0;

			for(int j=0;j<N;j++) {

				if(S[j].equals(tkhs)) score++;
			}
			for(int j=0;j<M;j++) {

				if(T[j].equals(tkhs)) score--;
			}

			ans = Math.max(ans, score);
		}
		System.out.println(ans);
	}

}