import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		String si = sc.nextLine();
		int[] num = new int[5];
		for(int i = 0;i< 4;i++){
			num[i] = sc.nextInt();
		}

		int start = 0;
		String ans = "";

		for(int i = 0;i< 4;i++){
			ans += si.substring(start, num[i]);
			ans += "\"";
			start = num[i];
		}

		if(num[3] != si.length()){
			ans += si.substring(start,si.length());
		}



		System.out.println(ans);
	}
}