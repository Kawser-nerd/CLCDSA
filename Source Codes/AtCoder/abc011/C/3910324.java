import java.util.*;
import java.lang.*;

public class Main {
    
    static int n;
    static int[] ng;
    
    public static void main (String args[]) {

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        ng = new int[3];
        
        for (int i = 0; i < 3; i++) {
            ng[i] = sc.nextInt();
        }
        
        boolean ans = true;
        if (!isOK(n, 0)) {
            ans = false;
        }

        for (int i = 0; i < 100; i++) {
            if (n == 0) break;
            
            if (isOK(n, 3) && n - 3 >= 0) {
                n -= 3;
            } else if (isOK(n, 2) && n - 2 >= 0) {
                n -= 2;
            } else if (isOK(n, 1) && n - 1 >= 0) {
                n -= 1;
            } else {
                ans = false;
                break;
            }
        }
        
        if (n > 0) {
            ans = false;
        }
        
        System.out.println(ans ? "YES":"NO");
    }
    
    static boolean isOK(int num, int param) {
        for (int i = 0; i < 3; i++) {
            if (num - param == ng[i]) {
                return false;
            }
        }
        return true;
    }
}