package round1c;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class C2 {
	
	public static class CacheItem {
		public long boxStart;
		public long toyStart;
		
		public CacheItem(long boxStart, long toyStart) {
			this.boxStart = boxStart;
			this.toyStart = toyStart;
		}
		
		@Override
		public int hashCode() {
			return (int)(boxStart ^ toyStart);
		}

		@Override
		public boolean equals(Object obj) {
			CacheItem other = (CacheItem)obj;
			return other.boxStart == boxStart && other.toyStart == toyStart;
		}
		
		
	}
	
	public static class Item {
		public int type;
		public long count;
		
		public Item(int type, long count) {
			this.type = type;
			this.count = count;
		}

		@Override
		public String toString() {
			return "Type: " + type + ", Count: " + count;
		}
		
		
	}
	
	public static Map<CacheItem, Long> cache = new HashMap<CacheItem, Long>();
	
	public static long solve(List<Item> boxes, long boxStart, List<Item> toys, long toyStart) {
		CacheItem cacheItem = new CacheItem(boxStart, toyStart);
		Long count = cache.get(cacheItem);
		if (count != null) return count.longValue();
		
		if (boxes.isEmpty() || toys.isEmpty()) {
			return 0;
		} else if (boxes.get(0).type == toys.get(0).type) {
			//System.out.println("Count: " + currentCount + ", " + boxes + ", " + toys);
			List<Item> newBoxes = new ArrayList<Item>(boxes.size());
			List<Item> newToys = new ArrayList<Item>(toys.size());
			Item firstBox = boxes.get(0);
			Item firstToy = toys.get(0);
			long used = Math.min(firstBox.count, firstToy.count);
			if (firstBox.count > used) {
				newBoxes.add(new Item(firstBox.type, firstBox.count - used));
			}
			if (firstToy.count > used) {
				newToys.add(new Item(firstToy.type, firstToy.count - used));
			}
			for (int i=1;i<boxes.size();i++) {
				newBoxes.add(boxes.get(i));
			}
			for (int i=1;i<toys.size();i++) {
				newToys.add(toys.get(i));
			}
			long result = used + solve(newBoxes, boxStart + used, newToys, toyStart + used);
			cache.put(cacheItem, Long.valueOf(result));
			return result;
		} else {
			List<Item> newBoxes = new ArrayList<Item>(boxes.size());
			for (int i=1;i<boxes.size();i++) {
				newBoxes.add(boxes.get(i));
			}
			long count1 = solve(newBoxes, boxStart + boxes.get(0).count, toys, toyStart);

			List<Item> newToys = new ArrayList<Item>(boxes.size());
			for (int i=1;i<toys.size();i++) {
				newToys.add(toys.get(i));
			}
			long count2 = solve(boxes, boxStart, newToys, toyStart + toys.get(0).count);
			long result = Math.max(count1, count2);
			cache.put(cacheItem, Long.valueOf(result));
			return result;
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=0;i<t;i++) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			List<Item> boxes = new ArrayList<Item>(n);
			List<Item> toys = new ArrayList<Item>(m);
			
			for (int j=0;j<n;j++) {
				long count = sc.nextLong();
				int type = sc.nextInt();
				boxes.add(new Item(type, count));
			}
			for (int j=0;j<m;j++) {
				long count = sc.nextLong();
				int type = sc.nextInt();
				toys.add(new Item(type, count));
			}
			
			cache.clear();
			System.out.println("Case #" + (i + 1) + ": " + solve(boxes, 0, toys, 0));
		}
	}
}
