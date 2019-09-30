import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        String[] words = sc.nextLine().split(",");
        String haiku = words[0] + " " + words[1] + " " + words[2];
        System.out.println(haiku);
    }
}