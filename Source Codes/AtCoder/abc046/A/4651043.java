import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HashSet<Integer> set = new HashSet<Integer>();
	set.add(sc.nextInt());
	set.add(sc.nextInt());
	set.add(sc.nextInt());
	System.out.println(set.size());
    }
}