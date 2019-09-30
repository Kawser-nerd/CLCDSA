import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), l = in.nextInt();
        in.nextLine();
        String[] lines = new String[l];
        for(int i = 0; i < l; i++)  {
            lines[i] = in.nextLine();
        }
        int pos = in.nextLine().indexOf('o');
        for(int i = l - 1; i >= 0; i--) {
            if(pos != n * 2 - 2 && lines[i].charAt(pos + 1) == '-') {
                pos += 2;
            } else if(pos != 0 && lines[i].charAt(pos -1) == '-') {
                pos -= 2;
            }
        }
        System.out.println(pos / 2 + 1);
    }
}