import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		boolean j = true;
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		String s = sc.next();
		String[] strArray = s.split("");
		if(strArray.length != a+b+1) j = false;
		if(strArray[a].equals("-")) {
			for(int i = 0;i < strArray.length;i++) {
				if(i != a) {
					if(!(strArray[i].equals("-"))) {
						int x = Integer.parseInt(strArray[i]);
						if(x >= 10 && x < 0) j = false;
					}
					else j = false;
				}
			}
		}
		else j = false;
		if(j) System.out.println("Yes");
		else if(!j) System.out.println("No");
		sc.close();	
	}
}