import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {
		long res=0;
		for(int c=s.nextInt();c>0;c--)
			res+=s.nextInt()*s.nextInt();
		System.out.println((int)(res*1.05));
	}
}