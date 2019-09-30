import java.util.*;

public class Main {
	static Scanner sc;
	static int A,B,N;
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		A = sc.nextInt();
		B = sc.nextInt();
		N = A+B;
		if(B>=A) {
			System.out.println("Impossible");
		} else {
			int honest = getHonest();
			char[] ans = new char[N];
			for(int i=0; i<N; i++) {
				ans[i] = ask(honest, i) ? '1' : '0';
			}
			System.out.println("! " + String.valueOf(ans));
		}
		sc.close();
	}

	static int getHonest() {
		int need = B+1;
		LinkedList<Integer> list = new LinkedList<>();
		for(int i=0; i<N; i++) {
			if(list.isEmpty()) {
				list.push(i);
			} else {
				if(ask(list.peek(), i)) {
					list.push(i);
				} else {
					list.pop();
					need--;
				}
			}
			if(list.size()>=need)
				return list.pop();
		}
		
		return -1;
	}
	
	static boolean ask(int a, int b) {
		System.out.println("? "+a+" "+b);
		return sc.next().equals("Y");
	}
}