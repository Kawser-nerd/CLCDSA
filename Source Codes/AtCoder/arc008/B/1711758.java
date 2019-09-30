import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int M = scan.nextInt();

        int name[] = new int[26];
        int kit[] = new int[26];
        String str = scan.next();
        for(int i = 0; i < N; i++)
            name[str.charAt(i) - 'A']++;
        str = scan.next();
        for(int i = 0; i < M; i++)
            kit[str.charAt(i) - 'A']++;

        int ans = 0;
        for(int i = 0; i < 26; i++) {
            if(name[i] > 0 && kit[i] == 0) {
                ans = -1;
                break;
            }
            else if(name[i] > 0 && kit[i] > 0) {
                if(ans < Math.ceil((float)name[i] / kit[i]))
                    ans = (int)Math.ceil((float)name[i] / kit[i]);
            }
        }
        
        System.out.println(ans);
    }
}