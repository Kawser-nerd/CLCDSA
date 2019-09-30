import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		boolean[][] s = new boolean[N][N];
		for(int i = 0;i < N;++i) {
			String str = sc.next();
			for(int j = 0;j < N;++j)
				s[i][j] = str.charAt(j) == 'o';
		}
		sc.close();
		
		for(int i = 0;i < N;++i) {
			for(int j = N-1;j >= 0;--j)
				if(s[j][i])
					System.out.print('o');
				else
					System.out.print('x');
			System.out.println();
		}
	}
}