import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
	int N =	sc.nextInt();
	int T =	sc.nextInt();
	int[] a	= new int[N];
	int pre	= sc.nextInt();
	int ans	= 0;
        for(int i = 1; i<N; i++) {
            int	cur = sc.nextInt();
            ans += Math.min(cur-pre,T);
            pre	= cur;
        }
	System.out.println(ans+T);
    }
}