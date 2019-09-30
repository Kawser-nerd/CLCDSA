import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int sub=sc.nextInt();
		int ten=0;
		for(int i=0; i<sub; i++) {
			ten+=Math.max(0, 80-sc.nextInt());
		}
		System.out.println(ten);
	}
}