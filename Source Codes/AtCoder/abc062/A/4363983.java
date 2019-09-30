import java.util.*;

public class Main {
    public static void main(String[] args) {
        //List<Integer> list = new ArrayList<Integer>(Arrays.asList(0, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1));
        int list[] = {0, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        String ans = (list[a] == list[b])? "Yes" : "No";
        System.out.println(ans);
    }    
}