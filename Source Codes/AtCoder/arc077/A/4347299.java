import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {

		int n = sc.nextInt();
		ArrayDeque<Integer> dq = new ArrayDeque<>();
		for (int i=0; i<n; i++) {
			int temp = sc.nextInt();
			if (n%2 == 0) {
				if (i%2 != 0) dq.addFirst(temp);
				else dq.addLast(temp);
			}
			else {
				if (i%2 == 0) dq.addFirst(temp);
				else dq.addLast(temp);
			}

		}
		StringBuilder sb = new StringBuilder();
		for (Integer e: dq) {
			sb.append(e+" ");
		}
		sb.delete(sb.length()-1, sb.length());
		System.out.println(sb);

	}
}