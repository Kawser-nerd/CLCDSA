import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        int N = sc.nextInt();
        String[] A = new String[S.length()];
        ArrayList<String> Ans = new ArrayList<>();
        A = S.split("");
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A.length; j++) {
                Ans.add(A[i] + A[j]);
            }
        }
        System.out.println(Ans.get(N - 1));
    }
}