import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String spot[][] = new String[4][4];
		for(int i = 0; i < 4; i ++) {
			for(int j = 0; j < 4; j ++) {
				spot[i][j] = sc.next();
			}
		}
		for(int i = 3; i >= 0; i --) {
			for(int j = 3; j >= 0; j --) {
				System.out.print(spot[i][j]+(j > 0 ? " " : ""));
			}
			System.out.println();
		}
	}
}