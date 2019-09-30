import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int A = sc.nextInt();
		int B = sc.nextInt();
		String[] s = new String[N];
		int[] d = new int[N];
		for(int i = 0;i < N;++i) {
			s[i] = sc.next();
			d[i] = sc.nextInt();
		}
		sc.close();
		
		int currentPos = 0;
		for(int i = 0;i < N;++i) {
			int m = d[i];
			if(m < A)
				m = A;
			else if(m > B)
				m = B;
			if(s[i].equals("East"))
				currentPos += m;
			else
				currentPos -= m;
		}
		if(currentPos == 0)
			System.out.println("0");
		else if(currentPos > 0)
			System.out.println("East " + currentPos);
		else
			System.out.println("West " + (-currentPos));
	}
}