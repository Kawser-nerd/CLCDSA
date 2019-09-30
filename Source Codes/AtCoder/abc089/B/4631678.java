import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		boolean i = false;
		boolean j = false;
		boolean k = false;
		String[] s = new String[N];
		for(int l = 0;l < N;l++) {
			s[l] = sc.next();
			
		}
		for(int l = 0;l < N;l++) {
			if(s[l].equals("P")) {
				i = true;
			}
			else if(s[l].equals("W")) {
				j = true;
			}
			else if(s[l].equals("G")) {
				k = true;
			}
			else {
				i = false;
				j = false;
				k = false;
				break;
			}
		}
		if(i = true && j && k) System.out.println("Three");
		else if(!i && !j && !k) System.out.println("Four");
		sc.close();
	}

}