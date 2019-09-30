import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[][]data = new int[3][3];
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				data[i][j] = sc.nextInt();
			}
		}
		int a1 = 0;
		int b1 = data[0][0];
		int b2 = data[1][0];
		int b3 = data[2][0];
		int a2 = data[0][1]-b1;
		int a3 = data[0][2]-b1;
		if(data[0][0]==a1+b1 && data[0][1]==a2+b1 && data[0][2]==a3+b1 && data[1][0]==a1+b2 && data[1][1]==a2+b2 && data[1][2]==a3+b2 && data[2][0]==a1+b3 && data[2][1]==a2+b3 && data[2][2]==a3+b3) {
			System.out.println("Yes");
		}else System.out.println("No");
		sc.close();
	}
}