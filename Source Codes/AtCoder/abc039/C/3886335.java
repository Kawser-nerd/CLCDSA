import java.util.Scanner;

class Main{
	static int n;
	static long ans = 1000000000;
	static int[] memo;
	static int[] dp;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//?????
		String k = sc.next();
		int num = 0;
		for(int i = 0;i < k.length()-4;i++){
			if(k.charAt(i) == 'B' && k.charAt(i + 2) == 'B' &&k.charAt(i + 4) == 'B'){
				num = i;
				break;
			}
		}
		
		if(num == 6){
			System.out.println("Do");
			return;
		}else if(num == 4 ){
			System.out.println("Re");

		}else if(num == 2 ){
			System.out.println("Mi");

		}else if(num == 1 ){
			System.out.println("Fa");

		}else if(num == 11 ){
			System.out.println("So");

		}else if(num == 9 ){
			System.out.println("La");

		}else if(num == 7 ){
			System.out.println("Si");

		}
		
		
		
		
		
	}




}

class Pair implements Comparable{
	int from;
	int end;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return end - otherpair.end;
	}
}