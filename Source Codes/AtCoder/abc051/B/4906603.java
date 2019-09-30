import java.util.Scanner;

public class Main{

	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);

		int k = Integer.parseInt(scanner.next());
		int s = Integer.parseInt(scanner.next());

		int res = 0;

		for(int x = 0; x <=k; x++){
			for(int y = 0; y<= k; y++){
				int z = s - (x + y);
				if(0 <= z && z <= k)
					res++;
			}
		}

		System.out.println(res);
	}
}