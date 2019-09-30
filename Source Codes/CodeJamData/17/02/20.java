/* Google Code Jam Qualification Round 2017
 * Problem B. Tidy Numbers
 * Solution in Java
 * By Smithers
 */

import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int t = scanner.nextInt();
        for (int x = 1; x <= t; x++) {
            char[] n = Long.toString(scanner.nextLong()).toCharArray();
            
            for (int i = 0; i + 1 < n.length; i++) {
                if (n[i] > n[i + 1]) {
                    while (i > 0 && n[i-1] == n[i])
                        i--;
                    n[i]--;
                    while (++i < n.length) {
                        n[i] = '9';
                    }
                }
            }
            
            String y = new String(n, n[0] == '0' ? 1 : 0, n.length - (n[0] == '0' ? 1 : 0));
            System.out.println("Case #" + x + ": " + y);
        }
    }
}
