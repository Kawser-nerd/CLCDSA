import java.util.Scanner;

/**
 * ??????: 2 sec / ?????: 64 MB
 * 
 * ??? ???????????????????? 2 ? 29 ????????????????
 * ?????????????????????????????????????????? ???????????????????????????????
 * 
 * ????????????????????? ?? 1 ? 4 ???????????????? ?? 2 ? 100 ?????????????????
 * ?? 3 ? 400 ???????????????? ?? 4 ??? 1 ? 3 ?????????????????????????? ??????
 * 1 ? 3 ???????????????????????????????????? ???? 2000 ???? 3 ?????????????
 * 2100 ???? 2 ?????????? 3 ????????????????????
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int year = sc.nextInt();

        boolean isUruYear = false;

        if (year % 4 == 0) {
            isUruYear = true;
        }

        if (year % 100 == 0) {
            isUruYear = false;
        }

        if (year % 400 == 0) {
            isUruYear = true;
        }

        System.out.println(isUruYear ? "YES" : "NO");

    }
}