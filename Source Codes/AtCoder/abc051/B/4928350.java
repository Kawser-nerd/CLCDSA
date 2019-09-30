import java.util.Scanner;

class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int s = sc.nextInt();
		
		int answer = 0;
		for(int x = 0; x <= k; x++){
			for(int y = 0; y <= k; y++){
				int z = s - x - y;
				if((0 <= z) && (z <= k)){
					answer += 1;
				}
			}
		}
		
		System.out.println(answer);
	}
}