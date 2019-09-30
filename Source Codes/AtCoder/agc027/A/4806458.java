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
		int x = sc.nextInt();
		ArrayList<Integer> list = new ArrayList<>();
		sc.nextLine();
		for(int i = 0; i < n; i++) {
			list.add(sc.nextInt());
		}
		Collections.sort(list, Comparator.naturalOrder());
		int index = 0;
		for(int i = 0; i < list.size(); i++) {
			if(x < list.get(i)) {
				break;
			}
			if(i == list.size() -1 && x > list.get(i)) {
				break;
			}
			index++;
			x -= list.get(i);

		}
		System.out.println(index);
		
		
		
	}
}