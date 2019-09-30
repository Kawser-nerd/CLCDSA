import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		
		if(x%2==1)
		{
			x++;
		}
		else
		{
			x--;
		}
		
		System.out.println(x);
		
		sc.close();
	}

}