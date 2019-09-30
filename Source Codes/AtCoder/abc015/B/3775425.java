import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        String[] line = scanner.nextLine().split(" ", n);

        int programs = 0;
        int totalBugs = 0;
        for (int i = 0; i < n; i++) {
            int bugs = Integer.parseInt(line[i]);
            if (bugs > 0) {
                programs++;
                totalBugs += bugs;
            }
        }

        if (totalBugs % programs == 0) {
            System.out.println(totalBugs / programs);
        } else {
            System.out.println(totalBugs / programs + 1);
        }
    }
}