import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int height = sc.nextInt();
		int width = sc.nextInt();
		boolean oddCoin[][] = new boolean[height][width];
		for(int i = 0; i < height; i ++) {
			for(int j = 0; j < width; j ++) {
				oddCoin[i][j] = sc.nextInt() % 2 == 1;
			}
		}
		int count = 0;
		ArrayList<String> output = new ArrayList<String>();
		for(int i = 0; i < height - 1; i ++) {
			for(int j = 0; j < width; j ++) {
				if(oddCoin[i][j]) {
					count ++;
					oddCoin[i][j] = !oddCoin[i][j];
					oddCoin[i + 1][j] = !oddCoin[i + 1][j];
					output.add((i + 1)+" "+(j + 1)+" "+(i + 1 + 1)+" "+(j + 1));
				}
			}
		}
		for(int j = 0; j < width - 1; j ++) {
			if(oddCoin[height - 1][j]) {
				count ++;
				oddCoin[height - 1][j] = !oddCoin[height - 1][j];
				oddCoin[height - 1][j + 1] = !oddCoin[height - 1][j + 1];
				output.add(height+" "+(j + 1)+" "+height+" "+(j + 2));
			}
		}
		System.out.println(count);
		for(int i = 0; i < output.size(); i ++) {
			System.out.println(output.get(i));
		}
	}
}