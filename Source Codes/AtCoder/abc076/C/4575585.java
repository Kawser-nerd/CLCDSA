import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        char[] sdash = sc.next().toCharArray();
        char[] T = sc.next().toCharArray();
        List<String> ansCandidates = new ArrayList<>();

        for (int i = 0; i < sdash.length - T.length + 1; i++) {
            boolean isMatch = true;
            char[] ansCandidate = new char[sdash.length];

            for (int j = 0; j < T.length; j++) {
                char sChar = sdash[i + j];
                if (sChar != '?' && sChar != T[j]) {
                    isMatch = false;
                }
            }

            if (isMatch) {
                for (int j = 0; j < sdash.length; j++) {
                    ansCandidate[j] = sdash[j];
                }
                for (int j = i; j < i + T.length; j++) {
                    ansCandidate[j] = T[j - i];
                }
                for (int j = 0; j < ansCandidate.length; j++) {
                    if (ansCandidate[j] == '?') {
                        ansCandidate[j] = 'a';
                    }
                }
                ansCandidates.add(String.valueOf(ansCandidate));
            }
        }

        if (ansCandidates.size() == 0) {
            System.out.println("UNRESTORABLE");
        } else {
            Collections.sort(ansCandidates);
            System.out.println(ansCandidates.get(0));
        }
    }
}