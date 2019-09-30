import java.util.Scanner;

public class Main {

	public static boolean avairable(int[] as, int min, int max) {
		switch(max-min) {
		case 0:
			for(int i=0; i<as.length; i++)
				if(as[i]!=as.length-1&&2*as[i]>as.length)
					return false;
			return true;
		case 1:
			int alone_num=0;
			for(int a: as)
				if(a==min)
					alone_num++;
			return alone_num<max && 2*(max-alone_num)<=as.length-alone_num;
		default:
			return false;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] as = new int[n];
		int min = n;
		int max = 0;
		for(int i=0; i<n; i++) {
			as[i] = sc.nextInt();
			if(as[i]<min) min = as[i];
			if(as[i]>max) max = as[i];
		}
		sc.close();

		System.out.println(avairable(as, min, max)?"Yes":"No");
	}
}