import java.math.BigDecimal;
import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        String str = sc.next();

        // ????????????
        String pattern = "WBWBWWBWBWBW";
        String[] notes = new String[]{
                "Do",
                "",
                "Re",
                "",
                "Mi",
                "Fa",
                "",
                "So",
                "",
                "La",
                "",
                "Si"
        };

        int position = -1;
        for (int i = 0; i < str.length(); i++) {
            String tmp = str.substring(i);
            String comp = pattern.substring(0, Math.min(tmp.length(), pattern.length()));

            if (tmp.startsWith(comp)) {
                position = i;
                break;
            }
        }
        int posi = (notes.length - (position % notes.length)) % notes.length;
        System.out.println(notes[posi]);
    }
}