import java.util.*;
import java.io.*;

public class Main {
	public static void main (String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] arr = br.readLine().split(" ", 2);
		int n = Integer.parseInt(arr[0]);
		int k = Integer.parseInt(arr[1]);
		arr = br.readLine().split(" ", n);
		Person last = null;
		TreeSet<Person> set = new TreeSet<>(new Comparator<Person>() {
		public int compare(Person p1, Person p2) {
			return p1.age - p2.age;
		}
		});
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			Person p = new Person(i + 1, Integer.parseInt(arr[i]));
			set.add(p);
			if (i == 0) {
				last = p;
			} else if (i <= k - 1) {
				if (last.age < p.age) {
					last = p;
				}
			} else {
				if (last.age > p.age) {
					last = set.lower(last);
				}
			}
			if (i >= k - 1) {
				sb.append(last.rank).append("\n");
			}
		}
		System.out.print(sb);
	}
	
	static class Person {
		int rank;
		int age;
		public Person(int rank, int age) {
			this.rank = rank;
			this.age = age;
		}
		
		public boolean equals(Object o) {
			Person p = (Person)o;
			return p.rank == rank && p.age == age;
		}
		
		public int hashCode() {
			return rank + age;
		}
	}
}