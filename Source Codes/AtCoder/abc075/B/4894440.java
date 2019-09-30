import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();

        List<List<String>> l = new ArrayList<>();
        for (int i = 0; i < a; i++) {
            l.add(Arrays.stream(sc.next().split("")).collect(Collectors.toList()));
        }
        for (int i = 0; i < a; i++) {
            List<String> row = l.get(i);
            for (int j = 0; j < row.size(); j++) {
                if (row.get(j).equals("#")) {
                    if (i > 0) {
                        List<String> p = l.get(i - 1);
                        if (j > 0) {
                            String s = p.get(j - 1);
                            if (s.equals("#") == false) {
                                p.set(j - 1, s.equals(".") ? "1" : String.valueOf(Integer.parseInt(s) + 1));
                            }
                        }
                        if (p.get(j).equals("#") == false) {
                            p.set(j, p.get(j).equals(".") ? "1" : String.valueOf(Integer.parseInt(p.get(j)) + 1));
                        }
                        if (j < b - 1) {
                            String s = p.get(j + 1);
                            if (s.equals("#") == false) {
                                p.set(j + 1, s.equals(".") ? "1" : String.valueOf(Integer.parseInt(s) + 1));
                            }
                        }
                    }

                    if (j > 0) {
                        String s = row.get(j - 1);
                        if (s.equals("#") == false) {
                            row.set(j - 1, s.equals(".") ? "1" : String.valueOf(Integer.parseInt(s) + 1));
                        }
                    }
                    if (j < b - 1) {
                        String s = row.get(j + 1);
                        if (s.equals("#") == false) {
                            row.set(j + 1, s.equals(".") ? "1" : String.valueOf(Integer.parseInt(s) + 1));
                        }
                    }

                    if (i < a - 1) {
                        List<String> p = l.get(i + 1);
                        if (j > 0) {
                            String s = p.get(j - 1);
                            if (s.equals("#") == false) {
                                p.set(j - 1, s.equals(".") ? "1" : String.valueOf(Integer.parseInt(s) + 1));
                            }
                        }
                        if (p.get(j).equals("#") == false) {
                            p.set(j, p.get(j).equals(".") ? "1" : String.valueOf(Integer.parseInt(p.get(j)) + 1));
                        }
                        if (j < b - 1) {
                            String s = p.get(j + 1);
                            if (s.equals("#") == false) {
                                p.set(j + 1, s.equals(".") ? "1" : String.valueOf(Integer.parseInt(s) + 1));
                            }
                        }
                    }

                }
            }
            if (0 < i) {
                System.out.println(l.get(i - 1).stream().map(s -> {
                    if (s.equals(".")) {
                        return "0";
                    }
                    return s;
                }).collect(Collectors.joining()));
            }
        }
        System.out.println(l.get(l.size() - 1).stream().map(s -> {
            if (s.equals(".")) {
                return "0";
            }
            return s;
        }).collect(Collectors.joining()));
    }
}