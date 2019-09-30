import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int s = sc.nextInt();
	int e = sc.nextInt();
	int cnt = 0;
	for(int i = s; i<=e; i++) {
	    int rev = getRev(i);
	    if(i==rev) {
		cnt++;
	    }
	}
	System.out.println(cnt);
    }
    public static int getRev(int i) {
	int ic = 0;
	while(i>0) {
	    ic = ic*10+i%10;
	    i /= 10;
	}
	return ic;
    }
}