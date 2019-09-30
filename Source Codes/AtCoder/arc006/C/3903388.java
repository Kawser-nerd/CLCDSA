import java.util.*;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Collections;


public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        
        List<Integer> boxes = new ArrayList();
        for (int i = 0; i < n; i++) {
            boxes.add(Integer.parseInt(br.readLine()));
        }
        
        List<Integer> mtns = new ArrayList();
        for (Integer box: boxes) {
            int min = 100000;
            int index = -1;
            for (int i = 0; i < mtns.size(); i++) {
                int diff = mtns.get(i) - box;
                if (diff >= 0 && diff < min) {
                    min = diff;
                    index = i;
                }
            }
            if (min == 100000) {
                mtns.add(box);
            }
            else mtns.set(index, box);
        }
        
        System.out.println(mtns.size());
        
    }
}

class Box {
    int w;
    int h;
    public Box(int w, int h) {
        this.w = w;
        this.h = h;
    }
}

class BoxComparator1 implements Comparator<Box>{
	public int compare(Box b1, Box b2) {
		return b1.w - b2.w;
	}
}

class BoxComparator2 implements Comparator<Box> {
    public int compare(Box b1, Box b2) {
        return b1.h - b2.h;
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.