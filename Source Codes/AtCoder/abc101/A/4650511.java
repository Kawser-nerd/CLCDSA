import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String N = sc.next();
	int ans	= 0;
	for(int i = 0; i<N.length(); i++) {
            char c = N.charAt(i);
            if(c=='+')ans++;
            else ans--;
        }
	System.out.println(ans);
    }
}