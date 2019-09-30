import java.util.Scanner;

class Main{


static int[][] data;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//?????
		int n  = sc.nextInt();
		int m = sc.nextInt();
		
		if(m <= n/2){
			System.out.println(m-1);
			
		}else{
			System.out.println(n-m);
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