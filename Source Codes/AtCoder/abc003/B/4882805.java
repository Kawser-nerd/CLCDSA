import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] oneStr = sc.nextLine().split("");
		String[] twoStr = sc.nextLine().split("");
		String[] replacePossibleStr = {"a","t","c","o","d","e","r"};
		
		// ????????????????????????????????????
		for(int idx = 0;idx < oneStr.length;idx++) {
			int matchedCnt = 0;
			if(!oneStr[idx].contentEquals(twoStr[idx])) {
				// 1???@??????????2??????????????
				if(oneStr[idx].equals("@")) {
					for(String data:replacePossibleStr) {
						if(twoStr[idx].equals(data)) {
							matchedCnt++;
						}
					}
					if(matchedCnt == 0) {
						System.out.println("You will lose");
						sc.close();
						return;
					}
				// 2???@??????????1??????????????
				}else if(twoStr[idx].equals("@")) {
					for(String data:replacePossibleStr) {
						if(oneStr[idx].equals(data)) {
							matchedCnt++;
						}
					}
					if(matchedCnt == 0) {
						System.out.println("You will lose");
						sc.close();
						return;
					}
				// @?????????????????
				}else {
					System.out.println("You will lose");
					sc.close();
					return;
				}
			}
		}
		
		// ???????????????1???2???????
		System.out.println("You can win");
		sc.close();
	}
}