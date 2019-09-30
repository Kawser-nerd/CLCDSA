import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		String s = sc.next();
		char[] arr = new char[s.length()*2+1];
		for(int i = 0; i < arr.length; i++) {
			arr[i] = ':';
			if(i%2==1) {
				arr[i]=s.charAt(i/2);
			}
		}
		for(int i = 0; i < 4; i++) {
			int p = sc.nextInt();
			if(p==0) {
				arr[0] = '\"';
			} else {
				arr[2*p] = '\"';
			}
		}
		//System.out.println(Arrays.toString(arr));
		for(char c : arr) {
			if(c==':') continue;
			System.out.print(c);
		}
		System.out.println();
	}
}