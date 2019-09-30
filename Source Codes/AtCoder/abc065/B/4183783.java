//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int mod = 1000000007;
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		Button[] buttons = new Button[n];
		for (int i=0; i<n; i++) {
			buttons[i] = new Button(sc.nextInt()-1, false);
		}
		buttons[0].light = true;
		
		int ans = -1;
		int nowLight = 0;
		for (int i=0; i<n; i++) {
			
			buttons[nowLight].light = false;
			nowLight = buttons[nowLight].Push();
			
			buttons[nowLight].light = true;
			if (nowLight == 1) {
				ans = i+1;
				break;
			}
		}
		
		System.out.println(ans);
		
	}
}

class Button {
	int num;
	boolean light;
	Button(int n, boolean l) {
		num = n; light = l;
	}
	int Push() {
		return num;
	}
}