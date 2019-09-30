import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> A = new ArrayList<>();
        ArrayList<Integer> B = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            int a = sc.nextInt();
            A.add(a);
            B.add(a);
        }
        Collections.sort(A, Comparator.reverseOrder());
        for (int i = 0; i < A.size(); i++) {
            System.out.println(A.indexOf(B.get(i)) + 1);
        }
    }
}