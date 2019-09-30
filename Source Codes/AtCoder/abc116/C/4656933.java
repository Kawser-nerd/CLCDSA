import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] h = new int[n];
		for(int i = 0; i < n; i++) {
			h[i] = sc.nextInt();
		}
		int answer = 0;
		for(int i = 0; i < n; i++) {
			while(h[i] != 0) {
				answer += 1;
				for(int j = i; j < n; j++) {
					if(h[j] <= 0)
						break;
					else
						h[j] -= 1;
				}
			}
		}
		System.out.println(answer);
	}

}