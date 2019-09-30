import java.util.Scanner;

public class Main{
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		String str=sc.nextLine();
		String s=str.substring(0, 12)+str;
		//System.out.println(s);
		int doidx=0;
		for(int i=0;i<26;i++) {
			if(s.substring(i,i+7).equals("WWBWBWW")) {
				doidx=i+1;
			}
			//System.out.println(s.substring(i,i+7));

		}
		//System.out.println(doidx);
		switch(doidx%12) {
		case 0:
			System.out.println("Do");
			break;
		case 10:
			System.out.println("Re");
			break;
		case 8:
			System.out.println("Mi");
			break;
		case 7:
			System.out.println("Fa");
			break;
		case 5:
			System.out.println("So");
			break;
		case 3:
			System.out.println("La");
			break;
		case 1:
			System.out.println("Si");
			break;
		}
	}
}