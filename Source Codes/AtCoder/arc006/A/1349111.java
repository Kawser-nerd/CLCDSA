import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        try {
            // ????
            InputStreamReader isr = new InputStreamReader(System.in);
            BufferedReader br = new BufferedReader(isr);
            String strArr[] = br.readLine().split(" ");
            int e[] = new int[10];
            for (int i = 0; i < 6; i++) {
                int tmp = Integer.parseInt(strArr[i]);
                e[tmp]++;
            }
            int bonus = Integer.parseInt(br.readLine());
            strArr = br.readLine().split(" ");
            int l[] = new int[10];
            for (int i = 0; i < 6; i++) {
                int tmp = Integer.parseInt(strArr[i]);
                l[tmp]++;
            }
            int count = 0;
            for (int i = 0; i < 10; i++) {
                if (e[i] == 1 && l[i] == 1) {
                    count++;
                }
            }
            boolean bonusFlag = false;
            if (l[bonus] == 1) {
                bonusFlag = true;
            }
            if (count == 6) {
                System.out.println(1);
            } else if (count == 5) {
                if (bonusFlag) {
                    System.out.println(2);
                } else {
                    System.out.println(3);
                }
            } else if (count == 4) {
                System.out.println(4);
            } else if (count == 3) {
                System.out.println(5);
            } else {
                System.out.println(0);
            }
        } catch (IOException e) {
            e.printStackTrace();
           }
    }
}