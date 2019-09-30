import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        int ans = Math.abs(Math.abs(x) - Math.abs(y));
        if((x<0 && y>0) || (x>=0 && y<=0) ) ans++;
        else if(x>y) ans += 2;
        System.out.println(ans);
        sc.close();
    }

}