import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int x = sc.nextInt();
	int ans = 0;
	if(x<4) {
	    System.out.println(1);
	    return;
	}
	for(int i = 2; i<40; i++) {
	    int tmp = i;
	    int cnt = 0;
	    while(tmp<=x) {
		tmp *= i;
		cnt++;
	    }
	    if(cnt>=2) ans = Math.max(ans, tmp/i);
	}
	System.out.println(ans);
    }
}