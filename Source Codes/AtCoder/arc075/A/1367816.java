import java.util.*;

public class Main{ // Main
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int[] scores = new int[n];
		int sum = 0;
		int grade = 0;
		for(int i = 0; i < n; i ++) {
			scores[i] = scanner.nextInt();
			sum += scores[i];
		}
		if(sum % 10 != 0) {
			grade = sum;
		} else {
			Arrays.sort(scores);
			for(int score: scores) {
				if(score % 10 != 0) {
					grade = sum - score;
					break;
				}
			}
		}
		System.out.println(grade);
		
		
		scanner.close();
	}
	
}