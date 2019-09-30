import sun.reflect.generics.tree.Tree;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.stream.Collectors;


public class Main {
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		s.nextLine();
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = s.nextInt();
		}
		int cur = n;
		int doi=0;
		for(int i:arr)
		{
			if(i%4!=0)
				if(i%2==0)
				{
					doi++;
				}
		}
		if(doi!=0)
		{
			cur-=doi;
		cur++;
		}
		int patru=0;
		for(int i:arr)
		{
			if(i%4==0)
				patru++;
		}
		//System.out.println(cur+" "+patru);
				
		if(patru>=cur/2) System.out.println("Yes");
		else System.out.println("No");
		
		
	}
	
	
} ./Main.java:2: warning: Tree is internal proprietary API and may be removed in a future release
import sun.reflect.generics.tree.Tree;
                                ^
1 warning