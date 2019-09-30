import java.util.Scanner;
import java.util.*;
public class Main{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int a   = scan.nextInt();
        List<Integer> listA = new ArrayList<Integer>();

        for (int i = 0; i < a; i++) {
            listA.add(new Integer(scan.nextInt()));
        }

        List<Integer> listB = new ArrayList<Integer>(new LinkedHashSet<>(listA));

        System.out.println(listB.size());
    }
}