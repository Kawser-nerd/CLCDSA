import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int l = sc.nextInt();
        String[] s = new String[n];
        List<String> li = new ArrayList<String>();
        for (int i = 0; i < n; i++) {
            s[i] = sc.next();
            li.add(s[i]);
        }
        Collections.sort(li);
        for (int i = 0; i < n; i++) {
            System.out.print(li.get(i));
        }
        System.out.println();

        sc.close();
    }
}