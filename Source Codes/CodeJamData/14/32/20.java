import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class B {
	private static Scanner scan = new Scanner(System.in);
	public static void main(String[] args) throws FileNotFoundException {
		int cases = scan.nextInt();
		PrintStream outfile = new PrintStream("B-small.out.txt");

		String result = "";
		for (int c = 1; c <= cases; c++) {
			result = "Case #" + c + ": " + test();
			outfile.println(result);
			System.out.println(result);
		}
		outfile.close();
	}
	
	private static long test() {
		Car[] cars = new Car[scan.nextInt()];
		boolean[] middles = new boolean[26];
		boolean possible = true;
		for (int i = 0; i < cars.length; i++) {
			String input = removeRepeats(scan.next());
			int len = input.length();
			char front = input.charAt(0);
			char back = input.charAt(len-1);
			if (front == back && len > 1)
				possible = false;
			cars[i] = new Car(front, back);
			for (int j = 1; j < len-1; j++) {
				int c = input.charAt(j) - 'a';
				if (middles[c])
					possible = false;
				middles[c] = true;
			}
		}
		if (!possible)
			return 0;
		Car[] fronts = new Car[26];
		Car[] backs = new Car[26];
		int[] repeats = new int[26];
		ArrayList<Car> nonRepeats = new ArrayList<Car>();
		for (Car car : cars) {
			if (middles[car.front] || middles[car.back])
				return 0;
			if (car.front == car.back)
				repeats[car.front]++;
			else {
				if (fronts[car.front] != null || backs[car.back] != null)
					return 0;
				fronts[car.front] = car;
				backs[car.back] = car;
				nonRepeats.add(car);
			}
		}
		for (int i = 0; i < 26; i++) {
			if (fronts[i] != null && backs[i] != null) {
				fronts[i].prev = backs[i];
				backs[i].next = fronts[i];
				if (!fronts[i].union(backs[i]))
					return 0;
			}
		}

		HashSet<Car> roots = new HashSet<Car>();
		for (Car car : nonRepeats) {
			if (isInCycle(car))
				return 0;
			roots.add(car.getParent());
		}
		
		int sections = roots.size();
		long result = 1;
		for (int i = 0; i < 26; i++) {
			if (repeats[i] >= 1) {
				result = multiplyMod(result, factorialMod(repeats[i]));
				if (fronts[i] == null && backs[i] == null)
					sections++;
			}
		}
		result = multiplyMod(result, factorialMod(sections));
		return result;
	}
	
	private static String removeRepeats(String str) {
		char c = ' ';
		StringBuilder result = new StringBuilder();
		for (int i = 0; i < str.length(); i++) {
			char nextC = str.charAt(i);
			if (c != nextC) {
				c = nextC;
				result.append(c);
			}
		}
		return result.toString();
	}
	
	private static boolean isInCycle(Car car) {
		for (Car current = car.next; true; current = current.next) {
			if (current == car)
				return true;
			else if (current == null)
				return false;
		}
	}
	
	private static long multiplyMod(long a, long b) {
		return (a * b) % 1000000007L;
	}
	
	private static long factorialMod(int n) {
		long result = n;
		for (long i = n-1; i > 1; i--)
			result = multiplyMod(result, i);
		return result;
	}

	private static class Car {
		public final int front;
		public final int back;
		public Car next, prev;
		private Car parent;
		public Car(char front, char back) {
			this.front = front - 'a';
			this.back = back - 'a';
			next = null;
			prev = null;
			parent = this;
		}
		public boolean union(Car other) {
			if (getParent() == other.getParent())
				return false;
			getParent().parent = other;
			return true;
		}
		public Car getParent() {
			if (parent == this)
				return this;
			parent = parent.getParent();
			return parent;
		}
	}
}
