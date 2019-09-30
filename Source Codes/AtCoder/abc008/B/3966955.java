import java.util.*;
import java.util.Map.Entry;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String S[] = new String[N];
        for (int i = 0; i < N; i++) {
            S[i] = sc.next();
        }
        Map<String, Integer> m = new HashMap<String, Integer>();
        for (String s : S) {
            int v;
            if (m.containsKey(s)) {
                v = m.get(s) + 1;
            } else {
                v = 1;
            }
            m.put(s, v);
        }
        List<Entry<String, Integer>> list_entries = new ArrayList<Entry<String, Integer>>(m.entrySet());
        Collections.sort(list_entries, new Comparator<Entry<String, Integer>>() {
            // compare???????????
            public int compare(Entry<String, Integer> obj1, Entry<String, Integer> obj2) {
                // ??
                return obj2.getValue().compareTo(obj1.getValue());
            }
        });

        // for (Entry<String, Integer> entry : list_entries) {
        // System.out.println(entry.getKey() + " : " + entry.getValue());
        // }
        System.out.println(list_entries.get(0).getKey());
    }
}