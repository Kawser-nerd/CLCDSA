import java.util.Arrays;
import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int C=sc.nextInt();
		int K=sc.nextInt();
		int[] time=new int[N];
		for(int i=0; i<N; i++) {
			time[i]=sc.nextInt();
		}
		Arrays.sort(time);		//???
		int[] kannin=new int[N];
		for(int i=0; i<N; i++) {
			kannin[i]=time[i]+K;
		}
		int bus=1;
		int ninzu=1;
		int min=time[0];
		int max=kannin[0];
		for(int i=1; i<N; i++) {
			if(time[i]<=max && ninzu<C) {
				ninzu++;
			}
			else if(time[i]<=max && ninzu>=C) {		//????????????
				bus++;
				ninzu=1;
				min=time[i];
				max=kannin[i];
			}
			else if(time[i]>max) {	//???????
				bus++;
				ninzu=1;
				min=time[i];
				max=kannin[i];
			}
		}
		System.out.println(bus);
	}
}