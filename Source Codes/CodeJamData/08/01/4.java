package library;
import java.util.*;
public class Translation<T>
{
	Hashtable<T,Integer> a;
	Hashtable<Integer,T> b;
	int next;
	public Translation()
	{
		a=new Hashtable<T,Integer>();
		b=new Hashtable<Integer,T>();
		next=0;
	}
	public int add(T item)
	{
		if(a.containsKey(item))
		{
			return a.get(item);
		}
		a.put(item,next);
		b.put(next, item);
		next++;
		return next-1;
	}
	public int get(T item)
	{
		if(a.containsKey(item))
		{
			return a.get(item);
		}
		return -1;
	}
	public T get(int index)
	{
		if(b.containsKey(index))
		{
			return b.get(index);
		}
		return null;
	}
}