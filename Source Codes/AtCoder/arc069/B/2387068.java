import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s = sc.next();

		//SS
		char[] ans = new char[n];

		fill(ans, 'S','S',s);

		if(!(ans[n-2]=='S' ^ ans[n-1]=='S' ^ s.charAt(n-1)=='o' ^ ans[0]=='S')
				&& !(ans[n-1]=='S' ^ ans[1]=='S' ^ s.charAt(0)=='o' ^ ans[0]=='S')) {
			System.out.println(new String(ans));
			return;
		}

		fill(ans,'S','W',s);

		if(!(ans[n-2]=='S' ^ ans[n-1]=='S' ^ s.charAt(n-1)=='o' ^ ans[0]=='S')
				&& !(ans[n-1]=='S' ^ ans[1]=='S' ^ s.charAt(0)=='o' ^ ans[0]=='S')) {
			System.out.println(new String(ans));
			return;
		}

		fill(ans,'W','S',s);

		if(!(ans[n-2]=='S' ^ ans[n-1]=='S' ^ s.charAt(n-1)=='o' ^ ans[0]=='S')
				&& !(ans[n-1]=='S' ^ ans[1]=='S' ^ s.charAt(0)=='o' ^ ans[0]=='S')) {
			System.out.println(new String(ans));
			return;
		}

		fill(ans,'W','W',s);

		if(!(ans[n-2]=='S' ^ ans[n-1]=='S' ^ s.charAt(n-1)=='o' ^ ans[0]=='S')
				&& !(ans[n-1]=='S' ^ ans[1]=='S' ^ s.charAt(0)=='o' ^ ans[0]=='S')) {
			System.out.println(new String(ans));
			return;
		}

		System.out.println(-1);

	}

	static void fill(char[] ans, char a, char b, String s) {
		ans[0]=a;
		ans[1]=b;
		for (int i=1;i<ans.length-1;i++) {
			if(ans[i-1]=='S' ^ ans[i]=='S' ^ s.charAt(i)=='o') {
				ans[i+1]='S';
			} else {
				ans[i+1]='W';
			}
		}
	}

}