package at.jaki.round1C.B;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class B2 {

    private static final String INPUT = "B-large.in";
    //private static final String INPUT = "B-small-attempt1.in";
    //private static final String INPUT = "B-test.in";
    private static final String OUTPUT = "B-large.out";
    //private static final String OUTPUT = "B-small-attempt1.out";
    //private static final String OUTPUT = "B-test.out";

    public static final int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(INPUT));
        PrintWriter pw = new PrintWriter(OUTPUT);
        int totalTests = Integer.parseInt(br.readLine());
        for (int testNo = 1; testNo <= totalTests; testNo++) {
            int n = Integer.parseInt(br.readLine());
            String[] temp = br.readLine().split(" ");
            System.out.println(Arrays.toString(temp));

            List<String> list = new ArrayList<String>();
            long multi1 = transform1(temp, list);
            System.out.println(list);

            while (true) {
                int oldSize = list.size();
                List<String> list2 = new ArrayList<String>();
                transform2(list, list2);
                System.out.println(list2);
                int newSize = list2.size();
                list = list2;
                if (newSize == oldSize) {
                    break;
                }
            }
            System.out.println(list);
            while (true) {
                boolean done = transform3(list);
                System.out.println(list);
                if (done) {
                    break;
                }
            }

            String result;
            if (isValid(list)) {
                long r = multi1 * fact(list.size());
                r %= MOD;
                result = "" + r;
            } else {
                result = "0";
            }

            pw.print("Case #" + testNo + ": ");
            pw.println(result);

            System.out.println(result);
        }

        pw.flush();
        pw.close();

    }

    private static boolean isValid(List<String> list) {
        StringBuilder sb = new StringBuilder();
        for (String s : list) {
            sb.append(s);
        }
        Set<Character> used = new HashSet<Character>();
        char prevCh = '!';
        for (char ch : sb.toString().toCharArray()) {
            if (ch != prevCh) {
                if (used.contains(prevCh)) {
                    return false;
                }
                used.add(prevCh);
                prevCh = ch;
            }
        }
        if (used.contains(prevCh)) {
            return false;
        }
        return true;
    }

    private static boolean transform3(List<String> list) {
        Set<Integer> toRem = new HashSet<Integer>();
        String newString = null;
        outer:
        for (int i = 0; i < list.size(); i++) {
            char ch1S = list.get(i).charAt(0);
            char ch1E = list.get(i).charAt(list.get(i).length() - 1);
            for (int j = 0; j < list.size(); j++) {
                if (i == j) continue;
                char ch2S = list.get(j).charAt(0);
                char ch2E = list.get(j).charAt(list.get(j).length() - 1);
                if (ch1S == ch2E) {
                    toRem.add(i);
                    toRem.add(j);
                    newString = list.get(j).concat(list.get(i));
                    break outer;
                } else if (ch1E == ch2S) {
                    toRem.add(i);
                    toRem.add(j);
                    newString = list.get(i).concat(list.get(j));
                    break outer;
                }
            }
        }
        if (newString != null) {
            List<String> toRemSt = new ArrayList<String>();
            for (int x : toRem) {
                toRemSt.add(list.get(x));
            }
            list.removeAll(toRemSt);
            list.add(newString);
            return false;
        } else {
            return true;
        }
    }

    private static long transform2(List<String> oldList, List<String> newList) {
        Set<Integer> used = new HashSet<Integer>();
        for (int i = 0; i < oldList.size(); i++) {
            if (allAsFirst(oldList.get(i))) {
                Integer startIndex = null;
                Integer endIndex = null;
                for (int j = 0; j < oldList.size(); j++) {
                    if (i == j) continue;
                    if (used.contains(j)) continue;
                    if (oldList.get(j).charAt(0) == oldList.get(i).charAt(0)) {
                        startIndex = j;
                    }
                    if (oldList.get(j).charAt(oldList.get(j).length() - 1) == oldList.get(i).charAt(0)) {
                        endIndex = j;
                    }
                }
                StringBuilder sb = new StringBuilder();
                if (endIndex != null) {
                    sb.append(oldList.get(endIndex));
                    used.add(endIndex);
                }
                sb.append(oldList.get(i));
                used.add(i);
                if (startIndex != null) {
                    sb.append(oldList.get(startIndex));
                    used.add(startIndex);
                }
                newList.add(sb.toString());
            }
        }
        for (int i = 0; i < oldList.size(); i++) {
            if (!used.contains(i)) {
                newList.add(oldList.get(i));
            }
        }

        return 1;
    }

    private static long transform1(String[] temp, List<String> list) {
        List<String> allAsOne = new ArrayList<String>();
        List<String> mixed = new ArrayList<String>();
        for (String s : temp) {
            if (allAsFirst(s)) {
                allAsOne.add(s);
            } else {
                mixed.add(s);
            }
        }
        for (String mix : mixed) {
            list.add(mix);
        }
        Map<Character, List<String>> map = map(allAsOne);
        long multi = 1;
        for (char key : map.keySet()) {
            List<String> allSt = map.get(key);
            if (allSt.size() == 1) {
                list.add(allSt.get(0));
            } else {
                multi *= fact(allSt.size());
                multi %= MOD;
                StringBuilder sb = new StringBuilder();
                for (String s : allSt) {
                    sb.append(s);
                }
                list.add(sb.toString());
            }
        }
        return multi;
    }

    private static Map<Character, List<String>> map(List<String> allAsOne) {
        Map<Character, List<String>> map = new HashMap<Character, List<String>>();
        for (String s : allAsOne) {
            if (!map.containsKey(s.charAt(0))) {
                map.put(s.charAt(0), new ArrayList<String>());
            }
            map.get(s.charAt(0)).add(s);
        }
        return map;
    }

    private static boolean allAsFirst(String s) {
        char key = s.charAt(0);
        for (char ch : s.toCharArray()) {
            if (ch != key) return false;
        }
        return true;
    }

    private static long fact(int size) {
        long res = 1;
        for (int i = 1; i <= size; i++) {
            res *= i;
            res %= MOD;
        }
        return res;
    }


}
