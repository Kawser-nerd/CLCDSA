import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int X = sc.nextInt();
        int Y = sc.nextInt();
        
        int ans = 0;
        if (X >= 0 && Y >= 0) {
        	if (X > Y) {
        		ans += Y == 0 ? 1 : 2;
        		ans += X - Y;
        	} else {
        		ans += Y - X;
        	}
        } else if (X >= 0 && Y < 0) {
        	if (X == Math.abs(Y)) {
        		ans+=1;
        	} else {
        		ans+= 1;
        		ans+= Math.abs(X + Y);
        	}
        } else if (X < 0 && Y < 0) {
        	if (X < Y) {
        		ans+= Math.abs(X - Y);
        	} else {
        		ans+=2;
        		ans+= Math.abs(Y - X);
        	}
        } else if (X < 0 && Y >= 0) {
        	if (Math.abs(X) == Y) {
        		ans +=1;
        	} else {
        		ans += Y == 0 ? 0 : 1;
        		ans += Math.abs(X + Y);
        	}
        }
        
        System.out.println(ans);
    }
}