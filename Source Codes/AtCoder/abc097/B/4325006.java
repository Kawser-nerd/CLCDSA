import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int X = scan.nextInt();
		int result = 0;
		int count = 1;
		for(int i = 1;i <= X;i++) {
			for(int j = 2;;j++) {
				if(i == 1) {
					result = 1;
					break;
				}
				if((int)Math.pow(i,j) > X) {
					break;
				}else {
					if((int)Math.pow(i,j) >= result) {
						result = (int)Math.pow(i,j);
					}
				}
				count = (int)Math.pow(i,j);
			}
		}
		System.out.println(result);
	}
}