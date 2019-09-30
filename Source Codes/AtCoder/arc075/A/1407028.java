import java.util.LinkedList;
import java.util.List;
import java.util.OptionalInt;
import java.util.Scanner;

public class Main {
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> ls = new LinkedList<>();
        for(int i = 0;i < n;i++)
            ls.add(sc.nextInt());
        int sum = ls.stream().mapToInt(e -> e).sum();
        if(sum % 10 != 0)
            System.out.println(sum);
        else
        {
            OptionalInt tmp = ls.stream().mapToInt(e -> e).filter(e -> e % 10 != 0).min();
            if(tmp.isPresent())
                System.out.println(sum - tmp.getAsInt());
            else
                System.out.println(0);
        }
    }
}