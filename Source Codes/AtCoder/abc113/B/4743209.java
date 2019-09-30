import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int t = sc.nextInt();
		int a = sc.nextInt();
		int [] hArray = new int [n];
		int num = 0;
		double tem = 0, dif = 0, mindif = Double.MAX_VALUE;
		for(int i = 0; i < n; i++) {
			hArray[i] = sc.nextInt();
			tem = t - hArray[i] * 0.006;
			if(tem >= a) dif = tem - a;
			else dif = a - tem;
			if(mindif >= dif) {
				mindif = dif;
				num = i + 1;
			}
		}
		System.out.println(num);
		
	sc.close();
	}

}