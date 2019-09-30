import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	int a=scan.nextInt();
	int ans=1;
	for(int i=a;i!=0;i--) {
		if(Math.sqrt(i)==(int)Math.sqrt(i)){
			System.out.println(i);
			break;
	}
	}
	scan.close();
}
}