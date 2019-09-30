import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] data = new int[3];
		for(int i = 0; i < 3; i++) {
			data[i] = sc.nextInt();
		}
		int K = sc.nextInt();
		
		int maxIdx = 0;
		int max = data[0];
		for(int i = 1; i < 3; i++) {
			if(max < data[i]) {
				max = data[i];
				maxIdx = i;
			}
		}
		
		for(int i = 0; i < K; i++) {
			data[maxIdx] *= 2;
		}
		
		System.out.println(data[0] + data[1] + data[2]);
		
		sc.close();

	}

}