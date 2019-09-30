import java.util.*;
public class Main {
	public static void main(String args[]) {
		ArrayList<String> list = new ArrayList<>();
		Scanner sc = new Scanner(System.in);
		String S = sc.nextLine();
		String T = sc.nextLine();
		String tmp;
		int L = S.length();
		boolean check = true;
		for (int i = 0; i < L; i++) {
			list.add(String.valueOf(S.charAt(i)));
		}
		for (int i = 0; i < L; i++) {
			tmp = list.get(L - 1);
			list.add(0, tmp);
			list.remove(list.size() - 1);
			int cnt = 0;
			for (int j = 0; j < L; j++) {
				if(list.get(j).equals(String.valueOf(T.charAt(j)))) {
					cnt++;
				}
			}
			if (cnt == L) {
				System.out.println("Yes");
				check = false;
				break;
			}
		}
		if (check) {
			System.out.println("No");
		}
		
	}
}