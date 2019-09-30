import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt(),l = sc.nextInt(),t = sc.nextInt();
		int temp,cnt = 0,d;
		int[] a = new int[n];

		for(int i = 0;i < n;i++){
			a[i] = sc.nextInt();
			d = sc.nextInt();

			if(d == 1){
				temp = a[i] + t;
				a[i] = temp % l;
				cnt += temp / l;
			}else{
				temp = a[i] - t;
				a[i] = temp % l;
				cnt += temp / l;
				if(a[i] < 0){
					a[i] += l;
					cnt--;
				}
			}
		}

		Arrays.sort(a);

		cnt %= n;
		if(cnt < 0)cnt += n;
		cnt %= n;
		for(int i = cnt;i < cnt + n;i++){
			int j = i % n;
			System.out.println(a[j]);
		}

		sc.close();
	}
}