import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		Integer s = scan.nextInt();
		List<Integer> numList = new ArrayList();
		OUT:for(int i = 1;; i++) {
			if(i==1) {
				numList.add(s);
			}
			Integer currentValue = null;
			if(i>1) {
				Integer prevValue = numList.get(i-2);
				if(prevValue%2==0) {
					currentValue = prevValue/2;
				}else {
					currentValue = 3*prevValue+1;
				}
				for(Integer num:numList) {
					if(currentValue == num) {
						System.out.println(i);
						break OUT;
					}
				}
				numList.add(currentValue);
			}
		}
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.