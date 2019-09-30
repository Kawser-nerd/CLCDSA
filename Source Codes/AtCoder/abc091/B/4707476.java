import java.util.*; 
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String [] s = new String[n];
		for(int i = 0; i < n; i++) {
			s[i] = sc.next();
		}
		int m = sc.nextInt();
		String [] t = new String[m];
		for(int i = 0; i < m; i++) {
			t[i] = sc.next();
		}
		int point = 0;
		for(int i = 0; i < n; i++) {
			int plus = 0;
			int minus = 0;
			for(int j= 0; j < n; j++) {
				if(s[i].equals(s[j])) {
					plus ++;
				}
			}
			for(int k = 0; k < m; k++) {
				if(s[i].equals(t[k])) {
					minus ++;
				}
			}
			if(point < plus - minus) {
				point = plus - minus;
			}
		}
		System.out.println(point);

	}

}