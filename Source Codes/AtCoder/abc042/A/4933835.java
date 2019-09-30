import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		String[] sArray = s.split(" ");

		int five  = 0;
		int seven = 0;

		for(int i=0; i<3; i++) {
			if(sArray[i].equals("5")) {
				five++;
			}else if(sArray[i].equals("7")){
				seven++;
			}
		}

		//????
		if(five == 2 && seven == 1) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}

}