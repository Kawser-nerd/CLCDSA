import java.util.Scanner;
class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		boolean[] mt=new boolean[N+1];
		mt[sc.nextInt()]=true;
		mt[sc.nextInt()]=true;
		int K=sc.nextInt();
		for(int i=0; i<K; i++) {
			int tmp=sc.nextInt();
			if(mt[tmp]) {
				System.out.println("NO");
				System.exit(0);
			}
			else {
				mt[tmp]=true;
			}
		}
		System.out.println("YES");
	}
}