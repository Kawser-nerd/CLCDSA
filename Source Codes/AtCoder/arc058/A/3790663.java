import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            solve(sc);
        }
    }

    public static void solve(Scanner sc) {
        int N = sc.nextInt();
        int K = sc.nextInt();
        sc.nextLine();
        String[] Ds = sc.nextLine().split(" ");
        Set<String> DSet = new HashSet<>(Arrays.asList(Ds));
        boolean contains = true;
        while (contains) {
            contains = false;
            String ns = String.valueOf(N);
            for (int i = 0; i < ns.length(); i++) {
                if (DSet.contains(String.valueOf(ns.charAt(i)))) {
                    N++;
                    contains = true;
                    break;
                }
            }
        }

        System.out.println(N);
    }
}