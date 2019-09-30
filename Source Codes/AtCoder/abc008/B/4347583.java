import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		String candidate[] = new String[num];
		int vote[] = new int[num];
		for(int i = 0; i < num; i ++) {
			candidate[i] = sc.next();
			int j = 0;
			for(; j < i; j ++) {
				if(candidate[j].equals(candidate[i])) {
					break;
				}
			}
			vote[j] ++;
		}

		int max = 0;
		int index = 0;
		for(int i = 0; i < num; i ++) {
			if(max < vote[i]) {
				max = vote[i];
				index = i;
			}
		}
		System.out.println(candidate[index]);
	}
}