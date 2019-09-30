import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();
        char[] s = sc.next().toCharArray();

        char[] ans = new char[n];
        LinkedList<Character> list = new LinkedList<>();
        for(int i = 0; i < n; i++) {
            list.add(s[i]);
        }

        for(int i = 0; i < n; i++) {
            PriorityQueue<Character> pq = new PriorityQueue<>();
            for(int j = 0; j < list.size(); j++) {
                pq.add(list.get(j));
            }
            loop : while(true) {
                char first = pq.poll();
                int tmp = k;
                LinkedList<Character> tmpList = (LinkedList<Character>) list.clone();
                tmpList.remove((Character) first);
                if(first != s[i]) {
                    tmp--;
                    if(tmp < 0) continue;
                }
                for(int j = i + 1; j < n; j++) {
                    if(tmpList.contains((Character) s[j])) {
                        tmpList.remove((Character) s[j]);
                    }else {
                        tmp--;
                        if(tmp < 0) continue loop;
                    }
                }
                if(first != s[i]) k--;
                ans[i] = first;
                list.remove((Character) first);
                break;
            }
        }

        System.out.println(String.valueOf(ans));

        sc.close();
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.