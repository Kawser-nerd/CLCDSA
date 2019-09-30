import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] line = scanner.nextLine().split(" ", 4);
        int childPer = Integer.parseInt(line[0]);
        int adultPer = Integer.parseInt(line[1]);
        int kDeduct = Integer.parseInt(line[2]);
        int k = Integer.parseInt(line[3]);

        line = scanner.nextLine().split(" ", 2);
        int nChild = Integer.parseInt(line[0]);
        int nAdult = Integer.parseInt(line[1]);

        int sum = 0;
        if (nChild + nAdult >= k) {
            sum += (childPer - kDeduct) * nChild;
            sum += (adultPer - kDeduct) * nAdult;
        } else {
            sum += childPer * nChild;
            sum += adultPer * nAdult;
        }
        System.out.println(sum);
    }
}