import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

class Main{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int x = scan.nextInt();
        int y = scan.nextInt();
        scan.close();
        List<Integer> group1 = new ArrayList<Integer>(Arrays.asList(1, 3, 5, 7, 8, 10, 12));
        List<Integer> group2 = new ArrayList<Integer>(Arrays.asList(4, 6, 9, 11));
        if (group1.containsAll(Arrays.asList(x, y)) || group2.containsAll(Arrays.asList(x, y)))
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}