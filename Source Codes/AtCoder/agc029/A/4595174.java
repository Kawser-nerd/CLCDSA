import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String st = sc.next();
		int num = st.length();
		boolean isBlack[] = new boolean[st.length()];
		for(int i = 0; i < num; i ++) {
			isBlack[i] = st.charAt(i) == 'B';
		}
		ArrayList<Integer> sameColor = new ArrayList<Integer>();
		int tmp = 0;
		boolean tmpIsBlack = true;
		for(int i = 0; i < num; i ++) {
			if(isBlack[i] != tmpIsBlack) {
				sameColor.add(tmp);
				tmp = 0;
				tmpIsBlack = !tmpIsBlack;
			}
			tmp ++;
		}
		sameColor.add(tmp);
		long count = 0;
		while(sameColor.size() >= 2) {
			if(sameColor.size() <= 1) {
				break;
			}
			count += (long) sameColor.get(0) * sameColor.get(1);
			sameColor.remove(1);
			if(sameColor.size() <= 1) {
				break;
			}
			sameColor.set(1, sameColor.get(0) + sameColor.get(1));
			sameColor.remove(0);
		}
		System.out.println(count);
	}
}