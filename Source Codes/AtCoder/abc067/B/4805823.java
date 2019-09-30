import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int numberOfStickUsed = sc.nextInt();
		ArrayList<Integer> list = new ArrayList<>();
		for(int i = 0; i < n; i++) {
			list.add(sc.nextInt());
		}
		Collections.sort(list,Comparator.reverseOrder());
		int sum = 0;
		for(int i = 0; i < numberOfStickUsed; i++) {
			sum += list.get(i);
		}
		System.out.println(sum);
		
	}
}