import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        long[] count = new long[5];
        List<Character> symbols = new ArrayList<Character>() {
            {
                add('M');
                add('A');
                add('R');
                add('C');
                add('H');
            }
        };
        for (int i = 0; i < N; i++) {
            String name = sc.next();
            int index = symbols.indexOf(name.toCharArray()[0]);
            if (index != -1) {
                count[index] = count[index] + 1;
            }
        }

        long ans = 0;
        for (int i = 0; i < symbols.size(); i++) {
            for (int j = i + 1; j < symbols.size(); j++) {
                for (int k = j + 1; k < symbols.size(); k++) {
                    ans += count[i] * count[j] * count[k];
                }
            }
        }
        System.out.println(ans);
    }
}