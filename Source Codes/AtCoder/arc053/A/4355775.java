import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int h=sc.nextInt(),w=sc.nextInt();
        out.println((h-1)*w+h*(w-1));
    }
}