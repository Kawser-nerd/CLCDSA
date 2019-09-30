import static java.lang.Math.*;

import java.io.*;
import java.math.*;
import java.util.*;

public class ProblemBLarge {

	static class Car {
		String s;
		LinkedHashMap<Character, Long> numAddedSameCharCars = new LinkedHashMap<Character, Long>();

		char getFirst() {
			return s.charAt(0);
		}

		char getLast() {
			return s.charAt(s.length() - 1);
		}

		void addAllSameChars(Car car) {
			for (Map.Entry<Character, Long> entry : car.numAddedSameCharCars.entrySet()) {
				Character key = entry.getKey();
				Long value = numAddedSameCharCars.get(key);
				if (value == null) value = 0L;
				value += entry.getValue();
				numAddedSameCharCars.put(key, value);
			}
		}
		
		@Override
		public String toString() {
			return ""+s+" ("+numAddedSameCharCars+")";
		}
	}

	public class Case {
		LinkedHashSet<Car> cars = new LinkedHashSet<Car>();
		LinkedHashSet<Car> carsToCheck = new LinkedHashSet<Car>();

		public void solve(int caseIndex) {

			for (Car car : cars) {
				if (isSameCharCar(car)) {
					car.numAddedSameCharCars.put(car.s.charAt(0), 1L);
				}
			}
//			System.out.println("Cars: "+cars);

			carsToCheck = new LinkedHashSet<Car>();
			carsToCheck.addAll(cars);

//			LinkedHashSet<Car> carsWithSameChar = new LinkedHashSet<Car>();

			while (!carsToCheck.isEmpty()) {
				Car car = carsToCheck.iterator().next();
				carsToCheck.remove(car);

				if (isSameCharCar(car)) {
					for (Car car2 : cars) {
						if (car2 != car) {
							if (car2.getLast() == car.getFirst()) {
								combineCars(car2, car);
								break;
							}
							else if (car.getLast() == car2.getFirst()) {
								combineCars(car, car2);
								break;
							}
						}
					}
				}
			}

			carsToCheck = new LinkedHashSet<Car>();
			carsToCheck.addAll(cars);
			while (!carsToCheck.isEmpty()) {
				Car car = carsToCheck.iterator().next();
				carsToCheck.remove(car);

				for (Car car2 : cars) {
					if (car2 != car) {
						if (car2.getLast() == car.getFirst()) {
							combineCars(car2, car);
							break;
						}
						else if (car.getLast() == car2.getFirst()) {
							combineCars(car, car2);
							break;
						}
					}
				}
			}

			BigInteger result;
			if (!isValid()) {
				result = BigInteger.valueOf(0);
			}
			else {
				long mod = 1000000007L;
	
				result = BigInteger.valueOf(1);
				for (long i = 1; i <= cars.size(); i++) {
					result = result.multiply(BigInteger.valueOf(i));
				}
	
				for (Car car : cars) {
					for (Long sameChars : car.numAddedSameCharCars.values()) {
						long a = 1;
						for (long i = 1; i <= sameChars; i++) {
							a *= i;
							a %= mod;
						}
						result = result.multiply(BigInteger.valueOf(a));
					}
				}

				result = result.mod(BigInteger.valueOf(mod));
			}

//			long result;
//			if (!isValid()) {
//				result = 0;
//			}
//			else {
//				long mod = 1000000007L;
//	
//				result = 1;
//				for (long i = 1; i <= cars.size(); i++) {
//					result *= i;
//					result %= mod;
//				}
//	
//				for (Car car : cars) {
//					for (Long sameChars : car.numAddedSameCharCars.values()) {
//						long a = 1;
//						for (long i = 1; i <= sameChars; i++) {
//							a *= i;
//							a %= mod;
//						}
//						result *= a;
//						result %= mod;
//					}
//				}
//			}

			
			println("Case #" + (caseIndex + 1) + ": " + result);
		}

		void combineCars(Car car1, Car car2) {
			Car car = new Car();
			car.s = car1.s + car2.s;

			car.addAllSameChars(car1);
			car.addAllSameChars(car2);
//			car.numAddedSameCharCars = car1.numAddedSameCharCars + car2.numAddedSameCharCars;

			cars.add(car);
			carsToCheck.add(car);

			cars.remove(car1);
			carsToCheck.remove(car1);
			cars.remove(car2);
			carsToCheck.remove(car2);
//			System.out.println("Cars: "+cars);
		}

		boolean isSameCharCar(Car car) {
			String s = car.s;
			for (int k = 0; k < s.length(); k++) {
				if (s.charAt(k) != s.charAt(0)) {
					return false;
				}
			}
			return true;
		}
		
		boolean isValid() {
			LinkedHashSet<Character> processed = new LinkedHashSet<>();

			Character last = null;
			for (Car car : cars) {
				String s = car.s;
				for (int k = 0; k < s.length(); k++) {
					char ch = s.charAt(k);
//					System.out.println("Current: "+ch);
					if (last != null && last.charValue() == ch) {
//						System.out.println("Last: "+last+", processed: "+processed);
					}
					else {
						if (processed.contains(ch)) return false;
						processed.add(ch);
					}
					last = ch;
				}
			}
			return true;
		}
		
