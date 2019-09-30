import java.util.ArrayList;
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int A = sc.nextInt();

		int B = sc.nextInt();

		int K = sc.nextInt();

		ArrayList<Integer> array = new ArrayList<>();

		for(int i=0;i<K;i++) {

			if(A+i<=B) array.add(A+i);
		}

		for(int i=K-1;i>=0;i--) {

			if(!array.contains(B-i) && B-i>=A) array.add(B-i);
		}

		for(int i=0;i<array.size();i++) {

			System.out.println(array.get(i));
		}
	}

}