import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        sc.nextLine();
        String line = sc.nextLine();

        char[] commands = new char[N];
        for (int i = 0; i < N; i++) {
            commands[i] = line.charAt(i);
        }

        char[] resources = { 'A', 'B', 'X', 'Y' };

        int ret = Integer.MAX_VALUE;

        for (char c1 : resources) {
            for (char c2 : resources) {
                for (char c3 : resources) {
                    for (char c4 : resources) {
                        int num = 0;
                        for (int i = 0; i < N; i++) {
                            if (i == N - 1) {
                                num++;
                                break;
                            }

                            if ((commands[i] == c1 && commands[i+1] == c2) || (commands[i] == c3 && commands[i+1] == c4)) i++;
                            num++;
                        }

                        ret = Math.min(ret, num);
                    }
                }
            }
        }

        System.out.println(ret);
    }
}