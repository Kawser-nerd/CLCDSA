import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long ans = 0;
        long pre = 1;
        long pre2 = 2;
        if(N==1) ans = pre;
	for(int i = 2; i<=N; i++) {
	    ans = pre + pre2;
            pre2 = pre;
            pre = ans;
        }
        System.out.println(ans);
    }
}