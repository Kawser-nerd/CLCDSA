import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		String ans = sc.next();
		int right[] = new int[4];
		String choose[] = {"1", "2", "3", "4"};
		for(int i = 0; i < 4; i ++) {
			right[i] = num - ans.replace(choose[i], "").length();
		}
		Arrays.sort(right);
		System.out.println(right[3]+" "+right[0]);
	}
}