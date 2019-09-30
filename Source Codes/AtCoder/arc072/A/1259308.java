import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] a = new long[n];
		for(int i=0;i<n;i++) a[i] = sc.nextLong();
		sc.close();
		long count1 = 0;
		long sum = 0;
		//System.out.println("-----------------------");
		for(int i=0;i<n;i++){
			sum += a[i];
			//System.out.print(sum+" -> ");
			if(i%2==0&&sum<=0){
				count1 += 1-sum;
				sum = 1;
			} else if(i%2==1&&sum>=0){
				count1 += sum+1;
				sum = -1;
			}
			//System.out.println(sum+" "+count1);
		}
		//System.out.println("-----------------------");
		sum = 0;
		long count2 = 0;
		for(int i=0;i<n;i++){
			sum += a[i];
			//System.out.print(sum+" -> ");
			if(i%2==1&&sum<=0){
				count2 += 1-sum;
				sum = 1;
			} else if(i%2==0&&sum>=0){
				count2 += sum+1;
				sum = -1;
			}
			//System.out.println(sum+" "+count2);
		}
		//System.out.println("-----------------------");
		System.out.println(Math.min(count1, count2));

	}

}