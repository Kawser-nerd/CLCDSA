import java.util.*;

public class Main {
    private static int L;
    private static int R;
    private static ArrayList<Integer> Left = new ArrayList<>();
    private static ArrayList<Integer> Right = new ArrayList<>();

    public static void input(){
        Scanner scan = new Scanner(System.in);

        L = scan.nextInt();
        R = scan.nextInt();

        for (int i=0;i<L;i++){
            Left.add(scan.nextInt());
        }

        for (int i=0;i<R;i++){
            Right.add(scan.nextInt());
        }
    }

    public static void main(String args[]) {
        //??
        input();

        int ans = 0;
        for (int i=0;i<L;i++){
            for (int j=0;j<Right.size();j++){
                if (Left.get(i) == Right.get(j)) {
                    Right.remove(j);
                    ans++;
                    break;
                }
            }
        }
        System.out.println(ans);
    }
}