import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int d = sc.nextInt();
        int k = sc.nextInt();
        int [] l = new int[d];
        int [] r = new int[d];
        for (int i = 0 ; i < d ; i++) {
            l[i] = sc.nextInt();
            r[i] = sc.nextInt();
        }
        int [] s = new int[k];
        int [] t = new int[k];
        for (int i = 0 ; i < k ; i++) {
            s[i] = sc.nextInt();
            t[i] = sc.nextInt();
        }
        for (int i = 0 ; i < k ; i++) {
            int start = s[i];
            int goal = t[i];
            int day = 0;
            if (start < goal) {
                for (int j = 0 ; j < d ; j++) {
                    if (l[j] <= start && r[j] >= start) {
                        start = r[j];
                        if (r[j] >= goal) {
                            day = j + 1;
                            break;
                        }
                    }
                }
                System.out.println(day);
            } else {
                for (int j = 0 ; j < d ; j++) {
                    if (r[j] >= start && l[j] <= start) {
                        start = l[j];
                        if (l[j] <= goal) {
                            day = j + 1;
                            break;
                        }
                    }
                }
                System.out.println(day);
            }
        }
    }

}