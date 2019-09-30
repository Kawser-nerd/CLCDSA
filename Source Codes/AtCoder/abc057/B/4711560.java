import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        int[][] student = new int[50][2];
        int[][] point = new int[50][2];

        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            student[i][0] = a;
            student[i][1] = b;
        }

        for (int i = 0; i < m; i++) {
            int c = sc.nextInt();
            int d = sc.nextInt();
            point[i][0] = c;
            point[i][1] = d;
        }

        sc.close();

        for (int i = 0; i < n; i++) {
            int min = Math.abs(student[i][0] - point[0][0]) + Math.abs(student[i][1] - point[0][1]);
            int check = 1;
            for (int j = 0; j < m; j++) {
                int dist = Math.abs(student[i][0] - point[j][0]) + Math.abs(student[i][1] - point[j][1]);
                if (min > dist) {
                    min = dist;
                    check = j + 1;
                }
            }
            System.out.println(check);
        }
    }
}