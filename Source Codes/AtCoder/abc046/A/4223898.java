import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		boolean bucket[] = new boolean[105];
		for(int i = 0; i < 3; i ++) {
			bucket[sc.nextInt()] = true;
		}
		long count = 0;
		for(int i = 0; i < bucket.length; i ++) {
			if(bucket[i]) {
				count ++;
			}
		}
		System.out.println(count);
	}
}