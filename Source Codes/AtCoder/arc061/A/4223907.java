import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		char[] pres = sc.next().toCharArray();
		int n = pres.length;
		int[] s = new int[n];
		for(int i = 0; i < n; i++) {
			s[i] = Integer.parseInt(String.valueOf(pres[i]));
		}
		
		/*Stack<Task> stack = new Stack<Task>();
		stack.push(new Task(0, 0, 0));
		long ans = 0;
		while(!stack.isEmpty()) {
			Task t = stack.pop();
			int i = t.i;
			long x = t.x;
			long y = t.y * 10 + s[i];
			
			if(i == n - 1) {
				ans += x + y;
				continue;
			}
			stack.push(new Task(x * 10 + y, 0, i + 1));
			stack.push(new Task(x, y, i + 1));
		}
		
		System.out.println(ans);*/
		/*System.out.println(calc(s, n, 0, s[0], 1));*/
		int a = 0;
		System.out.println(calc2(s, n, a, 0));
	}
	
	/*private static long calc(int[] s, int n, long x, long y, int i) {
		if(i == n) {
			return x + y;
		}
		return calc(s, n, x + y, s[i], i + 1) + calc(s, n, x, y * 10 + s[i], i + 1);
	}*/
	
	private static long calc2(int[] s, int n, int a, int i) {
		if(i == n - 1) {
			long tmp = s[0];
			long ans = 0;
			for(int j = 0; j < n - 1; j++) {
				if(a % 2 == 1) {
					tmp = tmp * 10 + s[j + 1];
				}else {
					ans += tmp;
					tmp = s[j + 1];
				}
				a >>= 1;
			}
			return ans + tmp;
		}
		a <<= 1;
		return calc2(s, n, a, i + 1) + calc2(s, n, a + 1, i + 1);
	}
	
	//x?y???"+"?????????????y???????????"+"????y????2?????
	/*static class Task {
		long x;
		long y;
		int i;
		
		Task(long x, long y, int i) {
			this.x = x;
			this.y = y;
			this.i = i;
		}
	}*/
}