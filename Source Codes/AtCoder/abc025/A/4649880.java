import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String n = sc.next();
	int x = sc.nextInt();
	String[] str = new String[n.length()*n.length()];
	int index = 0;
	for(int i = 0; i<5;i++) {
	    for(int j = 0;j<5;j++) {
		str[index++] = String.format("%s%s",n.charAt(i),n.charAt(j));
	    }
	}
	Arrays.sort(str);
	System.out.println(str[x-1]);
    }
}