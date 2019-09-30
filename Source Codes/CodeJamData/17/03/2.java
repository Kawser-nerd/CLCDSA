package qualifier;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class CBathroomStalls {
    public static void main (String[] args) {
        try(Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)))) {
            int tests = sc.nextInt();
            
            for (int t = 1; t <= tests; t++) {
                long initialSize = sc.nextLong();
                long personCount = sc.nextLong();
                
                Map<Long, Long> numberAtSize = new HashMap<>();
                Queue<Long> sizeHeap = new PriorityQueue<>(Comparator.reverseOrder());
                
                long remainingPeople = personCount - 1;
                sizeHeap.add(initialSize);
                numberAtSize.put(initialSize, 1L);
                
                while(remainingPeople > 0) {
                    long size = sizeHeap.peek();
                    long number = numberAtSize.get(size);
                    if (number <= remainingPeople) {
                        numberAtSize.remove(sizeHeap.poll());
                        remainingPeople -= number;
                    } else {
                        numberAtSize.put(size, number - remainingPeople);
                        number = remainingPeople;
                        remainingPeople = 0;
                    }
                    long leftoverSize = size - 1;
                    long leftSize = leftoverSize / 2;
                    long rightSize = leftoverSize - leftSize;
                    for(long key : new long[] {leftSize, rightSize}) {
                        if (numberAtSize.containsKey(key)) {
                            numberAtSize.put(key, numberAtSize.get(key) + number);
                        } else {
                            numberAtSize.put(key, number);
                            sizeHeap.add(key);
                        }
                    }
                }
                
                long largestRemainingSize = sizeHeap.peek();
                long leftSpace = (largestRemainingSize - 1) / 2;
                long rightSpace = (largestRemainingSize - 1) - leftSpace;
                
                System.out.printf("Case #%d: %d %d%n", t, rightSpace, leftSpace);
            }
        }
    }
}
