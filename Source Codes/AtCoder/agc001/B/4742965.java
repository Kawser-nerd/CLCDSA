import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long num = sc.nextLong();
		long start = sc.nextLong();
		System.out.println(num + cal(start, num - start));
	}

	public static long cal(long width, long height) {
		if(width * height == 0) {
			return - Math.max(width, height);
		}else if(width == height) {
			return width;
		}else if (width > height) {
			return width / height * height * 2 + cal(width % height, height);
		}else {
			return height / width * width * 2 + cal(width, height % width);
		}
	}
}