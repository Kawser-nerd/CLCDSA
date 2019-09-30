import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int X = sc.nextInt();
		int[] material = new int[N];
		for(int i = 0;i < N;i++) {
			material[i] = sc.nextInt();
			X -= material[i];
		}
		sc.close();
		Arrays.sort(material);
		int count = N;
		for(int i = 0;i < N;i++) {
			count += X / material[i];
			X -= (X / material[i]) * material[i];
		}
		
		System.out.println(count);
	}

}