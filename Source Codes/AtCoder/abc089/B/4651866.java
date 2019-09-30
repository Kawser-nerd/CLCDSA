import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		boolean i = true;
	
		String[] s = new String[N];
		
		for(int l = 0;l < N;l++) {
			s[l] = sc.next();
			if(s[l].equals("Y")) i = false;
		}
		sc.close();
	
		if(i) System.out.println("Three");
		else System.out.println("Four");
		
	}

}
//AtCoder089_B