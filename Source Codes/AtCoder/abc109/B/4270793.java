import java.util.*;
class Main {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int n = Integer.parseInt(s.nextLine());
        String prevWord = null;
        String currWord = null;
        Set<String> set = new HashSet<>();
        boolean isValid = true;
        for(int i = 0; i< n ;i++) {
            currWord = s.nextLine();
            if(set.contains(currWord)) {
                isValid = false;
            }
            set.add(currWord);
            if( isValid && i != 0 ) {
                if(prevWord.charAt(prevWord.length() - 1) != currWord.charAt(0)) {
                    isValid = false;
                }
            }
            prevWord = currWord;
        }
        System.out.println(isValid ? "Yes" : "No");
    }
}