import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        String[] names = new String[n];
        int[] popularity = new int[n];

        int totalPopularity = 0;
        for (int i = 0; i < n; i++) {
            String[] line = scanner.nextLine().split(" ", 2);
            names[i] = line[0];
            popularity[i] = Integer.parseInt(line[1]);
            totalPopularity += popularity[i];
        }

        String city = "atcoder";
        for (int i = 0; i < n; i++) {
            if (popularity[i] > totalPopularity / 2) {
                city = names[i];
                break;
            }
        }
        System.out.println(city);
    }
}