		long factorial(long p) {
			long result = 1;
			for (long i = 2; i <= p; i++) result *= i;
			return result;
		}

	}

	public void run() throws Exception {
		BufferedReader r = new BufferedReader(new FileReader("input.txt"));
		int numCases = new InputParser(r.readLine()).readInt();

		for (int caseIndex = 0; caseIndex < numCases; caseIndex++) {
			Case c = new Case();

			InputParser p = new InputParser(r.readLine());

			int numCars = p.readInt();
			p = new InputParser(r.readLine());
			for (int i = 0; i < numCars; i++) {
				Car car = new Car();
				car.s = p.readToken();
				c.cars.add(car);
			}

			c.solve(caseIndex);
		}

		r.close();
	}

	public static void main(String[] args) throws Exception {
		fileWriter = new PrintWriter(new OutputStreamWriter(new BufferedOutputStream(new FileOutputStream("output.txt"))));
		new ProblemBLarge().run();
		fileWriter.close();
	}

	public static class InputParser {
		String text;
		int pos;

		public InputParser(String text) {
			this.text = text;
		}

		public void skipSpaces() {
			while (pos < text.length()) {
				if (text.charAt(pos) != ' ') break;
				pos++;
			}
		}

		public String readUntil(char expectedChar) {
			StringBuilder b = new StringBuilder();
			while (pos < text.length()) {
				char ch = text.charAt(pos);
				if (ch == expectedChar) break;
				b.append(ch);
				pos++;
			}
			return b.toString();
		}

		public String readToken() {
			skipSpaces();
			return readUntil(' ');
		}

		public int readInt() {
			return Integer.parseInt(readToken());
		}

		public long readLong() {
			return Long.parseLong(readToken());
		}

		public double readDouble() {
			return Double.parseDouble(readToken());
		}

		public char readChar() {
			char ch = text.charAt(pos);
			pos++;
			return ch;
		}

		public void readExpectedString(String s) {
			for (int i = 0; i < s.length(); i++) {
				char ch = s.charAt(i);
				if (readChar() != ch) throw new RuntimeException("Expected: "+ch);
			}
		}
	}

	public static PrintWriter fileWriter;

	public static void print(String text) {
		fileWriter.print(text);
		System.out.print(text);
	}

	public static void println(String text) {
		fileWriter.println(text);
		System.out.println(text);
	}

	public static <Key, Value> void addToMultiMapArrayList(Key key, Value value, Map<Key, ArrayList<Value>> map) {
		ArrayList<Value> list = map.get(key);
		if (list == null) {
			list = new ArrayList<Value>();
			map.put(key, list);
		}
		list.add(value);
	}

	public static <Key, Value> void addToMultiMapLinkedHashSet(Key key, Value value, Map<Key, LinkedHashSet<Value>> map) {
		LinkedHashSet<Value> list = map.get(key);
		if (list == null) {
			list = new LinkedHashSet<Value>();
			map.put(key, list);
		}
		list.add(value);
	}

	public static <Key, Value> ArrayList<Value> getMultiMapValues(Map<Key, Collection<Value>> map) {
		ArrayList<Value> result = new ArrayList<Value>();
		for (Collection<Value> list : map.values()) {
			result.addAll(list);
		}
		return result;
	}

//	binarySearch(, , 0.000000001, new Function<Double, Integer>() {
//		public Integer evaluate(Double key) {
//			return ;
//		}
//	});
	public static double binarySearch(double low, double high, double precision, Function<Double, Integer> f) {
		if (high < low) throw new RuntimeException("High ("+high+") cannot be smaller than low ("+low+")");
		{
			int lowValue = f.evaluate(low);
			if (lowValue == 0) return low;
			if (lowValue > 0) throw new RuntimeException("Unsuitable low: "+low);
		}
		{
			int highValue = f.evaluate(high);
			if (highValue == 0) return high;
			if (highValue < 0) throw new RuntimeException("Unsuitable high: "+high);
		}

		while (true) {
			double mid = (low + high) * 0.5;
			if (abs(high - low) < precision) {
				return mid;
			}

			int c = f.evaluate(mid);
			if (c < 0) low = mid;
			else if (c > 0) high = mid;
			else return mid;
		}
	}

	public static <T> LinkedHashSet<T> intersection(Set<T> s1, Set<T> s2) {
		if (s2.size() < s1.size()) {
			Set<T> temp = s1;
			s1 = s2;
			s2 = temp;
		}
		LinkedHashSet<T> result = new LinkedHashSet<T>();
		for (T o : s1) {
			if (s2.contains(o)) result.add(o);
		}
		return result;
	}

	public static interface Function<Key, Value> {
		public Value evaluate(Key key);
	}

	public static class Int2 {
		int x, y;

		public Int2(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Int2 other = (Int2) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

		@Override
		public String toString() {
			return "("+x+","+y+")";
		}
	}
}



