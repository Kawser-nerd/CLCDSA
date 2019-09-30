import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Integer n = sc.nextInt();
		int k = sc.nextInt();
		List<Integer> d = new ArrayList<>();
		for (int i=0;i < k;i++) d.add(sc.nextInt());

        while (true) {
			boolean flag = true;
			String nStr = n.toString();
			int[] amt = new int[nStr.length()];
			for (int i=0;i < nStr.length();i++) {
				amt[i] = Integer.parseInt(nStr.substring(i,i+1));
			}
			for (int c : amt) {
				if (d.contains(c)) {
					flag = false;
					break;
				}
			}
			if(flag) {
				System.out.println(n);
				break;
			}
			n++;
		}
	}
}