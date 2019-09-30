import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		boolean g = true;
		int t = 0;
		String a = sc.next();
		String b = sc.next();
		String[] strArray1 = a.split("");
		String[] strArray2 = b.split("");
		Arrays.sort(strArray1);
		Arrays.sort(strArray2,Collections.reverseOrder());
		int m1 = strArray1.length;
		int m2 = strArray2.length;
		if(m1 > m2) m1 = m2;
		for(int i = 0;i < m1;i++) {
			if(strArray1[i].compareTo(strArray2[i]) < 0) {
				g  = false;
				break;
			}
			if(strArray1[i].compareTo(strArray2[i]) == 0) t++;
		}
		if(t == m1 && m1 < m2) {
			System.out.println("Yes");
		}
		else if(g) {
			System.out.println("No");
		}
		else if(!g) {
			System.out.println("Yes");
		}
		sc.close();
	}
}